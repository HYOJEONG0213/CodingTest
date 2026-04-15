#include <bits/stdc++.h>
using namespace std;

int N,ret, l, r;
string s;
stack <int> stk;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	cin >> s;
	
	stk.push(-1);
	for(int i = 0; i < N; i++){
		if(s[i] == '('){
			stk.push(i);
		}
		else if(s[i] == ')'){
			stk.pop();
			if(!stk.size()) {
				stk.push(i);
			}
			
			else{
				int temp = i - stk.top();
				ret = max(temp, ret);
			}
		}
	}
	
	cout << ret;
}