using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    class Queen : Bee
    {
       
        public Queen(Hive hive) : base(hive)
        {
           
        }
        
        public Queen() { }


        public override void DoJob()
        {

            if (CurrentSeason == Seasons.Summer)
            {
                ProduceBee();
            }
            
            Eat();
            Console.WriteLine("Quuens' job is done!");
        }

        public void SetSeason(Seasons season)
        {
            CurrentSeason = season;
        }

        public override void Fly() {
            Console.WriteLine("Usually I don't fly a lot. This day too");
        }

        protected override double CalculateConsumption()
        {
            return CurrentSeason == Seasons.Summer ? HoneyConsumptionRateBasic * 4 : HoneyConsumptionRateBasic * 1.5;
            
        }

        

        private void ProduceBee()
        {
            if (MyHive == null || CurrentSeason != Seasons.Summer) return;
            Random random = new Random();
            int numOfNewBees = 2;
            for (int i = 0; i < numOfNewBees; i++)
            {
                Bee newBee = random.Next(15) > 13 ? (Bee)new Drone(MyHive) : new Worker(MyHive);
                MyHive.AcceptBee(newBee);
                Console.WriteLine("A bee has been created");
            }
        }

    

       

    }
}
