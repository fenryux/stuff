#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

int cycles = 0;
bool* visited;

Graph::Graph(int size)
{ 
    this->size = size;
    std::vector<int> subvec;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            subvec.push_back(0);
        graph.push_back(subvec);
        subvec.clear();
    }
    visited = new bool[size];
    for(int i=0; i<size;i++)
        visited[i] = false;
}
void Graph::find_simple_cycles() {
    for(int i=0;i<size;i++) {
        for(int j=0; j<size;j++)
            visited[i] = false;
        DFS_cycles(i);
    }
    cout << cycles << endl;
}
void Graph::DFS_cycles(int it) {
    if(!visited[it]) {
        visited[it] = true;
        for(int i=0;i<graph[it].size();i++)
            if(!visited[i] && graph[it][i] != 0)
                DFS_cycles(i);
        visited[it] = false;
    }
    else{
        cycles++;
        visited[it] = false;
        return;
    }
}
void Graph::init() {
    cout << "Enter adjacency matrix: " << endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++) {
            cin >> graph[i][j];
        }
    }
    for(int i=0;i<size;i++) {
        for (auto j:graph[i])
            cout << graph[i][j] << " ";
        cout << endl;
    }
}


