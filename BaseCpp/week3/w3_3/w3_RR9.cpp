#include <iostream>
using namespace std;

void run(int a){
	int arr[3][3] = {};
	int cnt = 1;
	if(a < 10){
		for(int i = 0 ; i < 3; i++){
			for(int j = 0 ; j <3; j++){
				arr[i][j] = cnt++;
			}
		}
	}
	else{
		for(int i = 0; i < 3; i++){
			for(int j = 2; j >= 0; j--){
				arr[i][j] = cnt++;
			}
		}
	}
	
	for(int i = 0 ; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

int main(){
	int a;
	cin >> a;
	run(a);
}
