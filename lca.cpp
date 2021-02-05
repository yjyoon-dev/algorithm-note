// 알고리즘 노트
// LCA (트리 최소 공통 조상 구하기)
// 최소 공통 조상: 트리 상의 정점 u, v에서 u와 v의 공통 조상 중 가장 깊이 있는 정점
// 시간복잡도: O(logN)
// dp[v][t] 가 정점 v의 2^t 번째 조상이라고 할 때, dp[v][t] = dp[dp[v][t-1]][t-1]
// 과정 1) depth[u] > depth[v] 일 때 u를 u의 조상으로 바꾼다
// 과정 2) u와 v를 각각 자신의 조상으로 바꾼다

#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
int depth[N];
int dp[N][30];
int visit[N];
int n;

void dfs(int v, int d){
	visit[v] = 1;
	depth[v] = d;
	for(auto i : g[v]){
		if(!visit[i]){
			dp[i][0] = v;
			dfs(i, d+1);
		}
	}
}

void make_table(){
	for(int j=1; j<30; j++){
		for(int i=1; i<=n; i++){
			dp[i][j] = dp[ dp[i][j-1] ][j-1];
		}
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i=0; diff; i++){
		if(diff & 1) u = dp[u][i];
		diff >>= 1;
	}
	if(u == v) return u;

	for(int i=29; i>=0; i--){
		if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	make_table();

	int m; cin >> m;
	while(m--){
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}