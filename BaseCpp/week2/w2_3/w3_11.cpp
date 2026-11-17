#include <iostream>
using namespace std;

int a, arr[3][3];

void input(){
	cin >> a;
}

void process(){
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			arr[i][j] = a++;
		}
	}
}

void output(){
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

int main(){
	input();
	process();
	output();
	
}
