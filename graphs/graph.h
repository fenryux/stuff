#pragma once

#include <vector>

class Graph{
private:
    std::vector<std::vector<int>> graph;
    int graph_size;
public:
    Graph(int size); // инициализация графа
    void initialize();
    void DFS(int v, int from);
    void dijkstras(int* distance, bool* vertex, int start); // для поиска кратчайшего пути ко всем вершинам
};