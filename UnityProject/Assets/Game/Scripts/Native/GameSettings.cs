using UnityEngine;
using System.Runtime.InteropServices;


[System.Serializable]
[StructLayout(LayoutKind.Sequential)]
public struct WaveSpawnConfiguration
{
    public float time;
    public int numToSpawn;
    public float intervalBetweenSpawn;
}

public class GameSettings : MonoBehaviour
{
    public Transform WaypointRoot;
    public WaveSpawnConfiguration[] SpawnConfigurations;

    public void SetupNativeScriptStates(Native.AbstractBaseNativeScript nativeScriptHandle)
    {
        if (nativeScriptHandle == null)
            return;

        Native.NativeGameState config;
        config.waypointCount = WaypointRoot.childCount;
        config.waypoints = new float[config.waypointCount * 4];
        for (int i = 0; i < config.waypointCount; i++)
        {
            Transform waypoint = WaypointRoot.GetChild(i);
            config.waypoints[i * 4] = waypoint.position.x;
            config.waypoints[i * 4 + 1] = waypoint.position.z;
            config.waypoints[i * 4 + 2] = waypoint.forward.x;
            config.waypoints[i * 4 + 3] = waypoint.forward.z;
        }
        config.waveCount = SpawnConfigurations.Length;
        config.waves = SpawnConfigurations;

        // We have our data, now we construct the pointer to pass to the native layer
        int size = Marshal.SizeOf(typeof(Native.NativeGameState));
        nativeScriptHandle.NativeMemory = Marshal.AllocHGlobal(size);
        Marshal.StructureToPtr(config, nativeScriptHandle.NativeMemory, false);

        nativeScriptHandle.PassGameConfig(nativeScriptHandle.NativeMemory);
        nativeScriptHandle.StartSimulation();
    }
}
