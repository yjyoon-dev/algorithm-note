// 알고리즘 노트
// KMP 문자열 검색 알고리즘
// 시간복잡도: O(N+M) -> 젚더미 길이 + 바늘 길이
// 접미사 배열을 이용한 문자열 검색

#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& N){
    int m=N.size();
    vector<int> pi(m,0);
    int begin=1, matched=0;
    while(begin+matched < m){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1]=matched;
        }
        else{
            if(matched==0) ++begin;
            else{
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> kmp(const string& H, const string& N){
    int n=H.size(), m=N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int matched=0;
    for(int i=0;i<n;i++){
        while(matched>0 && H[i]!=N[matched])
            matched=pi[matched-1];
        if(H[i]==N[matched]){
            ++matched;
            if(matched==m){
                ret.push_back(i-m+1);
                matched=pi[matched-1];
            }
        }
    }
    return ret;
}