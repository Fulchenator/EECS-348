#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) { cout << "Could not open file.\n"; return 0; }

    int N;
    fin >> N;
    vector<vector<int> > A(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> A[i][j];

    int c1, c2;
    cout << "Enter two column numbers to swap (0-based): ";
    cin >> c1 >> c2;

    if (c1 >= 0 && c1 < N && c2 >= 0 && c2 < N) {
        for (int i = 0; i < N; i++) {
            int temp = A[i][c1];
            A[i][c1] = A[i][c2];
            A[i][c2] = temp;
        }
    } else {
        cout << "Invalid column numbers.\n";
    }

    cout << "Matrix after column swap:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << A[i][j];
        cout << "\n";
    }

    return 0;
}
