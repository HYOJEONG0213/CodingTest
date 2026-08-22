#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f1(T a, T b, T c = 1){
	cout << a+b+c << "\n";
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	f1(1,2);
	f1(1,2,3);
	f1(1.1, 2.2);
	f1(1.1, 2.2, 3.3);
}
