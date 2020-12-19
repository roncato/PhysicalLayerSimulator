using System;
using System.Configuration;
using System.Threading;
using System.Threading.Tasks;

namespace PhysicalLayerSimulator
{
	public class PhysicalLayerSimulator : IDisposable
	{

		#region Instance Variables

		private readonly global::PhysicalLayer.PhysicalLayer _physicalLayer;
		private PhysicalLayerSimulatorState _state;
		private readonly CancellationTokenSource _cancelSource = new CancellationTokenSource();
		private int _stepPeriod;

		#endregion

		public PhysicalLayerSimulator()
		{
			_physicalLayer = new global::PhysicalLayer.PhysicalLayer();
			_state = PhysicalLayerSimulatorState.Stopped;
		}

		~PhysicalLayerSimulator()
		{
			_physicalLayer.Dispose();
		}

		public void Initialize()
		{
			_physicalLayer.Initialize();
			int.TryParse(ConfigurationManager.AppSettings["StepPeriod"], out _stepPeriod);
		}

		public async void Start()
		{
			_state = PhysicalLayerSimulatorState.Running;
			_cancelSource.Token.Register(() =>
			{
				_state = PhysicalLayerSimulatorState.Stopped;
				_physicalLayer.Dispose();
			});
			var task = new Task(() =>
					{
						while (_state == PhysicalLayerSimulatorState.Running)
						{
							var sTime = DateTime.Now;
							_physicalLayer.Step();
							var ellapsed = DateTime.Now.Subtract(sTime).TotalMilliseconds;
							if (ellapsed < _stepPeriod)
							{
								Thread.Sleep((int)(_stepPeriod - ellapsed));
							}
						}
					}
					, _cancelSource.Token
				);
			task.Start();
			await task;
		}

		public void Stop()
		{
			_cancelSource.Cancel();
		}

		public void Dispose()
		{
			if (_state == PhysicalLayerSimulatorState.Running)
			{
				Stop();
			}
			_cancelSource.Dispose();
		}

		#region Properties

		public PhysicalLayerSimulatorState State
		{
			get { return _state; }
		}

		public PhysicalLayer.PhysicalLayer PhysicalLayer
		{
			get
			{
				return _physicalLayer;
			}
		}

		public int StepPeriod
		{
			get { return _stepPeriod; }
			set { _stepPeriod = value; }
		}

		#endregion

	}
}
