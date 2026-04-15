#include <bits/stdc++.h>
using namespace std;

int N, S[24][24], ret = 987654321;
vector <int> v, v2;

void f(){
	int sum1 = 0;
	for(int i : v){
		for(int j : v){
			sum1 += S[i][j];
		}
	}
	
	int sum2 = 0;
	for(int i : v2){
		for(int j : v2){
			sum2 += S[i][j];
		}
	}
	
	
	ret = min(ret, abs(sum1 - sum2));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i =0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> S[i][j];
		}
	}
	
	for(int i =1; i < (1 << N); i++){
		v.clear();
		v2.clear();
		for(int j =0; j < N; j++){
			if((i & (1<<j)) != 0){
				v.push_back(j);
				//cout << i << ": "<< j << "\n";
			}
			else{
				v2.push_back(j);
			}
		}
		
		if(v.size()==N/2){
			f();
		}
	}
	
	cout <<ret;
}