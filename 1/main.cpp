#include <iostream>
#include <fstream>

#include "Safe.h"
#include "NewSafe.h"

int main()
{
    const std::string filePath = "input_stolen.txt";
    std::ifstream inputFile(filePath);

    NewSafe safe = NewSafe();
    // safe.turn('L', 68);
    // safe.turn('L', 30);
    // safe.turn('R', 48);
    // safe.turn('L', 5);
    // safe.turn('R', 60);
    // safe.turn('L', 55);
    // safe.turn('L', 1);
    // safe.turn('L', 99);
    // safe.turn('R', 14);
    // safe.turn('L', 82);

    std::string line;
    while (getline(inputFile, line))
    {
        // "L/R" + Int
        const int distance = std::stoi(line.std::string::substr(1, line.size()));

        safe.turn(line[0], distance);
    }
    inputFile.close();

    std::cout << "Password: " << safe.password() << std::endl;
    std::cout << "Answer is 6122";
    return 0;
}
