#include <bits/stdc++.h>
using namespace std;

string s;
int N;
map <string, int> mp;

struct Trie{
	map <char, Trie *> next;
	
	void Insert(string s, int index, vector <char> &v, bool flag){
		if(s.size() <= index) 
		{
			if(flag == false) return;
			for(auto i: v) cout << i;
			cout << "\n";
			return;
		}
		
		char current = s[index];
		v.push_back(s[index]);
		if(next[current] == 0){
			if(flag == true){
				for(auto i : v) cout << i;
				cout << "\n";
				flag = false;
			}
			next[current] = new Trie();
		}
		next[current]->Insert(s, index+1, v, flag);
	} 
};



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Trie trie;
	for(int i = 0; i < N; i++){
		cin >> s;
		mp[s]++;
		if(mp[s] >= 2){
			cout << s << mp[s] << "\n";
		}
		else{
			vector <char> v;
			trie.Insert(s, 0, v, true);
		}
	}
}