#include <iostream>
#include <map>
#include <utility>

double weighted_value(const std::pair<std::string, double>& a, 
    const std::pair<std::string, double>& b) {
    return a.second*b.second;
}


int main() {
    std::map<std::string, double> dow_price = {
        {"MMM", 81.86}, {"AA", 34.69}, {"MO", 54.59}
    };

    std::map<std::string, double> dow_weight = {
        {"MMM", 5.8543}, {"AA", 7.235}, {"MO", 4.593}
    };

    std::map<std::string, std::string> dow_name = {
        {"MMM", "3M Co."}, {"AA", "Alcoa Inc."}, {"MO", "Altria Group Inc."}
    };

    for (const auto& name : dow_name) {
        const auto& p1 = dow_price.find(name.first);
        const auto& p2 = dow_weight.find(name.first);
        std::cout << name.second;
        std::cout << "weighted value: " << weighted_value(*p1, *p2) << std::endl;
    }

    // finding example
    if (dow_price.find("MMM") != dow_price.end())
        std::cout << "MMM founded!\n";

    // now moving through array
    for (const auto& dow_pr : dow_price) {
        std::string full_name = dow_name[dow_pr.first];
        std::cout << "Company: " << full_name << "\tPrice: " << dow_pr.second << "\n";
    }

    return 0;
}