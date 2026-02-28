class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int i = 0, j = arr2.size() - 1, minDiff = INT_MAX;
        vector<int> res(2);
        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j], diff = abs(sum - x);
            if (diff < minDiff) minDiff = diff, res = {arr1[i], arr2[j]};
            (sum < x) ? i++ : j--;
        }
        return res;
    }
};