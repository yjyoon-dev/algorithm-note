// 알고리즘 노트
// string 을 이용한 큰 수 처리
// 1. 숫자로 이루어진 문자열 a 와 b 의 합을 문자열 형태로 반환
// 2. a 와 b 의 일의 자리만을 더하는 것을 반복
// 3. 더해진 일의 자리 값을 매 반복문마다 반환할 문자열에 누적한 후 a 와 b 의 일의 자리 제거
// 4. 반환할 문자열에 일의 자리부터 누적시켰으므로 마지막에 reverse

#include <string>
#include <algorithm>
using namespace std;

string addBigInt(string a, string b){
	int sum=0;
	string ret;
	while(!a.empty() || !b.empty() || sum){
		if(!a.empty()){
			sum+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			sum+=b.back()-'0';
			b.pop_back();
		}
		ret+=(sum%10)+'0';
		sum/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}