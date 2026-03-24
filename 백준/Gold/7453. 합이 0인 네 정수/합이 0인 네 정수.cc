#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, A[4004], B[4004], C[4004], D[4004];
ll ret;
vector<int> AB, CD;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	AB.reserve(N*N);
	
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			AB.push_back(A[i]+B[j]);
			CD.push_back(C[i]+D[j]);
		}
	}
	
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	
	int left = 0;
	int right = CD.size()-1;
	while(left < AB.size() && right >= 0){
		int current = AB[left] + CD[right];
		
		if(current==0){
			int target1 = AB[left], target2 = CD[right];
			ll cnt1 = 0, cnt2 = 0;
			while(left < AB.size() && AB[left] == target1){
				cnt1++;
				left++;
			}
			while(right >= 0 && CD[right] == target2){
				cnt2++;
				right--;
			}
			
			ret += cnt1 * cnt2;
		}
		else if(current < 0){
			left++;
		}
		else{
			right--;
		}
	}
	
	cout << ret;
}