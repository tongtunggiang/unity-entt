using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Native
{
    public abstract class AbstractBaseNativeScript : MonoBehaviour
    {
        public EventHub Events { get; private set; } = new EventHub();
        public System.IntPtr NativeMemory { get; set; }

        public virtual void OnDestroy()
        {
            System.Runtime.InteropServices.Marshal.FreeHGlobal(NativeMemory);
            NativeMemory = System.IntPtr.Zero;
        }

        //--
        // Public derivable sections
        public abstract void Update();
        public abstract void Start();
        public abstract void Awake();
        public abstract void PassGameConfig(System.IntPtr config);
        public abstract void StartSimulation();
    }
}
