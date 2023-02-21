#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 二分查找类
	// Q704: 二分查找
	int search(vector<int> nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int middle = left + ((right - left) >> 1);
			if (target < nums[middle]) {
				right = middle - 1;
			}
			else if (target > nums[middle]) {
				left = middle + 1;
			}
			else {
				return middle;
			}
		}
		return -1;
	}

	// Q35: 搜索插入位置

};

int main01() {

	Solution solution;

	// Q704
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	cout << solution.search(nums, target) << endl;

	return 0;
}