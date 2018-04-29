using System;
using System.Runtime.Serialization;

namespace OOP_Lab3
{
    [Serializable]
    public class Drone : Bee
    {
        public override void DoJob(bool danger) {
            if (CurrentSeason == Seasons.Summer)
            {
                Eat();
            }
            if (danger) Console.WriteLine("too lazy. again. even to write in uppercase");
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
