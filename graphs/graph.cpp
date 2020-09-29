#include "graph.h"
#include <iostream>
#define MAX 10000

Graph::Graph(int size){
    graph_size = size;
    std::vector<int> subvec;
    for(int i = 0;i < graph_size; i++){
        for(int j = 0;j < graph_size; j++)
            subvec.push_back(0);
        graph.push_back(subvec);
        subvec.clear();
    }
}
void Graph::dijkstras(int* distance, bool* vertex, int start){

    distance[start-1] = 0;

    int min_index;
    int local_min;

    for(int i=0;i<graph.size();i++){
        if(i!=start-1)
            distance[i] = MAX;
        vertex[i] = false;
    }

    do {
        min_index = MAX;
        local_min = MAX;

        for(int i = 0; i < graph.size(); i++)
            if(!vertex[i] && (distance[i] < local_min )){
                local_min = distance[i];
                min_index = i;
            }

        if(min_index != MAX){
            for(int i = 0; i < graph.size(); i++){
                if(graph[min_index][i] > 0){
                    if((local_min + graph[min_index][i]) < distance[i])
                        distance[i] = local_min + graph[min_index][i];
                }
            }
            vertex[min_index] = true;
        }
    } while(min_index < MAX);
}

void Graph::initialize(){
    std::cout << "Please, enter graph matrix: \n";
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            std::cin >> graph[i][j];
        }
    }

    std::cout << std::endl;
    for(int i=0;i<graph_size;i++) {
        for (int j = 0; j < graph_size; j++)
            std::cout << graph[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}