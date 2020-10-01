#include <iostream>
#include "graph.h"

int main(){
    int graph_size;

    std::cout << "Enter graph size: ";
    std::cin >> graph_size;

    Graph graph(graph_size);

    int start,end; // начальная и конечная вершины

    graph.initialize(); // заполнение матрицы смежности графа

    std::cout << "Enter start and end vertex: ";
    std::cin >> start >> end;

    graph.find_max(start-1,end-1);
    graph.find_min(start,end);

    graph.print_minmax_path();

    return 0;
}