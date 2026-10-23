#include <iostream>
using namespace std;

int main(){
	int a;
	int arr[6];
	cin >> a;
	for(int i = 0; i < 6; i++){
		arr[i] = a--;
	}
	cout << arr[2];
}

