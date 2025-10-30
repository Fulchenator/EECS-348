#include <iostream>
#include <fstream>
#include <vector>
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

    int mainSum = 0, secSum = 0;
    for (int i = 0; i < N; i++) {
        mainSum += A[i][i];
        secSum += A[i][N - 1 - i];
    }

    cout << "Main diagonal sum: " << mainSum << "\n";
    cout << "Secondary diagonal sum: " << secSum << "\n";

    return 0;
}
