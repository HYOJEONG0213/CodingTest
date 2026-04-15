#include <bits/stdc++.h>
using namespace std;

int ret, a[54], N, K;
string s;

int check(int num){
	int cnt = 0; 
	
	for(int i = 0; i < N; i++){
		if(!a[i]) break;
		if(a[i] == (a[i] & num)){
			cnt++;
		}
	}
	
	return cnt;
}

void go(int idx, int num, int cnt){
	if(cnt > K) return;
	
	if(idx == 26){
		ret = max(ret, check(num));
		return;
	}
	
	
	go(idx+1, num | (1 << idx), cnt+1);
	if(idx != (int) 'a'-'a' && idx != (int) 'n'-'a' 
	&& idx != (int) 't'-'a' && idx != (int) 'i'-'a'
	&& idx != (int) 'c'-'a'){
		go(idx+1, num, cnt);
	}
	
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			int idx = (int) s[j] - 'a';
			a[i] |= 1 << idx;
		}
	}
	
	go(0, 0, 0);
	
	cout << ret;
	
}