#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

// #define modulus 9973

typedef int Numtype;

struct matrix{
    std::vector<std::vector<Numtype>> mat;
    /**
     * @brief Construct a new matrix object by size and default insert value
     * 
     * @param row Size of row
     * @param col Size of column
     * @param value Default insert value
     */
    matrix(const size_t & row, const size_t & col, const Numtype &&value = 0) {
        mat.resize(row);
        for(auto &r: mat) r.resize(col, value);
    }
    /**
     * @brief returns the number of columns
     * 
     * @return size_t&& number of columns
     */
    size_t &&col() const {
        return mat[0].size();
    }
    /**
     * @brief Returns the number of rows
     * 
     * @return size_t&& number of rows
     */
    size_t &&row() const {
        return mat.size();
    }
    /**
     * @brief Checks if a matrix is square
     * 
     * @return true col() == row()
     * @return false otherwise
     */
    bool isSquare() const {
        return col() == row();
    }
    std::vector<Numtype> &operator[] (const size_t &&rindex) {
        return this->mat[rindex];
    }
    /**
     * @brief Returns the trace of a square matrix
     * 
     * @return Numtype&& Tr(*this)
     */
    Numtype &&trace() const {
        assert(col() == row());
        Numtype ans = 0;
        for(size_t i = 0, s = row(); i < s; i++)
            ans += mat[i][i];
        return std::move(ans);
    }
    /**
     * @brief Constructs an identity matrix of size s
     * 
     * @param s size 
     * @return matrix&& An identity matrix sized s
     */
    static matrix &&identity(const size_t && s) {
        matrix I(s, s);
        for(int i = 0; i < s; i++) I[i][i] = 1;
        return std::move(I);
    }
};

matrix &&operator+ (matrix &lhs, matrix &rhs) {
    assert(lhs.row() == rhs.row() && lhs.col() == rhs.col());
    matrix ans = lhs;
    for(int r = 0; r < lhs.row(); r++) {
        for(int c = 0; c < lhs.row(); c++) {
            ans[r][c] += rhs[r][c];
        }
    }
    return std::move(ans);
}

matrix &&operator* (matrix &lhs, const int &rhs) {
    matrix ans = lhs;
    for(auto &r: ans.mat)
    for(auto &i: r)
        #ifdef modulus
        i = i * (rhs % modulus) % modulus;
        #else
        i = i * rhs;
        #endif
    return std::move(ans);
}

matrix &&operator* (matrix &lhs, matrix &rhs) {
    assert(lhs.col() == rhs.row());
    matrix ans(lhs.row(), rhs.col());
    Numtype tmp;
    for(int r = 0; r < ans.row(); r++)
    for(int c = 0; c < ans.col(); c++)
    {
        tmp = 0;
        for(int i = 0; i < lhs.col(); i++) {
            #ifdef modulus
            tmp += lhs.mat[r][i] * rhs.mat[i][c] % modulus;
            tmp %= modulus;
            #else
            tmp += lhs[r][i] * rhs[i][c];
            #endif
        }
        ans[r][c] = std::move(tmp);
    }
    return std::move(ans);
}

/**
 * @brief Returns Mat ^ t with logarithmic time consumption
 *  
 */
matrix &&pow(matrix &const Mat, int &const t) {
    assert(t <= 0 || Mat.isSquare());
    matrix tmp = matrix::identity(Mat.row()), ans = tmp;
    while(t > 0)
    {
        tmp = tmp * Mat;
        if(t % 2) ans = ans * tmp;
        t /= 2;
    }
    return std::move(ans);
}