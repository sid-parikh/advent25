#include <iostream>
#include <sstream>

// input replace L with - and delete R
const char raw[] = {
    #embed "../input/day01"
    , '\0'
};

using namespace std;

int main() {
    // part 1
    istringstream input{raw};
    int num = 0, pos = 50, ans = 0;
    while (input >> num) {
        pos = (pos + num) % 100;
        if (pos == 0) ++ans;
    }
    cout << ans << endl;

    // part 2
    input = istringstream{raw};
    pos = 50, ans = 0;
    while (input >> num) {
        if (num >= 0) {
            for (; num > 0; --num) {
                ++pos;
                if (pos == 100) pos = 0;
                if (pos == 0) ++ans;
            }
        } else  {
            for (; num < 0; ++num) {
                --pos;
                if (pos == -1) pos = 99;
                if (pos == 0) ++ans;
            }
        }
    }
    cout << ans << endl;
}