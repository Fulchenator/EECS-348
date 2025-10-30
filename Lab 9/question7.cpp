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

    int r, c, val;
    cout << "Enter row, column, and new value (0-based): ";
    cin >> r >> c >> val;

    if (r >= 0 && r < N && c >= 0 && c < N)
        A[r][c] = val;
    else
        cout << "Invalid row/column.\n";

    cout << "Matrix after update:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << A[i][j];
        cout << "\n";
    }

    return 0;
}
