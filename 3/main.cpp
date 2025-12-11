#include <fstream>
#include <iostream>

int largest_joltage(const std::string&);
int choi(char);

int main() {
    const std::string filePath = "input_small";
    std::ifstream inputFile(filePath);

    std::string line;
    int max_joltage = 0;
    while (getline(inputFile, line)) {
        max_joltage += largest_joltage(line);
    }
    std::cout << "Largest joltage: " << max_joltage << std::endl;
    return 0;
}

int largest_joltage(const std::string& bank) {
    int battery_one_index = choi(bank[0]);
    int battery_two_index = choi(bank[1]);
    for (int i = 0; i < bank.length() - 1; i++) {
        if (choi(bank[i]) > bank[battery_one_index]) {
            battery_one_index = i;
        }
    }

    for (int i = battery_one_index + 1; i < bank.length(); i++) {
        if (choi(bank[i]) > bank[battery_two_index]) {
            battery_two_index = i;
        }
    }

    return choi(bank[battery_one_index]) * 10 + choi(bank[battery_two_index]);
}

int choi(const char c) {
    return c - '0';
}