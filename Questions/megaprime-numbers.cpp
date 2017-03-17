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

int next(int num) {
    if (num == '2') {
        return '3';
    }
    if (num == '3') {
        return '5';
    }
    if (num == '5') {
        return '7';
    }
    if (num == '7') {
        return '2';
    }
    return '0';
}

string findNextQuaternary(string num) {
    int len = num.length();
    int carry = 0;
    int i = len - 1;
    if (num[i] == '7') {
        num[i] = '2';
        carry = 1;
    } else {
        num[i] = next(num[i]);
    }
    i--;
    while(carry && i >= 0) {
        if (num[i] == '7') {
            num[i] = '2';
            carry = 1;
        } else {
            num[i] = next(num[i]);
            carry = 0;
        }
        i--;
    }
    if (carry) {
        string res = "2";
        res.append(num);
        num = res;
    }
    return num;
}

// long long findClosestNumber(long long a) {
//     int digits[20];
//     long long temp = a;
//     int nod = 0;
//     while(temp) {
//         digits[nod] = temp % 10;
//         nod++;
//         temp /= 10;
//     }
//     int i = nod - 1;
//     while(0) {
//         temp = digits[i];
//         if (temp == 2) {

//         }
//     }
// }

int main() {
    long long a, b;
    cin >> a >> b;
    long long start, end, count = 0;
    // start = findClosestNumber(a);
    // end = findClosestNumber(b);
    long long q = start;
    while(q <= end) {
        if (isPrime(q)) {
            count ++;
        }
        q = findNextQuaternary(i);
    }
    
    return 0;
}