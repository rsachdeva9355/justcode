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

int n;

char consonants[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

void printStrings(bool startWithWovel, string tillNow, int len) {
    if (len == n) {
        cout << tillNow << endl;
        return;
    }

    if (startWithWovel) {
        for (int i = 0; i < 5; i++) {
            string current = tillNow + (vowels[i]);
            printStrings(!startWithWovel, current, len+1);
        }
    } else {
        for (int i = 0; i < 20; i++) {
            string current = tillNow + (consonants[i]);
            printStrings(!startWithWovel, current, len+1);
        }
    }
}

int main() {
    cin >> n;   
    printStrings(false, "", 0);
    printStrings(true, "", 0);
    return 0;
}