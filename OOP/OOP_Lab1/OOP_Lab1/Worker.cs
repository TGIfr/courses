using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    class Worker : Bee
    {
        public override void DoJob()
        {
            if (MyHive != null)
            {
                MyHive.StoredHoney  += 2; 
            }
            Eat();
            Console.WriteLine("Simple worker's work has been done");
        }

        public double CollectHoney()
        {
            if (CurrentSeason == Seasons.Summer)
            {
                Console.WriteLine("After hard work i collected 2.25 points of honey");
                return 2.25;
            }
            else
            {
                Console.WriteLine("houston, we have a problem. It's hecking winter. NO FLOWERS");
                return 0;
            }
            
        }

        public override void Fly() {
            Console.WriteLine("OK, but you will suffer!");
        }

        protected override double CalculateConsumption() {
            return CurrentSeason == Seasons.Summer ? HoneyConsumptionRateBasic * 1.5 : HoneyConsumptionRateBasic * 1;
        }

        public Worker(Hive hive) : base(hive)
        {
            
        }
        public Worker() { }
    }
}
