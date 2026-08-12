#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbit bunny";
	string b = "AaBbCcDdEe";
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<char>());
	cout << a << "\n" << b;
}
