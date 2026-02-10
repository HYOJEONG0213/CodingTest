#include <bits/stdc++.h>
using namespace std;

int N, K;
string a;
set <string> st;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> K;
		// 해당 b에 누적해야함  
		string b = "";
		for(int j = 0; j < K; j++){
			cin >> a;
			b += "*" + a;
			st.insert(b);
		}
	}
	
	for(auto value : st){
		// 몇개의 문자열이 들어가있는가  
		int cnt = count(value.begin(), value.end(), '*');
		// 마지막 string만 추출  
		int pos = value.find_last_of("*");
		string temp = value.substr(pos+1); 
		
		
		for(int depth = 0; depth < cnt-1; depth++) cout << "--";
		cout << temp << "\n";
	}
}