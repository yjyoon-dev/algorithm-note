// 알고리즘 노트
// 최대공약수 최소공배수
// 1. GCD: 최대공약수 / LCM: 최소공배수
// 2. 유클리드-호제법에 의거한 알고리즘
// 3. 항상 b 값이 a 보다 더 작은 값을 유지

int gcd(int a, int b){
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

int lcm(int a, int b){
	return (a * b) / gcd(a, b);
}
