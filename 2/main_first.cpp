#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

void invalid_ids(std::string, std::vector<unsigned long long>&);

int main(){
    std::vector<unsigned long long> list;

    const std::string filePath = "input";
    std::ifstream inputFile(filePath);

    // Split input file (which is delimited by commas) into vector of strings
    std::vector<std::string> result;
    std::string line;
    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        while (ss.good()) {
            std::string substr;
            getline( ss, substr, ',' );
            result.push_back( substr );
        }
    }

    // Loop through vector
    for (const auto& s : result) {
        invalid_ids(s, list);
    }
    inputFile.close();

    unsigned long long a = 0;
    for (const auto& s : list) {
        a += s;
    }
    std::cout << "Sum: " << a << std::endl;
    return 0;
}

// Returns sum of all invalid IDs
// An invalid id in an integer that is a set of numbers written twice (ie 11, 1010, 126126)
// Input: range is a string with the format "A-B" where A and B are integers
void invalid_ids(std::string range, std::vector<unsigned long long>& list) {
    const size_t dash_index = range.find('-');
    const long long min = std::stoll(range.substr(0, dash_index));
    const unsigned long long max = std::stoll(range.substr(dash_index + 1));

    // Check all integers in range for validity
    for(unsigned long long i = min; i <= max; i++) {
        const std::string s = std::to_string(i);
        const int length = s.length();
        // An integer with an odd number of digits cannot be invalid
        if (length % 2 != 0) {
            continue;
        }
        std::string first_half = s.substr(0, length / 2);
        std::string second_half = s.substr(length / 2);
        if(first_half == second_half) {
            list.push_back(i);
        }
    }
}
