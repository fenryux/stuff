#pragma once
#include <list>

class Graph { 
    int V; // Кол-во вершин в графе
    std::list<int>* adj; // Указатель на массив списков с ребрами 
    int max_path; //максимальный путь
    int min_path; //минимальный путь

    // рекурсивная функция для поиска пути
    void printAllPathsUtil(int, int, bool[], int[], int&); 
  
public: 
    Graph(int V);
    void addEdge(int u, int v); 
    void printAllPaths(int s, int d); 
}; 