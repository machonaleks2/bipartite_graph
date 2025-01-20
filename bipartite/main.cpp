#include "bipartite.h"
#include <iostream>
#include <string>

void display_help() {
    std::cout << "Usage:\n"
        << "  -i <input_file> : Input file with graph edges.\n"
        << "  -o <output_file> : Output file for results.\n";
 
}

int main(int argc, char* argv[]) {
    std::string input_file, output_file;

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            input_file = argv[++i];
        }
        else if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        }
        else {
            std::cerr << "Invalid argument: " << arg << "\n";
            display_help();
            return 1;
        }
    }

    // Prompt user for input interactively if not provided
    if (input_file.empty()) {
        std::cout << "Enter the input file with graph edges: ";
        std::getline(std::cin, input_file);
    }

    if (output_file.empty()) {
        std::cout << "Enter the output file for results: ";
        std::getline(std::cin, output_file);
    }

    try {
        // Parse the graph, check bipartiteness, and write results
        auto graph = parse_graph(input_file);
        auto result = is_bipartite(graph);
        write_output(output_file, result);
        std::cout << "Results written to " << output_file << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        display_help();
        return 1;
    }

    return 0;
}
