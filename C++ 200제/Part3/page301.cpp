#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	tuple <string, int, double> t;
	t = make_tuple("문자열", 10, 1.2);
	
	tuple <int, double, string> t2;
	t2 = make_tuple(20, 2.2, "토끼");
	
	auto t3 = tuple_cat(t, t2);
	
	cout << sizeof(t) << " " << sizeof(t2) << " " << sizeof(t3);
}
