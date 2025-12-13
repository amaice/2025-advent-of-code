#include <fstream>
#include <iostream>
#include <vector>

bool in_range(long long id, long long min, long long max);

// --- Day 5: Cafeteria ---
int main() {
    const std::string filePath = "input";
    std::ifstream inputFile(filePath);

    std::vector <std::vector<long long>> fresh_ranges;
    std::string line;
    bool reached_end_of_ranges = false;
    while (getline(inputFile, line)) {
        if (!reached_end_of_ranges) {
            if (line.empty()) {
                reached_end_of_ranges = true;
            } else {
                long long min = std::stoll(line.substr(0, line.find('-')));
                long long max = std::stoll(line.substr( line.find('-') + 1));
                fresh_ranges.push_back({min, max});
            }
        }
    }

    std::vector <std::vector<long long>> all_ranges;
    for (const auto& fresh_range : fresh_ranges) {
        if (all_ranges.empty()) {
            all_ranges.push_back(fresh_range);
        } else {
            for (const auto& range : all_ranges) {
                fresh_range = {fresh_range[0], fresh_range[1]};
            }
        }

    }

    std::cout << "num_fresh_IDs: " << std::endl;
    return 0;
}

bool in_range(const long long id, const long long min, const long long max) {
    return id >= min && id <= max;
}
