#include <iostream>
using namespace std;

int a,b,c;

int main(){
	cin >> a >> b >> c;
	cout << max(max(a,b), c) << " " << min(min(a,b),c);
}
