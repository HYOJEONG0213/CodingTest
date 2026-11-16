#include <iostream>
using namespace std;

int arr[6] = {0}, a, b;

int main(){
	cin >> a >> b;
	for(int i = 0; i <= b-a; i++){
		arr[i] = a+i;
	}
	for(int i = 0 ; i < 6; i++) cout << arr[i] << "";
}
