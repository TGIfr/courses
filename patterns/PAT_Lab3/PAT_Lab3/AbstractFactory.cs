using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab3
{
    public enum PaperTypes
    {
        Diploma,
        CharterInterschool,
        CharterOther
    }

    public class Participant
    {
        public PaperTypes Type;
        public double MoneyForPapers;
        public string School;
        public int Grade;
        public string Achievement;
        public string Name;

        public Participant(PaperTypes t, double moneyForPapers, string school,
            int grade, string achievement, string name = "John")
        {
            Type = t;
            School = school;
            MoneyForPapers = moneyForPapers;
            Grade = grade;
            Achievement = achievement;
            Name = name;
        }
    }

    public class PapersMaker
    {
        private readonly List<PapersFactory> _factories;
        public Papers MakePapers(Participant p)
        {
            PapersFactory appropriate = null;
            foreach (var factory in _factories)
            {
                if (factory.Cost < p.MoneyForPapers)
                {
                    appropriate = factory;
                    p.MoneyForPapers -= factory.Cost;
                    break;
                }
            }

            if (appropriate == null)
            {
                Console.WriteLine("You got not enough money");
                return null;
            }
            Console.WriteLine("Here is your papers");
            return appropriate.CreatePapers(p);

        }

        public PapersMaker(List<PapersFactory> list)
        {
            _factories = list;
            _factories.Sort((a, b) => (int) (b.Cost - a.Cost));
        }
    }
    public abstract class PapersFactory
    {
        protected int Inks;
        protected int PaperQuality;

        public virtual double Cost => PaperQuality * 5.5 + Inks * 6;

        public abstract Papers CreatePapers(Participant p);

    }

    public class CheapPapersFactory : PapersFactory
    {
        private static PapersFactory _instance;
        private static object syncLock = new object();

        public override Papers CreatePapers(Participant p)
        {
            switch (p.Type)
            {
                case PaperTypes.Diploma: return new LowDiploma(p);
                case PaperTypes.CharterInterschool: return new LowInterSchoolCharter(p);
                default: return new LowOtherCharter(p);
            }
        }

        public CheapPapersFactory()
        {
            Inks = 1;
            PaperQuality = 2;
        }


        public static PapersFactory GetPapersFactory() {
            if (_instance == null) {
                lock (syncLock) {
                    if (_instance == null) {
                        _instance = new CheapPapersFactory();
                    }
                }
            }

            return _instance;
        }
    }

    public class DorogobogatoPapersFactory : PapersFactory
    {
        private static PapersFactory _instance;
        private static object syncLock = new object();

        public DorogobogatoPapersFactory() {
            Inks = 5;
            PaperQuality = 6;
        }

        public override Papers CreatePapers(Participant p)
        {
            switch (p.Type) {
                case PaperTypes.Diploma: return new DorogobogatoDiploma(p);
                case PaperTypes.CharterInterschool: return new DorogobogatoInterSchoolCharter(p);
                default: return new DorogobogatoOtherCharter(p);
            }
        }

        

        public static PapersFactory GetPapersFactory() {
            if (_instance == null) {
                lock (syncLock) {
                    if (_instance == null) {
                        _instance = new DorogobogatoPapersFactory();
                    }
                }
            }

            return _instance;
        }
    }


    public abstract class Papers
    {
        public string Text;

        public string Quality { get; protected set; }
    }

    public class InterSchoolCharter : Papers
    {
        private string StandartText(Participant p)
        {
            return
                $"Greetings, {p.Name}, pupil of {p.School}, {p.Grade} grade. You've won {p.Achievement} in interschool contest," +
                $"and receive this {Quality} quality interschool charter";
        }
       
        public InterSchoolCharter(Participant p, string quality)
        {
            Quality = quality;
            Text = StandartText(p);
        }
    }

    public class LowInterSchoolCharter : InterSchoolCharter
    {
        public LowInterSchoolCharter(Participant p) : base (p, "LOW") {

        }
    }

    public class DorogobogatoInterSchoolCharter : InterSchoolCharter
    {
        public DorogobogatoInterSchoolCharter(Participant p) : base(p, "DOROGOBOGATO") {

        }
    }

    public class Diploma : Papers
    {
        private string StandartText(Participant p) {
            return
                $"Greetings, {p.Name}, diplomant of {p.School}, {p.Grade} grade. You got this diploma for {p.Achievement}" +
                $"of {Quality} quality";
        }

        public Diploma(Participant p, string quality) {
            Quality = quality;
            Text = StandartText(p);
        }
    }

    public class LowDiploma : Diploma
    {
        public LowDiploma(Participant p) : base(p, "LOW") {

        }
    }

    public class DorogobogatoDiploma : Diploma
    {
        public DorogobogatoDiploma(Participant p) : base(p, "DOROGOBOGATO") {

        }
    }

    public class OtherCharter : Papers
    {
        private string StandartText(Participant p) {
            return
                $"Greetings, {p.Name}, pupil of {p.School}, {p.Grade} grade. You've won {p.Achievement} in dich," +
                $"and receive this {Quality} quality dich charter";
        }
        public OtherCharter(Participant p, string quality) {
            Quality = quality;
            Text = StandartText(p);
        }
    }

    public class LowOtherCharter : OtherCharter
    {
        public LowOtherCharter(Participant p) : base(p, "LOW") {

        }
    }

    public class DorogobogatoOtherCharter : OtherCharter
    {
        public DorogobogatoOtherCharter(Participant p) : base(p, "DOROGOBOGATO") {

        }
    }
}
