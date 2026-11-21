#include <iostream>
using namespace std;

char aToZ(){
	char a;
	cin >> a;
	return (a-'A' < 'Z'-a) ? 'A' : 'Z';
}

int main(){
	cout << aToZ();
}
