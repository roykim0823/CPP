using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Reckless_Driver {
    public enum PlayerState
    {
        HEALTHY,// > 70
        INJURED,// 26 && 70
        CRITICAL,// 1 && 25
        DEAD// 0
    }

    class PlayerHealth
    {
        private int healthUnits = 100;

        public PlayerState State
        {
            get;
            private set;
        }

        public PlayerHealth()
        {
            State = PlayerState.HEALTHY;
        }

        private void UpdateState()
        {
            if (healthUnits > 70)
            {
                State = PlayerState.HEALTHY;
            }
            else if (healthUnits > 25 && healthUnits <= 70)
            {
                State = PlayerState.INJURED;
            }
            else if (healthUnits >= 1 && healthUnits <= 25)
            {
                State = PlayerState.CRITICAL;
            }
            else
            {
                State = PlayerState.DEAD;
            }
        }

        public int Units
        {
            get => healthUnits;
            set
            {
                healthUnits = value;
                if (healthUnits > 100)
                    healthUnits = 100;
                else if (healthUnits < 0)
                    healthUnits = 0;
                UpdateState();
            }
        }
        
    }
    class Player : GameObject
    {
        public Powerup Power { get; set; }
        public PlayerHealth Health { get; set; }
       // public int Health { get; set; }
        public PlayerVehicle Vehicle { get; set; }
        public Player(int health, PlayerVehicle vehicle) {
            Health = new PlayerHealth();
            Health.Units = health;
            Vehicle = vehicle;
            Power = PowerupFactory.CreatePowerup(-1);
        }
        public bool IsAlive
        {
            get => Health.State != PlayerState.DEAD;
        }
        public void ApplyDamage(int damage, int cash) {
            Power.ApplyPowerup(this, damage, cash);
            //Health.Units -= damage - Vehicle.Strength;
            //GameManager.Instance.AddCash(cash);
        }
        public void Drive() {
            Console.WriteLine("\nPlayer is driving [Health={0}][Powerup={1}]",Health.Units, Power.ToString()  );
            for(int i = 0; i < 10; ++i) {
                Thread.Sleep(300);
                Console.Write(".");
            }
            Console.WriteLine("");
        }
        public void Accelerate() {
            Vehicle.Up();
        }
        public void Brake() {
            Vehicle.Back();
        }
        public void SteerLeft() {
            Vehicle.Left();
        }
        public void SteerRight() {
            Vehicle.Right();
        }
    }
}
