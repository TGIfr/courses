using System;

namespace OOP_Lab2
{
    class HiveUtils
    {
        private HiveUtils() { }

        public static void CheckIfSuccessul(Hive hive)
        {
            Console.WriteLine(hive.StoredHoney > 110 ? "Successful" : "Not successful");
        }
    }
}
