using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reckless_Driver
{
    abstract class Powerup : GameObject
    {
        private const int DURATION = 5;
        public int CountDown { get; protected set; }
        public static readonly int POWERUP_COUNT = 2;
        public abstract void ApplyPowerup(Player player, int damage, int cash);

        public Powerup()
        {
            CountDown = DURATION;
        }
        public virtual bool IsActive()
        {
            return true;
        }
    }

    class HealthKit : Powerup
    {
        public override void ApplyPowerup(Player player, int damage, int cash)
        {
        }

        public override void OnCollision(GameObject other)
        {
            if (other.Tag == "Player" && other is Player)
            {
                Console.WriteLine("****************************");
                Console.WriteLine("********** HEALTHKIT **********");
                Console.WriteLine("****************************");
                var player = (Player) other;
                player.Health.Units += 25;
            }
        }
    }

    class NoPowerup : Powerup
    {
        public override void ApplyPowerup(Player player, int damage, int cash)
        {
            player.Health.Units -= damage - player.Vehicle.Strength;
            GameManager.Instance.AddCash(cash);
        }

        public override bool IsActive()
        {
            return false;
        }

        public override string ToString()
        {
            return "Default";
        }
    }

    class Armor : Powerup
    {
        public override void ApplyPowerup(Player player, int damage, int cash)
        {
            var totalDamage = player.Vehicle.Strength + damage / 2;
            player.Health.Units -= totalDamage;
            GameManager.Instance.AddCash(cash);
            if (--CountDown == 0)
            {
                player.Power = new NoPowerup();
            }
        }

        public override string ToString()
        {
            return string.Format("Armor [{0}]", CountDown);
        }

        public override void OnCollision(GameObject other)
        {
            if (other.Tag == "Player")
            {
                Console.WriteLine("****************************");
                Console.WriteLine("*********** ARMOR **********");
                Console.WriteLine("****************************");
                Player player = (Player) other;
                player.Power = this;
            }
        }
    }
}
