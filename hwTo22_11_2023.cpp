#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>
#include <fstream>
#include <cassert>

#define int long long

using namespace std;

void clearFile(const string& filename) {
    ofstream file(filename, ios::trunc);
    file.close();
}
void sumOfMatrices(int** matrix1, int** matrix2, int** resultMatrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void countZeroRows(int** matrix, int rows, int cols, int& zeroRowCount) {
    zeroRowCount = 0;

    for (int i = 0; i < rows; ++i) {
        bool isZeroRow = true;

        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                isZeroRow = false;
                break;
            }
        }

        if (isZeroRow) {
            zeroRowCount++;
        }
    }
}
bool hasDiagonalDominance(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        int diagonalElement = abs(matrix[i][i]);
        int sumOfOtherElements = 0;

        for (int j = 0; j < size; ++j) {
            if (j != i) {
                sumOfOtherElements += abs(matrix[i][j]);
            }
        }

        if (diagonalElement < sumOfOtherElements) {
            return false;
        }
    }

    return true;
}
void generateMatrix(int** matrix, int size) {
    int tempValOfCell;
    for (int i = 0; i < size; ++i) {
        tempValOfCell = 1;

        for(int k = 0;k<i;k++){
            matrix[i][k] = matrix[0][size-i+k];
        }

        for (int j = i; j < size; ++j) {
            matrix[i][j] = tempValOfCell;
            tempValOfCell++;
        }

    }
}

void hwToTwentySecondDecemberTaskFirst(){
    ifstream inputFile("inputForTask1.txt");
    ofstream outputFile("outputForTask1.txt");

    int rows, cols;

    inputFile >> rows >> cols;

    int** matrix1 = new int*[rows];
    int** matrix2 = new int*[rows];
    int** resultMatrix = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        resultMatrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> matrix2[i][j];
        }
    }

    sumOfMatrices(matrix1, matrix2, resultMatrix, rows, cols);
    outputFile<<rows<<' '<<cols<<endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outputFile << resultMatrix[i][j] << " ";
        }
        outputFile << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] resultMatrix[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix;

    inputFile.close();
    outputFile.close();
}
void hwToTwentySecondDecemberTaskFirstTest() {
    ofstream inputFile("inputForTask1.txt");
    inputFile << "3 3" << endl;

    inputFile << "1 2 3" << endl;
    inputFile << "7 8 9" << endl;
    inputFile << "7 8 9" << endl;

    inputFile << "9 8 7" << endl;
    inputFile << "6 5 4" << endl;
    inputFile << "3 2 1" << endl;
    inputFile.close();
    hwToTwentySecondDecemberTaskFirst();
    ifstream outputFile("outputForTask1.txt");
    int expectedResults[3][3] = {
            {10, 10, 10},
            {13, 13, 13},
            {10, 10, 10}
    };

    int rows, cols;
    outputFile >> rows >> cols;
    assert(rows == 3);
    assert(cols == 3);

    int result;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outputFile >> result;
            assert(result == expectedResults[i][j]);
        }
    }
    outputFile.close();
}


void hwToTwentySecondDecemberTaskSecond() {
    ifstream inputFile("inputForTask2.txt");
    ofstream outputFile("outputForTask2.txt");

    int rows, cols;

    inputFile >> rows >> cols;

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    int zeroRowCount;
    countZeroRows(matrix, rows, cols, zeroRowCount);

    outputFile << zeroRowCount;

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    inputFile.close();
    outputFile.close();
}
void hwToTwentySecondDecemberTaskSecondTest() {
    ofstream inputFile("inputForTask2.txt");
    inputFile << "3 3" << std::endl;
    inputFile << "0 0 0" << std::endl;
    inputFile << "1 2 3" << std::endl;
    inputFile << "0 0 0" << std::endl;
    inputFile.close();
    hwToTwentySecondDecemberTaskSecond();
    ifstream outputFile("outputForTask2.txt");
    int zeroRowCount;
    outputFile >> zeroRowCount;
    assert(zeroRowCount == 2);
    outputFile.close();
}


void hwToTwentySecondDecemberTaskThird() {
    ifstream inputFile("inputForTask3.txt");
    ofstream outputFile("outputForTask3.txt");
    int size;
    inputFile >> size;
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    bool hasDominance = hasDiagonalDominance(matrix, size);
    outputFile << (hasDominance ? "Yes" : "No")<<endl;

    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    inputFile.close();
    outputFile.close();
}
void hwToTwentySecondDecemberTaskThirdTest() {
    ofstream inputFile("inputForTask3.txt");
    inputFile << "3" << endl;
    inputFile << "3 2 1" << endl;
    inputFile << "2 1 3" << endl;
    inputFile << "1 3 2" << endl;
    inputFile.close();
    hwToTwentySecondDecemberTaskThird();
    ifstream outputFile("outputForTask3.txt");
    string result;
    outputFile >> result;
    assert(result == "No");
    outputFile.close();

    clearFile("inputForTask3.txt");
    clearFile("outputForTask3.txt");

    inputFile = ofstream ("inputForTask3.txt");
    inputFile << "3" << endl;
    inputFile << "2 1 1" << endl;
    inputFile << "1 7 1" << endl;
    inputFile << "1 1 3" << endl;
    inputFile.close();
    hwToTwentySecondDecemberTaskThird();
    outputFile = ifstream ("outputForTask3.txt");
    outputFile >> result;
    assert(result == "Yes");
    outputFile.close();

}

void hwToTwentySecondDecemberTaskFourth() {
    ifstream inputFile("inputForTask4.txt");
    ofstream outputFile("outputForTask4.txt");

    int size;

    inputFile >> size;
    size--;

    int** matrix = new int*[size];

    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    generateMatrix(matrix, size);
    outputFile<<size+1<<endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            outputFile << matrix[i][j] << ' ';
        }
        outputFile << endl;
    }

    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    inputFile.close();
    outputFile.close();
}
void hwToTwentySecondDecemberTaskFourthTest() {
    int size = 5;
    ofstream inputFile("inputForTask4.txt");

    inputFile << size<< endl;
    inputFile.close();

    hwToTwentySecondDecemberTaskFourth();

    ifstream outputFile("outputForTask4.txt");

    outputFile >> size;
    size--;
    int** matrix = new int*[size];

    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            outputFile >> matrix[i][j];
        }
    }

    int expectedResults[5-1][5-1] = {
            {1, 2, 3, 4},
            {4, 1, 2,3},
            {3, 4, 1,2},
            {2, 3,4,1}
    };

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            assert(matrix[i][j] == expectedResults[i][j]);
        }
    }

    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    outputFile.close();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    hwToTwentySecondDecemberTaskFirstTest();
    hwToTwentySecondDecemberTaskSecondTest();
    hwToTwentySecondDecemberTaskThirdTest();
    hwToTwentySecondDecemberTaskFourthTest();

    return 0;
}
