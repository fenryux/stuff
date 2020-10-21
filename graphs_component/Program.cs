using System;
using Graphs;

namespace component
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of vertexes: ");
            Graph graph = new Graph(Convert.ToInt32(Console.ReadLine()));
            Console.WriteLine("Enter adjacency matrix:");
            graph.init();
            graph.FindComps();
            Console.ReadLine();
        }
    }
}
