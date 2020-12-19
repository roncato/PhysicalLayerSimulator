using System.Security.Cryptography.X509Certificates;

namespace PhysicalLayerSimulator
{
	public interface IPhysicalLayerSimulator
	{

		/// <summary>
		/// Starts Simulator
		/// </summary>
		void Start();

		/// <summary>
		/// Stops Simulator
		/// </summary>
		void Stop();

		/// <summary>
		/// Simulator State
		/// </summary>
		PhysicalLayerSimulatorState State { get; }

		/// <summary>
		/// Initializes Simulator
		/// </summary>
		void Initialize();

	}
}
