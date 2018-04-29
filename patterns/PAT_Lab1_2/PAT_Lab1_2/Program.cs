using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab1_2
{
    class Program
    {
        static void Main(string[] args) {
            //root
            UsualSeller ceo = new UsualSeller("Mike");

            UsualSeller mid = new UsualSeller("Melody");
            ceo.Add(mid);
            UsualSeller mid2 = new UsualSeller("NaN");
            ceo.Add(mid2);

            UsualSeller low = new UsualSeller("Mo");
            UsualSeller low2 = new UsualSeller("Cork");
            UsualSeller low3 = new UsualSeller("Sara");
            mid.Add(low);
            mid2.Add(low2);
            mid2.Add(low3);

            EndSeller larry = new EndSeller("Larry");
            EndSeller jen = new EndSeller("Jen");
            EndSeller cern = new EndSeller("Cern");
            EndSeller lepton = new EndSeller("Lepton");

            low.Add(larry);
            low.Add(lepton);
            low2.Add(jen);
            mid.Add(cern);

            ceo.SellCosmetics(150, 68);

            ceo.Display(2);
            Console.ReadKey();
        }
    }
}
