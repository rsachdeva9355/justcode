// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
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

// long long int maxNum = 1000000000;
bool prime[1000000000] = {1};
void SieveOfEratosthenes(long long int n)
{
    for (long long int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (long long int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    Print all prime numbers
    for (long long int p=2; p<=n; p++)
    if (prime[p])
        cout << p << " ";
}

// Driver Program to test above function
int main()
{
    long long int n = 20;
    cout << "Following are the prime numbers smaller "
        << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}