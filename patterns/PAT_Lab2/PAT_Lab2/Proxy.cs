using System;

namespace PAT_Lab2
{
    class Accountant : IAccountant
    {
        
        public Documents MakeDocuments(Client c)
        {
            return new Documents("It says that all ok, " + c.Name);
        }
    }

    class CheckingAccountant : IAccountant
    {
        Accountant ac = new Accountant();

        public Documents MakeDocuments(Client c) {
            if (c.Payed)
            {
                Console.WriteLine("Docs ok, " + c.Name);
                return ac.MakeDocuments(c);
            }
            Console.WriteLine("Money first!, " + c.Name);
            return new Documents("NOT TODAY!!!");
        }
    }

    interface IAccountant
    {
        Documents MakeDocuments(Client c);
    }

    
    class Documents
    {
        public string Smth;

        public Documents(string smth)
        {
            this.Smth = smth;
        }
    }

    class Client
    {
        public string Name;
        public bool Payed;

        public Client(string name, bool payed)
        {
            this.Name = name;
            this.Payed = payed;
        }
    }
}
