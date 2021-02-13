// 알고리즘 노트
// 교란순열 (완전순열)
// 번호가 주어진 모든 사람이 번호를 뽑을 때 모두 자신의 번호가 아닌 변호를 뽑는 순열
// 사람의 수가 N명일 때 가능한 교란순열의 경우의 수를 Dn 이라고 할 때
// Dn = (n - 1) * (Dn-1 + Dn-2)
// 이 점화식을 이용한 교란순열 경우의 수 계산 코드

const int MOD = 1e9+7;
long long cache[101];

long long derange(int n){
	if(n<=2) return n-1;
	if(cache[n]!=0) return cache[n];
	return cache[n] = (n-1)*(derange(n-2)+derange(n-1))%MOD;
}