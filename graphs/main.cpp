#include <iostream>
#include <vector>
#define MAX 10000

void initialize(std::vector<std::vector<int>> &vec, int n);
void dijkstras(const std::vector<std::vector<int>> &graph, int* distance, bool* vertex, int start);

int main(){

    int vertex_n;
    int temp;
    bool graph_type = false;
    std::vector<std::vector<int>> graph;

    std::cout << "Enter N: ";
    std::cin >> vertex_n;

    bool* vertex = new bool[vertex_n];
    *vertex = {false};
    int* distance = new int[vertex_n];
    for(int i = 0; i < vertex_n; i++)
        distance[i] = MAX;

    initialize(graph,vertex_n);

    std::cout << "Enter graph type (1 - oriented, 0 - unoriented): ";
    std::cin >> graph_type;

    if(!graph_type) {
        for (int i = 0; i < vertex_n; i++) {
            graph[i][i] = 0;
            for (int j = i + 1; j < vertex_n; j++) {
                printf("Enter %d - %d:", i + 1, j + 1);
                std::cin >> temp;
                graph[i][j] = temp;
                graph[j][i] = temp;
            }
        }
    }else{
        for (int i = 0; i < vertex_n; i++) {
            graph[i][i] = 0;
            for (int j = 0; j < vertex_n; j++) {
                if(i == j){ // без петель
                    graph[i][i] = 0;
                    continue;
                }
                printf("Enter %d - %d:", i + 1, j + 1);
                std::cin >> graph[i][j];
            }
        }
    }

    std::cout << std::endl;
    for(int i=0;i<vertex_n;i++) {
        for (int j = 0; j < vertex_n; j++)
            std::cout << graph[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Enter start vertex: ";
    std::cin >> temp;

    dijkstras(graph,distance,vertex,temp);
    for(int i = 0; i<vertex_n;i++) {
        if(distance[i] == MAX || distance[i] == 0)
            std:: cout << i + 1 << " - " << "no path available" << std::endl;
        else
            std:: cout << i + 1 << " - " << distance[i] << std::endl;
    }

    delete [] vertex;
    delete [] distance;
    graph.clear();

    return 0;
    }

void initialize(std::vector<std::vector<int>> &vec, int n){
    std::vector<int> subvec;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            subvec.push_back(0);
        vec.push_back(subvec);
        subvec.clear();
    }
}

void dijkstras(const std::vector<std::vector<int>> &graph, int* distance, bool* vertex, int start){
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