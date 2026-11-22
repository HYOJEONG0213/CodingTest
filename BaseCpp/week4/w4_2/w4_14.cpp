#include <iostream>
using namespace std;

char arr[2][7];

int main(){
	for(int i = 0 ; i < 2; i++){
		cin >> arr[i];
	}
	
	int cnt = 0;
	for(int i = 0 ; i < 7 ; i++){
		if(arr[0][i] != arr[1][i]) cnt++;
	}
	
	cout << cnt;
}
