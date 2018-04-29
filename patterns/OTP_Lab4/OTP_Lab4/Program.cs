using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab4
{
    class Program
    {
        static void Main(string[] args) {
            var pc = new PayControl();
            pc.Pay(0);
            pc.Pay(1);
            pc.Pay(2);
            pc.Pay(6);
            pc.Pay(1);

            Console.ReadKey();
            Console.Clear();

            var cleaner = new CleaningProcessor();

            cleaner.SetCleaningStrategy(new FastStrategy());
            cleaner.Clean();
            
            cleaner.SetCleaningStrategy(new NormalStrategy());
            cleaner.Clean();

            cleaner.SetCleaningStrategy(new FullStrategy());
            cleaner.Clean();

            Console.ReadKey();
        }
    }
}
