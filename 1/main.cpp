#include <iostream>
#include <fstream>

#include "Safe.h"

int main()
{
    const std::string filePath = "input.txt";
    std::ifstream inputFile(filePath);

    Safe safe = Safe();

    std::string line;
    while (getline(inputFile, line))
    {
        // "L/R" + Int
        const int distance = std::stoi(line.std::string::substr(1, line.size()));

        safe.turn(line[0], distance);
    }
    inputFile.close();

    std::cout << safe.password() << std::endl;

    return 0;
}
