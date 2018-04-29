using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    interface IStingPatrol
    {
        void LookForEnemies();
        void Sting();
        int AlertLevel { get; }
    }
}
