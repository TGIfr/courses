using System;
using System.Collections.Generic;

namespace OOP_Lab2
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
            WorkStart += bee.DoJob;
            beeList.Add(bee);
        }
        

        public Hive()
        {
            beeList = new List<Bee>();
            mainQueen = new Queen(this);
           
            beeList.Add(mainQueen);
            CurrentCycle = 0;
            WorkStart += mainQueen.DoJob;
        }

        public Hive(Queen queen)
        {
            beeList = new List<Bee>();
            queen.MyHive = this;
            mainQueen = queen;
            beeList.Add(mainQueen);
            CurrentCycle = 0;
            WorkStart += mainQueen.DoJob;
        }


        protected virtual void OnWorkStart(WorkEventArgs e) {
            EventHandler<WorkEventArgs> handler = WorkStart;
            if (handler != null) {
                handler(this, e);
            }
        }

        public event EventHandler<WorkEventArgs> WorkStart;

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

            Random r = new Random();
            WorkEventArgs e = new WorkEventArgs(r.Next(10) > 7);
            OnWorkStart(e);

            Console.WriteLine("Honey at end = {0}", StoredHoney);
            Console.WriteLine("One more cycle has ended\n\n");
        }
    }

    public class WorkEventArgs : EventArgs
    {
        public bool Danger;

        public WorkEventArgs(bool danger) {
            Danger = danger;
        }
    }
}
