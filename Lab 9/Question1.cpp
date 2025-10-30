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
    if (!fin) {
        cout << "Could not open file.\n";
        return 0;
    }

    int N;
    fin >> N;
    vector<vector<int> > A(N, vector<int>(N));
    vector<vector<int> > B(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> A[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> B[i][j];

    cout << "Matrix A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << A[i][j];
        cout << "\n";
    }

    cout << "Matrix B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << B[i][j];
        cout << "\n";
    }

    return 0;
}
