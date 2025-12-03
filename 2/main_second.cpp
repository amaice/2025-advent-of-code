#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

void invalid_ids(std::string, std::vector<long long>&);
bool id_invalid(long long);

int main(){
    std::vector<long long> list;
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

    // Sum each invalid number
    long long a = 0;
    for (const auto& s : list) {
        a += s;
    }
    std::cout << "Soum: " << a << std::endl;
    return 0;
}

// Returns sum of all invalid IDs
// An invalid id in an integer that is a set of numbers written any number of times (ie 11, 1010, 101010)
// Input: range is a string with the format "A-B" where A and B are integers
void invalid_ids(std::string range, std::vector<long long>& list) {
    const size_t dash_index = range.find('-');
    const long long min = std::stoll(range.substr(0, dash_index));
    const long long max = std::stoll(range.substr(dash_index + 1));

    // Check all integers in range for validity
    for(long long i = min; i <= max; i++) {
        if(id_invalid(i)) {
            list.push_back(i);
        }
    }
}

// Returns true if ID is invalid (somewhat backwards, I know)
bool id_invalid(long long id) {
    const std::string s = std::to_string(id);
    const int length = s.length();

    // split number into sections, first 123123 -> 1 2 3 1 2 3, then 12 31 23, last 123 123
    for (long long i = 1; i <= length / 2; i++) {
        bool idInvalid = true;
        std::string prev_section = s.substr(0, i);
        for (int j = i; j < length; j += i) {
            std::string curr_section = s.substr(j, i);
            if(prev_section != curr_section) {
                idInvalid = false;
                break;
            }
        }
        // if it looped through the number and each section was equal -> invalid
        if(idInvalid) {
            return true;
        }
    }
    return false;
}
