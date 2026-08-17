#include <bits/stdc++.h>
using namespace std;

class Test1{
public:
	Test1() = default;
	void getNum(){
		cout << a << " " << b << "\n";
	}
		
private:
	int a;
	double b;
};

class Test2{
public:
	Test2() {};
	void getNum(){
		cout << a << " " << b;
	}
		
private:
	int a;
	double b;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//Test1 *test1 = new Test1();
	Test1 test1 {};
	Test2 *test2 = new Test2();
	test1.getNum();
	test2->getNum();
}
