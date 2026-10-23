#include "iostream"
using namespace std;

int main(){
	int a;
	cin >> a;
	for(int i = a; i < a+3; i++){
		for(int j = 0; j < 3; j ++){
			cout << i ;	
		}
		cout << "\n";
	}
}
