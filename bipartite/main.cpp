#include "bipartite.h"
#include "cli.h"
#include <iostream>
#include <string>


void print_help() {
    std::cout << "Usage:\n"
        << "  -i <input_file> : Input file with graph edges.\n"
        << "  -o <output_file> : Output file for results.\n"
        << std::endl;
}


bool parse_arguments(int argc, char* argv[], CLI& cli) {
    cli.input_file, cli.output_file;

    bool help_requested = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            help_requested = true;
            break;
        }
        else if ((arg == "-i" || arg == "--input") && i + 1 < argc) {
            cli.input_file = argv[++i];
        }
        else if ((arg == "-o" || arg == "--output") && i + 1 < argc) {
            cli.output_file = argv[++i];
        }
        else {
            std::cerr << "Invalid argument: " << arg << "\n";
            help_requested = true;
            break;
        }
    }
    return help_requested;
}

int main(int argc, char* argv[]) {
    CLI cli;
    cli.input_file, cli.output_file;

    bool help = parse_arguments(argc, argv, cli);

    if (help) {
        print_help();
        return 0;
    }

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            cli.input_file = argv[++i];
        }
        else if (arg == "-o" && i + 1 < argc) {
            cli.output_file = argv[++i];
        }
    }

    // Prompt user for input interactively if not provided
    if (cli.input_file.empty()) {
        std::cout << "Enter the input file with graph edges: ";
        std::getline(std::cin, cli.input_file);
    }

    if (cli.output_file.empty()) {
        std::cout << "Enter the output file for results: ";
        std::getline(std::cin, cli.output_file);
    }

    try {
        // Parse the graph, check bipartiteness, and write results
        auto graph = parse_graph(cli.input_file);
        auto result = is_bipartite(graph);
        write_output(cli.output_file, result);
        std::cout << "Results written to " << cli.output_file << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        print_help();
        return 1;
    }

    return 0;
}
