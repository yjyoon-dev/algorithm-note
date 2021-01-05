// 알고리즘 노트
// 유니온 파인드 (Union - Find)
// 상호배타적 집합 알고리즘

#include <vector>
using namespace std;

struct Unionfind{
    vector<int> parent, rank;
    void makeSet(int n){
        parent=vector<int>(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        rank=vector<int>(n,1);
    }
    int ufFind(int n){
        if(parent[n]==n) return n;
        return parent[n]=ufFind(parent[n]); 
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
