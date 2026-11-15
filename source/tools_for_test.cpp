#include "tools_for_test.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cpr/cpr.h>



namespace shtr {
    std::string inputWord(const std::string& outputText) {
        while (true) {
            std::string resultWord;

            std::cout << outputText;
            std::cin >> resultWord;

            if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error! Incorrect input. (inputWord)\n";
                continue;
            }

            return resultWord;
        }
    }

    cpr::Parameters toParameters(const std::vector<cpr::Pair>& arguments) {
        cpr::Parameters resultParameters;

        for (const auto& pair : arguments) {
            resultParameters.Add({pair.key.c_str(), pair.value.c_str()});
        }

        return resultParameters;
    }
}