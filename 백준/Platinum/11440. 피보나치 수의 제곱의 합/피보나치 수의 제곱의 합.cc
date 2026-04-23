#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, K, dp;
const ll MOD = 1000000007;

struct Matrix{
	ll mat[2][2];
	Matrix(){
		mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
	}
};

Matrix mul(Matrix a, Matrix b){
	Matrix temp;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++)
				temp.mat[i][j] = (temp.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
		}
	}
	return temp;
} 

// 행렬 제곱  
Matrix getNum(Matrix m, ll n){
	Matrix temp;
	// 대각행렬 
	temp.mat[0][0] = 1;
	temp.mat[1][1] = 1;
	
	// 지수 분할정복  
	while(n > 0){
		if(n%2 == 1) temp = mul(temp, m);
		m = mul(m, m);
		n /= 2;
	}
	
	return temp;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	// 피보나치 행렬 거듭제곱 구하기 
	Matrix base;
	base.mat[0][0] = 1;
	base.mat[0][1] = 1;
	base.mat[1][0] = 1;
	base.mat[1][1] = 0;
	
	Matrix ret = getNum(base, N); 
	
	ll fn = ret.mat[0][1];
	ll fn1 = ret.mat[0][0];
	
	cout << (fn*fn1) % MOD;
	
}