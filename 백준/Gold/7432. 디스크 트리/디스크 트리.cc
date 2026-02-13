#include <bits/stdc++.h>
using namespace std;

int N;
string s;

vector <string> split(string input, string delimiter){
	vector <string> ret;
	auto start = 0;
	auto end = input.find(delimiter);
	while(end != string::npos){
		ret.push_back(input.substr(start, end-start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	ret.push_back(input.substr(start));
	
	return ret;
}

struct Trie{
	map <string, Trie *> next;
	
	void insert(vector <string> &v, int index){
		if(v.size() <= index) return;
		
		auto current = next.find(v[index]);
		//발견 못했다면  
		if(current == next.end()){
			next[v[index]] = new Trie();
		}
		next[v[index]] -> insert(v, index+1);
	}
	
	void dfs(int index){
		for(auto i : next){
			for(int i = 0; i < index; i++) cout << " ";
			cout << i.first << "\n";
			i.second->dfs(index+1);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Trie trie;
	for(int i = 0; i < N; i++){
		cin >> s;
		vector <string> v = split(s, "\\");
		trie.insert(v, 0);
	}
	trie.dfs(0);
}