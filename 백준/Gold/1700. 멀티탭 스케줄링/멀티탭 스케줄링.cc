#include <bits/stdc++.h>
using namespace std;

int N, K, a[104], visited[104], ret;
vector <int> v;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		cin >> a[i];
	}
	for(int i = 0; i < K; i++){
		if(visited[a[i]] == 0){
			if(v.size() == N){
				int last = 0, pos;
				for(int _v : v){
					int here = 987654321;
					int j;
					for(j = i + 1; j < K; j++){
						if(_v == a[j]){
							here = j;
							break;
						}
					}
					
					//가장 가까운놈은 삭제안되게 작업하는거임 
					if(last < here){
						last = here;
						pos = _v;
					}
				}
				
				visited[pos] = 0;
				v.erase(find(v.begin(), v.end(), pos));
				ret++;
			}
			
			
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}

	cout << ret;
}