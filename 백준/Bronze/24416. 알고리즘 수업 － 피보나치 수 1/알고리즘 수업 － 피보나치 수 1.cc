#include <bits/stdc++.h>
using namespace std;
int N, dp[44], cnt1, cnt2;

int fibo1(int N){
	if(N == 1 || N == 2) return 1;
	cnt1++;
	
	return fibo1(N-2) + fibo1(N-1);
}

int fibo2(int N){
	if(N == 1 || N == 2) return 1;
	int &ret = dp[N];
	if(ret != 0) return ret;
	cnt2++;
	
	return ret = fibo2(N-1) + fibo2(N-2);
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	//깡
	int a = fibo1(N);
	//cout << a << " ";
	cout << cnt1 +1 << " "; 
	//DP
	int b = fibo2(N);
	//cout << b << " "; 
	cout << cnt2 ;
}