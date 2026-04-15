#include <bits/stdc++.h>
using namespace std;

int dice[14], pos[4], ret, visited[104], v[104];
vector <int> adj[54];

void add(int a, int b){
	adj[a].push_back(b);
}

void setmap(){
	for(int i = 0; i < 20; i++) add(i, i+1);
	add(5,21); add(21,22);	add(22,23); add(23,24);
	add(10,27); add(27,28); add(28,24);
	add(15,29); add(29,30); add(30,31); add(31,24);
	add(24,25); add(25,26); add(26,20);
	add(20, 100);
	
	for(int i = 1; i <= 20; i++){
		v[i] = i * 2;
	}
	v[21]=13; v[22]=16; v[23]=19; v[24]=25; v[25]=30; v[26]=35;
	v[27]=22; v[28]=24; v[29]=28; v[30]=27; v[31]=26; v[100]=0;	
}

int move(int here, int cnt){
	if(here==100) return 100;
	
	if(adj[here].size()>=2){
		here = adj[here][1];
		cnt--;
	}
	
	while(cnt > 0){
		if(here==100) break;
		
		here = adj[here][0];
		cnt--;
	}
	return here;
}

bool check(int nx, int idx){
	if(nx==100) return false;
	
	for(int i = 0; i < 4; i++){
		if(i == idx) continue;
		if(pos[i] == nx) return true;
	}
	
	return false;
}

void dfs(int idx, int sum){
	if(idx==10){
		ret = max(sum, ret);
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int temp_idx = pos[i];
		int nx = move(temp_idx, dice[idx]);
		
		if(check(nx, i)) continue;
		//if(nx != 100 && visited[nx]==1) continue;
		
		visited[temp_idx]=0;
		visited[nx]=1; 
		pos[i] = nx;
		dfs(idx+1, sum + v[nx]);

		visited[temp_idx]=1;
		visited[nx]=0;
		pos[i] = temp_idx;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	setmap();
	for(int i = 0; i < 10; i++)
		cin >> dice[i];
		
	dfs(0, 0);
	
	cout << ret;
}