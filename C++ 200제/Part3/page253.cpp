#include <bits/stdc++.h>
using namespace std;

struct A{
	int x = 0;
};

class B{
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cout << "is_empty" << " ";
	cout << is_empty<A>::value << " ";
	cout << is_empty<B>::value << " ";
	
	cout << "\nis_array ";
	cout << is_array<A>::value << " ";
	cout << is_array<B>:: value << " ";
	cout << is_array<int[3]>::value << " ";
	
	cout << "\nis_same " ;
	cout << is_same<A, B>::value << " ";
	cout << is_same<int, signed int>::value << " ";
	cout << is_same<int, bool>::value << " ";
	cout << is_same<char, unsigned char>::value << " ";
}
