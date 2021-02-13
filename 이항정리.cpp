// 알고리즘 노트
// 이항정리 (조합) 계산
// 1. nCr : n개 중 r개를 고르는 경우의 수
// 2. DP 를 이용해 최적화 가능
// 3. 수가 너무 커질 경우 bigInteger 와 연계해서 사용
// 4. 점화식 : nCr = n-1Cr-1 + n-1Cr
// 5. 이때 n=r 또는 r=0 이면 전부 고르거나 하나도 안 고르므로 항상 1

#define MAX 100
using namespace std;

long long cache[MAX][MAX];

long long bino(int n, int r){
	if(n==r || r==0) return 1;
	long long& ret = cache[n][r];
	if(ret!=0) return ret;
	return ret=bino(n-1,r-1)+bino(n-1,r);
}