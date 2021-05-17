using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

namespace Native
{
    using Entity = System.UInt32;

    [System.Serializable] public class EntityCreatedEvent : UnityEvent<Entity> { }
    [System.Serializable] public class EntityDestroyedEvent : UnityEvent<Entity> { }

    public class EventHub
    {
        public EntityCreatedEvent entityCreated = new EntityCreatedEvent();
        public void InvokeEntityCreated(Entity e) { entityCreated.Invoke(e); }

        public EntityDestroyedEvent entityDestroyed = new EntityDestroyedEvent();
        public void InvokeEntityDestroyed(Entity e) { entityDestroyed.Invoke(e); }
    }

}
