#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
set <string> st;
vector <string> ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		st.insert(s);
	}
	for(int i = 0; i < M; i++){
		cin >> s;
		if(st.find(s) != st.end()) {
			ret.push_back(s);
		}
	}
	
	sort(ret.begin(), ret.end());
	
	cout << ret.size() << "\n";
	for(auto i : ret) cout << i << "\n";
}