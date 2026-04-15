#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv, ret = 987654321;

struct A{
	int p, f, s, v, c;
} a[16];

map <int, vector <vector <int>>> ret_list;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for(int i = 0; i < N; i++){
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}
	
	for(int i = 1; i < (1 << N); i++){
		int psum = 0, fsum = 0, ssum = 0, vsum = 0, csum = 0;
		vector <int> v1;
		
		for(int j = 0 ; j < N; j++){
			if(i & (1 << j)) {
				v1.push_back(j + 1);
				psum += a[j].p;
				fsum += a[j].f;
				ssum += a[j].s;
				vsum += a[j].v;
				csum += a[j].c;	
			}
		}
		
		if(psum < mp || fsum < mf || ssum < ms || vsum < mv) continue;
		
		if(ret >= csum){
			ret = csum;
			ret_list[ret].push_back(v1);
		}
	}
	
	if(ret == 987654321) cout << -1;
	else{
		cout << ret <<'\n';
		sort(ret_list[ret].begin(), ret_list[ret].end());
		for(auto i : ret_list[ret][0]) cout << i << " ";
	}
	
	
} 