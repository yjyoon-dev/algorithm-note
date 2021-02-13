// 알고리즘 노트
// O(logN) 거듭제곱 알고리즘
// 모든 수는 2진수로 표현이 가능함에 따라 비트마스크를 이용한 기법

#define MOD 1000000007

long long power(long long n, long long m){
    long long ret = 1;
    while(m){
        if(m & 1) ret = ret * n % MOD;
        m = m / 2;
        n = n * n % MOD;
    }
    return ret;
}


