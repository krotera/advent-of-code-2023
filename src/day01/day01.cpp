#include "day01.hpp"

#include <cctype>

#include <fstream>
#include <iostream>
#include <assert.h>
#include <vector>
#include <numeric>

void day01(std::string const& input)
{
    std::ifstream ifs {input, std::ifstream::in};

    assert(ifs.good());
    if (!ifs.good())
    {
        std::cerr << "ERROR: Unable to read " << input << std::endl;

        return;
    }

    /*
     * ```
     * On each line, the calibration value can be found by combining the first
     * digit and the last digit (in that order) to form a single two-digit
     * number.
     *
     * For example:
     *
     *     1abc2
     *     pqr3stu8vwx
     *     a1b2c3d4e5f
     *     treb7uchet
     *
     * In this example, the calibration values of these four lines are `12`,
     * `38`, `15`, and `77`. Adding these together produces `142`.
     * ```
     *
     * Considering the input as a long sequence of characters, we can have a
     * simple state machine that:
     *
     *     1. Records the first numeric character encountered
     *     2. Records each subsequent numeric character (if any), appending it
     *        to the first and having it overwrite itself continuously
     *     3. When encountering a '\n', parses the stored digit(s) and stores
     *        them as a calibration value
     *
     * At the end, we sum up all the calibration values for the answer.
     */
    std::vector<int> values;
    std::string curr_value(2, '\0');
    char c = '\0';

    while (ifs.get(c))
    {
        if (std::isdigit(c))
        {
            // Record the digit to the proper value.
            if (!curr_value[0])
            {
                curr_value[0] = c;
            }
            else
            {
                curr_value[1] = c;
            }
        }
        else if (c == '\n')
        {
            // Parse recorded digit(s) and store them as a calibration value.
            if (curr_value[0])
            {
                if (!curr_value[1])
                {
                    // If the current line only had one digit, repeat it.
                    curr_value[1] = curr_value[0];
                }

                values.push_back(std::stoi(curr_value));
            }
            // When the current line had no digits, there's nothing to do.

            // Reset before the next line after the '\n'.
            curr_value[0] = '\0';
            curr_value[1] = '\0';
            c = '\0';
        }
    }

    ifs.close();

    // Report the sum of the calibration values.
    size_t sum = 0;

    std::cout <<
        std::accumulate(values.begin(),
                        values.end(),
                        sum) <<
        std::endl;
}
