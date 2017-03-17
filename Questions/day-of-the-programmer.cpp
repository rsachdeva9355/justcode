#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int year;
    cin >> year;
    bool leap = false;
    if (year < 1918) {
        if (year % 4 == 0) {
            cout << "12.09." << year << endl;
        } else {
            cout << "13.09." << year << endl;
        }
        return 0;
    } else if (year > 1918) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            cout << "12.09." << year << endl;
        } else {
            cout << "13.09." << year << endl;
        }
        return 0;
    } else {
        cout << "26.09.1918" << endl;
        return 0;
    }
}