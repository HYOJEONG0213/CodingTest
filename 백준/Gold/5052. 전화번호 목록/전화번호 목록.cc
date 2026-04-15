#include <bits/stdc++.h>
using namespace std;

int T, n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	
	
	while(T--){
		string A[10004]={};
		bool flag = true;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		
		sort(&A[0], &A[0]+n);
		for(int i = 0; i < n; i++){
			if(A[i].size() > A[i+1].size()){
				continue;
			}
			
			if(A[i] == A[i+1].substr(0, A[i].size())){
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}