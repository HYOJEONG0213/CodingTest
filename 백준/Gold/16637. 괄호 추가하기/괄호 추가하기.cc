#include <bits/stdc++.h>
using namespace std;

int N, cnt, ret = -987654321;
vector <int> num;
vector <char> opper;
string s;

int go(int a, char b, int c){
    if(b == '+') return a + c;
    else if(b == '-') return a - c;
    else return a * c;
}

void dfs(int here, int sum){
    if(here == num.size() - 1){
        ret = max(sum, ret);
        return;
    }
    
    int temp = go(sum, opper[here], num[here+1]);
    dfs(here + 1, temp);
    
    if(here + 2 <= num.size() - 1) {
        temp = go(num[here+1], opper[here+1], num[here+2]);
        temp = go(sum, opper[here], temp);
        dfs(here + 2, temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else opper.push_back(s[i]);
    }
    
    dfs(0, num[0]);
    
    
    cout << ret;
}   