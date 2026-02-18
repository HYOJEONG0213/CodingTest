#include <bits/stdc++.h>
using namespace std;

int N, ret;

struct Trie;
vector <Trie> nodes;


struct Trie{
	int next[30];
	bool isEnd;
	int cnt;
	
	Trie(){
		memset(next, -1, sizeof(next));
		isEnd = false;
		cnt = 0;
	}
	
	
	static void insert(int node_idx, const string &s, int index){
		if(s.size() <= index) {
			nodes[node_idx].isEnd = true;
			return;
		}
		
		int current = s[index] - 'a';
		if(nodes[node_idx].next[current]==-1) {
			//벡터 마지막 인덱스에 할당  
			nodes[node_idx].next[current] = nodes.size();
			nodes.push_back(Trie());
			nodes[node_idx].cnt++;
		}
		insert(nodes[node_idx].next[current], s, index+1);
	}
	
	static void find(int node_idx, const string &s, int index){
		if(s.size() <= index) return;
		
		int current = s[index] - 'a';
		if(index == 0 || nodes[node_idx].isEnd == true || nodes[node_idx].cnt >= 2){
			//cout << s << " " << index << "\n";
			ret++;
		}
		
		find(nodes[node_idx].next[current], s, index+1);
	}
};



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(cin >> N){
		//초기화
		string a;
		vector <string> s;
		nodes.clear();
		nodes.push_back(Trie());
		
		Trie trie;
		ret = 0;
		
		for(int i = 0; i < N; i++){
			cin >> a;
			s.push_back(a);
			Trie::insert(0, s[i], 0);
		}  
		for(int i = 0; i < N; i++){
			Trie::find(0, s[i], 0);
		}  
		//cout << ret << " ";
		cout << fixed << setprecision(2) << (double)ret/N << "\n";
	}
}