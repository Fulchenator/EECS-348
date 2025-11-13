#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
    int n;
    int* d;
public:
    Matrix(): n(0), d(nullptr) {}
    Matrix(int s): n(s) { d=new int[n*n]; for(int i=0;i<n*n;i++) d[i]=0; }
    Matrix(const Matrix& m): n(m.n) { d=new int[n*n]; for(int i=0;i<n*n;i++) d[i]=m.d[i]; }
    Matrix& operator=(const Matrix& m){ if(this!=&m){ delete[] d; n=m.n; d=new int[n*n]; for(int i=0;i<n*n;i++) d[i]=m.d[i]; } return *this; }
    ~Matrix(){ delete[] d; }

    int size() const { return n; }
    int& at(int r,int c){ return d[r*n+c]; }
    int  atc(int r,int c) const { return d[r*n+c]; }

    void print(const string& title) const {
        cout<<title<<"\n";
        for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<setw(4)<<atc(i,j); cout<<"\n"; }
    }

    Matrix operator+(const Matrix& b) const {
        Matrix r(n); for(int i=0;i<n*n;i++) r.d[i]=d[i]+b.d[i]; return r;
    }
    Matrix operator*(const Matrix& b) const {
        Matrix r(n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            int s=0; for(int k=0;k<n;k++) s+=atc(i,k)*b.atc(k,j);
            r.at(i,j)=s;
        }
        return r;
    }

    int mainDiagSum() const { int s=0; for(int i=0;i<n;i++) s+=atc(i,i); return s; }
    int secondaryDiagSum() const { int s=0; for(int i=0;i<n;i++) s+=atc(i,n-1-i); return s; }
};

bool reads_two(const string& file, Matrix& A, Matrix& B){
    ifstream fin(file); int N; if(!(fin>>N) || N<=0) return false;
    A=Matrix(N); B=Matrix(N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) fin>>A.at(i,j);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) fin>>B.at(i,j);
    return fin.good() || fin.eof();
}

Matrix switch_rows(Matrix m,int r1=0,int r2=1){
    int n=m.size(); if(r1<0||r2<0||r1>=n||r2>=n) return m;
    for(int j=0;j<n;j++){ int t=m.at(r1,j); m.at(r1,j)=m.at(r2,j); m.at(r2,j)=t; }
    return m;
}
Matrix switch_columns(Matrix m,int c1=0,int c2=1){
    int n=m.size(); if(c1<0||c2<0||c1>=n||c2>=n) return m;
    for(int i=0;i<n;i++){ int t=m.at(i,c1); m.at(i,c1)=m.at(i,c2); m.at(i,c2)=t; }
    return m;
}
Matrix edit_spot(Matrix m,int r=0,int c=0,int v=100){
    if(r>=0&&c>=0&&r<m.size()&&c<m.size()) m.at(r,c)=v; return m;
}

int main(){
    string fn; cout<<"File: "; getline(cin,fn);
    Matrix A,B; if(!reads_two(fn,A,B)){ cout<<"Error reading file\n"; return 1; }

    A.print("Matrix A:");
    B.print("Matrix B:");
    (A+B).print("A + B:");
    (A*B).print("A * B:");
    cout<<"Main diagonal sum (A): "<<A.mainDiagSum()<<"\n";
    cout<<"Secondary diagonal sum (A): "<<A.secondaryDiagSum()<<"\n";
    switch_rows(A).print("A after switch_rows(0,1):");
    switch_columns(A).print("A after switch_columns(0,1):");
    edit_spot(A).print("A after edit_spot(0,0,100):");
}
