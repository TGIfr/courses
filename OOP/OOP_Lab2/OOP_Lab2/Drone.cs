using System;

namespace OOP_Lab2
{
    class Drone : Bee
    {
        public override void DoJob(object sender, WorkEventArgs e) {
            if (CurrentSeason == Seasons.Summer)
            {
                Eat();
            }
            if (e.Danger) Console.WriteLine("too lazy. again. even to write in uppercase");
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
