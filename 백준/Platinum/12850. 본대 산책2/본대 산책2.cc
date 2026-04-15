#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 8> Row;
typedef array<Row, 8> Matrix;
const ll MOD = 1000000007;
Matrix A = {{
{0, 1, 1, 0, 0, 0, 0, 0},	//0: 학생회관 
{1, 0, 0, 1, 0, 0, 0, 0},	//1: 형남공학관 
{1, 0, 0, 1, 1, 0, 0, 0},	//2: 진리관  
{0, 1, 1, 0, 1, 1, 0, 0},	//3: 한경 
{0, 0, 1, 1, 0, 1, 1, 0},	//4: 신앙 
{0, 0, 0, 1, 1, 0, 1, 1},	//5: 미래관
{0, 0, 0, 0, 1, 1, 0, 1},	//6: 전산관 
{0, 0, 0, 0, 0, 1, 1, 0}	//7: 정보과학관 
}};

Matrix ret;
int D;

Matrix mul(Matrix &a, Matrix &b){
	Matrix temp;
	for(int i = 0; i < 8; i++) temp[i].fill(0);
	
	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 8; k++){
			if(a[i][k]==0) continue;
			for(int j = 0; j < 8; j++){
				temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	
	return temp;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 8; i++){
		ret[i][i] = 1;
	}
	cin >> D;
	
	while(D > 0){
		if(D%2 == 1){
			ret = mul(ret, A);
		}
		A = mul(A, A);
		D /= 2;
	}
	
	cout << ret[7][7];
}