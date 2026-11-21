#include <iostream>
using namespace std;

int arr[3][4], a, cnt = 12;

int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++)
			arr[i][j] = cnt--;
	}
	
	cin >> a;	
	for(int i = 0; i < 3; i++)
		arr[i][a] = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			cout << arr[i][j] << " " ;
		}
		cout << "\n";
	}
}
