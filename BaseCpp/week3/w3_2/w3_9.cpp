#include <iostream>
using namespace std;

char arr[2][3] = {'F','E','W','D','C','A'};

void findCh(char c){
	for(int i = 0 ;  i < 2; i++){
		for(int j = 0 ; j < 3; j++){
			if(arr[i][j]==c) {
				cout << "발견";
				return; 
			}
		}
	}
	cout << "미발견";
}

int main(){
	char c;
	cin >> c;
	findCh(c);
}
