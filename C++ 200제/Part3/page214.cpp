#include <bits/stdc++.h>
using namespace std;

class Test{
public:
	Test(string c, string k, string n) : country(c), king(k), name(n){};
	Test(int y) : year(y){};
	getName(){
		cout << country << " " << king << " " << name << "\n";
	}
	getYear(){
		cout << year;
	}
		
private:
	string country;
	string king;
	string name;
	int year; 
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test test("조선", "연산군", "이융");
	Test test2(1494);
	test.getName();
	test2.getYear();
}
