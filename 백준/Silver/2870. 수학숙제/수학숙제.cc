#include <bits/stdc++.h>
using namespace std;

int N, start;
string s, ret;
vector <string> v;
bool flag;

void remove0(){
    while(true){
        if(ret.size() && ret.front() == '0')
            ret.erase(ret.begin());
        else break;
    }
    
    if(ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a<b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
       // bool flag = false;
      //  int cnt = 0;
        cin >> s;
        ret = "";
        
        for(int j = 0; j < s.size(); j++){
            if(isdigit(s[j])){
                ret += s[j];
            }
            else if(ret.size()) remove0();
        }
        if(ret.size()) remove0();
    }
    sort(v.begin(), v.end(), cmp);
    for(string a : v) cout << a << "\n";
}