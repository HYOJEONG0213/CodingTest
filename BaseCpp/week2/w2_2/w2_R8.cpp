#include <iostream>
using namespace std;

char a[5], b[5], c;

int main(){
	cin >> c;
	for(int i = 0; i < 5; i++) {
		a[i] = char(c+i);
		cout << a[i];
	}
	cout << "\n";
	for(int i = 0; i < 5; i++) {
		b[i] = char(c-i);
		cout << b[i];
	}
}
