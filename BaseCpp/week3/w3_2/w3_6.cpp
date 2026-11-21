#include <iostream>
using namespace std;

int arr[3][3], y1, y2, x1, x2;

int main(){
	char a = 'A';
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j <3; j++){
			arr[i][j] = a++;
		}
	}
	cin >> y1 >> x1;
	cin >> y2 >> x2;
	swap(arr[y1][x1], arr[y2][x2]);
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j <3; j++){
			cout << (char)arr[i][j];
		}
		cout << "\n";
	}
}
