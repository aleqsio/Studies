using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cakecsharp
{
    class Program
    {
       static List<Decimal> listofpieces;
        static void Main(string[] args)
        {
            readpieces();
           Console.WriteLine(countturns());
            Console.ReadKey();
        }
        public static decimal Sqrt(decimal x, decimal? guess = null)
        {
            var ourGuess = guess.GetValueOrDefault(x / 2m);
            var result = x / ourGuess;
            var average = (ourGuess + result) / 2m;

            if (average == ourGuess) // This checks for the maximum precision possible with a decimal.
                return average;
            else
                return Sqrt(x, average);
        }
        static int countturns()
        {
            int steps = 0;
            Decimal precision = 0.00001M;
            int currentpiece = 0;
            Decimal lastposition=0;
            bool turned = false;
            List<marker> positions= new List<marker>();
            for(Decimal i=0;i<360;i+=precision)
            {
                marker m = new marker();
                m.pos = i+precision/2;
                m.color = false;
                positions.Add(m);
            }
            while (true)
            {

                steps++;
                Decimal newposition = lastposition + listofpieces[currentpiece];
                Decimal tmppos = -5;
                Decimal tmppos2 = 505;
                Decimal middle = (newposition / 2 + lastposition / 2)%360;
                Decimal newpos;
                bool foundtrue=false;
                if (newposition>360)
                {
                    tmppos = newposition % 360;
                    tmppos2 = 0;
                }
                    for (int i = 0; i < 360 * precision; i++)
                    {
                        if ((positions[i].pos >= lastposition&& positions[i].pos <= newposition) ||( positions[i].pos>=tmppos2&& positions[i].pos <= tmppos))
                        {
                        newpos = middle - (middle-positions[i].pos);
                        marker cpy = positions[i];
                        cpy.pos = newpos%360;
                        cpy.color = !cpy.color;
                      
                        positions[i] = cpy;
                        }
                    if (positions[i].color)
                    {
                        foundtrue = true;
                    }
                }
                
                currentpiece++;
                lastposition = newposition%360;
                if(currentpiece>2)
                {
                    currentpiece = 0;
                }
                if(!foundtrue)
                {
                    break;
                }
            }
            return steps;
        }

      static  void readpieces()
        { 
            listofpieces = new List<decimal>();
            for (int i = 0; i < 3; i++)
            {
                Decimal p1;
                Decimal.TryParse(Console.ReadLine(), out p1);
                if (i < 2)
                {
                    p1 = 360 / p1;
                } else
                {
                    p1 = 360 / Sqrt(p1);
                }
                
                listofpieces.Add(p1);
            }
            
        }
    }
    struct marker
    {
        public Decimal pos;
        public bool color;
    }
   
}
