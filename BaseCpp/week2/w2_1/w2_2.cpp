#include <iostream>
using namespace std;

int arr[4];
int sum = 0;
int main(){
	for(int i = 0 ; i < 4; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	cout << sum;
	
}
