using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Native
{
    [StructLayout(LayoutKind.Sequential)]
    struct NativeGameState
    {
        public System.Int32 waypointCount;
        public float[] waypoints;
        public System.Int32 waveCount;
        public WaveSpawnConfiguration[] waves;
    }
}
