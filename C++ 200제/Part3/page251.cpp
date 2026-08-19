#include <bits/stdc++.h>
using namespace std;

enum A{
};
enum class B{
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cout << "is_integral : ";
	cout << is_integral<A>::value << " ";
	cout << is_integral<B>::value << " ";
	cout << is_integral<signed int>::value << " ";
	cout << is_integral<unsigned int>::value << " ";
	cout << is_integral<double>::value << " ";
	cout << is_integral<bool>::value << " ";
	
	cout << "\nis_enum : ";
	cout << is_enum<A>::value << " ";
	cout << is_enum<B>::value << " ";
	cout << is_enum<signed int>::value << " ";
	cout << is_enum<unsigned int>::value << " ";
	cout << is_enum<double>::value << " ";
	cout << is_enum<bool>::value << " ";
	
	cout << "\nis_signed : ";
	cout << is_signed<A>::value << " ";
	cout << is_signed<B>::value << " ";
	cout << is_signed<signed int>::value << " ";
	cout << is_signed<unsigned int>::value << " ";
	cout << is_signed<double>::value << " ";
	cout << is_signed<bool>::value << " ";
	
	cout << "\nis_unsigned : ";
	cout << is_unsigned<A>::value << " ";
	cout << is_unsigned<B>::value << " ";
	cout << is_unsigned<signed int>::value << " ";
	cout << is_unsigned<unsigned int>::value << " ";
	cout << is_unsigned<double>::value << " ";
	cout << is_unsigned<bool>::value << " ";
}
