#include <bits/stdc++.h>
using namespace std;

int f(int &x){
	cout << sizeof(x) << "\n";
}

int f2(int *x){
	cout << sizeof(x) << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x = 20;
	f(x);
	f2(&x);
}
