#include <iostream>
using namespace std;

int arr[3][3] = {3,1,6,7,8,4,9,2,3};
int a, b, c, mx, mn;

int main(){
	cin >> a >> b >> c;
	arr[a][b] = c;
	mx = mn = arr[0][0];
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			mx = (mx < arr[i][j] ? arr[i][j] : mx);
			mn = (mn < arr[i][j] ? mn : arr[i][j]);
		}
	}
	cout << mx + mn;
}
