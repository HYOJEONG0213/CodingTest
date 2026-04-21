#include <bits/stdc++.h>
using namespace std;

struct Student{
	int m, d;
	vector <int> p;
	
	bool operator <(const Student &other) const{
		return d < other.d;
	}
	
} ;
vector <Student> student;
int cnt[34];

int N, K, D, d, M, a,  ret;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> D;
	student.resize(N);
	for(int i = 0; i < N; i++){
		cin >> student[i].m >> student[i].d;
		for(int j = 0; j < student[i].m; j++){
			cin >> a;
			student[i].p.push_back(a);
		}
	} 
	
	// d 오름차순 정렬  
	sort(student.begin(), student.end());
	
	// 투포인터  
	int l = 0, ret = 0;
	for(int r = 0; r < N; r++){
		for(int i : student[r].p) cnt[i]++;
		
		while(student[r].d - student[l].d > D){
			for(int i : student[l].p) cnt[i]--;
			l++;
		}
		
		int len = r - l + 1;
		int dontknow = 0;
		
		for(int i = 1; i <= K; i++){
			if(cnt[i] > 0 && cnt[i] != len){
				dontknow++;
			}
		}
		
		ret = max(ret, dontknow * len);
	}
	
	cout << ret;
}