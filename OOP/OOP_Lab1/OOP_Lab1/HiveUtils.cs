using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1
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
