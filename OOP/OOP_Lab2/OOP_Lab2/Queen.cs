using System;

namespace OOP_Lab2
{
    class Queen : Bee, IStingPatrol
    {
       
        public Queen(Hive hive) : base(hive)
        {
           
        }
        
        public Queen() { }


        public override void DoJob(object sender, WorkEventArgs e)
        {

            if (CurrentSeason == Seasons.Summer)
            {
                ProduceBee();
            }
            if (e.Danger) LookForEnemies();
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


        public void LookForEnemies()
        {
            Console.WriteLine("I'm not protecting the hive, wtf?!");
        }

        public void Sting()
        {
            Console.WriteLine("My rival was killed");
        }

        public int AlertLevel => 0;
    }
}
