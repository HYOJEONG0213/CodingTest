#include <iostream>
using namespace std;

char input;

int main(){
	cin >> input;
	if(input >= '0' && input <= '9')
		cout << input - '0' + 5;
}
