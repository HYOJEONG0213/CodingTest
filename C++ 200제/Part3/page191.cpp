#include <bits/stdc++.h>
using namespace std;

struct Test1{
	struct Test2{
		Test2(int x) : innerData(x){}
		
		int innerData;
	};
	
	Test1(int x) : data(x){}
	
	Test2 test2{10};
	int data;
} ;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 test1(20);
	cout << test1.test2.innerData << " " << test1.data;
}
