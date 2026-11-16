#include <iostream>
using namespace std;

int a;

void LOT(){
	for(int j = 1; j <= 5; j++) {
		cout << j;
	}
	cout << "\n";
}

int main(){
	cin >> a;
	for(int i = 0 ; i < a; i ++)
		LOT() ;
}
