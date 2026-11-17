#include <iostream>
using namespace std;

int a, b;

int main(){
	cin >> a >> b;
	int sub = abs(a-b);
	if(sub % 2 == 1){
		cout << "°í¹éÇÑ´Ù";
	}
	else
		cout << "Â¦»ç¶û¸¸"; 
}
