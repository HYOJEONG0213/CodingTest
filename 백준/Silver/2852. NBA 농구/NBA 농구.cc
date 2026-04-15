#include <bits/stdc++.h>
using namespace std;

#define prev qqqqq
int N, A, B, asum, bsum, o;
string s, prev;

//출력 형식 : 08:20 
string print(int a){
    string mm = "00" + to_string(a / 60);
    string ss = "00" + to_string(a % 60);
    return mm.substr(mm.size()-2, 2) + ":" + ss.substr(ss.size()-2, 2);
}

//단위 통합 
int timetosecond(string s){
    return atoi(s.substr(0,2).c_str()) * 60 + atoi(s.substr(3,2).c_str());
}

//실제 시간 계산 
int go(int &sum, string s){
    return sum += timetosecond(s) - timetosecond(prev);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> o >> s;
        
        //이기고 있는 중! 
        if(A > B) go(asum, s);
        else if(A < B) go(bsum, s);
        
        o == 1 ? A++ : B++;
                        
        prev = s;
    }

    //게임 끝날떄까지 존버 
    if(A > B) go(asum, "48:00");
        else if(A < B) go(bsum, "48:00");
    
    cout << print(asum) << "\n";
    cout << print(bsum) << "\n";

}