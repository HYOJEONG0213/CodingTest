#include <bits/stdc++.h>
using namespace std;

int A, B, C, num;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	cin >> C;
	B += C%60;
	if(B > 59){
		num += B / 60;
		B %= 60;
	}
	A += C/60 + num;
	while(A > 23){
		A -= 24;
	}
	
	cout << A << " " << B;
}