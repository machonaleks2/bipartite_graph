/**
 * @file cli.h
 * @brief Example CLI application with short and long command-line options.
 *
 * This file includes CLI struct that is mean to aggregate all the value parsed by the CLI during runtime.
 */

#pragma once

#include <string>

struct CLI {
	std::string input_file;
	std::string output_file;
};
