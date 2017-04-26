using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace neural2
{
    class Program
    {
        struct neuron
        {
            float value;
        }
        struct synapse
        {
            neuron start;
            neuron end;
            float weight;
        }
        struct layer
        {
            List<synapse> layersynapsies;
        }
       static float resultfromdata(List<float> input)
        {
            int count = 0;
            foreach (float x in input) {
                if (x == 1)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                return 1f;
            }
            else
            {
                return 0f;
            }
        }
        static void Main(string[] args)
        {
        }
    }
}
