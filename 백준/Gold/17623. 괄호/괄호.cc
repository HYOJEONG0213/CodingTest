#include <bits/stdc++.h>
using namespace std;

int T, N;
string dp[1004];

//두 string 중 작은 거 return  
string comp(string a, string b){
	if(a.size() > b.size()) return b;
	else if(a.size() < b.size()) return a;
	
	if(a > b) return b;
	else if(a < b) return a;
	
	return a;
}


string makeStr(string a, string b){
	return comp(a+b, b+a);
}

void init(){
	fill(dp, dp+1004, "9999999999999999999999999999999999999999999999"); 
	dp[0] = "";
	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";
	
	for(int i = 1; i <= 1000; i++){
		string temp = makeStr("1"+dp[i/2]+"2", dp[i%2]);
		dp[i] = comp(temp, dp[i]);
		temp = makeStr("3"+dp[i/3]+"4", dp[i%3]);
		dp[i] = comp(temp, dp[i]);
		temp = makeStr("5"+dp[i/5]+"6", dp[i%5]);
		dp[i] = comp(temp, dp[i]);
		
		for(int j = i; j <= 1000; j++){
			dp[j] = comp(dp[j], makeStr(dp[j-i], dp[i]));
		}
	}
	
	
	
//	for(int i = 1; i <= 6; i++){
//		cout << dp[i] << "*\n";
//	}
	//cout << dp[30] << " " << dp[33] <<"*\n";
}



int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	init();
	
	cin >> T;
	while(T--){
		cin >> N;
		for(char i : dp[N]){
			int j = i - '0';
			switch(j){
				case 1:
					cout << "(";
					break;
				case 2:
					cout << ")";
					break;
				case 3 : 
					cout << "{";
					break;
				case 4 : 
					cout << "}";
					break;
				case 5:
					cout << "[";
					break;
				case 6:
					cout << "]";
					break;
			}
		}
		cout <<"\n";
	}	

}