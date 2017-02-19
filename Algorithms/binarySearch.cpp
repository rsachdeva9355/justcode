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

int binarySearch(vector<int> arr, int n, int a) {
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = (r + l - 1) / 2;
        cout << mid << endl;
        if(arr[mid] == a) {
            return mid;
        }
        if (arr[mid] < a) {
            l = mid + 1;
        }
        if (arr[mid] > a) {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int a = 3;
    int b = 4;
    cout <<(b + a) / 2 << endl;
    return 0;
}