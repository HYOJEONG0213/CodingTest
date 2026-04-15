#include <bits/stdc++.h>
using namespace std;

int A, B, isPrime[20];
double p, q, dp[20][20][20];

void makePrime(){
	fill(isPrime, isPrime+20, 1);
	isPrime[0]=0;
	isPrime[1]=0;
	for(int i = 2; i <= 20; i++){
		for(int j = i*2; j <= 20; j+=i){
			isPrime[j] = 0;
		}
	}
}

double go(int idx, int a, int b){
	if(idx==18){
		if(isPrime[a]) return 1;
		if(isPrime[b]) return 1;
		return 0.0;
	}
	double &ret = dp[idx][a][b];
	if(ret >= -0.5f) return ret;
	
	ret = 0.0;
	ret += go(idx+1, a, b) * (1-p) * (1-q);
	ret += go(idx+1, a+1, b) * p * (1-q);
	ret += go(idx+1, a, b+1) * (1-p) * q;
	ret += go(idx+1, a+1, b+1) * p * q;
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	makePrime();
	cin >> A >> B;
	p = A/100.0f;
	q = B/100.0f;
	//cout << p << " " << q <<"\n";
	
	
	cout << fixed << setprecision(7) << go(0,0,0);
}