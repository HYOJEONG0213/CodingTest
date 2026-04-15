#include <bits/stdc++.h>
using namespace std;

string s;
map <int,int> mp;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 26; i++){
		mp[i] = -1;
	}
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(mp[s[i]-'a']==-1)
			mp[s[i]-'a'] = i;
	}
	
	for(int i = 0; i < 26; i++){
		cout << mp[i] << " ";
	}
}