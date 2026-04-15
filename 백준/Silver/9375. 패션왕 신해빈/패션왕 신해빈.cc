#include <bits/stdc++.h>
using namespace std;

int m, n;
string name, type;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> m;
		map <string, int> _map;

		for (int j = 0 ; j < m; j++){
			cin >> name >> type;
			_map[type] ++;
		}
		
		//경우의 수는 long long으로 해야함. 숫자가 커질수 있으니! 
		long long ret = 1;
		for(auto c: _map){
			ret *= (long long) c.second + 1;
		}
		ret --; //아무것도 안입는경우  
		cout << ret << "\n";
	}
	
}