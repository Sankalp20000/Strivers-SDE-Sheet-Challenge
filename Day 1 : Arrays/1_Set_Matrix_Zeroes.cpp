class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        // Brute
        // (1) if arr[i][j] == 0{ markRow(i), markCol(j)}
        // (2) if(arr[i][j] == -1){ arr[i] = 0}
        // TC = O(mn*(m+n)) + O(mn)
        // SC = O(1)

        // Better
        // Initialize (1) rows[m] = {0}, cols[n] = {0}
        // if (arr[i][j] == 0)  mark rows[i] = 1,cols[j] = 1
        // traverse the array if(rows[i] || cols[j])    arr[i][j] = 0
        // TC = O(2mn)
        // SC = O(n) + O(m)
        // Note : We are already doing the problem in O(n^2) TC, so we cannot improve           it        further, so we improve the space complexity 

        // Optimal
        // rows[m] = 0 -> arr[..][0]
        // cols[n] = 0 -> arr[0][..]
        // TC = O(mn), SC = O(1)

        int m = arr.size();
        int n = arr[0].size();
        int col0 = 1;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(arr[i][j] == 0){
                    // mark rows[m] as 0
                    arr[i][0] = 0;
                    // mark cols[n] as 0
                    if(j != 0)  arr[0][j] = 0;
                    else    col0 = 0;
                }
            }
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0;
                }
            }
        }

        for(int j = 1 ; j < n ; j++){
            if(arr[0][0] == 0)  arr[0][j] = 0;
        }

        for(int i = 0 ; i < m ; i++){
            if(col0 == 0)   arr[i][0] = 0;
        }


    }
};
