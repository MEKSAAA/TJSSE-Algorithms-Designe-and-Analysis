#include<iostream>
#include<vector>
using namespace std;

int uniquePath(int m, int n)
{
	vector<vector<int>>p(m, vector<int>(n, 0));
	p[0][0] = 1;	//initial state
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j > 0)
				p[i][j] = p[i][j - 1];
			else if (i > 0 && j == 0)
				p[i][j] = p[i - 1][j];
			else if (i > 0 && j > 0)
				p[i][j] = p[i - 1][j] + p[i][j - 1];
		}
	}
	return p[m - 1][n - 1];
}

int main()
{
	int m, n;
	cout << "Please enter m: ";
	cin >> m;
	cout << "Please enter n: ";
	cin >> n;
	cout << "result: " << uniquePath(m, n) << endl;
	return 0;
}