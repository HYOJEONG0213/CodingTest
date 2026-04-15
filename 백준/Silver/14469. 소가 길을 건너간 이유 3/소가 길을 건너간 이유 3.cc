#include <bits/stdc++.h>
using namespace std;

int N, start, during, ret;
vector <pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i =0;i<N;i++){
		cin >> start >> during;
		v.push_back({start, during});
	}
	
	//day순 오름차순 
	sort(v.begin(), v.end());
	
	for(auto i : v){
		if(ret >= i.first){
			ret += i.second;
		}
		else if(ret < i.first){
			ret = i.first + i.second;
		}
	}
	
	cout << ret;
}