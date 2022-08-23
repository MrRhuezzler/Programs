// Strassen Multiplication

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::vector<std::vector<int>> int2D;
typedef std::vector<int> int1D;

#define print1D(vec)           \
    for (int e : vec)          \
    {                          \
        std::cout << e << ' '; \
    }

#define print(vec)         \
    for (int1D e : vec)    \
    {                      \
        print1D(e);        \
        std::cout << "\n"; \
    }

void paddZeros(std::vector<std::vector<int>> &mat)
{

    int nearestPowerOfTwo = 0;
    int size = mat.size();
    while (pow(2, nearestPowerOfTwo) < size)
        nearestPowerOfTwo++;

    int new_size = pow(2, nearestPowerOfTwo);
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j < new_size; j++)
            mat[i].push_back(0);
    }

    for (int i = size; i < new_size; i++)
    {
        mat.push_back(std::vector<int>(new_size, 0));
    }
}

// A - B
int2D subtract(const int2D &A, const int2D &B)
{
    int2D C;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        int1D row;
        for (int j = 0; j < size; j++)
        {
            row.push_back(A[i][j] - B[i][j]);
        }
        C.push_back(row);
    }

    return C;
}

// A + B
int2D add(const int2D &A, const int2D &B)
{
    int2D C;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        int1D row;
        for (int j = 0; j < size; j++)
        {
            row.push_back(A[i][j] + B[i][j]);
        }
        C.push_back(row);
    }

    return C;
}

// A * B
int2D multiply(const int2D &A, const int2D &B, int size)
{

    int2D result;

    if (size == 2)
    {
        int a, b, c, d, e, f, g, h;

        a = A[0][0];
        e = B[0][0];

        b = A[0][1];
        f = B[0][1];

        c = A[1][0];
        g = B[1][0];

        d = A[1][1];
        h = B[1][1];

        int p1, p2, p3, p4, p5, p6, p7;

        p1 = a * (f - h);
        p2 = (a + b) * h;
        p3 = (c + d) * e;
        p4 = d * (g - e);
        p5 = (a + d) * (e + h);
        p6 = (b - d) * (g + h);
        p7 = (a - c) * (e + f);

        int upperLeft, upperRight, bottomLeft, bottomRight;
        upperLeft = p5 + p4 - p2 + p6;
        upperRight = p1 + p2;
        bottomLeft = p3 + p4;
        bottomRight = p1 + p5 - p3 - p7;

        result.push_back({upperLeft, upperRight});
        result.push_back({bottomLeft, bottomRight});
    }
    else
    {

        int new_size = size / 2;
        int2D a, b, c, d, e, f, g, h;

        // Split matrices A, B into 4 sub matrices
        // Top Left
        for (int i = 0; i < new_size; i++)
        {
            int1D rowA;
            int1D rowB;
            for (int j = 0; j < new_size; j++)
            {
                rowA.push_back(A[i][j]);
                rowB.push_back(B[i][j]);
            }
            a.push_back(rowA);
            e.push_back(rowB);
        }

        // Top Right
        for (int i = 0; i < new_size; i++)
        {
            int1D rowA;
            int1D rowB;
            for (int j = new_size; j < size; j++)
            {
                rowA.push_back(A[i][j]);
                rowB.push_back(B[i][j]);
            }
            b.push_back(rowA);
            f.push_back(rowB);
        }

        // Bottom Left
        for (int i = new_size; i < size; i++)
        {
            int1D rowA;
            int1D rowB;
            for (int j = 0; j < new_size; j++)
            {
                rowA.push_back(A[i][j]);
                rowB.push_back(B[i][j]);
            }
            c.push_back(rowA);
            g.push_back(rowB);
        }

        // Bottom Right
        for (int i = new_size; i < size; i++)
        {
            int1D rowA;
            int1D rowB;
            for (int j = new_size; j < size; j++)
            {
                rowA.push_back(A[i][j]);
                rowB.push_back(B[i][j]);
            }
            d.push_back(rowA);
            h.push_back(rowB);
        }

        int2D p1, p2, p3, p4, p5, p6, p7;
        p1 = multiply(a, subtract(f, h), new_size);
        p2 = multiply(add(a, b), h, new_size);
        p3 = multiply(add(c, d), e, new_size);
        p4 = multiply(d, subtract(g, e), new_size);
        p5 = multiply(add(a, d), add(e, h), new_size);
        p6 = multiply(subtract(b, d), add(g, h), new_size);
        p7 = multiply(subtract(a, c), add(e, f), new_size);

        int2D upperLeft, upperRight, bottomLeft, bottomRight;

        upperLeft = add(add(p5, subtract(p4, p2)), p6);
        upperRight = add(p1, p2);
        bottomLeft = add(p3, p4);
        bottomRight = add(p1, subtract(p5, add(p3, p7)));

        for (int i = 0; i < size; i++)
        {
            int1D row;
            for (int j = 0; j < size; j++)
            {
                // Upper or Lower
                if (i < new_size)
                {
                    // Upper
                    if (j < new_size)
                    {
                        // Left
                        row.push_back(upperLeft[i][j]);
                    }
                    else
                    {
                        // Right
                        row.push_back(upperRight[i][new_size - j]);
                    }
                }
                else
                {
                    // Lower
                    if (j < new_size)
                    {
                        // Left
                        row.push_back(bottomLeft[new_size - i][j]);
                    }
                    else
                    {
                        // Right
                        row.push_back(bottomRight[new_size - i][new_size - j]);
                    }
                }
            }

            result.push_back(row);
        }
    }

    return result;
}

int2D strassen(int2D &A, int2D &B)
{

    int2D C;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        C.push_back(int1D(size, -1));
    }

    multiply(A, B, size);
    return C;
}

int main()
{

    int2D A = {{1, 1, 2, 2}, {1, 1, 2, 2}, {3, 3, 4, 4}, {3, 3, 4, 4}};
    int2D B = {{1, 1, 2, 2}, {1, 1, 2, 2}, {3, 3, 4, 4}, {3, 3, 4, 4}};

    strassen(A, B);

    // print(A);
    // std::cout << std::endl;
    // print(B)
    //         std::cout
    //     << std::endl;

    return 0;
}