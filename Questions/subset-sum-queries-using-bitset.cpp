#include<iostream>

using namespace std;

bool exists(int num, int* arr, int size, int ind) {
	if (ind == size) {
		return false;
	}
	if (num == 0) {
		return true;
	}
	return exists(num - arr[ind], arr, size, ind + 1) || exists(num, arr, size, ind + 1);
}

int main() {
	int arr[] = {1, 2, 3};
	cout<<exists(7, arr, sizeof(arr), 0);
	return 0;
}