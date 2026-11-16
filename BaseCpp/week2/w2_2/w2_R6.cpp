#include <iostream>
using namespace std;

char arr[5];
int count;

int main(){
	for(int i = 0 ; i <5; i++){
		cin >> arr[i];
		if(arr[i] >= '0' && arr[i] <= '9'){
			count++;
		}
	}
	cout << count;
}
