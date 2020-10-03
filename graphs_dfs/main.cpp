#include <iostream> 
#include <vector>

#include "graph.h"

void init(std::vector<std::vector<int>> &graph, const int& graph_size);

int main() 
{ 
    // int graph_size = 0;
    // std::cout << "Enter graph size: ";
    // std::cin >> graph_size;

    Graph graph(10); 

    std::vector<std::vector<int>> adj_matrix = {{0,1,1,0,0,0,0,0,0,0}, //1
                                                {1,0,1,1,1,0,0,0,0,0}, //2
                                                {1,1,0,0,1,1,0,0,0,0}, //3
                                                {0,1,0,0,1,0,1,1,0,0}, //4
                                                {0,1,1,1,0,1,0,1,1,0}, //5
                                                {0,0,1,0,1,0,0,0,1,1}, //6
                                                {0,0,0,1,0,0,0,1,0,0}, //7
                                                {0,0,0,1,1,0,1,0,1,0}, //8
                                                {0,0,0,0,1,1,0,1,0,1}, //9
                                                {0,0,0,0,0,1,0,0,1,0}}; //10
    
//    init(adj_matrix,graph_size); 

        std::vector<std::vector<int>> adj_matrix1 = {{0,0,1,0,0,0,0,0,0,0}, //1
                                                    {1,0,0,0,0,0,0,0,0,0}, //2
                                                    {0,1,0,0,0,0,0,0,0,0}, //3
                                                    {0,1,0,0,1,0,0,1,0,0}, //4
                                                    {0,1,1,0,0,1,0,1,1,0}, //5
                                                    {0,0,1,0,0,0,0,0,1,0}, //6
                                                    {0,0,0,1,0,0,0,0,0,0}, //7
                                                    {0,0,0,0,0,0,1,0,1,0}, //8
                                                    {0,0,0,0,0,0,0,0,0,1}, //9
                                                    {0,0,0,0,0,1,0,0,0,0}}; //10


    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(adj_matrix1[i][j] != 0)
                graph.addEdge(i,j);

    int start,end;
    std::cout << "Enter start and end vertex: ";
    std::cin >> start >> end;

    //std::cout << "Following are all different paths from " << start << " to " << end << std::endl;
    //std::cout << std::endl; 
    graph.printAllPaths(--start, --end); 
  
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
