using System;
using System.Runtime.Serialization;

namespace OOP_Lab3
{
    [Serializable]
    public abstract class Bee : Insect
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
            //hive.WorkStart += new EventHandler<WorkEventArgs>(DoJob);
        }

        public abstract void Fly();

        public abstract void DoJob(bool danger);

        protected abstract double CalculateConsumption();

        protected override void Eat() {
            if (MyHive != null) {
                MyHive.StoredHoney -= CalculateConsumption();
            } else {
                var args = new HiveNotFoundExceptionArgs(this);
                throw new HiveNotFoundException<HiveNotFoundExceptionArgs> (args);
                //Console.WriteLine("I don't have a Hive!");
            }
        }


    }

    

    public class HiveNotFoundException<TExceptionArgs> : Exception 
        where TExceptionArgs : ExceptionArgs
    {
        private readonly TExceptionArgs _args;

        public TExceptionArgs Args => _args;

        public HiveNotFoundException(TExceptionArgs args, string message = null)
            : base(message)
        {
            _args = args;
        }

       

        public override string Message {
            get
            {
                string baseMsg = base.Message;
                return (_args == null) ? baseMsg : baseMsg + " (" + _args.Message + ")";
            }
        }
    }

    public abstract class ExceptionArgs
    {
        public virtual string Message { get { return string.Empty; } }
    }

    public sealed class HiveNotFoundExceptionArgs : ExceptionArgs
    {
        private readonly object _bee;

        public object DatBee => _bee;

        public HiveNotFoundExceptionArgs(object bee)
        {
            _bee = bee.GetType().IsSubclassOf(typeof(Bee)) ? bee : null;
        }
        public override string Message {
            get
            {
                return "Dat be not found dat hive" + ((_bee != null)? "\r\nDat bee" + _bee: "");
            }
        }
    }

}
