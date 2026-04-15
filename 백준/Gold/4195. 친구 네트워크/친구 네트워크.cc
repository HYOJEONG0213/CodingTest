#include <bits/stdc++.h>
using namespace std;

int T, F, num=1;
const int MAX = 200004;
string target, a, b;
int level[MAX];
int p[MAX];
unordered_map <string, int> mp;

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(level[x] > level[y]){
		level[x]+=level[y];
		p[y] = x;
	}
	else{
		level[y]+=level[x];
		p[x] = y;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> F;
		memset(p, -1, sizeof(p));
		fill(level, level+MAX, 1);
		mp.clear();
		
		for(int i = 0; i < F; i++){
			cin >> a >> b;
			// 인덱스 부여하기  
			if(mp[a]==0) mp[a] = num++;
			if(mp[b]==0) mp[b] = num++;
			
			merge(mp[a], mp[b]);
			
			cout <<level[find(mp[a])]<< "\n";
		}
	}
}