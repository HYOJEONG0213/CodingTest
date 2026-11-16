#include <iostream>
using namespace std;

char a, b;

int main(){
	cin >> a >> b;
	if((a == 'A' && b == 'D') || (a == 'D' && b == 'A')){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				cout << static_cast<char>('A' + j) << " ";
			}
			cout << "\n";
		}
	}
	
	if((a == 'B' && b == 'H') || (a == 'H' && b == 'B')){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 6; j++){
				cout << static_cast<char>('B' + j) << " ";
			}
			cout << "\n";
		}
	}
}
