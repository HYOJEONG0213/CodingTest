#include <iostream>
using namespace std;

char arr[3][5] = {'D', 'A', 'C', 'C', 'D', 'S', 'D', 'F', 'A', 'E', 'E', 'E', 'T', 'J', 'H'};


bool CHECK(char d){
	for(int i = 0 ; i <3 ;i ++){
		for(int j = 0 ; j < 5; j++){
			if(arr[i][j]==d) return true;
		}
	}
	return false;
}

void INPUT(){
	char c;
	cin >> c;
	cout << (CHECK(c) ? "있음" : "없음");
}

int main(){
	INPUT();
}
