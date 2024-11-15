#include<iostream>
#include<vector>
using namespace std;

bool isTargetIn(vector<vector<int>>matrix,int target)
{
	int m = matrix.size();
	int n = matrix[0].size();

	//  �Ӿ�������½ǿ�ʼ����
	int row = m - 1;
	int col = 0;

	//  ����������Сֵ�����ֵ�򷵻�false
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
	int m, n;  //mΪ�����������nΪ���������
	int target;

	cout << "Please enter m: ";
	cin >> m;
	cout << "Please enter n: ";
	cin >> n;

	vector<vector<int>>matrix(m, vector<int>(n, 0));  //����

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
  ��������:
  7 11 15
  8 12 19
  9 17 23
*/