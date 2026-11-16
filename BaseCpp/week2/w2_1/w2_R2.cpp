#include <iostream>
using namespace std;

char c;

void KFC(){
	cout << "KFC" << "\n";
}

void BBQ(){
	cout << "BBQ" << "\n";
}

int main(){
	cin >> c;
	if(c == 'B') {
		KFC();
		BBQ();
	}
	else if(c == 'b'){
		BBQ();
	}
	else if(c == '7'){
		KFC();
	}
}
