#include "bipartite.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <stdexcept>
#include <iostream>

std::map<int, std::vector<int>> parse_graph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::map<int, std::vector<int>> graph;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int u, v;
        if (!(iss >> u >> v)) {
            continue; // Ignore malformed lines or extra whitespace
        }
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    file.close();
    return graph;
}

std::pair<bool, std::pair<std::vector<int>, std::vector<int>>> is_bipartite(const std::map<int, std::vector<int>>& graph) {
    std::map<int, int> colors; // -1: unvisited, 0: color1, 1: color2
    for (const auto& node : graph) {
        colors[node.first] = -1;
    }

    std::vector<int> group1, group2;
    std::queue<int> queue;

    for (const auto& node : graph) {
        if (colors[node.first] != -1) {
            continue; // Node already visited
        }

        // Start BFS for this connected component
        queue.push(node.first);
        colors[node.first] = 0;
        group1.push_back(node.first);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (int neighbor : graph.at(current)) {
                if (colors[neighbor] == -1) {
                    // Assign opposite color to the neighbor
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
                    // Conflict detected, graph is not bipartite
                    return { false, {{}, {}} };
                }
            }
        }
    }

    return { true, {group1, group2} };
}

void write_output(const std::string& filename, const std::pair<bool, std::pair<std::vector<int>, std::vector<int>>>& result) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    if (result.first) {
        file << "The graph is bipartite.\nGroup 1: ";
        for (int node : result.second.first) {
            file << node << " ";
        }
        file << "\nGroup 2: ";
        for (int node : result.second.second) {
            file << node << " ";
        }
        file << "\n";
    }
    else {
        file << "The graph is not bipartite.\n";
    }

    file.close();
}
