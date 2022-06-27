using System;
using System.Collections.Generic;

namespace Reckless_Driver
{
    class PowerupFactory
    {
        public static Powerup CreatePowerup(int key)
        {
            switch (key)
            {
                case -1:
                    return new NoPowerup();
                case 0:
                    return new HealthKit();
                case 1:
                    return new Armor();
            }

            return null;
        }
    }

    class SideObjectFactory
    {
        private Dictionary<int, Func<SideObject>> callbacks = new Dictionary<int, Func<SideObject>>();

        private SideObjectFactory()
        {

        }
        public static SideObjectFactory Instance { get; private set; } = new SideObjectFactory();

        public void RegisterCallback(int key, Func<SideObject> callback)
        {
            callbacks[key] = callback;
        }
        public SideObject CreateSideObject(int key)
        {
            return callbacks[key]();
        }
    }
}