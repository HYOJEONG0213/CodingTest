#include <iostream>
using namespace std;

int input(){
	int a;
	cin >> a;
	return a;
}

void cals(int a, int b, int c){
	cout << a+b+c;
}

int main(){
	int a = input();
	int b = input();
	int c = input();
	cals(a,b,c);
}
