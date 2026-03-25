#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
typedef pair<int,int> pp;
int N, a, b, B[100004], p[500004];
vector <pp> A;
vector <int> ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(B, B+100004, INF);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		A.push_back({b, a});
	}
	sort(A.begin(), A.end());
	
	int n = 0;
 	for(int i = 0; i < N; i++){
		int value = A[i].second;
		auto *iter = lower_bound(B, B+n, value);
		if(*iter == INF){
			n++;
		}
		*iter = value;
		p[value] = (iter-B)+1;
	}
	
	cout << N-n << "\n";
	for(int i = N-1; i >= 0; i--){
		//cout << p[A[i].second] << " ";
		
		if(p[A[i].second]==n){
			n--;
		}
		else{
			ret.push_back(A[i].second);
		}
	}
	
	sort(ret.begin(), ret.end());
	for(int i : ret){
		cout << i << "\n";
	}
}