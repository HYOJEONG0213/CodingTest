#include <bits/stdc++.h>
using namespace std;

int N, K;
char a;
string st[1004];

struct Trie{
	map<string, Trie *> next;
	
	~Trie(){
		for(auto i : next){
			if(i.second != nullptr) delete i.second;
		}
	}
	
	//trie 
	void insert(const vector <string> & now, int index){
		if(index >= now.size()) return;
		
		auto current = next.find(now[index]);
		if(current == next.end()){
			next[now[index]] = new Trie();
		}
		next[now[index]]->insert(now, index+1);
	}
	
	//dfs
	void find(int depth){
		for(auto n : next){
			// depth 깊이별로 탐색  
			for(int i = 0; i < depth; i++){
				cout << "--";
			}
			cout << n.first << "\n";
			n.second -> find(depth+1);
		}
	}

};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Trie * trie = new Trie();
	for(int i = 0; i < N; i++){
		cin >> K;
		vector <string> ch(K) ;
		for(int j = 0; j < K; j++){
			cin >> ch[j];
		}
		trie->insert(ch, 0);
	}
	
	trie->find(0);
}