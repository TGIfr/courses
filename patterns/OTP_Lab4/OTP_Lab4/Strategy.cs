using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab4
{
    class CleaningProcessor
    {
        private ICleaningStrategy _cs;
        public void Clean()
        {
            _cs.Clean();
        }

        public void SetCleaningStrategy(ICleaningStrategy cs)
        {
            _cs = cs;
        }
    }

    public interface ICleaningStrategy
    {
        void Clean();
    }

    public class FastStrategy : ICleaningStrategy
    {
        public void Clean()
        {
            Console.WriteLine("Fast cleaning: folding things and sweeping");
        }
    }

    public class NormalStrategy : ICleaningStrategy
    {
        public void Clean() {
            Console.WriteLine("Normal cleaning: wiping dust and vacuum cleaning");
        }
    }

    public class FullStrategy : ICleaningStrategy
    {
        public void Clean() {
            Console.WriteLine("Full cleaning: washing floor and windows");
        }
    }
}
