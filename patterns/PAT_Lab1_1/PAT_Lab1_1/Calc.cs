using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab1_1
{
    //enum Operations
    //{
    //    Add,
    //    Minus,
    //    Mult,
    //    Divide,
    //    Sqrt,
    //    Mod,
    //    Pow
    //}
    interface ICalc
    {
        //double PerformOperation(Operations op, double a, double b);
        double Add(double a, double b);
        double Minus(double a, double b);
        double Mult(double a, double b);
        double Divide(double numerator, double denumerator);
        double Sqrt(double a);
        double Mod(double a, double b);
        double Pow(double a, double power);
    }
    class AbstractCalc 
    {
        ICalc calc;
        public AbstractCalc(ICalc p) {
            this.calc = p;
        }

        public double Add(double a, double b)
        {
            return this.calc.Add(a, b);
        }

        public double Minus(double a, double b)
        {
            return this.calc.Minus(a, b);
        }

        public double Mult(double a, double b)
        {
            return this.calc.Mult(a, b);
        }

        public double Divide(double numerator, double denumerator)
        {
            return this.calc.Divide(numerator, denumerator);
        }

        public double Sqrt(double a)
        {
            return this.calc.Sqrt(a);
        }

        public double Mod(double a, double b)
        {
            return this.calc.Mod(a, b);
        }

        public double Pow(double a, double power)
        {
            return this.calc.Pow(a, power);
        }
    }
    class NormalCalc : ICalc
    {
      
        public double Add(double a, double b) {
            return a + b;
        }

        public double Minus(double a, double b)
        {
            return a - b;
        }

        public double Mult(double a, double b)
        {
            return a * b;
        }

        public double Divide(double numerator, double denumerator)
        {
            return numerator / denumerator;
        }

        public double Sqrt(double a)
        {
            Console.WriteLine("SQRT NOT ALOWED HERE");
            return 0;
        }

        public double Mod(double a, double b)
        {
            Console.WriteLine("MOD NOT ALOWED HERE");
            return 0;
        }

        public double Pow(double a, double power)
        {
            Console.WriteLine("POW NOT ALOWED HERE");
            return 0;
        }
    }
    class EngineerCalc : ICalc
    {
        public double Add(double a, double b) {
            return a + b;
        }

        public double Minus(double a, double b) {
            return a - b;
        }

        public double Mult(double a, double b) {
            return a * b;
        }

        public double Divide(double numerator, double denumerator) {
            return numerator / denumerator;
        }

        public double Sqrt(double a) {
            return Math.Sqrt(a);
        }

        public double Mod(double a, double b) {
            return a % b;
        }

        public double Pow(double a, double power) {
            return Math.Pow(a, power);
        }
    }
}
