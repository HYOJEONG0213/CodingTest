#include <bits/stdc++.h>
using namespace std;

int N, arr[100004], visited[100004];
long long ret;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int end = 0;
	for(int start = 0; start < N; start++){
		int temp = 0;
		if(v.size()){
			temp += v[v.size()-1] - 1;
		}
		if(end == N){
			v.push_back(temp);
			continue;
		}
		for(; end < N; end++){
			if(visited[arr[end]]==0){
				visited[arr[end]]=1;
				temp++;
				continue;
			}
			else if(visited[arr[end]]==1){
				visited[arr[start]]=0;
				v.push_back(temp);
				break;
			}
		}
		if(end == N){
			v.push_back(temp);
		}
		
	}
	
	for(int i : v) {
		ret += i;
		//cout << i << " ";
	}
	
	cout <<ret;
}