using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    abstract class Bee : Insect
    {

        protected const double HoneyConsumptionRateBasic = 0.5;

        

        protected static Seasons CurrentSeason;

      
        public Hive MyHive { get;  set; }

        static Bee()
        {
            CurrentSeason = Seasons.Summer;
        }

        public Bee()
        {
            //Console.WriteLine("Constructor Bee() was called");
        }

        public Bee(Hive hive)
        {
            MyHive = hive;
        }

        public abstract void Fly();

        public abstract void DoJob();

        protected abstract double CalculateConsumption();

        protected override void Eat() {
            if (MyHive != null) {
                MyHive.StoredHoney -= CalculateConsumption();
            } else {
                Console.WriteLine("I don't have a Hive!");
            }
        }


    }
}
