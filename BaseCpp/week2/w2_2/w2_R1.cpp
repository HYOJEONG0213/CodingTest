#include <iostream>
using namespace std;

char a, b;

int main(){
	cin >> a >> b;
	cout << a << ": " << static_cast<int>(a) << "\n";
	cout << b << ": " << static_cast<int>(b);
}
