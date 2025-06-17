/*
id: 22011479
name: Riknesh
contact: +60125770795
email: riknesh_22011479@utp.edu.my
lab: 2
*/

#include <bits/stdc++.h>
using namespace std;

int findLargestPlus(vector<vector<int>> &mat) {
    
    int n = mat.size();
    
    vector<vector<int>> left(n, vector<int>(n, 0));
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> top(n, vector<int>(n, 0));
    vector<vector<int>> bottom(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                right[i][j] = (j == n - 1) ? 1 : right[i][j + 1] + 1;
                bottom[i][j] = (i == n - 1) ? 1 : bottom[i + 1][j] + 1;
            }
        }
    }
    
    int maxPlusSize = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                int armLength = min({left[i][j], right[i][j],
                                     top[i][j], bottom[i][j]});
                                     
                maxPlusSize = max(maxPlusSize,
                                    (4 * (armLength - 1)) + 1);
            }
        }
    }
    
    return maxPlusSize;
}

int main() {
    
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    
    cout << findLargestPlus(mat) << endl;
    return 0;
}