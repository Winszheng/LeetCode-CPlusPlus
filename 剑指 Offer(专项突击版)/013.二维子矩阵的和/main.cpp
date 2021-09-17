#include <vector>
using namespace std;

// 二维前缀和
class NumMatrix {
    vector<vector<int>> mat;    // 前缀和登记表
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        mat.resize(n, vector<int>(m));mat[0][0] = matrix[0][0];
        for(int i=1;i<m;i++)mat[0][i] = mat[0][i-1]+matrix[0][i];
        for(int i=1;i<n;i++)mat[i][0] = mat[i-1][0]+matrix[i][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++)mat[i][j] = mat[i][j-1]+mat[i-1][j]+matrix[i][j]-mat[i-1][j-1];
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = mat[row2][col2];
        if(row1 > 0)sum -= mat[row1-1][col2];
        if(col1 > 0)sum -= mat[row2][col1-1];
        if(row1>0 && col1)sum += mat[row1-1][col1-1];
        return sum;
    }
};
