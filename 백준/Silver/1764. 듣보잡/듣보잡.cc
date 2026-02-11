#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map <string, int> mp;
vector <string> ret;

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		mp[s]++;
	}
	for(int i = 0; i < M; i++){
		cin >> s;
		if(mp[s]==1) {
			ret.push_back(s);
		}
		mp[s]++;
	}
	
	sort(ret.begin(), ret.end());
	
	cout << ret.size() << "\n";
	for(auto i : ret) cout << i << "\n";
}