#include <iostream>
using namespace std;

class DynamicMat {
private:
    int** matrix;
    int rows;
    int cols;

public:
    DynamicMat(int r, int c) : rows(r), cols(c) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    ~DynamicMat() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    DynamicMat(const DynamicMat& other) : rows(other.rows), cols(other.cols) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    DynamicMat& operator=(const DynamicMat& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            rows = other.rows;
            cols = other.cols;
            
            matrix = new int*[rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newMatrix = new int*[newRows];
        
        for (int i = 0; i < newRows; i++) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = fillValue;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; i++) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = transposed;
        swap(rows, cols);
    }

    void addTwoToOddIndices() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i + j) % 2 != 0) {
                    matrix[i][j] += 2;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int get(int i, int j) const {
        return matrix[i][j];
    }

    void set(int i, int j, int value) {
        matrix[i][j] = value;
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }
};

int main() {
    DynamicMat mat(3, 4);
    
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat.set(i, j, count++);
        }
    }

    cout<<"Original Matrix:"<<endl;
    mat.print();
    cout<<"\nAfter adding 2 to odd indices:"<<endl;
    mat.addTwoToOddIndices();
    mat.print();

    cout<<"\nAfter transpose:"<<endl;
    mat.transpose();
    mat.print();
    cout<<"\nAfter resizing to 4x5 with fill value 99:"<<endl;
    mat.resize(4, 5, 99);
    mat.print();
    cout<<"\nAfter resizing to 2x3 with fill value -1:"<<endl;
    mat.resize(2, 3, -1);
    mat.print();
    return 0;
}