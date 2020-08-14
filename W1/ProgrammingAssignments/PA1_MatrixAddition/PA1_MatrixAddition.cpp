// PA1_MatrixAddition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<exception>

using namespace std;

class Matrix {
private:
    int NumberOfRows;
    int NumberOfColumns;
    vector<vector<int>> matrix;
public:
    Matrix() {
        this->NumberOfColumns = 0;
        this->NumberOfRows = 0;
    }
    Matrix(int nRows, int nCols) {
        Reset(nRows, nCols);
    }

    void SetToZero() {
        for (int i = 0; i < NumberOfRows; ++i) {
            for (int j = 0; j < NumberOfColumns; ++j) {
                matrix[i][j] =0;
            }
        }
    }

    void Reset(int nRows, int nCols) {
        if (nRows != 0 && nCols != 0)
        {
            this->NumberOfRows = nRows;
            this->NumberOfColumns = nCols;
            if (NumberOfColumns < 0 || NumberOfRows < 0) {
                throw out_of_range("Wrong Index");
            }
            matrix.resize(nRows, vector<int>(nCols, 0));
            SetToZero();
        }
        else {
            this->NumberOfRows = 0;
            this->NumberOfColumns = 0;
            if (NumberOfColumns < 0 || NumberOfRows < 0) {
                throw out_of_range("Wrong Index");
            }
            matrix.resize(0, vector<int>(0, 0));
        }
    }

    int At(int row, int col) const {
        if (row >= NumberOfRows || row<0 || col >= NumberOfColumns || col < 0)
        {
            throw out_of_range("");
        }
        return matrix[row][col];
    }

    int& At(int row, int col) {
        if (row >= NumberOfRows || row<0 || col >= NumberOfColumns || col < 0) {
            throw out_of_range("");
        }
        return matrix[row][col];
    }

    int GetNumRows() const {
        return NumberOfRows;
    }

    int GetNumColumns() const {
        return NumberOfColumns;
    }

    vector<vector<int>> GetMatrix() const{
        return matrix;
    }

};

istream& operator>>(istream& stream, Matrix& matrix) {
    if (stream) {
        int nRows;
        stream >> nRows;
        int nCols;
        stream >> nCols;
        matrix.Reset(nRows, nCols);

        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                stream >> matrix.At(i, j);
            }
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows()<<" "<<matrix.GetNumColumns()<<endl;
    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream << matrix.At(i, j);
            if (j < matrix.GetNumColumns() - 1) {
                stream << " ";
            }
        }
        stream << endl;
    }
    return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    bool status = lhs.GetNumColumns() == rhs.GetNumColumns();
    status = status && lhs.GetNumRows() == rhs.GetNumRows();
    status = status && lhs.GetMatrix() == rhs.GetMatrix();
    return status;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() && lhs.GetNumColumns()!=rhs.GetNumColumns()) {
        throw invalid_argument("Different Sizes");
    }
    else {
        Matrix newMatrix(lhs.GetNumRows(), lhs.GetNumColumns());
        for (int i = 0; i < lhs.GetNumRows(); ++i) {
            for (int j = 0; j < lhs.GetNumColumns(); ++j) {
                newMatrix.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
            }
            
        }
        return newMatrix;
    }
}


//int main()
//{
//    Matrix one;
//    Matrix two;
//
//    cin >> one >> two;
//    cout << one + two << endl;
//
//    return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
