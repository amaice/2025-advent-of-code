#include <fstream>
#include <iostream>

int largest_joltage(const std::string&);

int main() {
    const std::string filePath = "input";
    std::ifstream inputFile(filePath);

    std::string line;
    int max_joltage = 0;
    while (getline(inputFile, line)) {
        max_joltage += largest_joltage(line);
    }
    std::cout << "Largest joltage: " << largest_joltage;
    return 0;
}

int largest_joltage(const std::string& bank) {
    int battery_one_index = bank[0] - '0';
    int battery_two_index = bank[1] - '0';
    for (int i = 0; i < bank.length(); i++) {
        if ((bank[i] - '0') > bank[battery_one_index]) {
            battery_one_index = i;
        }
    }

    for (int i = 0; i < bank.length(); i++) {
        
    }

    return 0;
}
