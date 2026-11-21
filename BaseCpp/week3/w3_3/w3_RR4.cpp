#include <iostream>
using namespace std;

int a, b, c, arr[3][4];

int main(){
	cin >> a >> b >> c;
	for(int i = 0 ; i < 4; i++) arr[0][i] = a++;
	for(int i = 0 ; i <4; i++) arr[1][i] = b++;
	for(int i = 0; i < 10; i++) arr[2][i] = c++;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
} 
