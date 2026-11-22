#include <iostream>
using namespace std;

char a, b;

int main(){
	cin >> a >> b;
	char *p1 = &a, *p2 = &b;
	char temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	
	cout << a << " " << b;
}
