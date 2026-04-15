#include <bits/stdc++.h>
using namespace std;

int N, a[3], ret, v[63][63][63], _a[3];
int attack[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

struct A {
    int a;
    int b;
    int c;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    queue <A> q;
    q.push({a[0], a[1], a[2]});
    
    while(v[0][0][0] == 0){
        auto f = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            _a[0] = max(0, f.a - attack[i][0]);
            _a[1] = max(0, f.b - attack[i][1]);
            _a[2] = max(0, f.c - attack[i][2]);
            if(v[_a[0]][_a[1]][_a[2]] != 0) continue;
            
            v[_a[0]][_a[1]][_a[2]] = v[f.a][f.b][f.c] + 1; 
            q.push({_a[0], _a[1], _a[2]});
        }
    }
    
    cout << v[0][0][0];
}