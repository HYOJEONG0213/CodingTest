#include <bits/stdc++.h>
using namespace std;

struct A{
	int w;
	int u;
	bool flag;
};
const int INF = 987654321;
int N, M, a, b, d, ret;
int dict1[4004], dict2[4004][2];
vector <pair<int, int>> adj[4004];

//여우 
void dij1(){
	dict1[1] = 0;
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({0, 1});
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int cost = f.first;
		int u = f.second;
		
		if(dict1[u] != cost) continue;
		
		for(auto i : adj[u]){
			int weight = i.first;
			int v = i.second;
			
			int next = cost + weight;
			if(dict1[v] > next){
				dict1[v] = next;
				pq.push({next, v});
			}
		}
	}
}

//struct Compare {
//	bool operator()(const A &a, const A &b) const	{	
//		return a.w < b.w;
//	}
//};

//늑대  
void dij2(){
	dict2[1][1] = 0;
	priority_queue <tuple<int,int,bool>, vector <tuple<int,int,bool>>, greater <tuple<int,int,bool>> > pq;
	//priority_queue <A, vector<A>, Compare> pq;
	pq.push(make_tuple(0, 1, true));
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int cost, u, flag;
		tie(cost, u, flag) = f;
		//int cost = f.w;
		//int u = f.u;
		//int flag = f.flag;
		
		//느슨한 삭제?  
		if(dict2[u][flag] < cost) continue;
		
		
		for(auto i : adj[u]){
			int weight = i.first;
			int v = i.second;
			//늑대 2배의 속도!!  
			if(flag == true){
				weight /= 2;
				//cout << weight << " ";
			}
			else if(flag == false){
				weight *= 2;
				//cout << weight << " ";
			}
			
			int next = cost + weight;
			if(dict2[v][!flag] > next){
				dict2[v][!flag] = next;
				pq.push(make_tuple(next, v, !flag));
			}
		}
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dict1, dict1+4004, INF);
	fill(&dict2[0][0], &dict2[0][0]+4004*2, INF);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> d;
		d *= 2;
		adj[a].push_back({d, b});
		adj[b].push_back({d, a});
	}
	
	//여우 
	dij1();
	//늑대 
	dij2();
	
	
	for(int i = 1; i <= N; i++){
		//cout << dict1[i] << " " << dict2[i][0] << " " << dict2[i][1] <<"\n";
		 
		
		if(dict1[i] < (dict2[i][0] < dict2[i][1] ? dict2[i][0] : dict2[i][1])) {
			ret++;
		}
	}
	
	cout << ret;
}