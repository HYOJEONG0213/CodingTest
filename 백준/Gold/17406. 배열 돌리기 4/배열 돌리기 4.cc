#include <bits/stdc++.h>
using namespace std;

int N, M, K, a, r, c, s, ret=987654321;
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

struct {
	int r, c, s;
}R[10];

void show(vector <vector<int>> &v){
	cout << "\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << v[i][j] << " ";
		}
		cout <<"\n";
	}
	cout <<"\n";
}

void check(vector <vector<int>> &v){
	for(int i = 0; i < N; i++){
		int sum = 0;
		for(int j = 0; j < M; j++){
			sum += v[i][j];
		}
		
		ret = min(ret, sum);
	}
}

vector <vector<int>> go(int sy, int sx, int r, vector <vector<int>> &board){
	//v : 바꿀영역들 모은 벡터 
	//v : 숫자 로테이션 된 바뀐 벡터 
	vector <pair<int,int>> v;
	vector <vector<int>> vv = board;
	
	for(int idx = 1; idx <= r; idx++){
		int y = sy-idx, x = sx-idx;
		int dir = 0;
		v.clear();
		v.push_back({y, x});
		x++;
		v.push_back({y, x});
		while(!(y==sy-idx && x==sx-idx)) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if(ny < sy-idx || ny > sy+idx || nx < sx-idx || nx > sx + idx){
				dir++;
				continue;
			}
			if(ny == sy-idx && nx == sx-idx) break;
			
			v.push_back({ny,nx});
			y = ny, x = nx;
		}
		
//		cout << "* ";
//		for(auto i : v){
//			cout << board[i.first][i.second] << " ";
//		}
//		cout << "\n";
//		
		for(int i = 1; i < v.size(); i++){
			tie(y, x) = v[i];
			vv[y][x] = board[v[i-1].first][v[i-1].second];
		}
		
		auto last = v[v.size()-1];
		vv[sy-idx][sx-idx] = board[last.first][last.second];
	}
	
	return vv;
}

void f(vector <vector<int>> &v){
	vector <int> a;
	for(int i = 0; i < K; i++){
		a.push_back(i);
	}
	
	vector <vector<int>> tempv = v;
	copy(v.begin(), v.end(), tempv.begin());
	do{
		copy(v.begin(), v.end(), tempv.begin());
		
		for(int i = 0; i < K; i++){
			//cout << a[i] << " ";
			tempv = go(R[a[i]].r, R[a[i]].c, R[a[i]].s, tempv);
			//show(tempv);
		}
		check(tempv);
		//show(tempv);
		//cout << "\n";
	}while(next_permutation(a.begin(), a.begin()+ K));
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;
	vector <vector <int>> v;
	vector <int> tempv;
	for(int i=0;i<N;i++){
		tempv.clear();
		for(int j=0;j<M;j++){
			cin >> a;
			tempv.push_back(a);
		}
		
		v.push_back(tempv);
	}
	
	for(int i=0; i < K; i++){
		cin >> r >> c >> s;
		r--, c--;
		R[i].r = r; 
		R[i].c = c;
		R[i].s = s;
	}
	
	f(v);
	
	cout <<ret;
} 