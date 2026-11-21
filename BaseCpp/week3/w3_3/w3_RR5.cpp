#include <iostream>
using namespace std;

int arr[6][3], cnt=10, a, b ;

int main(){
	cin >> a >> b;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 6; j++){
			arr[j][i] = cnt++;
		}
	}
	
	for(int i = a; i <= b; i++){
		for(int j = 0; j < 3; j++)
			arr[i][j] = 7; 
	}
	
	for(int i = 0 ; i < 6; i ++){
		for(int j = 0 ; j < 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n"; 
	}
}
