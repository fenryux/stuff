#pragma once

#include <vector>

class Graph{
private:
    std::vector<std::vector<int>> graph;
    int graph_size;
public:
    Graph(int size);
};