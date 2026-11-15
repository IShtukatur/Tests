#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include "tools_for_test.hpp"



int main() {
    cpr::Response response;
    std::vector<cpr::Pair> args;

    std::cout << "===============================================\n";

    while (true) {
        std::string firstValue;
        std::string secondValue;

        std::cout << "Enter \"get\" or \"post\" as the first value for the HTTP request.\n";
        firstValue = shtr::inputWord("Enter first value: ");


        if (firstValue == "get") {
            response = cpr::Get(
                cpr::Url("https://httpbin.org/get"),
                shtr::toParameters(args)
            );
            break;
        } else if (firstValue == "post") {
            response = cpr::Post(
                cpr::Url("https://httpbin.org/post"),
                cpr::Payload(args.begin(), args.end())
            );
            break;
        }


        secondValue = shtr::inputWord("Enter second value: ");
        args.emplace_back(firstValue, secondValue);

        std::cout << "-------------------------------------------\n";
    }

    std::cout << "\n***********************************************\n";
    std::cout << response.status_line << "\n";
    for (const auto& pair : response.header) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    std::cout << "\n";
    std::cout << response.text << "\n";
    std::cout << "***********************************************\n";

    std::cout << "===============================================\n";

    return 0;
}