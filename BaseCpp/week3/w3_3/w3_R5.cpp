#include <iostream>
using namespace std;

int a, b;

int main(){
	cin >> a >> b;
	int *p = &a, *t = &b;
	int temp = *p;
	*p = *t;
	*t = temp;
	
	cout << *p << " " << *t;
}
