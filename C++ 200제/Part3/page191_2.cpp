#include <bits/stdc++.h>
using namespace std;

struct Test1{
	string data1;
	struct Test2{
		string data1;
		string data2;
	}t;
} ;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Test1 t1 = {"Åä³¢", {"°í¾çÀÌ", "µÅÁö"}};
	Test1 t2 = {"a", "b", "c"};
	
	cout << t1.data1 << " " << t1.t.data1 << " " << t1.t.data2 << "\n";
	cout << t2.data1 << " " << t2.t.data1 << " " << t2.t.data2;
}
