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

char matrix[1000][1000];

long distance(pair<double, double> a, pair<double, double> b) {
    return ceil(sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}

float area(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
   return abs((a.first*(b.second-c.second) + b.first*(c.second-a.second)+ c.first*(a.second-b.second))/2.0);
}

bool isInside(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> point)
{   
   /* Calculate area of triangle ABC */
   float A = area(a, b, c);
 
   /* Calculate area of triangle PBC */  
   float A1 = area (point, b, c);
 
   /* Calculate area of triangle PAC */  
   float A2 = area (a, point, c);
 
   /* Calculate area of triangle PAB */   
   float A3 = area (a, b, point);
   
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

bool insideSquare(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d, pair<double, double> point) {
    return (isInside(a, b, c, point) || isInside(a, b, d, point));
}

int main() {
    long w, h;
    cin >> w >> h;
    long cr;
    pair<double, double> center;
    cin >> center.second >> center.first >> cr;
    center.first += 0.5;
    center.second += 0.5;
    for (long i = 0; i < h; i++) {
        for (long j = 0; j < w; j++) {
            matrix[i][j] = '.';
        }
    }
    for (double i = 0.5; i <= h; i++) {
        for (double j = 0.5; j <= w; j++) {
            long dst = distance(center, make_pair(i, j));
            // cout << i << ":" << j << " " << dst << endl;
            if (dst <= cr) {
                matrix[(long)(i - 0.5)][(long)(j - 0.5)] = '#';
            }
        }
    }

    pair<double, double> sa, sb, sc, sd;
    cin >> sa.second >> sa.first >> sb.second >> sb.first;
    sa.second += 0.5;
    sa.first += 0.5;
    sb.second += 0.5;
    sb.first += 0.5;

    sc = make_pair((sa.first + sb.first + sb.second - sa.second) / 2, (sa.first + sb.second + sa.second - sb.first ) / 2);
    sd = make_pair((sa.first + sb.first + sa.second - sb.second) / 2, (sb.first + sb.second + sa.second - sa.first ) / 2);

    for (double i = 0.5; i <= h; i++) {
        for (double j = 0.5; j <= w; j++) {
            // cout << i << ":" << j << " " << insideSquare(sa, sb, make_pair(i, j)) << endl;
            if (insideSquare(sa, sb, sc, sd, make_pair(i, j))) {
                matrix[(long)(i - 0.5)][(long)(j - 0.5)] = '#';
            }
        }
    }
    // cout << insideSquare(sa, sb, make_pair(13.5, 14.5));
    for (long i = 0; i < h; i++) {
        for (long j = 0; j < w; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}