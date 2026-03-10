class Solution {
public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;

        // We want to find the next smaller element for each index i
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int idx = st.top();
                st.pop();
                // arr[idx] is the first element. 
                // It is the minimum for all subarrays starting at idx 
                // and ending before i.
                ans += (i - idx);
            }
            st.push(i);
        }

        // Handle elements remaining in the stack (no smaller element to their right)
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            ans += (n - idx);
        }

        return ans;
    }
};