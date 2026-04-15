#include <bits/stdc++.h>
using namespace std;

string A, B;
int lcs[1004][1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	for(int i = 1; i <= A.size(); i++){
		for(int j = 1; j <= B.size(); j++){
			if(A[i-1]==B[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	cout << lcs[A.size()][B.size()];
}