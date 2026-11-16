#include <iostream>
using namespace std;

int arr[6], a;


int main(){
	for(int i = 0 ; i < 3; i++) cin >> arr[i];
	cin >> a;
	for(int i = 3; i < 6; i++) arr[i] = a+i-3;
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
}
