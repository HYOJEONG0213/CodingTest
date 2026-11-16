#include <iostream>
using namespace std;

bool flag;
char a,b,c;

void input(){
	cin >> a >> b >> c;
}

void process(){
	if(a=='A' && b=='B' && c=='C') flag = 1;
}

void output(){
	if(flag == 1) cout << "ABC 찾았다";
	else cout << "못찾았다";
}

int main(){
	input();
	process();
	output(); 
}
