using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.Serialization;

namespace OOP_Lab3
{
    [Serializable]
    public class Hive : IComparable
    {

        public string Breed { get; private set; }

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

        
        private Func<bool> dangerFunc;

        private bool WildDanger()
        {
            Random r = new Random();
            return r.Next(10) > 5;
        }

        private bool NotWildDanger() {
            Random r = new Random();
            return r.Next(10) > 7;
        }

        public int BeesAmount
        {
            get { return beeList.Count; }
        }

        public void AcceptBee(Bee bee)
        {
            Console.WriteLine("Bee accepted");
       
            bee.MyHive = this;
            WorkStart += (sender, e) => {
                bee.DoJob(e.Danger);
            };
            //WorkStart += bee.DoJob;
            beeList.Add(bee);
        }

        private void InitDangerFunc()
        {
            if (Breed == "wild")
            {
                dangerFunc = WildDanger;
            }
            else
            {
                dangerFunc = NotWildDanger;
            }
        }

        public Hive()
        {
            Breed = "wild";
            beeList = new List<Bee>();
            mainQueen = new Queen(this);

            beeList.Add(mainQueen);
            CurrentCycle = 0;
            WorkStart += delegate (object sender, WorkEventArgs e) {
                mainQueen.DoJob(e.Danger);
            };
            //WorkStart += danger => mainQueen.DoJob(danger);
            InitDangerFunc();
        }
        public Hive(string breed = "wild")
        {
            Breed = breed;
            beeList = new List<Bee>();
            mainQueen = new Queen(this);
           
            beeList.Add(mainQueen);
            CurrentCycle = 0;
            WorkStart += delegate (object sender, WorkEventArgs e) {
                mainQueen.DoJob(e.Danger);
            };
            //WorkStart += danger => mainQueen.DoJob(danger);
            InitDangerFunc();


        }

        public Hive(Queen queen, string breed = "wild")
        {
            Breed = breed;
            beeList = new List<Bee>();
            queen.MyHive = this;
            mainQueen = queen;
            beeList.Add(mainQueen);
            CurrentCycle = 0;
            WorkStart += (sender,  e) => mainQueen.DoJob(e.Danger);
            //WorkStart += danger => mainQueen.DoJob(danger);
            InitDangerFunc();
        }


        protected virtual void OnWorkStart(WorkEventArgs e) {
            EventHandler<WorkEventArgs> handler = WorkStart;

            if (handler != null) {
                handler(this, e);
            }
        }

        //public event Action<bool> WorkStart;
        [field: NonSerialized]
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

            WorkEventArgs e = new WorkEventArgs(dangerFunc());
            OnWorkStart(e);
            //WorkStart(dangerFunc());

            Console.WriteLine("Honey at end = {0}", StoredHoney);
            Console.WriteLine("One more cycle has ended\n\n");
        }

        public int CompareTo(object obj)
        {
            if (obj == null)
            {
                throw new ArgumentException("Object is null");
            };

            Hive h = obj as Hive;
            if (h != null)
                return this.BeesAmount.CompareTo(h.BeesAmount);
            else
                throw new ArgumentException("Object is not a Hive");
        }

        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            foreach (var bee in beeList)
            {
                WorkStart += (sender, e) => {
                    bee.DoJob(e.Danger);
                };
                bee.MyHive = this;
            }
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
