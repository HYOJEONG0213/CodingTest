#include <iostream>
using namespace std;

int arr[5][5], cnt=1, a ;

int main(){
	for(int i = 4; i >= 0; i--){
		for(int j = 0; j < 5; j++){
			arr[j][i] = cnt++;
		}
	}
	
	cin >> a;
	
	for(int i = 0; i < 5; i++){
		arr[a][i] = a;
	}
	
	for(int i = 0 ; i <5 ; i++){
		for(int j = 0 ; j < 5; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
