// 알고리즘 노트
// 10진법 -> n진법으로 변환하기
// 숫자 n을 진수로 나눈 나머지들의 역순이므로
// 재귀 함수를 이용해 구할 수 있다
// ※ 다만 이와 같은 경우 n에 0이 입력되는 경우
// 0이 아닌 공백이 출력되므로 이에 대한 예외 처리가 필요하다

#include <string>
using namespace std;

string convert(int n, int b) {// 숫자 n을 b진수로 변환한 값을 string 으로 반환
    if(n == 0) return "";
    if(n%b < 10) return convert(n/b, b) + (char)(n%b+'0');
    return convert(n/b, b) + (char)(n%b-10+'A');
}