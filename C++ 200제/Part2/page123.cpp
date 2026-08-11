#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbits are so cuuuute and they are funny.";
	string b = "CATS ARE CUTE BUT RABBITS ARE THE BEST";
	transform(a.begin(), a.end(), a.begin(), [](unsigned char c){return toupper(c);});
	transform(b.begin(), b.end(), b.begin(), [](unsigned char c){return tolower(c);});
	cout << a << "\n";
	cout << b << "\n";
	
	char c = 'R';
	char d = 'd';
	tolower(c);
	toupper(d);
	cout << c << "\n";
	cout << d << "\n";
	
	
}


