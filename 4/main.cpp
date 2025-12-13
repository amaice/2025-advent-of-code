#include <fstream>
#include <iostream>
#include <vector>

bool is_roll(char);
int num_of_adjacent_rolls(const std::vector<std::vector<bool>>&, int, int);
bool out_of_bounds(const std::vector<std::vector<bool>>&, int, int);

// starting up, going clockwise
int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int main() {
    const std::string filePath = "input";
    std::ifstream inputFile(filePath);

    // Generate 2D vector of bools (whether a cell is a roll of paper)
    std::vector<std::vector<bool>> printing_department;
    std::string line;
    while (getline(inputFile, line)) {
        std::vector<bool> row;
        for (const char c : line) {
            row.push_back(is_roll(c));
        }
        printing_department.push_back(row);
    }

    int num_accessible = 0;
    for (int y = 0; y < printing_department.size(); y++) {
        for (int x = 0; x < printing_department[x].size(); x++) {
            if (printing_department[y][x]
            && num_of_adjacent_rolls(printing_department, y, x) < 4) {
                num_accessible++;
                std::cout << x << "," << y << std::endl;

            }
        }
    }

    std::cout << "num_accessible: " << num_accessible << std::endl;
    return 0;
}

// True if '@'
bool is_roll(const char c) {
    return c == '@';
}

int num_of_adjacent_rolls(const std::vector<std::vector<bool>>& printing_department, int y, int x) {
    int adjacent_rolls = 0;
    for (const auto direction : directions) {
        int temp_loc[2] = {y + direction[0], x + direction[1]};
        if (!out_of_bounds(printing_department, temp_loc[0], temp_loc[1])
        && printing_department[temp_loc[0]][temp_loc[1]]) {
            adjacent_rolls++;
        }
    }
    return adjacent_rolls;
}

bool out_of_bounds(const std::vector<std::vector<bool>>& printing_department, int y, int x) {
    if (y >= printing_department.size() || x >= printing_department[0].size()) {
        return true;
    }
    if (y < 0 || x < 0) {
        return true;
    }
    return false;
}