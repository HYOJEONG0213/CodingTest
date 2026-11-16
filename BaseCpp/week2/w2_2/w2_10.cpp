#include <iostream>
using namespace std;

char input;

int main(){
	cin >> input;
	if(input >= 'a' && input <= 'z') cout << static_cast<char>(input-'a'+'A');
	else if(input >= 'A' && input <= 'Z') cout << static_cast<char>(input-'A'+'a');
}
