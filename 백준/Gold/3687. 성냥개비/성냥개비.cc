#include <bits/stdc++.h>
using namespace std;
int T, a;
const string INF = "999999999999999";
//dp[성냥깨비 개수]로 만들 수 있는 최대/최소 숫자  
string dp1[110], dp2[110];
map <int, string> m1, m2;

void init(){
	m1[2] = "1";	m1[3] = "7";	m1[4] = "4"; 
	m1[5] = "2"; 	m1[6] = "0";	m1[7] = "8";
	
	m2[2] = "1"; 	m2[3] = "7";	m2[4] = "4";
	m2[5] = "5";	m2[6] = "9";	m2[7] = "8";
}

string swapNum(string st){
	for(int i = 1; i < st.size(); i++){
		if(st[i] - '0' != 0){
			swap(st[0], st[i]);
			return st;
		}
	}
	
	st[0] = '6';
	return st;
}

string convert(string st){
	for(int i = 1; i < st.size(); i++){
		if(st[i] == '6')
			st[i] = '0';
	}
	
	return st;
}

void small(int N){
	for(int j = 2; j <= 7; j++){
		dp1[j] = m1[j];	
	}
	dp1[6] = "6";
	
	for(int i = 2; i <= N; i++){
		for(int j = 2; j <= 7; j++){
			if(i+j > N) break;
			string temp = dp1[i] + m1[j];
			sort(temp.begin(), temp.end()); 
			if(temp[0]=='0') temp = swapNum(temp);
			temp = convert(temp);
			//cout << temp << "\n";
			
			if(dp1[i+j].size() > temp.size()) {
				dp1[i+j] = temp;
			}
			else if(atoll(dp1[i+j].c_str()) > atoll(temp.c_str())){
				dp1[i+j] = temp;
			}
		}
	}
}

void big(int N){
	dp2[2] = "1"; dp2[3] = "7"; dp2[4] = "11";
	dp2[5] = "71"; dp2[6] = "111"; dp2[7] = "711"; dp2[8] = "1111";
	
	for(int i = 2; i <= N; i++){
		for(int j = 2; j <= 7; j++){
			if(i+j > N) break;
			string temp = dp2[i] + m2[j];
			sort(temp.rbegin(), temp.rend());
			//cout << temp << "\n";
			
			if(dp2[i+j].size() < temp.size()) dp2[i+j] = temp;
			else if(atoll(dp1[i+j].c_str()) < atoll(temp.c_str())){
				dp2[i+j] = temp;
			}
		}
	}

}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	fill(dp1, dp1+110, INF);
	fill(dp2, dp2+110, "0");
	small(100);
	big(100);
	
	cin >> T;
	while(T--){
		cin >> a;
		cout << dp1[a] << " " << dp2[a] << "\n";
	}
}