#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
/*******************************************
 * a[i][j]->a[j][n-1-i]->a[n-1-i][n-j-1]->a[n-j-1][i]->a[i][j]
 * 
 * 
 * *******************************************/
int inplace_rotation90(vector<vector<int>> &image)
{
    // 90 degree clockwise rotation in-place
    int n = image.size();
    int m = image[0].size();

    if (m != n)
    {
        return 1;
    }
    int a0, a1, c = 0;
    for (int i = 0; i < (n - 1); ++i)
    {
        for (int j = i; j < (n - i - 1); ++j)
        {
            a0 = image[j][n - 1 - i];
            image[j][n - 1 - i] = image[i][j];
            a1 = image[n - 1 - i][n - j - 1];
            image[n - 1 - i][n - j - 1] = a0;
            a0 = image[n - j - 1][i];
            image[n - j - 1][i] = a1;
            image[i][j] = a0;
            ++c;
        }
    }
    // cout << "there should be " << n * n / 4 << " iterations, and there was " << c << " iterations\n";
    // if (n * n / 4 == c)
    //     cout << "PASSED\n";
    // else
    //     cout << "FAILED\n";
    return 0;
}

vector<vector<int>> get_test_image(int n)
{
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] = i * n + j;
    return mat;
}

void print_matVec(vector<vector<int>> mat)
{
    int n = mat.size();
    if (n == 0)
        return;
    int m = mat[0].size();
    if (m == 0)
        return;
    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << mat[i][j];
            if (j < m - 1)
                cout << ", ";
        }
        if (i < n - 1)
            cout << "\n";
    }
    cout << "]\n";
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> image = get_test_image(n);
    print_matVec(image);
    inplace_rotation90(image);
    print_matVec(image);
    return 0;
}