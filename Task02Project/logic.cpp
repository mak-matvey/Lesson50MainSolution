#include "logic.h"

int find_min_among_local_maxima(int** matrix, int n, int m)
{
    if (n <= 0 || m <= 0 || matrix == nullptr)
        return -1;

    int minLocalMax = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int current = matrix[i][j];
            bool isLocalMax = true;

            if (i > 0 && matrix[i - 1][j] >= current)
            {
                isLocalMax = false;
            }

            if (i < n - 1 && matrix[i + 1][j] >= current)
            {
                isLocalMax = false;
            }

            if (j > 0 && matrix[i][j - 1] >= current)
            {
                isLocalMax = false;
            }

            if (j < m - 1 && matrix[i][j + 1] >= current)
            {
                isLocalMax = false;
            }

            if (isLocalMax)
            {
                if (!found)
                {
                    minLocalMax = current;
                    found = true;
                }
                else if (current < minLocalMax)
                {
                    minLocalMax = current;
                }
            }
        }
    }

    return found ? minLocalMax : -1;
}
