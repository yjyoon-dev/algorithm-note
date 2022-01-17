// 알고리즘 배열
// Bottom-up DP를 이용해 2차원 배열 누적합 구하기

#include <iostream>
#define MAX 1024
using namespace std;

int N,M,K;
// 편의를 위해 첫번째 행과 열은 0으로 고정
int board[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 배열 입력
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin>>board[i][j];
    
    // dp[i][j]는 (0,0) ~ (i,j) 까지의 누적합
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            dp[i][j] = board[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    
    // (x1,y1) ~ (x2,y2) 누적합 출력
    cin>>K;
    while(K--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]<<'\n';
    }

    return 0;
}