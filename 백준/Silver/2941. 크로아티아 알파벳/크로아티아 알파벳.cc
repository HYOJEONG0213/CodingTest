#include <bits/stdc++.h>
using namespace std;
string s;
int ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	int i = 0;
	while(i < s.size()){
		if(i+1<s.size() && s[i]=='c' && (s[i+1]=='=' || s[i+1]=='-')){
			ret++;
			i+=2;
		}
		else if(i+2 < s.size() && s[i]=='d' && s[i+1]=='z' && s[i+2]=='='){
			ret++;
			i+=3;
		}
		else if(i+1 < s.size() && s[i]=='d' && s[i+1]=='-'){
			ret++;
			i+=2;
		}
		else if(i+1 < s.size() && s[i]=='l' && s[i+1]=='j'){
			ret++;
			i+=2;
		}
		else if(i+1 < s.size() && s[i]=='n' && s[i+1]=='j'){
			ret++;
			i+=2;
		}
		else if(i+1 < s.size() && s[i]=='s' && s[i+1]=='='){
			ret++;
			i+=2;
		}
		else if(i+1 < s.size() && s[i]=='z' && s[i+1]=='='){
			ret++;
			i+=2;
		}
		else{
			ret++;
			i++;
		}
	}
	cout << ret;
}