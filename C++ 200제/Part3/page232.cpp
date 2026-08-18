#include <bits/stdc++.h>
using namespace std;

class King{
public:
	string country;
	string name;
	int year;
};

class SubKing : King{
public:
	void SetValue(string c, string n, int y) {
		country = c;
		name = n;
		year = y; 
	}
	void GetValue(){
		cout << country << " " << name << " " << year << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	SubKing sub1;
	sub1.SetValue("고조선", "단군왕검", 2333);
	SubKing sub2;
	sub2.SetValue("고려", "충해왕", 1330);
	
	sub1.GetValue();
	sub2.GetValue();
	
}
