#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

long long largest_joltage(const std::string&);
int choi(char);
const int NUM_BATTERIES = 12;

int main() {
    const std::string filePath = "input_small";
    std::ifstream inputFile(filePath);

    std::string line;
    long long max_joltage = 0;
    while (getline(inputFile, line)) {
        //std::cout << line << " " << largest_joltage(line) << std::endl;
        max_joltage += largest_joltage(line);
    }
    // 3121910778619
    // 3105219158839
    std::cout << "Largest joltage: " << max_joltage << std::endl;
    return 0;
}

long long largest_joltage(const std::string& bank) {
    int batteries[NUM_BATTERIES] = {};
    batteries[0] = 0;
    // I hate having to include this edge case
     for (int battery = 0; battery < NUM_BATTERIES; battery++) {
        if (batteries[battery] == 0 && battery != 0) {
            batteries[battery] = batteries[battery - 1] + 1;
        }
        for (int i = batteries[battery]; i < bank.length() - NUM_BATTERIES + battery + 1; i++) {
            int a = bank.length() - NUM_BATTERIES + battery + 1;
            // std::string look = "                   ";
            // look[batteries[battery]] = '*';
            // look[i] = '*';
            // std::cout << look << std::endl;
            // std::cout << bank << std::endl << std::endl;

             if (choi(bank[i]) > choi(bank[battery])) {
                // std::cout << bank[i] << " > " << bank[battery] << std::endl;
                batteries[battery] = i;
                batteries[battery + 1] = i + 1;
            }
        }
    }

    // sum array together (ex. [1, 2, 3] -> 123
    long long joltage = 0;
    for (int battery = 0; battery < NUM_BATTERIES; battery++) {
        joltage += choi(bank[batteries[battery]]) * (long long)std::pow(10, NUM_BATTERIES - battery - 1);
    }
    std::cout << joltage << std::endl;
    return joltage;
}

// Char to int (ex. '1' -> 1)
int choi(const char c) {
    return c - '0';
}