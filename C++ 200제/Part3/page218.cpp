#include <bits/stdc++.h>
using namespace std;

class Test1{
public:
	Test1() : a(10), b(3.14), c("Rabbbbbbbbbit"){};
	void getNum(){
		cout << a << " " << b << " " << c;
	}
		
private:
	int a;
	double b;
	string c;
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 test;
	test.getNum();
}
