#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxScore(vector<int>nums1, vector<int>nums2)
{
	const int MOD = 1000000007;
	long long dp1 = 0, dp2 = 0;  // 记录当前的最大得分
	int n1 = nums1.size(), n2 = nums2.size();

	for (int i = 0, j = 0; i < n1 || j < n2;) {
		if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
			dp1 += nums1[i];
			i++;
		}
		else if (j < n2 && (i >= n1 || nums2[j] < nums1[i])) {
			dp2 += nums2[j];
			j++;
		}
		else {
			// nums1[i] == nums2[j]
			long long max_val = max(dp1, dp2) + nums1[i];
			dp1 = dp2 = max_val;
			i++;
			j++;
		}
	}

	return max(dp1, dp2) % MOD;
}

int main()
{
	vector<int>nums1, nums2;
	int sz1, sz2;
	cout << "Please enter the size of nums1: ";
	cin >> sz1;
	cout << "Please enter nums1: ";
	for (int i = 0; i < sz1; i++) {
		int j;
		cin >> j;
		nums1.push_back(j);
	}
	cout << "Please enter the size of nums2: ";
	cin >> sz2;
	cout << "Please enter nums2: ";
	for (int i = 0; i < sz2; i++) {
		int j;
		cin >> j;
		nums2.push_back(j);
	}
	cout << maxScore(nums1, nums2) << endl;
	return 0;
}