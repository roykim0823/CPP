using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Reckless_Driver {
    class GameManager {
        private static GameManager instance = new GameManager();
        public static GameManager Instance { get { return instance; } }
        private GameManager() {

        }
        private int cash;
        public int GetCash() {
            return cash;
        }
        public void AddCash(int amount) {
            cash += amount;
        }
        public void NewGame() {
            //Choose vehicle
            PlayerVehicle vehicle = new PlayerVehicle("Sedan", 5, 70, 4);
            //Create a player object
            Player player = new Player(100, vehicle);
            player.Tag = "Player";
            //Prepare the scenery
            Scene scene = new Scene();
            scene.Start(player);
            //Run a loop
            while (player.IsAlive) {
                Console.Clear();
                //Generate gameobjects (sideobjects, traffic, etc)
                scene.Execute();

                //Player is driving
                player.Drive();
            }
            EndGame();
        }

        

        public void EndGame() {
            Console.WriteLine("Total cash accumulated : {0}", cash);
        }
    }
}
