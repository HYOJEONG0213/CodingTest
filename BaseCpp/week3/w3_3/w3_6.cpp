#include <iostream>
using namespace std;

int arr[4][4], cnt = 1;

int main(){
	for(int i = 3; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			arr[j][i] = cnt++;
		}
	}
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
