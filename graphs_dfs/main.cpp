#include <iostream> 
#include <vector>

#include "graph.h"

void init(std::vector<std::vector<int>> &graph, const int& graph_size);

int main() 
{ 
    int graph_size = 0;
    std::cout << "Enter graph size: ";
    std::cin >> graph_size;

    Graph graph(graph_size); 

    std::vector<std::vector<int>> adj_matrix;

    init(adj_matrix,graph_size);

    for(int i=0;i<graph_size;i++)
        for(int j=0;j<graph_size;j++)
            if(adj_matrix[i][j] != 0)
                graph.addEdge(i,j);

    int start,end;
    std::cout << "Enter start and end vertex: ";
    std::cin >> start >> end;
 
    graph.printAllPaths(--start, --end); 
    
    system("pause");
    return 0; 
} 

void init(std::vector<std::vector<int>> &graph, const int& graph_size){
    std::vector<int> subgraph;
    for(int i=0;i<graph_size;i++){
        for(int j=0;j<graph_size;j++)
            subgraph.push_back(0);
        graph.push_back(subgraph);
        subgraph.clear();
    }
    std::cout << "Enter adjacency matrix: \n";
    for(int i=0;i<graph_size;i++)
        for(int j=0;j<graph_size;j++)
            std::cin >> graph[i][j];
}