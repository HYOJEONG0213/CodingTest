#include <bits/stdc++.h>
using namespace std;

int N, ret[54], a;
map <int, int> mp;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a;
		mp[a]++;
	}
	
	int idx = 0;
	while(idx < N){
		for(int j = 0; j <= 1000; j++){
			if(mp[j]==0) continue;
			
			// 바로다음 숫자가 있다면 징검다리 있는지 확인  
			if(mp[j+1] > 0){
				int z= j+2;
				while(z <= 1000 && mp[z]==0) z++;
				if(z <= 1000){	// 대체가능  
					while(mp[j] > 0){
						ret[idx++] = j;
						mp[j]--;
					}
					ret[idx++] = z;
					mp[z]--;
					break;
				}
				else{	//대체 불가능  
					while(mp[j+1] > 0){
						ret[idx++] = j+1;
						mp[j+1]--;
					}
					break;
				}
			}
			// 바로 다음 숫자 없는 경우  
			else{
				while(mp[j] > 0){
					ret[idx++] = j;
					mp[j]--;
				}
				break;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << ret[i] << " ";
	}
}