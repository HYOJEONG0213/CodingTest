#include <iostream>
using namespace std;

char a, b;

int main(){
	cin >> a >> b;
	if(a >= 'a' && a <= 'z') cout << a-'a'+'A';
	else if(a >= 'A' && a <= 'Z') cout << char(a-'A'+'a');
	
	if(b >= 'a' && b <= 'z') cout << b-'a'+'A';
	else if(b >= 'A' && b <= 'Z') cout << char(b-'A'+'a');
}
