#include <bits/stdc++.h>
using namespace std;

int f(int &x){
	x += 10;
	cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x = 20;
	cout << x << "\n"; 
	f(x);
	cout << x << "\n";
}
