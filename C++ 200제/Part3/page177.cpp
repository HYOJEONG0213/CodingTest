#include <bits/stdc++.h>
using namespace std;

void f1(int (*p)[3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << p[i][j] ;
		}
		cout << " ";
	}
	cout << "\n";
}

void f2(int arr[][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j] ;
		}
		cout << " ";
	}
	cout << "\n";
	
	arr[2][2]=100;
}

void f3(int *p){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << *((p+i*3)+j) ;
		}
		cout << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr1[3][3] = {{0,1,2}, {3,4}};
	f1(arr1);
	f2(arr1);
	f3(*arr1);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << arr1[i][j] ;
		}
		cout << " ";
	}
	cout << "\n";
}
