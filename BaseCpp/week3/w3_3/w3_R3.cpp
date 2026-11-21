#include <iostream>
using namespace std;

int a;
char gd;
char * t;

int main(){
	cin >> a >> gd;
	int *p = &a;
	char *t = &gd;
	
	cout << *p << " "<< *t;
}
