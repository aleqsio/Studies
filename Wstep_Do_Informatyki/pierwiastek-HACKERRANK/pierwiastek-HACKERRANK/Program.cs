using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace pierwiastek_HACKERRANK
{
    class Program
    {
        static double[] coeff = new double[10];
       static double breakpt;
        static double p, q;
        static void Main(string[] args)
        {
            string t = Console.ReadLine();
            p = Convert.ToDouble(t.Split(' ')[0]);
            q = Convert.ToDouble(t.Split(' ')[1]);
            breakpt = 1 / Math.Pow(10, 7);
            t = Console.ReadLine();

            for (int i = 0; i < 10; i++)
            {
                coeff[i] = Convert.ToDouble(t.Split(' ')[i]);
            }
            divide(p, q);
        }
    
static void divide(double p, double q)
    {
        double middle = p / 2 + q / 2;
        if (value(p) == 0)
        {
                Console.Write(p);
            return;
        }
        if (value(q) == 0)
        {
                Console.Write(q);
                return;
        }
        if (value(middle) == 0)
        {
                Console.Write(middle);
                return;
        }
        if (Math.Sign(value(middle - breakpt/2))!=Math.Sign(value(middle))|| Math.Sign(value(middle + breakpt/2)) != Math.Sign(value(middle)))
        {
                Console.Write(middle);
                return;
        }
        if (Math.Sign(value(middle))!=Math.Sign(value(p)))
            divide(p, middle);
        else
            divide(middle, q);
    }
  static  double value(double x)
    {
        return coeff[0] * Math.Sin(coeff[1] * x + coeff[2]) + coeff[3] * Math.Pow(Math.E, coeff[4] * x + coeff[5]) + coeff[6] * Math.Abs(coeff[7] * x + coeff[8]) + coeff[9];
    }
    }
    }
