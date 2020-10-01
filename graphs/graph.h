#pragma once

#include <vector>

class Graph{
private:
    std::vector<std::vector<int>> graph;
    int graph_size;
    int max_path_to;
    int min_path_to;
    bool* vertex;
public:
    Graph(int size); // инициализация графа
    void initialize(); // заполнение графа матрицой смежности
    void find_max(int start, int end); // поиск в глубину длиннейшего пути
    void find_min(int start, int end); // для поиска кратчайшего пути ко всем вершинам
    void print_minmax_path();
};