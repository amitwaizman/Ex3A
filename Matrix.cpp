#include "Matrix.hpp"
using namespace std;
namespace zich{
    Matrix:: Matrix(const vector<double> &mat1, const int row1, const int column1){
        mat=mat1;
        row=row1;
        column=column1;
    }
    Matrix::Matrix(){
        row=0;
        column=0;
    }
    Matrix::~Matrix(){}
    // copy Constructor
    Matrix::Matrix(const Matrix &other){
       mat=other.mat;
       row=other.row;
       column=other.column;
    }
    Matrix& Matrix::operator+(const Matrix& mat){
        return *this;
    }
    Matrix& Matrix::operator+=(const Matrix& mat){
        return *this;
    }
    Matrix& Matrix::operator+(){
        return *this;
    }
    Matrix& Matrix::operator-=(const Matrix& mat){
        return *this;

    }
    Matrix& Matrix::operator-(const Matrix &other){
        return *this;

    }
    Matrix& Matrix::operator-(){
        return *this;

    }
    Matrix& operator*( double n, Matrix& mat){
        return mat;
    }
    Matrix& Matrix::operator*(const Matrix& mat){
        return *this;
    }
    Matrix& Matrix::operator*=(const Matrix& mat){
        return *this;
    }
    Matrix& Matrix::operator*(const double  n){
        return *this;

    }
    Matrix& Matrix::operator*=(const double  n){
        return *this;
    }


    bool Matrix::operator>(const  Matrix& mat){
        return true;
    }
    bool Matrix::operator>=(const Matrix& mat){
        return true;

    }
    bool Matrix::operator<(const Matrix& mat){
        return true;

    }
    bool Matrix::operator<=(const Matrix& mat){
        return true;

    }
    bool Matrix::operator==(const Matrix& mat){
        return true;

    }
    bool Matrix::operator!=(const Matrix& mat){
        return true;

    }

    Matrix& Matrix::operator++(){
        return *this;
    }
     Matrix Matrix::operator++(int) { //n++
    return *this;
}
    Matrix& Matrix::operator--(){
        return *this;
    }
    Matrix Matrix::operator--(int){
        return *this;

    }

     std::ostream &operator<<(std::ostream &output, const Matrix &c){
        return output;
    }
    std::istream &operator>>(std::istream &input, Matrix &c){
        return input;
    }
};