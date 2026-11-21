#include <iostream>
using namespace std;

int arr[2][3], a;

int main(){
	for(int i = 1; i >= 0; i--){
		for(int j = 2; j >= 0; j--){
			cin >> arr[i][j];
		}
	}
	
	int ret[6] = {};
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			ret[i*3 + j] = arr[i][j];
		}
	}
	
	int temp = ret[0];
	ret[0] = ret[5];
	ret[5] = temp;
	
	for(int i = 0; i < 6; i++) cout << ret[i] << " ";
}
