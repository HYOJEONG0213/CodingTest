#include <iostream>
using namespace std;

char arr[3][5] = {'a','b','a','c','z','c','t','a','c','d','c','c','c','c','a'};
char c;
int cnt;

int main(){
	cin >> c;	
	for(int i = 0; i < 3; i++ ){
		for(int j = 0 ; j < 5; j++){
			if(arr[i][j]==c) cnt++;	
		}
	}
	
	if(cnt >= 7) cout << "세상에";
	else if(cnt >= 5) cout << "와우"; 
	else if(cnt >= 3) cout << "아아";
	else cout << "이런";
}
