#include <bits/stdc++.h>
using namespace std;

struct edge{
	double x, y;
	
	bool operator<(const edge &other) const{
		return y < other.y;
	}
};

int p[104], level[104];
int N;
double x, y, ret;
edge edges[104];
vector<tuple<double, int, int>> v;

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x] == level[y]){
			level[x]++;
		}
		p[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> edges[i].x >> edges[i].y;
	}
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			double dirY = pow(edges[j].y - edges[i].y, 2);
			double dirX = pow(edges[j].x - edges[i].x, 2);
			double dir = sqrt(dirY + dirX);
			v.push_back(make_tuple(dir, i, j));
		}
	}
	sort(v.begin(), v.end());
	int num = 0;
	for(int i = 0; i < v.size(); i++){
		double dir;
		int star1, star2;
		tie(dir, star1, star2) = v[i];
		star1 = find(star1);
		star2 = find(star2);
		if(star1==star2) continue;
		
		ret += dir;
		merge(star1, star2);
		num++;
		if(num == N-1) break;
	}
	
	cout << fixed << setprecision(2) << ret;
}