#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s, T;
int A[4000004];
ll ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	T.reserve(s.size() * 2 + 1);
	
	T += '#';
	for(char c : s){
		T += c;
		T += '#';
	}
	
	int R = 0, C = 0;	// R : 팰린드롬 가장 오른쪽, C : 팰린드롬 가운데 
	for(int i = 0; i < T.size(); i++){
		if(i < R){
			int mirror = 2*C - i;
			A[i] = min(R-i, A[mirror]);
		}
		else{
			A[i] = 0;
		}
		
		while(i-A[i] - 1 >= 0 && i+A[i]+1 < T.size() && T[i-A[i]-1]==T[i+A[i]+1]){
			A[i]++;
		}
		if(i+A[i] >= R){
			C = i;
			R = i + A[i];
		}
	}
	
	for(int i = 0; i < T.size(); i++){
		ret += (A[i]+1)/2;
	}
	
	cout << ret;
}