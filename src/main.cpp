#include <cstdlib>

#include <filesystem>
#include <iostream>
#include <string>

#include "day01.hpp"

/**
 * @brief Prints the usage of this puzzle solving suite
 */
static void print_usage(char const* exe_name)
{
    std::cout << "Usage: " << exe_name << " <puzzle_input_dir>" << std::endl;
}

/**
 * @brief Checks whether the command-line input is what we expect
 * @param argc This should be `2`, since we expect a path to the puzzle inputs
 * @param agrv The second member of this array should be a path to the inputs
 */
static bool good_input(int const argc, char const* const* argv)
{
    if (argc != 2)
    {
        return false;
    }

    char const* input_path = argv[1];

    if (!std::filesystem::is_directory(std::filesystem::status(input_path)))
    {
        std::cout <<
            "`" <<
            input_path <<
            "` is not a valid directory!" <<
            std::endl;

        return false;
    }

    return true;
}

int main(int argc, char** argv)
{
    if (!good_input(argc, argv))
    {
        print_usage(argv[0]);

        return EXIT_FAILURE;
    }

    std::string const input_path {argv[1]};

    day01(input_path + "/day01.txt");

    return EXIT_SUCCESS;
}
