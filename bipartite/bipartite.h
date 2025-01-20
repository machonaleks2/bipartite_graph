#pragma once


#include <map>
#include <vector>
#include <string>

/**
 * @brief Parses the input file and constructs the graph.
 *
 * @param filename Input file containing graph edges.
 * @return Adjacency list representation of the graph.
 * @throws std::runtime_error if the file cannot be read or is malformed.
 */
std::map<int, std::vector<int>> parse_graph(const std::string& filename);

/**
 * @brief Checks if the given graph is bipartite.
 *
 * @param graph Adjacency list representation of the graph.
 * @return A pair containing a boolean indicating bipartiteness and the two sets of nodes.
 *         If the graph is not bipartite, the sets will be empty.
 */
std::pair<bool, std::pair<std::vector<int>, std::vector<int>>> is_bipartite(const std::map<int, std::vector<int>>& graph);

/**
 * @brief Writes the output to the specified file.
 *
 * @param filename Output file name.
 * @param result Pair containing bipartiteness status and node groups.
 */
void write_output(const std::string& filename, const std::pair<bool, std::pair<std::vector<int>, std::vector<int>>>& result);


