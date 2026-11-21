#include <iostream>
using namespace std;

char arr[2][3];

void input(){
	for(int i = 0 ;  i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			cin >> arr[i][j];
		}
	}
}

void findUpper(){
	int cnt = 0;
	for(int i = 0 ;  i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			if(isupper(arr[i][j])) cnt++;
		}
	}
	cout << "대문자 : " << cnt << "\n";
}

void findLower(){
	int cnt = 0;
	for(int i = 0 ;  i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			if(islower(arr[i][j])) cnt++;
		}
	}
	cout << "소문자 : " << cnt << "\n";
}


int main(){
	input();
	findUpper();
	findLower();
	 
}
