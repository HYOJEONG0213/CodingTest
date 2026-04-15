#include <bits/stdc++.h>
using namespace std;

string a, b;
int N, M, lcs[1004][1004];
vector <char> ret;

void trace(){
	int i = N;
	int j = M;
	while(i > 0 && j > 0){
		if(a[i-1]==b[j-1]){
			ret.push_back(a[i-1]);
			i--; j--;
		}
		else{
			if(lcs[i-1][j] > lcs[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	N = a.size();
	M = b.size();
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(a[i-1]==b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	cout << lcs[N][M] << "\n";
	trace();
	for(int i = ret.size()-1; i >= 0; i--){
		cout << ret[i];
	}
}