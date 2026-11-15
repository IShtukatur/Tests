#pragma once

#include <string>
#include <cpr/cpr.h>



namespace shtr {
    std::string inputWord(const std::string& outputText);

    cpr::Parameters toParameters(const std::vector<cpr::Pair>& arguments);
}