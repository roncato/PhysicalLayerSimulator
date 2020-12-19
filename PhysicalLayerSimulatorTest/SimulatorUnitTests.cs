using System;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using PhysicalLayer;

namespace PhysicalLayerSimulatorTest
{
	[TestClass]
	public class SimulatorUnitTests
	{

		private readonly Random _random = new Random(0x0);

		[TestMethod]
		public void SimulatorShouldStart()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			var pl = new PhysicalLayer.PhysicalLayer();
			ps.Start();
		}
		[TestMethod]
		public void SimulatorShouldStop()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Start();
			ps.Stop();
		}

		[TestMethod]
		public void SimulatorShouldSendDataOnRadio1()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Radio1.SetSendLogFile("Radio1Tx.log");
			ps.Start();
			const int framesSent = 1;
			var sendData = new byte[framesSent * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE];
			var receiveData = new byte[framesSent * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE];
			var bufferIndex = 0;
			const ushort remoteAddress = 0;

			for (var i = 0; i < framesSent; i++)
			{
				var frame = GetRandomFrame(PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
				Buffer.BlockCopy(frame, ps.PhysicalLayer.Radio2.LocalAddress, sendData, bufferIndex, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
				ps.PhysicalLayer.Radio1.Send(remoteAddress, frame, 0, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
				bufferIndex += PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
			}
			bufferIndex = 0;
			Thread.Sleep(600);
			var buffer = new byte[framesSent * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE];
			while (ps.PhysicalLayer.Radio2.Available > 0)
			{
				var bytesRead = ps.PhysicalLayer.Radio2.Read(buffer, 0, framesSent * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
				Buffer.BlockCopy(buffer, 0, receiveData, bufferIndex, bytesRead);
				bufferIndex += bytesRead;
			}
			ps.Stop();
			ps.Dispose();
			Console.WriteLine("Finished processing. Statistics 1:{0}", ps.PhysicalLayer.Statistics1.ToString());
			Console.WriteLine("Finished processing. Statistics 2:{0}", ps.PhysicalLayer.Statistics2.ToString());
			Assert.AreEqual(0, ps.PhysicalLayer.Statistics1.Errors, "Statistics 1 errors greater than 0.");
			Assert.AreEqual(0, ps.PhysicalLayer.Statistics2.Errors, "Statistics 2 errors greater than 0.");
		}

		[TestMethod]
		public void SimulatorShouldSendDataOnRadio1Async()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.Start();
			const int framesSent = 100;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, true);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void SimulatorShouldSendDataOnRadio2Async()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.Start();
			const int framesSent = 100;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio2, ps.PhysicalLayer.Radio1);
			AssertStatistics(ps.PhysicalLayer.Statistics1, true);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void DifferentPowerShouldCauseErrors()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Radio1.TransmitterPower = 2.0;
			ps.Start();
			const int framesSent = 100;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, false);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void InterferanceOnChannelShouldCauseErrors()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Channel1.InterferanceFrequency = 2 * ps.PhysicalLayer.Radio1.TransmitterCarrierFrequency;
			ps.PhysicalLayer.Radio1.TransmitterPower = 0.9;
			ps.PhysicalLayer.Radio2.ReceiverPower = ps.PhysicalLayer.Radio1.TransmitterPower;
			ps.Start();
			const int framesSent = 10000;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, false);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void LowSnrShouldCauseErrors()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Channel1.SNR = 13;
			ps.Start();
			const int framesSent = 10000;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, false);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void DifferentModulationTypesShouldCauseErrors()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Radio1.TransmitterModulationType = ModulationType.QAM;
			ps.PhysicalLayer.Radio2.ReceiverModulationType = ModulationType.PSK;
			ps.Start();
			const int framesSent = 100;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, false);
			ps.Stop();
			ps.Dispose();
		}

		[TestMethod]
		public void DefaultPskModulationShouldNotCauseErrors()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.PhysicalLayer.Radio1.TransmitterModulationType = ModulationType.PSK;
			ps.PhysicalLayer.Radio2.ReceiverModulationType = ModulationType.PSK;
			ps.Start();
			const int framesSent = 100;
			SendToRadioAsync(ps, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, true);
		}

		[TestMethod]
		public void RadiosShouldSendAndReceiveSimultaneously()
		{
			var ps = new PhysicalLayerSimulator.PhysicalLayerSimulator();
			ps.Initialize();
			ps.Start();
			const int framesSent = 100;
			SendAndReceive2Radios(ps, framesSent, framesSent, ps.PhysicalLayer.Radio1, ps.PhysicalLayer.Radio2);
			AssertStatistics(ps.PhysicalLayer.Statistics1, true);
			AssertStatistics(ps.PhysicalLayer.Statistics2, true);
		}

		/// <summary>
		/// Sends Frames to another radio
		/// </summary>
		/// <param name="ps"></param>
		/// <param name="framesToSend"></param>
		/// <param name="sendRadio"></param>
		/// <param name="receiveRadio"></param>
		private void SendToRadioAsync(PhysicalLayerSimulator.PhysicalLayerSimulator ps, int framesToSend, 
			Radio sendRadio, Radio receiveRadio)
		{
			var bufferSize = framesToSend * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
			var sendData = new byte[bufferSize];
			var receiveData = new byte[bufferSize];
			var framesSent = 0;
			var receiveBufferIndex = 0;
			var sending = true;

			var sendTask = new Task(() =>
			{
				var bufferIndex = 0;
				for (framesSent = 0; framesSent < framesToSend; framesSent++)
				{
					var frame = GetRandomFrame(PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					Buffer.BlockCopy(frame, 0, sendData, bufferIndex, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					sendRadio.Send(receiveRadio.LocalAddress, frame, 0, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					bufferIndex += PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
				}
				while (sendRadio.Buffered > 0)
				{
					Thread.Sleep(10);
				}
				sending = false;
			});

			var receiveTask = new Task(() =>
			{
				while (sending)
				{
					while (receiveRadio.Available > 0)
					{
						var buffer = new byte[bufferSize];
						var bytesRead = receiveRadio.Read(buffer, 0, bufferSize);
						Buffer.BlockCopy(buffer, receiveRadio.LocalAddress, receiveData, receiveBufferIndex, bytesRead);
						receiveBufferIndex += bytesRead;
					}
				}
			});

			receiveTask.Start();
			sendTask.Start();
			sendTask.Wait();
			receiveTask.Wait();
			Console.WriteLine("Finished processing. Frames Sent:{0}, Frames Received:{1}", 
				framesSent, receiveBufferIndex / PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
		}

		/// <summary>
		/// Sends Frames from one radio to the other and vice-versa
		/// </summary>
		/// <param name="ps"></param>
		/// <param name="framesToSend1"></param>
		/// <param name="framesToSend2"></param>
		/// <param name="radio1"></param>
		/// <param name="radio2"></param>
		private void SendAndReceive2Radios(PhysicalLayerSimulator.PhysicalLayerSimulator ps, int framesToSend1,
			int framesToSend2, Radio radio1, Radio radio2)
		{
			var bufferSize = framesToSend1 * PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
			var sendData = new byte[bufferSize];
			var receiveData = new byte[bufferSize];
			var framesSent1 = 0;
			var framesSent2 = 0;
			var receiveBufferIndex1 = 0;
			var receiveBufferIndex2 = 0;
			var sending1 = true;
			var sending2 = true;

			var sendTaskRadio1 = new Task(() =>
			{
				var bufferIndex = 0;
				for (framesSent1 = 0; framesSent1 < framesToSend1; framesSent1++)
				{
					var frame = GetRandomFrame(PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					Buffer.BlockCopy(frame, 0, sendData, bufferIndex, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					radio1.Send(radio2.LocalAddress, frame, 0, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					bufferIndex += PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
				}
				while (radio1.Buffered > 0)
				{
					Thread.Sleep(10);
				}
				sending1 = false;
			});

			var sendTaskRadio2 = new Task(() =>
			{
				var bufferIndex = 0;
				for (framesSent2 = 0; framesSent2 < framesToSend2; framesSent2++)
				{
					var frame = GetRandomFrame(PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					Buffer.BlockCopy(frame, 0, sendData, bufferIndex, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					radio2.Send(radio1.LocalAddress, frame, 0, PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
					bufferIndex += PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE;
				}
				while (radio2.Buffered > 0)
				{
					Thread.Sleep(10);
				}
				sending2 = false;
			});

			var receiveTaskRadio1 = new Task(() =>
			{
				while (sending2)
				{
					while (radio1.Available > 0)
					{
						var buffer = new byte[bufferSize];
						var bytesRead = radio1.Read(buffer, 0, bufferSize);
						Buffer.BlockCopy(buffer, radio1.LocalAddress, receiveData, receiveBufferIndex1, bytesRead);
						receiveBufferIndex1 += bytesRead;
					}
				}
			});

			var receiveTaskRadio2 = new Task(() =>
			{
				while (sending1)
				{
					while (radio2.Available > 0)
					{
						var buffer = new byte[bufferSize];
						var bytesRead = radio2.Read(buffer, 0, bufferSize);
						Buffer.BlockCopy(buffer, radio2.LocalAddress, receiveData, receiveBufferIndex2, bytesRead);
						receiveBufferIndex2 += bytesRead;
					}
				}
			});

			receiveTaskRadio1.Start();
			receiveTaskRadio2.Start();
			sendTaskRadio1.Start();
			sendTaskRadio2.Start();
			sendTaskRadio1.Wait();
			sendTaskRadio2.Wait();
			receiveTaskRadio1.Wait();
			receiveTaskRadio2.Wait();
			ps.Stop();
			ps.Dispose();
			Console.WriteLine("Finished processing. Frames Sent Radio1:{0}, Frames Received Radio1:{1}, " +
							  "Frames Sent Radio2:{2}, Frames Received Radio2:{3}",
				framesSent1, receiveBufferIndex1 / PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE, framesSent2,
				receiveBufferIndex2 / PhysicalLayer.PhysicalLayer.PAYLOAD_SIZE);
		}

		/// <summary>
		/// Asserts Statistics
		/// </summary>
		/// <param name="stats">Statistics</param>
		/// <param name="assertPositive"></param>
		private void AssertStatistics(Statistics stats, bool assertPositive)
		{
			if (assertPositive)
			{
				Assert.AreEqual(0, stats.Errors, "Statistics errors greater than 0.");
			}
			else
			{
				Assert.AreNotEqual(0, stats.Errors, "Statistics errors greater than 0.");
			}
		}

		byte[] GetRandomFrame(int size)
		{
			var frame = new byte[size];
			_random.NextBytes(frame);
			return frame;
		}

	}
}