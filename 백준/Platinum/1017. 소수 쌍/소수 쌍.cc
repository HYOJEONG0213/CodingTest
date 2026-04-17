#include <bits/stdc++.h>
using namespace std;

int N, A[54], visited[54], assigned[27];
bool prime[2004];
vector <int> ret, L, R;

void getPrime(){
	fill(prime, prime+2004, true);
	
	for(int i = 2; i <= 2000; i++){
		if(prime[i]==false) continue;
		for(int j = i*2; j <= 2000; j+=i){
			prime[j] = false;
		}
	}
}


// assigned[i] : i번째 R값과 결합된 L의 값 -> R을 매칭시켜야함  
bool f(int l, int r){
	for(int i = 0; i < R.size() ; i++){
		if(i == r) continue;
		
		if(prime[L[l] + R[i]]==false) continue;
		
		if(visited[i]) continue;
		visited[i] = 1;
		
		if(assigned[i]==-1 || f(assigned[i], r)){
			assigned[i] = l;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(assigned, -1, sizeof(assigned));
	getPrime();
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	int temp = A[0] % 2;
	for(int i = 0; i < N; i++){
		if(A[i]%2 == temp){
			L.push_back(A[i]);
		}
		else{
			R.push_back(A[i]);
		}
	}
	
	if(L.size() != R.size()){
		cout << -1;
		return 0;
	}
	
	// i : R의 인덱스, j : L의 인덱스  
	for(int i = 0; i < R.size(); i++){
		if(prime[L[0] + R[i]]==false) continue;
		memset(assigned, -1, sizeof(assigned));
		
		int cnt = 0;
		
		// 첫번째꺼는 이미 했으므로  
		for(int j = 1; j < L.size(); j++){
			memset(visited, 0, sizeof(visited));
			if(f(j, i)) cnt++;
		}
		
		if(cnt == L.size() - 1){
			ret.push_back(R[i]);
		}
	}
	
	if(ret.size()==0){
		cout << -1;
		return 0;
	}
	
	sort(ret.begin(), ret.end());
	
	for(int i : ret){
		cout << i << " ";
	}
}