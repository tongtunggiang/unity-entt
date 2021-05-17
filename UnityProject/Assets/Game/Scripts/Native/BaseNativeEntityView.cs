using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

namespace Native
{
    using Entity = System.UInt32;

    public class BaseNativeEntityView : MonoBehaviour
    {
        public Entity EntityRef { get; set; }

        private void Start()
        {
            var native = FindObjectOfType<AbstractBaseNativeScript>();
            native.Events.entityDestroyed.AddListener(OnEntityDestroyed);
        }

        private void OnEntityDestroyed(Entity e)
        {
            if (e == EntityRef)
            {
                Destroy(gameObject);
            }
        }
    }
}