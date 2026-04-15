#include <bits/stdc++.h>
using namespace std;

string s, target, ret;
stack<char> stk; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	cin >> target;
	
	for(char a : s){
		stk.push(a);
		if(stk.size() < target.size()) continue;
		if(stk.top() == target[target.size()-1]){
			string temp = "";
			for(char i : target){
				temp += stk.top();
				stk.pop();
			}
			reverse(temp.begin(), temp.end());
			
			if(target != temp){
				for(int i : temp) stk.push(i);
			}
		}
	}
	
	if(stk.size() == 0){
        cout << "FRULA\n";
    }
	else{
        while(stk.size()){
            ret += stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end()); 
        cout << ret << "\n";
    }
}