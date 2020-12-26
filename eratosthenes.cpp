// 알고리즘 노트
// 에라토스테네스의 체를 이용한 소수 구하기

#include <cstring>
#include <cmath>

const int MAX = 100;
bool isPrime[MAX+1];

void eratos(int n){
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<=sqrt(n);i++)
		if(isPrime[i])
			for(int j=i*i;j<=n;j+=i)	
				isPrime[j]=false;
}