#include <bits/stdc++.h>
using namespace std;

string s;
bool flag = true;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> s;
	for(int i = 0; i < s.size();){
		if(i+1 < s.size() && ((s[i]=='p'&&s[i+1]=='i')) || (s[i]=='k'&&s[i+1]=='a')){
			i+=2;
		}
		else if(i+2 < s.size() && (s[i]=='c'&&s[i+1]=='h'&&s[i+2]=='u')){
			i+=3;
		}
		else{
			flag = false;
			break;
		}
	}
	
	cout << (flag ? "YES" : "NO");
}