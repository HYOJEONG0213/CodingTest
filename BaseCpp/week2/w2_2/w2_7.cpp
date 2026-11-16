#include <iostream>
using namespace std;

int a; 

int main(){
	cin >> a;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < a; j++){
			cout << "#"; 
		}
		cout << "\n";
	}
}
