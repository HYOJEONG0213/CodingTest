#include <iostream>
using namespace std;

int main(){
	int arr[5];
	int a;
	cin >> a;
	for(int i = 0; i < 5; i++){
		arr[i] = a+5;
	}
	for(int i = 0; i < 5; i++) 
		cout << arr[i] << " ";
}

