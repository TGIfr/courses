using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab1_1
{
    class Program
    {
        static void Main(string[] args) {
            AbstractCalc normCalc = new AbstractCalc(new NormalCalc());
            AbstractCalc engCalc = new AbstractCalc(new EngineerCalc());
            Console.WriteLine("Normal usual op: " + normCalc.Add(5, 6));
            Console.WriteLine("Eng usual op: " + engCalc.Add(5, 6));
            Console.WriteLine("Normal unusual op: " + normCalc.Pow(5, 6));
            Console.WriteLine("Eng unusual op: " + engCalc.Pow(5, 6));
            Console.ReadKey();
        }
    }
}
