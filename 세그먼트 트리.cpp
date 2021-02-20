// 세그먼트 트리
// 길이가 N 인 배열에 대하여 O(logN) 의 시간복잡도로 쿼리 수행
// 구간에 대한 특정 결괏값을 저장 및 갱신

#include <vector>
using namespace std;

// 예시: 최소 구간 트리
struct RMQ{
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& v){ // 파라미터: 원본 배열
        n = v.size();
        rangeMin = vector<int>(4*n); // 구간 트리의 노드 갯수는 원본 배열 크기의 4배를 하면 부족하지 않음
        init(v,1,0,n-1); // 2를 곱하는 연산을 통해 자손으로 내려가므로 첫번째 노드를 0이 아닌 1부터 시작
    }
    // 트리 초기화
    int init(const vector<int>& v, int node, int left, int right){
        if(left==right) return rangeMin[node]=v[left]; // 리프 노드 도달 시
        int mid = (left + right) / 2;
        return rangeMin[node] = min(init(v,node*2,left,mid),init(v,node*2+1,mid+1,right));
    }
    // left, right : 쿼리 구간
    // node : 현재 노드
    // nodeLeft, nodeRight : 노드 관할 구간
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        // 쿼리 구간과 전혀 겹치지 않을 경우 반환값이 무시되도록 매우 큰 값 반환
        if(right<nodeLeft || nodeRight<left) return 1e9;
        // 노드 구간이 쿼리 구간에 완전히 포함될 경우 바로 결괏값 반환
        if(left<=nodeLeft && nodeRight<=right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid+1,nodeRight));
    }
    // index번째 배열의 원소를 newValue 로 갱신할 때
    // node 를 루트로 하는 구간 트리 갱신하기
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
        if(index<nodeLeft || nodeRight<index) return rangeMin[node]; // 구간을 벗어났을 시 기존 값 반환
        if(nodeLeft==nodeRight) return rangeMin[node] = newValue; // 리프 노드 도달 시 갱신
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index,newValue,node*2,nodeLeft,mid),update(index,newValue,node*2+1,mid+1,nodeRight));
    }
};
