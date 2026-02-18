#include <bits/stdc++.h>
using namespace std;

int N, ret;

struct Trie{
	map <int, Trie *> next;
	bool isEnd = false;
	
	~Trie(){
		for(auto i : next) delete i.second;
		next.clear();
	}
	
	void insert(const string &s, int index){
		if(s.size() <= index) {
			isEnd = true;
			return;
		}
		
		int current = s[index] - 'a';
		if(!next[current]) next[current] = new Trie();
		next[current] -> insert(s, index+1);
	}
	
	void find(const string &s, int index){
		if(s.size() <= index) return;
		
		int current = s[index] - 'a';
		if(index == 0 || isEnd == true || next.size() >= 2){
			//cout << s << " " << index << "\n";
			ret++;
		}
		
		next[current] -> find(s, index+1);
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(cin >> N){
		//초기화
		string a;
		vector <string> s;
		
		Trie trie;
		ret = 0;
		
		for(int i = 0; i < N; i++){
			cin >> a;
			s.push_back(a);
			trie.insert(s[i], 0);
		}  
		for(int i = 0; i < N; i++){
			trie.find(s[i], 0);
		}  
		//cout << ret << " ";
		cout << fixed << setprecision(2) << (double)ret/N << "\n";
	}
}