#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWinHelper(const vector<int>& nums, int start, int end, int player1Score, int player2Score, bool isPlayer1Turn) {
    if (start > end) {
        // 游戏结束，判断玩家1的得分是否大于玩家2的得分
        return player1Score > player2Score;
    }

    if (isPlayer1Turn) {
        // 玩家1的回合
        return !canWinHelper(nums, start + 1, end, player1Score + nums[start], player2Score, !isPlayer1Turn) ||
            !canWinHelper(nums, start, end - 1, player1Score + nums[end], player2Score, !isPlayer1Turn);
    }
    else {
        // 玩家2的回合
        return !canWinHelper(nums, start + 1, end, player1Score, player2Score + nums[start], !isPlayer1Turn) ||
            !canWinHelper(nums, start, end - 1, player1Score, player2Score + nums[end], !isPlayer1Turn);
    }
}

bool canWin(vector<int>& nums) {
    return canWinHelper(nums, 0, nums.size() - 1, 0, 0, true);
}

int main() {
    int n;
    cout << "Please enter the size of array: ";
    cin >> n;

    vector<int>nums(n);
    cout << "Please enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << (canWin(nums) ? "true" : "false") << endl;

    return 0;
}
