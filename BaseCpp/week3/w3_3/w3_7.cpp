#include <iostream>
using namespace std;

int arr[4][4], cnt = 12, a;

int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			arr[i][j] = cnt--;
		}
	}
	cin >> a;
	for(int i = 0; i < 4; i++){
		arr[i][a] = 0;
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
