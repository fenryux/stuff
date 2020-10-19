using System;
using System.Collections.Generic;

namespace Graphs_cycles
{
    class Graph
    {
        private int vertex_n;
        private List<int>[] adjacency;
        private int[,] adj_matrix;
        private bool[] visited;
        private int cycles;
        private int vertex_in_cycle;

        public Graph(int vertex_n)
        {
            this.vertex_n = vertex_n;
            cycles = 0;
            vertex_in_cycle = 0;
            adjacency = new List<int>[vertex_n];
            for (int i = 0; i < vertex_n; i++)
            {
                adjacency[i] = new List<int>();
            }
            visited = new bool[vertex_n];
        }
        public void printCycles()
        {
            for (int i = 0; i < vertex_n; i++)
            {
                DFS(i,i);
                visited[i] = true;
            }
            if(!this.isOriented())
                cycles /= 2;
            Console.WriteLine("Cycles: " + cycles);
        }
        public void init()
        {
            int[,] array = new int[vertex_n,vertex_n];
            for (int i = 0; i < vertex_n; i++)
                for(int j=0;j<vertex_n;j++)
                {
                    var temp = Console.ReadLine().Split(' ');
                    foreach (var item in temp)
                    {
                        array[i,j] = Convert.ToInt32(item);
                        j++;
                    }
                }
            adj_matrix = array;
            //int[,] array = {{0,1,0,0},{0,0,1,1},{1,0,0,0},{0,0,1,0}};
            Console.WriteLine();
            for (int i = 0; i < vertex_n; i++)
                for(int j=0;j<vertex_n;j++)
                    if(array[i,j] != 0)
                    {
                        adjacency[i].Add(j);
                    }
        }
        private void DFS(int current, int start)
        {
            if(visited[current])
            {
                if(current == start && vertex_in_cycle > 2)
                    cycles++;
                return;
            }

            vertex_in_cycle++;
            visited[current] = true;

            foreach (var vertex in adjacency[current])
                DFS(vertex, start);
            
            visited[current] = false;
            vertex_in_cycle--;
        }
        private bool isOriented()
        {
            int count = 0;
            for (int i = 0; i < vertex_n; i++)
                for (int j = 0; j < vertex_n; j++)
                    if(adj_matrix[i,j] == adj_matrix[j,i])
                        count++;
            if(count == vertex_n*vertex_n)
                return false;
            return true;
        }    
    }
}