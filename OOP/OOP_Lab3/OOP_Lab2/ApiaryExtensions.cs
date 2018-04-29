using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab3
{
    static class  ApiaryExtensions
    {
        public static void TickWithData(this Apiary ap)
        {
            ap.Tick();
            foreach (Hive hive in ap)
            {
                Console.WriteLine(hive.BeesAmount);
                HiveUtils.CheckIfSuccessul(hive);
                
            }
            
        }
    }
}
