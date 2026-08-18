#include <bits/stdc++.h>
using namespace std;

class Object{
protected:
	void Test1(){
		cout << "물건을 가진다!" << "\n";
	}
};

class Human : public Object{
public:
	void Test2(){
		cout << "사람이" << "\n";
		Test1();
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Human man;
	man.Test2();
}
