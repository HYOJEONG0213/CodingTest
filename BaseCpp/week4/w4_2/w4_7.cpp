#include <iostream>
using namespace std;

void Magic(int (*arr)[3]) {
	int cnt = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			arr[i][j] = cnt++;
		}
	}
}

void Output(int (*arr)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(arr[i][j]==0) {
				cout << "  ";
				continue;
			}
			cout << arr[i][j]<< " ";
		}
		cout << "\n";
	}
}

int main() {
	int arr[3][3] = {};
	Magic(arr);
	Output(arr);
}
