#include <iostream>
using namespace std;

int arr[4][4], cnt=2 ;

int main(){
	for(int i = 0 ; i < 4; i++){
		for(int j = 0 ; j < 4; j++){
			arr[j][i] = cnt;
			cnt += 2;
		}
	}	
	
	for(int i = 0 ; i < 4; i++){
		for(int j = 0 ; j < 4; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}	
}
