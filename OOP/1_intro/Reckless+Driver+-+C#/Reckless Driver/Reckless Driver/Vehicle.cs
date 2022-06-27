using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reckless_Driver {
    class Vehicle : GameObject{
        public int Damage { get; set; }
        public int Cash { get; set; }
        public Vehicle(int damage, int cash) {
            Damage = damage;
            Cash = cash;
        }
    }
    class Sedan : Vehicle {
        public Sedan(int damage, int cash) : base(damage, cash) {
            Name = "Sedan";
        }
        public override void OnCollision(GameObject other) {
            if (other.Tag == "Player") {
                Player player = other as Player;
                Console.WriteLine("#### COLLISION -> [Sedan] Sparks flying");
                player.ApplyDamage(Damage, Cash);
            }
        }
    }
    class Van : Vehicle {
        public Van(int damage, int cash) : base(damage, cash) {
            Name = "Van";
        }
        public override void OnCollision(GameObject other) {
            if (other.Tag == "Player") {
                Player player = other as Player;
                Console.WriteLine("#### COLLISION -> [Van] Milk bottles falling");
                player.ApplyDamage(Damage, Cash);
            }
        }
    }
}
