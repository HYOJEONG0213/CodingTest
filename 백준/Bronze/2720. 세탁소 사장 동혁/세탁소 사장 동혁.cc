#include <bits/stdc++.h>
using namespace std;

int T, C, ret[4];
vector <int> v = {25, 10, 5, 1};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		memset(ret, 0, sizeof(ret));
		cin >> C;
		for(int i = 0; i < 4; i++){
			ret[i] = C / v[i];
			C -= v[i]*ret[i];
		}
		for(int i = 0; i < 4; i++){
			cout << ret[i] << " ";
		}
		cout << "\n";
	}
}