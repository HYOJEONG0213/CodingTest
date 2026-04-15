#include <bits/stdc++.h>
using namespace std;

const int n_max = 65;
int N;
char a[n_max][n_max];
stack <string> stk;


string quard(int y, int x, int n){
    if(n == 1){
        return string(1, a[y][x]);
    }
    
    string ret = "";
    
    //cout << "ㄴ";
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(a[y][x] != a[i][j]){
                ret += "(";
                ret += quard(y, x, n / 2);
                ret += quard(y, x + n / 2, n / 2);
                ret += quard(y + n / 2, x, n / 2);
                ret += quard(y + n / 2, x + n / 2, n / 2);
                ret += ")";
                return ret;
            }
        } 
    }
    return string(1, a[y][x]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            a[i][j] = s[j];
        }
        //cout << "ㅂ" << "\n";
    }
    //cout <<"ㅇㅇ";
    cout << quard(0, 0, N) << "\n";

}