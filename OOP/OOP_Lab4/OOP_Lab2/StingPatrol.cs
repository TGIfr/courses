using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab3
{
    interface IStingPatrol
    {
        void LookForEnemies();
        void Sting();
        int AlertLevel { get; }
    }
}
