#include <iostream>
using namespace std;

int main(){
	int arr[4];
	for(int i = 0 ; i < 4; i ++) 
		cin >> arr[i];
	int sum = 0;
	for(int i = 0 ; i < 4; i ++){
		sum += arr[i];		
	}
	cout << sum;
}

