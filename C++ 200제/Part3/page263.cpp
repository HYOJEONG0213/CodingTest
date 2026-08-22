#include <bits/stdc++.h>
using namespace std;

void sum(int arg, ...){
	int sum = 0;
	va_list v;
	va_start(v, arg);
	for(int i = 0; i < arg; i++){
		sum += va_arg(v, int);
	}
	va_end(v);
	
	cout << sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	sum(5,1,2,3,4,5);
}
