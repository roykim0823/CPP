using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Reckless_Driver {
    class Program {
        Player player;

        private static void Initialize()
        {
            SideObjectFactory.Instance.RegisterCallback(0, () =>
            {
                return new LetterBox(8, 13);
            });
            SideObjectFactory.Instance.RegisterCallback(1, () =>
            {
                return new FireHydrant(5, 10);
            });
        }
        static void Main(string[] args) {
            Initialize();
            GameManager.Instance.NewGame();
        }
    }
}
