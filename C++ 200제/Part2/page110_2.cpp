#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str = "1.2345";
	int idx = str.find(".");
	string a = str.substr(0, idx);
	string b = str.substr(idx+1, str.size());
	cout << a << " " << b;
}
