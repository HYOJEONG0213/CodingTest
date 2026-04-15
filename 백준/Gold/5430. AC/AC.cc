#include <bits/stdc++.h>
using namespace std;

string s, a;
int T, _size;
deque <int> q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> s;
		cin >> _size;
		cin >> a;
		q.clear();
		string temp = "";
		for(int i = 1; i < a.size()-1; i++){
			if(a[i] != ','){
				temp += a[i];
			}
			else{
				q.push_back(atoi(temp.c_str()));
				temp = "";
			}
		}
		if(temp.size())
			q.push_back(atoi(temp.c_str()));
		
		bool Rflag = false;
		bool flag = true;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R'){
				Rflag = !Rflag;
			}
			else if(s[i] == 'D'){
				if(_size==0){
					flag = false;
					break;
				}
				
				if(Rflag){
					q.pop_back();
					_size--;
				}
				else if(!Rflag){
					q.pop_front();
					_size--;
				}
			}
		}
		
		if(flag == false){
			cout << "error \n";
			continue;
		}
		
		if(Rflag){
			reverse(q.begin(), q.end());
		}
		
		cout << "[";
		for(int i=0; i < q.size(); i++){
			cout << q[i];
			if(i != q.size()-1)
				cout << ",";
		}
		cout << "]\n";
	}
}