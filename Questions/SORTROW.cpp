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

bool compare1(int a, int b) {
    return a - b > 0;
}
bool compare2(int a, int b) {
    return a - b < 0;
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > arr(n);
    for (int i = 0; i < n; i++) {
        vector<int> vc(n);
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            vc[j] = a;
        }
        arr[i] = vc;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sort(arr[i].begin(), arr[i].end(), compare2);
        } else {
            sort(arr[i].begin(), arr[i].end(), compare1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";   
        }
        cout << endl;
    }
    return 0;
}