#include <iostream>

using namespace std;

int main() {
	long t;
	cin >> t;
	while(t--) {
		long n;
		cin >> n;
		long fine = 0;
		long ones = 0;
		for (int i = 0; i < n; ++i)
		{
			bool a;
			cin >> a;
			if (a == 0 && fine == 0) {
				fine = 100 * (n - i);
			} else if (a == 1){
				ones++;
			}
		}
		long amount = fine + (n - ones) * 1000;
		cout << amount << endl;
	}
	return 0;
}