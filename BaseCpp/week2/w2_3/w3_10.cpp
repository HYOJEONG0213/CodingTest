#include <iostream>
using namespace std;

char arr[4][4], a;

void input(){
	cin >> a;
	
	for(int i = 0 ; i < 4; i ++){
		for(int j = 0 ; j < 4; j++){
			arr[i][j] = a;		
		}
	}
}

void output(){
	for(int i = 0 ; i < 4; i ++){
		for(int j = 0 ; j < 4; j++){
			cout << arr[i][j];		
		}
		cout << "\n";
	}
}

int main(){
	input();
	output();
}
