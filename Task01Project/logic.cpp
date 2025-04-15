int* find_last_local_min(int** matrix, int n, int m)
{
    if (n <= 0 || m <= 0 || matrix == nullptr)
    {
        return nullptr;
    }

    int* cords = nullptr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int current = matrix[i][j];
            bool is_local_min = true;

            if (i - 1 >= 0 && matrix[i - 1][j] <= current
                || i + 1 < n && matrix[i + 1][j] <= current
                || j - 1 >= 0 && matrix[i][j - 1] <= current
                || j + 1 < m && matrix[i][j + 1] <= current)
            {
                is_local_min = false;
            }

            if (is_local_min)
            {
                if (cords == nullptr)
                {
                    cords = new int[2];
                }
                cords[0] = i;
                cords[1] = j;
            }
        }
    }

    return cords;
}