using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reckless_Driver {
    class SideObject : GameObject{
        public int Damage { get; set; }
        public int Cash { get; set; }
        protected int count = 0;
        public SideObject(int damage, int cash) {
            Damage = damage;
            Cash = cash;
        }
    }
    class FireHydrant : SideObject {
        public FireHydrant(int damage, int cash) : base(damage, cash) {
            Name = "FireHydrant";
        }
        public override void OnCollision(GameObject other) {
            if(other.Tag == "Player") {
                Player player = other as Player;
                if(count == 0) {
                    Console.WriteLine("#### COLLISION -> [FireHydrant] Fountain");
                    player.ApplyDamage(Damage, Cash);
                }
                else {
                    Console.WriteLine("#### COLLISION -> [FireHydrant] Collided again");
                    player.ApplyDamage(Damage, Cash * count);
                }
            }
        }
    }
    class LetterBox : SideObject {
        public LetterBox(int damage, int cash) : base(damage, cash) {
            Name = "LetterBox";
        }
        public override void OnCollision(GameObject other) {
            if (other.Tag == "Player") {
                Player player = other as Player;
                if (count == 0) {
                    Console.WriteLine("#### COLLISION -> [LetterBox] Letters falling");
                    player.ApplyDamage(Damage, Cash);
                }
                else {
                    Console.WriteLine("#### COLLISION -> [LetterBox] Collided again");
                    player.ApplyDamage(Damage, Cash * count);
                }
            }
        }
    }
}
