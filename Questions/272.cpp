#include<iostream>

using namespace std;

int main() {
	string str = "";
	string input = "";
	string output = "";
	bool left = false;
	while (getline(cin, str)) {
		if (str == "" || str == "\n") {
			break;
		}
		input.append(str);
		input += '\n';
	}
	for (int  i = 0; i < input.length(); i++) {
		if (input[i] == '\"') {
			if (left) {
				output.append("''");
				left = false;
			} else {
				output.append("``");
				left = true;
			}
		} else {
			output += input[i];
		}
	}
	cout << output;
	return 0;
}

