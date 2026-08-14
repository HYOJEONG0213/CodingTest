#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[3] = {1,2,3};
	int b[3][3] = {{0,1,2},{3,4,5}};
	int c[3][3];
	int d[3][3] = {{0},};
	
	for(int i = 0; i < 3; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cout << b[i][j] << " ";
	cout << "\n";
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cout << c[i][j] << " ";
	cout << "\n";
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cout << d[i][j] << " ";
	cout << "\n";
}
