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

string compileString(int n) {
    if (n == 2) {
        return "min(int, int)";
    }
    string result = "min(int, ";
    result += compileString(n - 1);
    result += ")";
    return result;
}

int main() {
    int n;
    cin >> n;
    string answer = compileString(n);
    cout << answer << endl;
    return 0;
}