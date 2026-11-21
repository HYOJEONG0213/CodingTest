#include <iostream>
using namespace std;

int arr[2][3], a;

int main(){
	for(int i = 0 ; i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			cin >> arr[i][j];
		}	
	}
	for(int i = 0 ; i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			if(arr[i][j]==0) cout << '#';
			else cout << arr[i][j];
		}	
		cout << "\n";
	}
}
