#include <iostream>
using namespace std;

char vect[3][9] = {"BBQWORLD", "KFCAPPLE", "LOT"};
char c;
int ret;

int main(){
	cin >> c;
	for(int i =0 ; i < 3; i++){
		for(int j = 0; j< 8; j++){
			if(vect[i][j]==c) ret++;	
		}
	}	
	cout << ret;
}
