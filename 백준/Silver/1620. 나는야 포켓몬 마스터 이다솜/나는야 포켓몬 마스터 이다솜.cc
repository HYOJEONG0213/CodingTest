//맵 하나가지고 찾는건(find) 시간초과나므로 두개를 사용해야한당. O(N)

#include <bits/stdc++.h>
using namespace std;

map <string, int> mp1;
map <int, string> mp2;

int N, M;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> s;
		mp1[s] = i + 1;
		mp2[i+1] = s;
	}
	
	for(int i = 0; i < M; i++){
		cin >> s;
		if(atoi(s.c_str()) != 0 ) { //숫자라면 
			cout << mp2[atoi(s.c_str())] << "\n";
		}
		else{	//문자열이라면 
			cout << mp1[s] << "\n";
		}
	}
	
}