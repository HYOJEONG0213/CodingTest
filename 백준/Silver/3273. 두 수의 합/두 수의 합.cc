#include <bits/stdc++.h>
using namespace std;

int N, a, X, ret;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a;
		v.push_back(a);
	}
	cin >> X;
	
	sort(v.begin(), v.end());
	int start = 0;
	int end = v.size()-1;
	while(start < end){
		if(v[start]+v[end] < X) 
			start++;
		else if(v[start]+v[end] > X)
			end--;
		else if(v[start]+v[end]==X){
			ret++;
			end--;
		}
	}
	
	cout << ret;
}