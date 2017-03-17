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
    int n, t;
    cin >> n >> t;
    int temp = n;
    int count = 0;
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;
        temp -= c;
        if (temp < 5 && i < t - 1) {
            count += n - temp;
            temp = n;
        }
    }
    cout << count << endl;
    return 0;
}