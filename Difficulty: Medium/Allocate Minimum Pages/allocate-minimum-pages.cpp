
class Solution {
    int countStudents(vector<int> &arr, int pages) {
        int n = arr.size();
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int students = countStudents(arr, mid);
            if (students > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};