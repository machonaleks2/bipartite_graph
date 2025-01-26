#pragma once

#include <string>

/**
 * @brief Struktura CLI obsługująca argumenty wiersza poleceń.
 *
 * Przechowuje ścieżki do plików wejściowego i wyjściowego oraz zapewnia metody
 * do parsowania argumentów i interaktywnego wprowadzania brakujących danych.
 */
struct CLI {
    std::string input_file; ///< Ścieżka do pliku wejściowego.
    std::string output_file; ///< Ścieżka do pliku wyjściowego.

    /**
     * @brief Parsuje argumenty wiersza poleceń.
     *
     * @param argc Liczba argumentów.
     * @param argv Tablica argumentów.
     */
    void parse_arguments(int argc, char* argv[]);

    /**
     * @brief Interaktywnie wprowadza brakujące dane.
     */
    void prompt_for_missing_inputs();
};