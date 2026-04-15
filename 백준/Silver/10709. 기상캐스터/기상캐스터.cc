#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int H, W, prev;
char a[104][104];
int ret[104][104];

int main(){
    cin >> H >> W;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < H; i++){
        prev = -1;
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
            if(a[i][j] == 'c') {
                prev = j;
                ret[i][j] = 0;
            }
            else {
                if(prev == -1) continue;
                else ret[i][j] = j - prev;
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}