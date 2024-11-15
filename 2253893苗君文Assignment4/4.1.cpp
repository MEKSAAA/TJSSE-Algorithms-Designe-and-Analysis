#include<iostream>
#include<vector>
using namespace std;

bool isAllFlowers(vector<int>flowerbed, int n)
{
	int count = 0;
	if (flowerbed.size() == 1) {
		if (flowerbed[0] == 0)
			count = 1;
	}
	else {
		for (int i = 0; i < flowerbed.size(); i++) {
			if (flowerbed[i] == 0) {
				if ((i == 0 && flowerbed[i + 1] == 0) ||
					(i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) ||
					(i != 0 && i != flowerbed.size() - 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)) {
					count++;
					flowerbed[i] = 1;
				}
			}
		}
	}
	if (count >= n)
		return true;
	else
		return false;
}

int main()
{
	vector<int>flowerbed;
	int m,n;
	cout << "Please enter the size of flowerbed: ";
	cin >> m;
	cout << "Please enter flowerbed: ";
	for (int i = 0; i < m; i++) {
		int j;
		cin >> j;
		flowerbed.push_back(j);
	}
	cout << "Please enter n: ";
	cin >> n;

	if (isAllFlowers(flowerbed, n))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}