#include <bits/stdc++.h>
using namespace std;

extern int g_a = 100;

int f1(){
	return g_a++;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = g_a++;
	cout << a << " " ;
	cout << f1() << " " ;
	cout << f1() << " " ;
	cout << g_a;
}
