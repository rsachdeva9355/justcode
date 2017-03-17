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
    int n; 
    int k; 
    vector<pair<int,int>> storage; 
    cin >> n >> k; 
    for(int a0 = 0; a0 < n; a0++)
    { 
        int x_i; 
        int w_i; 
        cin >> x_i >> w_i; 
        storage.push_back(make_pair(x_i,w_i)); 
    } 
    long long cost = 0; 
    int i =1; 
    int ind =0; 
    while(i<n){ 
        cost += storage[i].second * (storage[i].first - storage[ind].first); 
        i++; 
        if(k>1) {
            k--; 
            ind = i; 
            i++; 
        } 
    }
    cout << cost << endl; 
    return 0;
}