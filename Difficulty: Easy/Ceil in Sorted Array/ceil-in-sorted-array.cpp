class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
         int low = 0;
            int high = arr.size() - 1;
            int ans = -1; // Shuru me assume karte hain ki ceil nahi mila

            while (low <= high) {
                int mid = low + (high - low) / 2; // Overflow se bachne ke liye

                if (arr[mid] >= x) {
                    ans = mid;       // Index ko save kar lo
                    high = mid - 1;  // Pehle ya chote element ke liye left me dhundo
                } else {
                    low = mid + 1;   // Agar element chota hai toh right me dhundo
                }
            }
            return ans;
        }
};