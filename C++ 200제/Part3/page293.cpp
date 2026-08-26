#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	auto t1 = 1;
	decltype (t1) t2 = 2;
	
	auto t3 = 3.4;
	decltype (t2 + t3) t4 = 3;
	
	cout << typeid(t1).name() << " " << typeid(t2).name() << " " << typeid(t3).name() << " " << typeid(t4).name() << "\n" ;
	
}
