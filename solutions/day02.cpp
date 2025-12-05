#include <cmath>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
const char raw[] = {
#embed "../input/day02"
    , '\0'};


int numDigits(long n) {
    int ans = 0;
    while (n > 0) {
        n /= 10;
        ++ans;
    }
    return ans;
}

bool isRepeating(std::string n, std::string pat)  {
    auto count = n.size() / pat.size();
    if (pat.size() * count != n.size()) return false;
    if (count < 2) return false;
    std::string buf = "";
    for (int i = 0; i < count; ++i) {
        buf += pat;
    }
    if (n == buf) {
        return true;
    }
    return false;
}

bool invalid(long n) {
    int digits = numDigits(n) / 2;
    int p = (int)pow(10, digits);
    return (n % p) == (n / p);
}

bool invalid2(long _n) {
    std::string n = std::to_string(_n);
    auto maxlen = n.size() / 2;
    for (int i = 1; i <= maxlen; ++i) {
        if (isRepeating(n, n.substr(0, i))) {
            return true;
        }
    }
    return false;
}

int main() {
  using std::operator""sv;

  std::vector<std::pair<long, long>> ranges;
  for (auto _word : std::ranges::views::split(std::string(raw), ","sv)) {
    auto word = std::string_view(_word);
    auto i = word.find_first_of('-');
    long first = std::stol(std::string(word.substr(0, i)));
    long second = std::stol(std::string(word.substr(i + 1)));
    ranges.emplace_back(first, second);
  }

  long sum = 0;
  long sum1 = 0;
  for (auto &&[s, e] : ranges) {
    for (long n = s; n <= e; ++n) {
        if (invalid2(n)) {
            sum += n;
        }
        if (invalid(n)) {
            sum1 += n;
        }
    }
  }
  std::cout << sum1 << "\n";
  std::cout << sum << "\n";
}

/**
54498614142 too high
 */