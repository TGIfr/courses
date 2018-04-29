using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    class Hive
    {
        public int CurrentCycle { get; private set; }

        private double _storedHoney = 100;

        public double StoredHoney
        {
            get { return _storedHoney; }
            set
            {
                    
                    _storedHoney = value;                                  
            }
        }

        private List<Bee> beeList;
        private Queen mainQueen;

        public int BeesAmount
        {
            get { return beeList.Count; }
        }

        public void AcceptBee(Bee bee)
        {
            Console.WriteLine("Bee accepted");
            bee.MyHive = this;
            beeList.Add(bee);
        }
        

        public Hive()
        {
            beeList = new List<Bee>();
            mainQueen = new Queen(this);
            beeList.Add(mainQueen);
            CurrentCycle = 0;
        }

        public Hive(Queen queen)
        {
            beeList = new List<Bee>();
            queen.MyHive = this;
            mainQueen = queen;
            beeList.Add(mainQueen);
            CurrentCycle = 0;
        }

        


        public void Tick()
        {
            CurrentCycle++;
            if (CurrentCycle % 6 == 0)
            {
                mainQueen.SetSeason(Seasons.Winter);
            } else if (CurrentCycle % 6 == 3)
            {
                mainQueen.SetSeason(Seasons.Summer);
            }

            Console.WriteLine("\n\nOne more cycle has started");
            Console.WriteLine("Honey at start = {0}", StoredHoney);
            for (int i = 0; i < beeList.Count; i++)
            {
                var bee = beeList[i];
                if(!(bee is Queen) ) bee.DoJob();
                
            }

            mainQueen.DoJob();

            Console.WriteLine("Honey at end = {0}", StoredHoney);
            Console.WriteLine("One more cycle has ended\n\n");
        }
    }
}
