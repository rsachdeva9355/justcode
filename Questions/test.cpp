#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m,n;
	
	cin >> m >> n;
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	sort(arr, arr + n -1);
	cout << arr[m -1] - arr[0] << endl;
	return 0;
}