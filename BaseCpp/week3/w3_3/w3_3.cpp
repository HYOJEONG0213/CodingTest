#include <iostream>
using namespace std;

int arr[3][3], a, cnt = 9;

int main(){
	cin >> a;
	if(a%5==1){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				arr[j][i] = cnt--;
			}
		}
	}
	else if(a%5==2){
		for(int j = 0 ;  j < 3; j++){
			for(int i = 2; i >= 0; i--){
				arr[j][i] = cnt--;
			}
		}
	}
	else{
		for(int i = 0 ; i < 3; i++){
			for(int j = 0 ; j < 3; j++){
				arr[j][i] = ++cnt; 
			}
		}
	}
	
	for(int i = 0 ; i <3; i++){
		for(int j = 0 ; j < 3; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
		
}

