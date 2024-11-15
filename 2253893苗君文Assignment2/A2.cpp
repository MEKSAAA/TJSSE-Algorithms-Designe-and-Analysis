#include<iostream>
#include<vector>
using namespace std;

bool isTargetIn(vector<vector<int>>matrix,int target)
{
	int m = matrix.size();
	int n = matrix[0].size();

	//  从矩阵的左下角开始搜索
	int row = m - 1;
	int col = 0;

	//  超过矩阵最小值，最大值则返回false
	if (target<matrix[0][0] || target>matrix[m - 1][n - 1])
		return false;

	while (row >=0 && col < n) {
		if (matrix[row][col] == target) {
			return true;
		}
		else if (matrix[row][col] > target) {
			row--;
		}
		else if (matrix[row][col] < target) {
			col++;
		}
	}
	return false;
}


int main()
{
	int m, n;  //m为矩阵的行数，n为矩阵的列数
	int target;

	cout << "Please enter m: ";
	cin >> m;
	cout << "Please enter n: ";
	cin >> n;

	vector<vector<int>>matrix(m, vector<int>(n, 0));  //矩阵

	cout << "Please enter matrix: " << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	cout << "Please enter target: ";
	cin >> target;

	if (isTargetIn(matrix, target))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}

/*
  测试用例:
  7 11 15
  8 12 19
  9 17 23
*/