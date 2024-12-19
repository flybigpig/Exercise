#include <iostream>
#include <cstdlib>
void allocate2DArray(int ***arr, int rows, int cols)
{
    *arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        (*arr)[i] = new int[cols];
    }
}
void deallocate2DArray(int ***arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] (*arr)[i];
    }
    delete[] *arr;
    *arr = nullptr;
}
int main()
{
    int **matrix;
    int rows = 3;
    int cols = 4;
    allocate2DArray(&matrix, rows, cols);
    // 初始化二维数组
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i * cols + j;
        }
    }
    // 输出二维数组
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    deallocate2DArray(&matrix, rows);
    return 0;
}