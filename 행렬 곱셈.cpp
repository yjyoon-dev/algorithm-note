// 알고리즘 노트
// 서로 같은 사이즈의 행렬 곱셈 알고리즘
// 시간 단축 저장용

#include <vector>
using namespace std;

int N = 100;

vector<vector<int>> matrixMultiple(const vector<vector<int>>& a, const vector<vector<int>>& b){

	vector<vector<int>> ret(N,vector<int>(N,0));

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				ret[i][j]+=a[i][k]*b[k][j];

	return ret;
}