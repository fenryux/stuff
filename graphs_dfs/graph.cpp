#include "graph.h"

#include <iostream>
using namespace std;
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    max_path = 0;
    min_path = 100000;
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); //добавления ребра между вершинами U и V (!!! ребро направленное !!!)
} 

void Graph::printAllPaths(int s, int d) // вывод всех путей от вершины A до вершины B
{ 
    bool* visited = new bool[V]; // посещенные вершины (по умолчанию - все не посещены)
  
    int* path = new int[V]; //массив для хранения путей
    int path_index = 0; // путь пуст
  
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // DFS для поиска путей 
    printAllPathsUtil(s, d, visited, path, path_index); 
    cout << endl;
    if(max_path == 0 && min_path == 100000)
        cout << "No path exist!" << endl;
    else if(max_path == min_path)
        cout << "Max path = min path: " << --max_path << endl;
    else
        cout << "max: " << --max_path << " min: " << --min_path << endl;
} 
  
//Рекурсивная функция для вывода всех путей от вершины U до вершины D
//visited[] хранит в себе пройденные вершины в текущем пути
//path[] хранит текущий путь, а path_index - текущую в нем вершину
void Graph::printAllPathsUtil(int u, int d, bool visited[], 
                              int path[], int& path_index) 
{ 
    // Пометить текущую вершину и добавить ее в путь
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // Если текущая вершина является конечной вершиной, то вывести путь и выбрать макс./мин. путь
    if (u == d) { 
        for (int i = 0; i < path_index; i++) 
            cout << ++path[i] << " ";
        if(path_index > max_path)
            max_path = path_index;
        if(path_index < min_path)
            min_path = path_index;
        cout << endl; 
    } 
    else // Если текущая вершина не является конечной
    { 
        // Рекурсия по всем вершинам 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, d, visited, path, path_index); 
    } 
  
    // Убрать текущую вершину из посещенных и отчистить путь 
    path_index--; 
    visited[u] = false; 
} 