using System;
using System.Collections.Generic;

namespace Graphs
{
    class Graph
    {
        private int size;
        private List<int>[] graph;
        private int[,] adj_matrix;
        private bool[] visited;
        private int comp;
        
        public Graph(int size)
        {
            this.size = size;
            graph = new List<int>[size];
            for (int i = 0; i < size; i++)
            {
                graph[i] = new List<int>();
            }
            visited = new bool[size];
            comp = 0;
        }
        public void init()
        {
            int[,] array = new int[size,size];
            for (int i = 0; i < size; i++)
                for(int j=0;j<size;j++)
                {
                    var temp = Console.ReadLine().Split(' ');
                    foreach (var item in temp)
                    {
                        array[i,j] = Convert.ToInt32(item);
                        j++;
                    }
                }
            adj_matrix = array;
            Console.WriteLine();
            for (int i = 0; i < size; i++)
                for(int j=0;j<size;j++)
                    if(array[i,j] != 0)
                    {
                        graph[i].Add(j);
                    }
        }
        public void FindComps()
        {
            for (int i = 0; i < size; i++)
                visited[i] = false;
            for (int i = 0; i < size; i++)
            {
                if(!visited[i])
                {
                    DFS(i);
                    comp++;
                }
            }
            Console.WriteLine("Components = " + comp);
        }
        public void DFS(int current)
        {
            visited[current] = true;
            foreach (int item in graph[current])
                if(!visited[item])
                    DFS(item);
        }
        private bool isOriented()
        {
            int count = 0;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if(adj_matrix[i,j] == adj_matrix[j,i])
                        count++;
            if(count == size*size)
                return false;
            return true;
        }    
    }
}
