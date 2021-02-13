// 위상정렬
// 사이클이 없는 DAG 에서만 가능
// DFS
// 단순히 노드의 순서를 출력하는 문제에서는 DFS 를 이용한 위상정렬의 구현이 더 간단하다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
bool visited[1001];
vector<int> ans;
bool adj[1001][1001];

void dfs(int n){
    visited[n]=true;
    for(int i=1;i<=N;i++)
        if(!visited[i] && adj[n][i])
            dfs(i);
    ans.push_back(n); // dfs 가 종료되는 순서대로
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>N>>M;
    
    // 정점 간의 연결 정보만 입력
    while(M--){
        int n; cin>>n;
        vector<int> v(n);
        for(int& i:v) cin>>i;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                adj[v[i]][v[j]]=true;
    }
    
    // 모든 정점에서 dfs 수행
    for(int i=1;i<=N;i++)
        if(!visited[i])
            dfs(i);
    
    reverse(ans.begin(),ans.end()); // 결과를 뒤집은 것이 위상 정렬의 결과

    // 역간선이 존재할 경우 사이클이 존재하므로 (DAG 가 아니므로) 위상 정렬 불가능
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(adj[ans[j]][ans[i]]){
                cout<<0;
                return 0;
            }
        }
    }
    
    // 위상 정렬 완료
    for(int i:ans) cout<<i<<" ";

    return 0;
}