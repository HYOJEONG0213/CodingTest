#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	tuple <string, int, double> t;
	t = make_tuple("¹®ÀÚ¿­", 10, 1.2);
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	
}
