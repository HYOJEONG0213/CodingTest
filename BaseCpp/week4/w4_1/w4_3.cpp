#include <iostream>
using namespace std;

int stringLen(string a){
	return a.size();
}

int main(){
	string a;
	cin >> a;
	cout << stringLen(a);
}
