#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
const char raw[] = {
#embed "../input/day03"
    , '\0'};

int main() {
  std::istringstream iss{raw};
  std::string l;
  std::vector<std::vector<int>> lines;
  while (iss >> l) {
    std::vector<int> line;
    line.reserve(l.size());
    for (char c : l) {
      line.push_back(c - '0');
    }
    lines.push_back(std::move(line));
  }

  int ans = 0;
  for (auto &&line : lines) {
    auto max = std::max_element(line.begin(), std::prev(line.end()));
    auto nextmax = std::max_element(std::next(max), line.end());
    ans += *max * 10 + *nextmax;
  }
  std::cout << ans << '\n';

  long ans2 = 0;
  for (auto &&line : lines) {
    auto max = std::max_element(line.begin(), line.end() - 11);
    long best = *max;
    for (int n = 10; n >= 0; --n) {
      best *= 10;
      max = std::max_element(max + 1, line.end() - n);
      best += *max;
    }
    ans2 += best;
  }
  std::cout << ans2 << '\n';
}