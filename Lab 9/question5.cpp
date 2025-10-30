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
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> A[i][j];
        }
    }

    int r1, r2;
    cout << "Enter two row numbers to swap (0-based): ";
    cin >> r1 >> r2;

    if (r1 >= 0 && r1 < N && r2 >= 0 && r2 < N) {
        swap(A[r1], A[r2]);
    } else {
        cout << "Invalid row numbers.\n";
        return 0;
    }

    cout << "Matrix after row swap:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << "\n";
    }

    return 0;
}
