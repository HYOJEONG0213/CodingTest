#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;
int N;
int a, b, ret;
priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		pq.push({a, b});
	}
	
	auto f = pq.top(); 
	pq.pop();
	int left = f.first;
	int right = f.second;
	
	while(pq.size()){
		f = pq.top(); 
		pq.pop();
		a = f.first;
		b = f.second;
		
		if(b < right) continue;
		if(a > right){
			ret += right - left;
			left = a;
			right = b;
			continue;
		}
		if(a <= right && b > right) right = b;
	}
	
	ret += right - left;
	
	cout << ret;
}