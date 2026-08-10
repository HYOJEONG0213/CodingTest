#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double a = 1.2345;
	double div = 0.0;
	double b = modf(a, &div);
	cout << (int)a/1 << " " << b;
}
