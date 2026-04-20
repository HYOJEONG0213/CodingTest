#include <bits/stdc++.h>
using namespace std;

int A[200004], ret;
string S, T;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	T = "#";
	for(char c: S){
		T += c;
		T += '#';
	}
	
	int R = 0, C = 0; // R : 펠린드롬 맨오른쪽, C : 펠린드롬 가운데  
	
	for(int i = 0; i < T.size(); i++){
		if(i <= R){
			int mirror = 2*C - i;
			A[i] = min(A[mirror], R-i);
		}
		else{
			A[i] = 0;
		}
		
		while(i-1 - A[i] >= 0 && i+1 + A[i] < T.size() && T[i-1-A[i]] == T[i+1+A[i]]){
			A[i]++;
		}
		
		if(i+A[i] > R){
			C = i;
			R = i+A[i];
		}
	}
	
	for(int i = 0; i < T.size(); i++){
		ret = max(ret, A[i]);
	}
	
	cout << ret;
	
}