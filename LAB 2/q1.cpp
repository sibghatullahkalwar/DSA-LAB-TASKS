#include <iostream>
using namespace std;

class resize_matrix {
public:
    int rows_, columns_;
    int** newarr;

    resize_matrix() {
        newarr = NULL;
        rows_ = 0;
        columns_ = 0;
    }

    void create(int r, int c) {
        rows_ = r;
        columns_ = c;

        newarr = new int*[rows_];
        for (int i = 0; i < rows_; i++) {
            newarr[i] = new int[columns_];
        }
    }

    void input() {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < columns_; j++) {
                cin >> newarr[i][j];
            }
        }
    }

    void resize_array(int newrows, int newcols, int initValue = 0) {
        int** temp = new int*[newrows];
        for (int i = 0; i < newrows; i++) {
            temp[i] = new int[newcols];
        }

        for (int i = 0; i < newrows; i++) {
            for (int j = 0; j < newcols; j++) {
                if (i < rows_ && j < columns_)
                    temp[i][j] = newarr[i][j];
                else
                    temp[i][j] = initValue;
            }
        }

        for (int i = 0; i < rows_; i++) {
            delete[] newarr[i];
        }
        delete[] newarr;

        newarr = temp;
        rows_ = newrows;
        columns_ = newcols;
    }

    int** matrix_transpose() {
        int** trans = new int*[columns_];
        for (int i = 0; i < columns_; i++) {
            trans[i] = new int[rows_];
        }

        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < columns_; j++) {
                trans[j][i] = newarr[i][j];
            }
        }
        return trans;
    }

    void add_two_odd_index() {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < columns_; j++) {
                if ((i + j) % 2 != 0) {
                    newarr[i][j] += 2;
                }
            }
        }
    }

    void display() {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < columns_; j++) {
                cout << newarr[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~resize_matrix() {
        if (newarr != NULL) {
            for (int i = 0; i < rows_; i++) {
                delete[] newarr[i];
            }
            delete[] newarr;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    resize_matrix obj;
    obj.create(rows, cols);

    cout << "Enter matrix elements:" << endl;
    obj.input();

    cout << endl << "Original Matrix:" << endl;
    obj.display();

    int newrows, newcols;
    cout << endl << "Enter new rows and columns: ";
    cin >> newrows >> newcols;

    obj.resize_array(newrows, newcols, 0);

    cout << endl << "Resized Matrix:" << endl;
    obj.display();

    obj.add_two_odd_index();
    cout << endl << "After adding 2 to odd indices:" << endl;
    obj.display();

    int** trans = obj.matrix_transpose();
    cout << endl << "Transpose Matrix:" << endl;
    for (int i = 0; i < obj.columns_; i++) {
        for (int j = 0; j < obj.rows_; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < obj.columns_; i++) {
        delete[] trans[i];
    }
    delete[] trans;

    return 0;
}

