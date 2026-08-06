#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 0, b = 0;
	int interA = 1, interB = 2;
	for(int i = 0; i < 5; i++){
		a += interA;
		b += interB;
	}
	cout << a << " " << b << "\n";
}
