#include <bits/stdc++.h>
using namespace std;

class Test{
public:
	Test(string c, string k, string n) : country(c), king(k), name(n){};
	getPrint(){
		cout << country << " " << king << " " << name ;
	}
		
private:
	string country;
	string king;
	string name;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test test("조선", "세조", "이유");
	test.getPrint();
}
