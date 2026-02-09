#include <bits/stdc++.h>
using namespace std;

int a, N, M, dp[104][104];
vector <int> A, B, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> a;
		A.push_back(a);
	}
	cin >> M;
	for(int i = 1; i <= M; i++){
		cin >> a;
		B.push_back(a);
	}
	
	
	int i = 0, j = 0;
	while(max_element(A.begin()+i, A.end()) != A.end()){
		auto Aiter = max_element(A.begin()+i, A.end());
		auto Biter = find(B.begin()+j, B.end(), *Aiter);
		if(Biter != B.end()){
			ret.push_back(*Biter);
			i = Aiter - A.begin();
			j = Biter - B.begin() + 1;
		}
		
		A.erase(A.begin() + (Aiter - A.begin()));
		continue;
	}
	
	
	cout << ret.size() << "\n";
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << " ";
	} 
}