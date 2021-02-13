// 알고리즘 노트
// 유니온 파인드 (Union - Find)
// 상호배타적 집합 알고리즘

#include <vector>
using namespace std;

struct Unionfind{
    vector<int> parent, rank;
    Unionfind(int n){
        parent = rank = vector<int>(n+1,1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
    }
    int f(int n){
        if(parent[n]==n) return n;
        return parent[n]=f(parent[n]);  // 경로 압축 기법
    }
    void u(int a, int b){
        a = f(a), b = f(b);
        if(a==b) return;
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
    }
};
