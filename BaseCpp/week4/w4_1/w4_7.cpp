#include <iostream>
using namespace std;

void FindABC(string s, int &na, int &nb, int &nc){
	for(auto c: s){
		if(c=='A') na++;
		else if(c=='B') nb++;
		else if(c=='C') nc++;
	}
}

int main(){
	string s1, s2;
	int a=0, b=0, c=0;
	cin >> s1 >> s2;
	FindABC(s1, a, b, c);
	FindABC(s2, a, b, c);
	cout << a << " " << b << " " << c;
}
