#include <iostream>
#include <string>
#include <cpr/cpr.h>



int main() {
    cpr::Response response = cpr::Get(cpr::Url("https://httpbin.org/get"));
    std::cout << response.text << std::endl;

    std::cout << "Enter something to continue: ";
    std::string temp;
    std::cin >> temp;

    return 0;
}