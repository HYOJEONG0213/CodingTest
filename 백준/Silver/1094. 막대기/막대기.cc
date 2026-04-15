#include <bits/stdc++.h>
using namespace std;

#define prev pppp

int n = 64, X, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	for(int i = 0; i <=6; i++){
		if(X & (1 << i)) ret++;
	}
	
	
	cout << ret;
}