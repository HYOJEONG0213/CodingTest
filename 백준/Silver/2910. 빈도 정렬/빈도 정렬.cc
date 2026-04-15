#include <bits/stdc++.h>
using namespace std;

int N, C, a[1004];
map <int, int> m, m_first;
vector <pair<int, int>> v;

bool cmp(pair <int, int> a, pair <int, int> b){
    if(a.first == b.first){
        //빈도수 같으면 오름차순
        return m_first[a.second] < m_first[b.second];
    }
    
    //빈도수에 따른 내림차순 
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        m[a[i]]++;
        if(m_first[a[i]] == 0) m_first[a[i]] = i + 1;
    }
    
    for(auto it : m)
        v.push_back({it.second, it.first});
    
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        for(int j = 0; j < i.first; j++)
            cout << i.second << " ";
    }
        
}