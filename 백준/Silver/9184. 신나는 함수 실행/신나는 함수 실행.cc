#include <bits/stdc++.h>
using namespace std;
int dp[54][54][54], A, B, C;

int go(int a, int b, int c){
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	
	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	
	if(a > 20 || b > 20 || c > 20){
		ret = go(20, 20, 20);
	}
	else if(a < b && b < c){
		ret = go(a, b, c-1) + go(a, b-1, c-1) - go(a, b-1, c);
	}
	else{
		ret = go(a-1, b, c) + go(a-1, b-1, c) + go(a-1, b, c-1) - go(a-1, b-1, c-1);
	}
	
	return ret;
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	
	while(1){
		cin >> A >> B >> C;
		if(A == -1 && B == -1 && C == -1) return 0;
		
		cout << "w(" << A <<", "<<B << ", " << C <<") = " << go(A, B, C) <<"\n";
	}
}