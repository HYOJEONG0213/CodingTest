#include <bits/stdc++.h>
using namespace std;

struct Test1{
	int data;
} ;

struct Test2{
	Test1 test1;
	int data;
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 test1;
	Test2 test2 {test1, 20};
	cout << test2.test1.data << " " << test2.data;	
}
