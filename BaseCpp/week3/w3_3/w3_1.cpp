#include <bits/stdc++.h>
using namespace std;

int num, arr[4][4];

int main(){
	cin >> num;
	if(num%2 == 0){
		for(int i = 0; i < 4; i++){
			arr[i][i] = i+1;
		}
	}
	else{
		for(int i = 0; i < 4; i++){
			arr[i][3-i] = i+1;
		}
	}
	
	for(int i = 0 ; i < 4; i++){
		for(int j = 0 ; j < 4; j++){
			cout << arr[i][j] << " ";
		}
		cout<< "\n";
	}
}
