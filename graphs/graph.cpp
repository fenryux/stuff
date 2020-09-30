#include "graph.h"
#include <iostream>
#include <string>

#define MAX 10000

Graph::Graph(int size){
    graph_size = size;
    
    max_path_to = 0;
    min_path_to = MAX;

    std::vector<int> subvec;
    for(int i = 0;i < graph_size; i++){
        for(int j = 0;j < graph_size; j++)
            subvec.push_back(0);
        graph.push_back(subvec);
        subvec.clear();
    }
}

void Graph::find_max(int start, int end){
    static short Fmax = 0;
    static std::string Last;
    short v3 = 0;
    if(start == end){
        if(Fmax > max_path_to)
            max_path_to = Fmax;
    } else{
        for(short i = 0; i < graph.size(); i++) {
           if(((start-1)*graph.size())+i != ((start-1)*graph.size())+(end-1)){
               if(graph[start-1][i] == 1 && Last.find(i+1) == -1 ){
                   Fmax++;
                   v3 = i+1;
                   Last += start;
                   find_max(i++,end);
                   Fmax--;
                   Last.pop_back();
               }
           }

        }
        Fmax++;
        find_max(end,end);
        Fmax--;
    }
}

void Graph::find_min(int start, int end){
    if(start == end){
        min_path_to = 0;
        return;
    }

    int distance[graph.size()];
    bool vertex[graph.size()];

    for(int i = 0; i < graph.size(); i++){
        distance[i] = MAX;
        vertex[i] = false;
    }
    distance[start-1] = 0;

    int min_index;
    int local_min;

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
    min_path_to = distance[end-1];
}

void Graph::initialize(){
    std::cout << "Please, enter graph matrix: \n";
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            std::cin >> graph[i][j];
        }
    }

    // std::cout << std::endl;
    // for(int i=0;i<graph_size;i++) {
    //     for (int j = 0; j < graph_size; j++)
    //         std::cout << graph[i][j] << ' ';
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}

void Graph::print_minmax_path(){
    std::cout << "Max path: " << max_path_to << std::endl;
    std::cout << "Min path: " << min_path_to << std::endl;
}