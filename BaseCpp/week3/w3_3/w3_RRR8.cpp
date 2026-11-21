#include <iostream>
using namespace std;

char arr[3][3] = {'a','b','d','e','w','z','q','v','a'};

void Process(char c){
	c = c - 'A' + 'a';
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			if(arr[i][j]==c){
				cout << "존재";
				return;
			}
		}
	}
	cout << "없음";
}

void Input(){
	char c;
	cin >> c;
	Process(c);
}



int main(){
	Input(); 
}
