#include <bits/stdc++.h>
using namespace std;

void f1(int *p){
	for(int i = 0; i < 3; i++){
		cout << p[i] << " ";
	}
	cout << "\n";
}

void f2(int arr[]){
	for(int i = 0; i < 3; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	arr[2]=100;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr1[3] = {0,1,2};
	f1(arr1);
	f2(arr1);
		for(int i = 0; i < 3; i++){
		cout << arr1[i] << " ";
	}
	cout << "\n";
}
