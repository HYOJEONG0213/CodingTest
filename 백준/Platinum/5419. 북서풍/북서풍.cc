#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;

int T, n, x, y, tree[75004];
vector <pp> island;
vector <int> ylist;

struct cmp{
	bool operator ()(const pp &a, const pp &b){
		//y축 내림차순, 같다면 x축 오름차순  
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

int findIdx(int target){
	int l = 0, r = n-1;
	while(l <= r){
		int mid = (l+r)/2;
		if(ylist[mid] < target){
			l = mid+1;
		}
		else if(ylist[mid] > target){
			r = mid-1;
		}
		else if(ylist[mid]==target){
			return mid;
		}
	}
}

void update(int idx, int value){
	while(idx <= n){
		tree[idx] += value;
		idx += idx & -idx;
	}
}

ll sum(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		//초기화
		island.clear();
		ylist.clear(); 
		memset(tree, 0, sizeof(tree));
		ll ret = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			island.push_back({x, y});
			ylist.push_back(y);
		}
		
		sort(island.begin(), island.end(), cmp());
		sort(ylist.begin(), ylist.end());
		
		//맨 위에 있는 녀석부터 시작해서.. 내 위로 몇개고!  
		pp temp[75004];
		memset(temp, 0, sizeof(temp));
		int idx = 0;
		for(int i = 0; i < n; i++){
			if(i > 0 && island[i].second < island[i-1].second){
				idx++;
			}
			temp[i] = {island[i].first, idx};
		}
		sort(temp, temp+n);
		
		
		for(int i = 0; i < n; i++){
			int idx = temp[i].second + 1;
			ret += sum(idx);
			//cout << sum(idx) << " "; 
			update(idx, 1);
		}
		
		cout << ret << "\n";
	}
}