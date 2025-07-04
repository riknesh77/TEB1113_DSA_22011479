/*
id: 22011479
name: Riknesh
contact: +60125770795
email: riknesh_22011479@utp.edu.my
lab: 2 
*/

#include <iostream>
using namespace std;

#define ROWS 4
#define COLS 5
#define MAX 100

int main() {
    int mat[ROWS][COLS] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9}
    };

    int freq[MAX] = {0};   
    bool seen[MAX];        

    for (int j = 0; j < COLS; j++) {
        freq[mat[0][j]] = 1;
    }
    for (int i = 1; i < ROWS; i++) {
        for (int k = 0; k < MAX; k++) seen[k] = false;

        for (int j = 0; j < COLS; j++) {
            int val = mat[i][j];
            if (freq[val] == i && !seen[val]) {
                freq[val]++;       
                seen[val] = true;  
            }
        }
    }
    cout << "Common elements in all rows: ";
    for (int i = 0; i < MAX; i++) {
        if (freq[i] == ROWS) {
            cout << i << " ";
        }
    }

    return 0;
}
