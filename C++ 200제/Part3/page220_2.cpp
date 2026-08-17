#include <bits/stdc++.h>
using namespace std;

class Test1{
public:
	Test1() {
		cout << "생성자 호출 \n" ;
	}
	~Test1(){
		cout << "소멸자 호출";
	}
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 *test = new Test1();
	delete test;
	test = nullptr;
}
