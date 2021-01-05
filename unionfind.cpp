// 알고리즘 노트
// 유니온 파인드 (Union - Find)
// 상호배타적 집합 알고리즘

#include <vector>
using namespace std;

struct Unionfind{
    vector<int> parent, rank;
    Unionfind(int n){
        parent=vector<int>(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        rank=vector<int>(n+1,1);
    }
    int ufFind(int n){
        if(parent[n]==n) return n;
        return parent[n]=ufFind(parent[n]);  // 경로 압축 기법
    }
    void ufUnion(int a, int b){
        a = ufFind(a), b = ufFind(b);
        if(a==b) return;
        if(rank[a]<=rank[b]){
            parent[a]=b;
            if(rank[a]==rank[b]) rank[b]++;
        }
        else parent[b]=a;
    }
};
