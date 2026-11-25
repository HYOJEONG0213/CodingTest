#include <bits/stdc++.h>
using namespace std;

int N;
string channel[104], ret;

// 1 : 한칸아래, 2 : 한칸 위로, 3 : 다음칸과 순서변환, 4 : 전칸과 순서변환  

void f(string s, int sub){
	int idx = 0;
	for(; idx < N; idx++){
		if(channel[idx] == s) break;
	}
	
	for(int i = 0; i < idx; i++) ret += "1";
	for(int i = idx; i > sub; i--) {
		swap(channel[i-1], channel[i]);
		ret += "4";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> channel[i];
	
	f("KBS1", 0);
	f("KBS2", 1);
	
	cout << ret;
}