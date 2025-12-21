class Solution {
  public:
    int upperBound(vector<int> &arr, int x, int n){
        int low = 0; 
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low + high)/2;
            // maybe an answer
            if(arr[mid]>x){
                ans = mid;
                //look for mor small index on the left
                high = mid - 1;
            }
            else{
                low = mid+1; // look for right
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x){
        int cnt = 0;
        for (int i = 0;i<n;i++){
            cnt += upperBound(mat[i],x,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i<n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int req = (n * m)/2;
        while(low<=high){
            int mid = (low+high)/2;
            int smallEqual = countSmallEqual(mat,n,m,mid);
            if(smallEqual<=req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
