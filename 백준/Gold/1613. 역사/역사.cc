#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, s, visited[404], dict[404][404];


void show(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dict[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dict, -1, sizeof(dict));
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		dict[b][a] = 1;
	}
	
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dict[i][k]!=-1&&dict[k][j]!=-1 && dict[i][j] < dict[i][k]+dict[k][j]){
					dict[i][j] = dict[i][k]+dict[k][j];
				}
			}
		}
	}
	
	//show();
	
	
	cin >> s;
	for(int i = 0; i < s; i++){
		cin >> a >> b;
		
		if(dict[a][b] > -1){
			cout << "1\n";
		}
		else{
			if(dict[b][a] != -1){
				cout << "-1\n";
			}
			else{
				cout << "0\n";
			}
		}
	}
}