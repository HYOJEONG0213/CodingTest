#include <bits/stdc++.h>
using namespace std;

int N, A[800004], ret;
char a;
vector <char> board;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	board.push_back('#');
	for(int i = 0; i < N; i++){
		cin >> a;
		board.push_back(a);
		board.push_back('#');
	}
	int C=0, R=0;	// C : 팰린드롬 중앙, R : 팰린드롬 오른쪽 
	for(int i = 0; i < board.size(); i++){
		if(i <= R){
			int mirror = 2*C - i;
			A[i] = min(A[mirror], R-i);
		}
		else{
			A[i] = 0;
		}
		
		while(i-1-A[i] >= 0 && i+1+A[i] < board.size() && board[i-1-A[i]]==board[i+1+A[i]]){
			A[i]++;
		}
		
		if(i+A[i] == board.size()-1)
			ret = max(ret, A[i]);
		if(R < i+A[i]){
			R = i+A[i];
			C = i;
		}
	}
	
	cout << N - ret;
}