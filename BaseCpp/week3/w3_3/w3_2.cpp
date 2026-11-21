#include <iostream>
using namespace std;

void getChar(char a, char b){
	cout << ((a<b)? b : a);
}

int main(){
	char a, b;

	cin >> a >> b;
	getChar(a, b);
}
