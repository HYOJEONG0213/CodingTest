#include <iostream>
using namespace std;

char a, b;

void input(){
	cin >> a >> b;
}

bool isCapital(char c){
	if(c >= 'a' && c <= 'z') return false;
	return true;
}

void output(){
	bool flag1 = isCapital(a);
	bool flag2 = isCapital(b);
	
	if(flag1 * flag2 == 1) cout << "대문자들";
	else if(flag1+flag2 == 1) cout << "대소문자";
	else {
		for(char i = 'a'; i < 'z'; i++) cout << i; 
	}
}

int main(){
	input();
	output();
}
