#include <bits/stdc++.h>
using namespace std;

int R[1004], a, b, ret, K, T;
string s;
vector <int> v[1004];

void show(){
	for(int i = 0; i< T; i++){
		for(int j : v[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
}

void rotate(int idx){
	if(R[idx] == -1){
		rotate(v[idx].begin(), v[idx].begin()+1, v[idx].end());
	} 
	else{
		rotate(v[idx].rbegin(), v[idx].rbegin()+1, v[idx].rend());
	}
}

void go(int idx){
	vector <int> temp;
	temp.push_back(idx);
	for(int i = idx-1; i >= 0; i--){
		if(R[i+1] == 0) break;
		if(v[i][2] == v[i+1][6]) break;
		R[i] = -R[i+1];
		temp.push_back(i);
	}
	for(int i = idx+1; i < T ; i++){
		if(R[i-1] == 0) break;
		if(v[i][6] == v[i-1][2]) break;
		R[i] = -R[i-1];
		temp.push_back(i);
	}
	
	for(int i : temp)
		rotate(i);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> s;
		for(int j = 0; j < 8; j++){
			v[i].push_back(s[j] - '0');
		}
	}
	cin >> K;
	for(int i=0; i < K; i++){
		memset(R, 0, sizeof(R));
		cin >> a >> b;
		a--;
		R[a] = b;
		go(a);
		//show();
	}
	
	for(int i = 0; i < T ; i++){
		if(v[i][0] == 1) ret++;
	}
	
	cout << ret;
}