#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
string f(T1 x, T2 y){
	typename conditional<is_same<T1, T2>::value, int, double>::type type1;
	
	return typeid(type1).name();
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string a = f(1, 233.3);
	if(a=="d"){
		cout << "doubleÀÓ";
	}
	else{
		cout << "doubleÀÌ ¾Æ´Ô";
	}
}
