#include <iostream>
using namespace std;

int a,b,c;

int main(){
	cin >> a >> b >> c;
	for(int j = 0; j < c; j++){
		for(int i = a; i <= b; i++){
			cout << i << " ";
		}
		cout << "\n";
	}
}
