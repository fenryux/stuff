#pragma once
#include <vector>

class Graph { 
    std::vector<std::vector<int>> graph;
    void DFS_cycles(int to);
public:
    int size;
    Graph(int size);
    void addEdge(int u, int v);
    void find_simple_cycles();
    void init();
};