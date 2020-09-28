#include "graph.h"

Graph::Graph(int size){
    graph_size = size;
    std::vector<int> subvec;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            subvec.push_back(0);
        graph.push_back(subvec);
        subvec.clear();
    }
}
