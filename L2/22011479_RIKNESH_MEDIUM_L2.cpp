/*
id: 22011479
name: Riknesh
contact: +60125770795
email: riknesh_22011479@utp.edu.my
lab: 2 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createRotatedMatrix(const vector<vector<int>>& original) {
    int size = original.size();
    vector<vector<int>> rotated(size, vector<int>(size));

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            rotated[size - col - 1][row] = original[row][col];
        }
    }

    return rotated;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    vector<vector<int>> rotatedMatrix = createRotatedMatrix(matrix);

    cout << "\nRotated Matrix (90° counterclockwise):" << endl;
    printMatrix(rotatedMatrix);

    return 0;
}