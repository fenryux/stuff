#include <iostream>
#include <vector>

void InputAdjMatrix(std::vector<std::vector<int>>& graph, const int& graph_size) {
    std::vector<int> subgraph;
    for (int i = 0; i < graph_size; i++) {
        for (int j = 0; j < graph_size; j++)
            subgraph.push_back(0);
        graph.push_back(subgraph);
        subgraph.clear();
    }
    std::cout << "Enter adjacency matrix: \n";
    for (int i = 0; i < graph_size; i++) {
        std::cout << "Row [" << i + 1 << "]: ";
        for (int j = 0; j < graph_size; j++)
            std::cin >> graph[i][j];
    }
}

void DFS(std::vector<std::vector<int>>& adj_graph, int start_node, int node, std::vector<bool> visited, int& count_of_cycles, int& level) {

    if (visited[node]) {
        if (node == start_node && level > 2)
            count_of_cycles++;
        return;
    }
    level++;
    visited[node] = true;
    for (int i = 0; i < adj_graph.size(); i++)
        if (adj_graph[node][i] == 1)
            DFS(adj_graph, start_node, i, visited, count_of_cycles, level);
    visited[node] = false;
    level--;
}


int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Graph size: ";
    int graph_size;
    std::cin >> graph_size;
    //graph_size--;
    if (graph_size < 0) return 0;
    ///
    std::vector<std::vector<int>> adj_matrix;
    InputAdjMatrix(adj_matrix, graph_size);
    int count_of_cycles = 0;
    std::vector<bool> visited;
    visited.reserve(graph_size);
    for (int i = 0; i < graph_size; i++)
        visited.push_back(false);
    int level = 0;
    for (int counter = 0; counter < graph_size; counter++) {
        DFS(adj_matrix, counter, counter, visited, count_of_cycles, level);
        visited[counter] = true;
    }
    bool is_oriented = true;
    for (int i = 0; i < graph_size; i++) {
        for (int j = 0; j < graph_size; j++) {
            if (adj_matrix[i][j] != 0)
                if (adj_matrix[i][j] == adj_matrix[j][i])
                    is_oriented = false;
        }
    }
    if (!is_oriented)
        count_of_cycles /= 2;
    ///
    //int count_of_cycles = find_cycles(graph_size);
    std::cout << "\n\nCycles: " << count_of_cycles<< std::endl;
    system("pause");
    return 0;
}