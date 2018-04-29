using System;

namespace OOP_Lab2
{
    class Worker : Bee, ICollector, IStingPatrol
    {
        private int _alertLevel;

        public override void DoJob(object sender, WorkEventArgs e)
        {
            if (MyHive != null)
            {
                MyHive.StoredHoney  += CollectHoney(); 
            }
            if(e.Danger) LookForEnemies();
            Eat();
            Console.WriteLine("Simple worker's work has been done");
        }

        public void LookForEnemies()
        {
            Random random = new Random();
            if(random.Next(10) < 8 )
                Console.WriteLine("Nothing suspicious was found");
            else 
                Sting();
        }

        public void Sting()
        {
            Console.WriteLine("ALERT! Intruders was found and killed. Likely, I'm not dead");
            _alertLevel++;
        }

        public int AlertLevel { get { return _alertLevel; } }
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
