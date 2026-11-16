#include <iostream>
using namespace std;

char input;

int main(){
	cin >> input;
	for(int i = 'A'; i <= input; i++){
		cout << static_cast<char>(i) ;
	}
}
