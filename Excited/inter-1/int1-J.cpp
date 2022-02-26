#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <initializer_list>

// int modulus;

#define MODULUS 123456789LL

typedef long long Numtype;

class Matrix{
    std::vector<std::vector<Numtype>> mat;
public:
    std::vector<Numtype> &operator[] (const size_t &_index) {
        return this->mat[_index];
    }
    const std::vector<Numtype> &operator[] (const size_t &_index) const {
        return this->mat[_index];
    }

    Matrix(const size_t &row, const size_t &col, const Numtype &elem = 0) {
        this->mat.resize(row);
        for(auto &_row: mat) 
            _row.resize(col, elem);
    }
    Matrix(const bool &isColVec, const std::initializer_list<Numtype> &lst) {
        if(isColVec) {
            mat.resize(lst.size());
            auto r = mat.begin();
            for(const auto &rl: lst) {
                r->resize(1);
                r->front() = rl;
                r++;
            }
        } else {
            mat.resize(1);
            mat[0] = lst;
        }
    }
    Matrix(const std::initializer_list<std::initializer_list<Numtype>> &lst) {
        this->mat.resize(lst.size());
        auto r = mat.begin();
        for(const auto &rl: lst) {
            assert(rl.size() == lst.begin()->size());
            *r = rl;
            r++; 
        }
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
            #ifdef MODULUS
            ans += this->mat[k][k] % MODULUS;
            ans %= MODULUS;
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

Matrix operator+ (const Matrix &lhs, const Matrix &rhs) {
    assert(lhs.col() == rhs.col() && lhs.row() == rhs.row());
    Matrix ans(lhs.row(), lhs.col());
    for(size_t r = 0; r < ans.row(); r++) {
        for(size_t c = 0; c < ans.col(); c++) {
            #ifdef MODULUS
            ans[r][c] = lhs[r][c] + rhs[r][c] % MODULUS;
            #else
            ans[r][c] = lhs[r][c] + rhs[r][c];
            #endif
        }
    }
    return ans;
}

Matrix operator* (const Matrix &lhs, const Matrix &rhs) {
    assert(lhs.col() == rhs.row());
    Matrix ans(lhs.row(), rhs.col());
    for(size_t r = 0; r < ans.row(); r++) {
        for(size_t c = 0; c < ans.col(); c++) {
            for(size_t k = 0; k < lhs.col(); k++) {
                #ifdef MODULUS
                ans[r][c] += lhs[r][k] * rhs[k][c] % MODULUS;
                ans[r][c] %= MODULUS;
                #else
                ans[r][c] += lhs[r][k] * rhs[k][c];
                #endif
            }
        }
    }
    return ans;
}

Matrix pow(const Matrix &mat, Numtype p) {
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
    Matrix st(true, {2, 1, 8, 4, 2, 1}), mat = {
        {1, 2, 1, 3, 3, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 1, 3, 3, 1},
        {0, 0, 0, 1, 2, 1},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1}
    };
    int t;
    Numtype n;
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        if(n <= 2) std::cout << st[2-n][0] << '\n';
        else {
            Matrix ans = pow(mat, n - 2) * st;
            std::cout << ans[0][0] % MODULUS << '\n';
        }
    }
    return 0;
}