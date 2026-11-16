#include <iostream>
using namespace std;

int arr[6], a;

void PrintAll(){
	for(int i = 0;  i < 6; i++) cout << arr[i] << "\n";
}

int main(){
	cin >> a;
	for(int i = 0; i < 6 ;i++){
		arr[i] = a+i;
	}
	PrintAll();
}
