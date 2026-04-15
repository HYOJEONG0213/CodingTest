#include <bits/stdc++.h>
using namespace std;

int T, N, M, a;
vector <int> v;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		v.clear();
		
		cin >> N;
		for(int i = 0 ; i < N ; i ++){
			cin >> a;
			v.push_back(a);
		}
		
		sort(v.begin(), v.end());
		cin >> M;
		for(int i = 0 ; i < M; i++){
			cin >> a;
			auto temp = lower_bound(v.begin(), v.end(), a) ;
			if(temp == v.end()){
				cout << "0\n";
				continue;;
			}
			if(*temp == a) cout << "1\n";
			else cout << "0\n";
		}
	}
}