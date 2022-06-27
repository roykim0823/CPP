using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Reckless_Driver {
    class Scene {
        private const int NPC_TYPES = 2;
        private const int SIDEOBJECT_COUNT = 2;
        private const int TRAFFIC_COUNT = 2;
        private Queue<SideObject> sideList = new Queue<SideObject>();
        private Queue<Vehicle> trafficList = new Queue<Vehicle>();
        private Player player;
        private Random random = new Random();

        public void Start(Player player) {
            this.player = player;
        }

        public void Execute() {
            GenerateSideObjects();
            GenerateTraffic();
            GeneratePowerUps();
            DisplaySideObjects();
            DisplayTraffic();
            Collide();
        }

        private void GeneratePowerUps()
        {
            int spawnIndex = 0;
            switch (player.Health.State)
            {
                case PlayerState.HEALTHY://Less healthkits
                    spawnIndex = random.Next(10);
                    break;
                case PlayerState.INJURED:
                    spawnIndex = random.Next(6);
                    break;
                case PlayerState.CRITICAL:
                    spawnIndex = random.Next(3);
                    break;
                case PlayerState.DEAD:
                    spawnIndex = 100;
                    break;
            }

            if (spawnIndex < Powerup.POWERUP_COUNT)
            {
                if (spawnIndex != 0 && player.Power.IsActive())
                {
                    return;
                }

                PowerupFactory.CreatePowerup(spawnIndex).OnCollision(player);
            }
        }

        public void Collide() {
            GameObject go = null;
            if (random.Next(2) == 0)
                return;
            switch (random.Next(NPC_TYPES)) {
                case 0://Sideobjects
                    go = sideList.ElementAt(random.Next(sideList.Count)) ;
                    break;
                case 1://Traffic
                    go = trafficList.ElementAt(random.Next(trafficList.Count));
                    break;
            }
            if(go != null) {
                go.OnCollision(player);
            }
            Thread.Sleep(1000);
        }
        private void GenerateSideObjects() {
            switch (player.Health.State)
            {
                case PlayerState.HEALTHY:
                    if(sideList.Count > 6) {
                        sideList.Dequeue();
                    }
                    break;
                case PlayerState.INJURED:
                    while (sideList.Count > 4)
                        sideList.Dequeue();
                    break;
                case PlayerState.CRITICAL:
                    while (sideList.Count > 2)
                        sideList.Dequeue();
                    break ;
                case PlayerState.DEAD:
                    break;
            }

            sideList.Enqueue(SideObjectFactory.Instance.CreateSideObject(random.Next(SIDEOBJECT_COUNT)));
        }
        private void GenerateTraffic() {

            switch (player.Health.State)
            {
                case PlayerState.HEALTHY:
                    if(trafficList.Count > 6) {
                        trafficList.Dequeue();
                    }
                    break;
                case PlayerState.INJURED:
                    while (trafficList.Count > 4)
                        trafficList.Dequeue();
                    break;
                case PlayerState.CRITICAL:
                    while (trafficList.Count > 2)
                        trafficList.Dequeue();
                    break ;
                case PlayerState.DEAD:
                    break;
            }
           

            Vehicle vehicle = null;
            switch (random.Next(TRAFFIC_COUNT)) {
                case 0://Sedan
                    vehicle = new Sedan(15, 80);
                    break;
                case 1://Van
                    vehicle = new Van(18, 90);
                    break;
            }
            trafficList.Enqueue(vehicle);
        }
        private void DisplaySideObjects() {
            Console.WriteLine("<<<<< SIDEOBJECTS >>>>>");
            foreach(var obj in sideList) {
                Console.WriteLine(obj.Name);
            }
        }
        private void DisplayTraffic() {
            Console.WriteLine("<<<<< TRAFFIC >>>>>");
            foreach (var obj in trafficList) {
                Console.WriteLine(obj.Name);
            }
        }
    }
}
