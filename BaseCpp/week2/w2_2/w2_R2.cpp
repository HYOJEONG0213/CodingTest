#include <iostream>
using namespace std;

char input;

int main(){
	cin >> input;
	for(char i = input; i >= 'a'; i--){
		cout << i;
	}
}
