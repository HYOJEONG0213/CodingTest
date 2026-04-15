#include <bits/stdc++.h>
using namespace std;

long long N, temp, ret;
stack <pair<long, long>> stk;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> temp;
		int cnt = 1;
		
		while(stk.size() && stk.top().first <= temp){
			ret += stk.top().second;
			if(stk.top().first == temp){
				cnt = stk.top().second + 1;
			}
			else{
				cnt = 1;
			}
			stk.pop();
		}
		
		if(stk.size())
			ret++;
		stk.push({temp, cnt});
	}
	
	cout << ret;
}