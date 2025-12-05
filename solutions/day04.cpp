
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

const char raw[] = {
#embed "../input/day04"
    , '\0'};

int ROWS = 0;
int COLS = 0;

using Grid = std::vector<std::string>;
constexpr char P = '@';
constexpr char E = '.';

const std::vector<std::pair<int, int>> dirs = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

bool inBounds(int r, int c) {
    return r >= 0 && c >= 0 && r < ROWS && c < COLS;
}

int countNeighbors(int r, int c, Grid grid, char t = P)  {
    int ans = 0;
    for (auto [dr, dc] : dirs) {
        if (inBounds(r + dr, c + dc) && grid[r + dr][c + dc] == t) {
            ++ans;
        }
    }
    return ans;
}

int main () {
    Grid grid;
    std::istringstream iss {raw};
    std::string line;
    while (iss >> line) {
        COLS = line.size();
        grid.push_back(std::move(line));
    }
    ROWS = grid.size();

    int ans = 0;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (grid[r][c] == P && countNeighbors(r, c, grid) < 4) {
                ++ans;
            }
        }
    }
    std::cout << ans << '\n';

    int round = 0;
    int ans2 = 0;
    do {
        round = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == P && countNeighbors(r, c, grid) < 4) {
                    ++round;
                    grid[r][c] = E;
                }
            }
        }
        ans2 += round;
    } while (round > 0);

    std::cout << ans2 << '\n';
}