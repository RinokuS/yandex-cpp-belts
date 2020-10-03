#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        num_rows_ = 0;
        num_columns_ = 0;
    }

    Matrix(int num_rows, int num_columns) {
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            num_rows = num_columns = 0;
        }

        num_rows_ = num_rows;
        num_columns_ = num_columns;
        elements_.assign(num_rows, vector<int>(num_columns));
    }

    int& At(int row, int column) {
        return elements_.at(row).at(column);
    }

    int At(int row, int column) const {
        return elements_.at(row).at(column);
    }

    int GetNumRows() const {
        return num_rows_;
    }

    int GetNumColumns() const {
        return num_columns_;
    }
private:
    int num_rows_;
    int num_columns_;

    vector<vector<int>> elements_;
};

ostream& operator<<(ostream& out, const Matrix& matrix){
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << endl;
    }

    return out;
}

istream& operator>>(istream& in, Matrix& matrix){
    int rows, columns;
    in >> rows >> columns;
    matrix = Matrix(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            in >> matrix.At(i, j);
        }
    }

    return in;
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2){
    if (matrix1.GetNumRows() != matrix2.GetNumRows()){
        return false;
    } else if (matrix1.GetNumColumns() != matrix2.GetNumColumns()){
        return false;
    }

    for (int i = 0; i < matrix1.GetNumRows(); ++i) {
        for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
            if (matrix1.At(i,j) != matrix2.At(i,j)){
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2){
    if (matrix1.GetNumRows() != matrix2.GetNumRows()){
        throw invalid_argument("");
    } else if (matrix1.GetNumColumns() != matrix2.GetNumColumns()){
        throw invalid_argument("");
    }

    Matrix ans = {matrix2.GetNumRows(), matrix2.GetNumColumns()};

    for (int i = 0; i < matrix1.GetNumRows(); ++i) {
        for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
            ans.At(i,j) = matrix1.At(i,j) + matrix2.At(i,j);
        }
    }

    return ans;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
