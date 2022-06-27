using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reckless_Driver {
    class GameObject {
        public string Name { get; set; }
        public string Tag { get; set; }
        public bool Enabled { get; set; }
        public virtual void OnCollision(GameObject other) {

        }
    }
}
