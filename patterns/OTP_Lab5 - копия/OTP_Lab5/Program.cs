using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab5
{
    class Program
    {
        static void Main(string[] args) {

            FriendBase chain = new RichFriend();
            FriendBase more = new NotRichFriend();
            more.Successor = chain;
            chain = new DefinetelyNotRichFriend();
            chain.Successor = more;
            // hand the request to the chain
            Console.WriteLine(chain.AskForMoney(10));
            Console.WriteLine("\n\r\n\r");
            Console.WriteLine(chain.AskForMoney(200));
            Console.WriteLine("\n\r\n\r");
            Console.WriteLine(chain.AskForMoney(600));
            Console.WriteLine("\n\r\n\r");
            Console.WriteLine(chain.AskForMoney(4000));
           
            Console.ReadKey();
            Console.Clear();

            InterAgency interAgency = new InterAgency();
            Agency a = new Agency();
            Agency b = new Agency();

            interAgency.Register(a);
            interAgency.Register(b);

            User vasSeller = new Seller("VasyaSel");
            User petBuyer = new Buyer("PetyaBuy");

            a.Register(vasSeller);

            vasSeller.GetContacts();
            Console.WriteLine("vas got\n\r\n\r");
            a.Register(petBuyer);
            vasSeller.GetContacts();
            Console.WriteLine("vas got2\n\r\n\r");
            petBuyer.GetContacts();
            Console.WriteLine("pet got\n\r\n\r");

            User bSeller = new Seller("bSeller");
            b.Register(bSeller);

            petBuyer.GetContacts();
            Console.WriteLine("pet got 2\n\r\n\r");
            bSeller.GetContacts();
            Console.WriteLine("b got\n\r\n\r");
            bSeller.CostWish = Cost.High;
            vasSeller.QualityWish = Quality.Mid;
            petBuyer.QualityWish = Quality.Mid;
            petBuyer.GetContacts();
            Console.WriteLine("pet got 3\n\r\n\r");

            Console.ReadKey();
        }
    }
}
