#include <bits/stdc++.h>
using namespace std;

class Test1{
public:
	Test1() {
		arr = new int;
		arr2 = new int[3];
	}
	~Test1(){
		delete arr;
		delete [] arr2;
	}
	
	int * arr; 
	int * arr2;
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 *test = new Test1();
	delete test;
	test = nullptr;
}
