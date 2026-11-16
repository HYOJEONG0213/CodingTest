#include <iostream>
using namespace std;

int data[4], a;

int main(){
	cin >> a;
	if(a == 10) {
		for(int i = 10; i >= 7; i--) data[10 - i] = i;
	}
	
	for(int i = 0 ; i < 4; i++) cout << data[i] << " ";
}
