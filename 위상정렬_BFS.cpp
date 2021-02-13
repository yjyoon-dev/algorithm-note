// 위상 정렬
// 사이클이 없는 DAG 에서만 가능
// BFS
// 단순히 위상 정렬의 결과를 출력하는 것이 아닌 별도의 작업이 필요할 경우
// BFS 를 이용한 위상 정렬이 더욱 응용력이 높음

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[501];
vector<int> adj[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 정점 간의 연결 정보와 진입 간선 수 갱신
    int N; cin>>N;
    for(int i=1;i<=N;i++){
        while(true){
            int n;cin>>n;
            if(n==-1) break;
            adj[n].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q; // 필요에 따라 priority_queue 사용 가능 (동일 조건에서 작은 수부터 등장해야 할 때 등등)

    // 진입 간선의 개수가 0인 정점만 큐에 push
    for(int i=1;i<=N;i++)
        if(indegree[i]==0)
            q.push(i);
    
    bool isCycle = false;
    bool isCertain = true;
    vector<int> ans;

    for(int i=0;i<N;i++){ // 그래프가 DAG인 것이 보장될 경우 while(q.empty()) 를 사용해도 무관

        // N개를 뽑기 전에 큐가 빌 경우 그래프에 사이클이 존재하므로 위상 정렬 불가능
        if(q.empty()){
            isCycle=true;
            break;
        }

        int cur = q.front(); q.pop();
        ans.push_back(cur);

        // 해당 정점과 연결된 정점의 진입 간선을 하나씩 제거 후 0일 경우 큐에 push
        for(int i:adj[cur])
            if(--indegree[i]==0)
                q.push(i);

        if(q.size()>1) isCertain = false; // 큐의 크기가 1 이상일 경우 가능한 위상 정렬의 결과가 여러개
    }

    // 위상 정렬 결과
    for(int i:ans) cout<<i<<" ";

    return 0;
}