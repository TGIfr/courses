using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
{
    class Program
    {
        static void Main(string[] args) {
            Hive hive1 = new Hive();

            Console.WriteLine("Life of hive1 has started");
            for (int i = 0; i < 10; i++)
            {
                hive1.Tick();
                Console.WriteLine(hive1.BeesAmount);
                HiveUtils.CheckIfSuccessul(hive1);
                Console.ReadKey();
            }
            Console.WriteLine("Life of hive1 has ended");
            Queen directQueen = new Queen();
            Hive hive2 = new Hive(directQueen);

            Console.WriteLine("Life of hive2 has started");
            for (int i = 0; i < 10; i++) {
                hive2.Tick();
                Console.WriteLine(hive2.BeesAmount);
                HiveUtils.CheckIfSuccessul(hive2);
                Console.ReadKey();
            }
            Console.WriteLine("Life of hive2 has ended");

            Console.ReadKey();
        }
    }
}
