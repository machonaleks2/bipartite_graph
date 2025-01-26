#pragma once

#include <map>
#include <vector>
#include <string>

/**
 * @brief Struktura Graph reprezentująca graf za pomocą listy sąsiedztwa.
 */
struct Graph {
    std::map<int, std::vector<int>> adjacency_list; ///< Lista sąsiedztwa grafu.

    /**
     * @brief Parsuje graf z pliku.
     *
     * @param filename Ścieżka do pliku wejściowego zawierającego krawędzie grafu.
     * @throws std::runtime_error Jeśli plik nie może zostać otwarty.
     */
    void parse_from_file(const std::string& filename);
};

/**
 * @brief Struktura BipartiteCheck sprawdzająca dwudzielność grafu.
 */
struct BipartiteCheck {
    std::vector<int> group1; ///< Wierzchołki należące do pierwszej grupy.
    std::vector<int> group2; ///< Wierzchołki należące do drugiej grupy.
    bool is_bipartite; ///< Flaga wskazująca, czy graf jest dwudzielny.

    /**
     * @brief Sprawdza dwudzielność grafu.
     *
     * @param graph Graf reprezentowany za pomocą listy sąsiedztwa.
     */
    void check_bipartiteness(const Graph& graph);

    /**
     * @brief Zapisuje wyniki do pliku.
     *
     * @param filename Ścieżka do pliku wyjściowego.
     * @throws std::runtime_error Jeśli plik nie może zostać otwarty.
     */
    void write_results_to_file(const std::string& filename);
};
