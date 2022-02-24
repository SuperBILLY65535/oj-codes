#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

#define modulus 9973

typedef int Numtype;

class Matrix{
    std::vector<std::vector<Numtype>> mat;
public:
    std::vector<Numtype> &operator[] (const size_t &_index) {
        return this->mat[_index];
    }
    Matrix(const size_t &row, const size_t &col, const Numtype &elem = 0) {
        this->mat.resize(row);
        for(auto &_row: mat) 
            _row.resize(col, elem);
    }
    size_t row() const {
        return mat.size();
    }
    size_t col() const {
        return mat[0].size();
    }
    Numtype trace() const {
        assert(this->row() == this->col());
        Numtype ans = 0;
        for(size_t k = 0, r = this->row(); k < r ; k++) {
            #ifdef modulus
            ans += this->mat[k][k] % modulus;
            ans %= modulus;
            #else
            ans += this->mat[k][k];
            #endif
        }
        return std::move(ans); 
    }
    static Matrix identity(const size_t &s) {
        assert(s > 0);
        Matrix ans(s, s);
        for(size_t i = 0; i < s; i++)
            ans[i][i] = 1;
        return ans;
    }
};

Matrix operator+ (Matrix &lhs, Matrix &rhs) {
    assert(lhs.col() == rhs.col() && lhs.row() == rhs.row());
    Matrix ans(lhs.row(), lhs.col());
    for(size_t r = 0; r < ans.row(); r++) {
        for(size_t c = 0; c < ans.col(); c++) {
            #ifdef modulus
            ans[r][c] = lhs[r][c] + rhs[r][c] % modulus;
            #else
            ans[r][c] = lhs[r][c] + rhs[r][c];
            #endif
        }
    }
    return ans;
}

Matrix operator* (Matrix &lhs, Matrix &rhs) {
    assert(lhs.col() == rhs.row());
    Matrix ans(lhs.row(), rhs.col());
    for(size_t r = 0; r < ans.row(); r++) {
        for(size_t c = 0; c < ans.col(); c++) {
            for(size_t k = 0; k < lhs.col(); k++) {
                #ifdef modulus
                ans[r][c] += lhs[r][k] * rhs[k][c] % modulus;
                ans[r][c] %= modulus;
                #else
                ans[r][c] += lhs[r][k] * rhs[k][c];
                #endif
            }
        }
    }
    return ans;
}

Matrix pow(Matrix &mat, int p) {
    assert(p >= 0);
    assert(mat.row() == mat.col());

    Matrix ans(Matrix::identity(mat.row())), tmp(mat);
    while(p > 0) {
        if(p % 2) ans = ans * tmp;
        p >>= 1;
        tmp = tmp * tmp;
    }
    return ans;
}

int main() {
    int tests, sz, p;
    for(std::cin >> tests; tests>0; tests--) {
        std::cin >> sz >> p;
        Matrix m(sz, sz);
        for(size_t r = 0; r < m.row(); r++) {
            for(size_t c = 0; c < m.col(); c++) {
                std::cin >> m[r][c];
            }
        }
        std::cout << pow(m, p).trace() << '\n';
    }
    return 0;
}