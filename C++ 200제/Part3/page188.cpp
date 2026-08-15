#include <bits/stdc++.h>
using namespace std;

struct Test1{
	Test1(int x) : data(x){}
	int data;
} ;

struct Test2{
	Test2(){
		data = 20;
	}
	int data;
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 test1(10);
	Test2 test2;
	cout << test1.data << " " << test2.data;
	
}
