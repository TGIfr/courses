using System;

namespace OOP_Lab3
{
    class Program
    {
        static void Main(string[] args) {
            Hive hive1 = new Hive();

            Console.WriteLine("Life of hive1 has started");
            for (int i = 0; i < 3; i++) {
                hive1.Tick();
                Console.WriteLine(hive1.BeesAmount);
                HiveUtils.CheckIfSuccessul(hive1);
                Console.ReadKey();
            }
            Console.WriteLine("Life of hive1 has ended");
            Queen directQueen = new Queen();
            Hive hive2 = new Hive(directQueen);

            Apiary ap = new Apiary();

            ap.Add(hive1);
            ap.Add(hive2);

            for (int i = 0; i < 3; i++) {
                ap.Tick();
                Console.ReadKey();
            }

            for (int i = 0; i < 3; i++) {
                ap.TickWithData();
                Console.ReadKey();
            }

            HiveUtils.SerializeHiveXml(ap[0]);
            HiveUtils.SerializeHiveBinary(ap[0]);

            ap.Clear();
            ap.Add(HiveUtils.DeserializeHiveBinary());

            for (int i = 0; i < 3; i++) {
                ap.TickWithData();
                Console.ReadKey();
            }
            Console.WriteLine(ap.Count);
            Console.ReadKey();;



            Console.ReadKey();
        }
    }

    
}
