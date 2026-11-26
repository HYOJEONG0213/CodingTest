#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
int N, arr[500004], ret[500004];
stack <p> stk;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++){
		cin >> arr[i];	
	}
	
	stk.push({arr[0], 1});
	for(int i = 1 ; i < N; i++){
		while(!stk.empty() && stk.top().first < arr[i]){
			stk.pop();
		}
		
		
		if(stk.empty()) {
			stk.push({arr[i], i+1});
			continue;
		}
		
		ret[i] = stk.top().second;
		stk.push({arr[i], i+1});
	}
	
	for(int i = 0 ; i < N; i++){
		cout << ret[i] << " ";
	}
}