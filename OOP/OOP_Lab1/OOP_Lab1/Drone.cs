using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    class Drone : Bee
    {
        public override void DoJob() {
            if (CurrentSeason == Seasons.Summer)
            {
                Eat();
            }

            Console.WriteLine("Job's done, just cause i'm doing nothing");
        }



        public override void Fly() {
            Console.WriteLine("Nope, to lazy for flying");
        }

        protected override double CalculateConsumption()
        {
            return HoneyConsumptionRateBasic * 3;
        }

        //public Drone(Hive hive)  {
        //    //Console.WriteLine("Drone()");
        //}

        public Drone(Hive hive) : base(hive) {

        }

    }
}
