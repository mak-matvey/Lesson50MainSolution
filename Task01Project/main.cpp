#include "logic.h"
#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cout << "Input size of matrix (n, m): ";
    cin >> n >> m;

    if (n <= 0 || m <= 0)
    {
        cout << "Invalid matrix size!" << endl;
        return 0;
    }

    int** matrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }

    cout << "Input elements of your matrix: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int* local_min_cords = find_last_local_min(matrix, n, m);

    if (local_min_cords != nullptr)
    {
        cout << "Last local min has coordinates [" << local_min_cords[0]
            << ", " << local_min_cords[1] << "]" << " and value "
            << matrix[local_min_cords[0]][local_min_cords[1]] << endl;
        delete[] local_min_cords;
    }
    else
    {
        cout << "Local min not found!" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}