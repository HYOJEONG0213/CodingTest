#include <bits/stdc++.h>
using namespace std;

string s;
int N;

struct Trie{
	int cnt = 0; 	// 끝나는 문자열의 수  
	Trie *next[26]{};
	
	string Insert(string s, int index){
		if(s.size() <= index) {
			// 문자열이 이미 있는곳까지 왔다면..... 
			return (++cnt == 1 ? s : s+to_string(cnt));
		}
		
		char current = s[index] - 'a';
		if(next[current] == 0){
			next[current] = new Trie();
			next[current] -> Insert(s, index+1);
			return s.substr(0, index+1);
		}
		return next[current]->Insert(s, index+1);
	} 
};



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Trie trie;
	for(int i = 0; i < N; i++){
		cin >> s;
		cout << trie.Insert(s, 0) << "\n";
	}
}