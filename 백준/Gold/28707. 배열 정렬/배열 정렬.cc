#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<int, 14> aa;
typedef pair<ll, aa> pp;
int N, M, l[14], r[14], c[14];
array <int, 14> A;
priority_queue <pp, vector<pp>, greater<pp>> pq;
map <aa, ll> mp;

bool check(array<int, 14> C){
	for(int i = 1; i < N; i++){
		if(C[i] > C[i+1]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	cin >> M;
	for(int i = 1; i <= M; i++){
		cin >> l[i] >> r[i] >> c[i];
	}
	
	mp[A] = 0;
	
	pq.push({0, A});
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		ll herecost;
		aa B;
		tie(herecost, B) = f;
		
		if(check(B)==true){
			cout << herecost;
			return 0;
		}
		
		if(mp[B] < herecost) continue;
		
		//i : 이번에 선택, j : 이전값 
		for(int i = 1; i <= M; i++){
			aa tempB = B;
			swap(tempB[l[i]], tempB[r[i]]);
			ll next = herecost + c[i];
			
			if(mp[tempB]==0 || mp[tempB] > next){
				mp[tempB] = next;
				pq.push({herecost+c[i], tempB});
			}
		}
	}
	
	cout << "-1";
}