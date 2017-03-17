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

void countSort(vector<string> &strList, long index) {

    int count[10] = {0};
    int size = strList.size();
    // cout << index << endl;
    vector<string> output(size);
    for (int i = 0; i < size; i++) {
        string str = strList[i];
        int len = str.length();
        // cout << str << ":" << len << " ";
        if (index > len) {
            count[0]++;
        } else {
            // cout << str[len - index] - '0' << " - ";
            count[str[len - index] - '0']++;
        }
    }
    // cout << endl;
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // cout << endl;
    for (int i = size - 1; i >= 0; i--) {
        string str = strList[i];
        int len = str.length();
        if (index > len) {
            output[count[0] - 1] = str;
            count[0]--;
        } else {
            // cout << "Count:" << count[str[len - index] - '0'] - 1;
            output[count[str[len - index] - '0'] - 1] = str;
            count[str[len - index] - '0']--;
        }
    }
    strList = output;
}

void radixsort(vector<string> &strList, long max)
{
    for (int exp = 1; exp <= max; exp++)
        countSort(strList, exp);
}
 
int main()
{
    long n;
    cin >> n;
    vector<string> strList(n);
    long maxLen = 0;
    for (long i = 0; i < n; i++) {
        cin >> strList[i];
        long length = strList[i].length();
        if (length > maxLen) {
            maxLen = length;
        }
    }
    sort(strList.begin(), strList.end());
    // radixsort(strList, maxLen);
    for (long i = 0; i < strList.size(); i++) {
        cout << strList[i] << "\n";
    }
    return 0;
}