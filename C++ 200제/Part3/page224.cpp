#include <bits/stdc++.h>
using namespace std;

static class Test1{
public:
	Test1() {
		a = 10;
	}
	void sum(){
		a++;
	}
	
	static int a;
} test;

int Test1::a = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << test.a << "+1 = " ;
	test.sum();
	cout << test.a;
}
