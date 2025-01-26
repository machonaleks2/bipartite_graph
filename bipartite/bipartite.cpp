#include "bipartite.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <stdexcept>

void Graph::parse_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int u, v;
        if (!(iss >> u >> v)) {
            continue; // Ignoruj nieprawidłowe linie
        }
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u); // Graf nieskierowany
    }

    file.close();
}



void BipartiteCheck::check_bipartiteness(const Graph& graph) {
    std::map<int, int> colors; // -1: nieodwiedzony, 0: kolor1, 1: kolor2
    for (const auto& node : graph.adjacency_list) {
        colors[node.first] = -1;
    }

    std::queue<int> queue;
    is_bipartite = true;

    for (const auto& node : graph.adjacency_list) {
        if (colors[node.first] != -1) {
            continue; // Wierzchołek już odwiedzony
        }

        queue.push(node.first);
        colors[node.first] = 0;
        group1.push_back(node.first);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (int neighbor : graph.adjacency_list.at(current)) {
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[current];
                    if (colors[neighbor] == 0) {
                        group1.push_back(neighbor);
                    }
                    else {
                        group2.push_back(neighbor);
                    }
                    queue.push(neighbor);
                }
                else if (colors[neighbor] == colors[current]) {
                    is_bipartite = false;
                    return;
                }
            }
        }
    }
}

void BipartiteCheck::write_results_to_file(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    if (is_bipartite) {
        file << "The graph is bipartite.\nGroup 1: ";
        for (int node : group1) {
            file << node << " ";
        }
        file << "\nGroup 2: ";
        for (int node : group2) {
            file << node << " ";
        }
        file << "\n";
    }
    else {
        file << "The graph is not bipartite.\n";
    }

    file.close();
}
