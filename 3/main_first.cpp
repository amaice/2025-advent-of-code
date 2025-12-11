#include <fstream>
#include <iostream>

int largest_joltage(const std::string&);
int choi(char);

int main() {
    const std::string filePath = "input";
    std::ifstream inputFile(filePath);

    std::string line;
    int max_joltage = 0;
    while (getline(inputFile, line)) {
        //std::cout << line << " " << largest_joltage(line) << std::endl;
        max_joltage += largest_joltage(line);
    }
    std::cout << "Largest joltage: " << max_joltage << std::endl;
    return 0;
}

int largest_joltage(const std::string& bank) {
    int battery_one_index = 0;

    for (int i = 0; i < bank.length() - 1; i++) {
        if (choi(bank[i]) > choi(bank[battery_one_index])) {
            battery_one_index = i;
        }
    }

    int battery_two_index = battery_one_index + 1;
    for (int i = battery_two_index; i < bank.length(); i++) {
        if (choi(bank[i]) > choi(bank[battery_two_index])) {
            battery_two_index = i;
        }
    }

    return choi(bank[battery_one_index]) * 10 + choi(bank[battery_two_index]);
}

// Char to int (ex. '1' -> 1)
int choi(const char c) {
    return c - '0';
}