class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), i = 0, cnt = 0, maxi = -1;
        vector<int> fre(26, 0);
        for (int j = 0; j < n; j++) {
            if (fre[s[j] - 'a']++ == 0) cnt++;
            while (cnt > k) {
                if (--fre[s[i] - 'a'] == 0) cnt--;
                i++;
            }
            if (cnt == k) maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};