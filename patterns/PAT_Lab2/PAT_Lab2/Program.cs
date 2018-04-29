using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab2
{
    class Program
    {
        static void Main(string[] args) {
            Client c1 = new Client("Vasya", false);
            var c2 = new Client("Petya", true);
            var acCheck = new CheckingAccountant();
            acCheck.MakeDocuments(c1);
            acCheck.MakeDocuments(c2);

            Console.ReadKey();

            Console.Clear();

            User vasya = new User("Vasya");
            var jane = new User("Jane");
            var dich = new User("Dich");

            IGreeter ns = new Adapter();
            IGreeter os = new OldSystem();

            Console.WriteLine("NEW");
            Console.WriteLine(ns.GreetUser(vasya));
            Console.WriteLine(ns.GreetUser(jane));
            Console.WriteLine(ns.GreetUser(dich));

            Console.WriteLine("OLD");
            Console.WriteLine(os.GreetUser(vasya));
            Console.WriteLine(os.GreetUser(jane));
            Console.WriteLine(os.GreetUser(dich));

            Console.ReadKey();
        }
    }
}
