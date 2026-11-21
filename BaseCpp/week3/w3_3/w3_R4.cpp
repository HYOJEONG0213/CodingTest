#include <iostream>
using namespace std;

char a, b, c;

int main(){
	cin >> a >> b >> c;
	char *p1 = &a, *p2 = &b, *p3 = &c;
	cout << ++(*p1) << " " << ++(*p2) << " "<< ++(*p3); 
}
