#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 10;
	int * b = &a;
	cout << a << " " << sizeof(a) << "\n";
	cout << b << " " << sizeof(b) << "\n";
	
	double c = 23.4;
	double *d = &c;
	cout << c << " " << sizeof(c) << "\n";
	cout << d << " " << sizeof(d) << "\n";
}
