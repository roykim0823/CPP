using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reckless_Driver {
    class PlayerVehicle {
        public string Name { get; private set; }
        public int Handling{ get; private set; }
        public int TopSpeed{ get; private set; }
        public int Strength { get; private set; }
        public PlayerVehicle(string name, int handling, int topspeed, int strength) {
            Name = name;
            Handling = handling;
            TopSpeed = topspeed;
            Strength = strength;    
        }
        public void Up() {

        }
        public void Back() {

        }
        public void Left() {

        }
        public void Right() {

        }
    }
}
