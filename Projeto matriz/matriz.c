
//  Aluno: Paulo Marcelo Ribeiro Soeiro da Silva
//  Matricula: 20190040030

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Funções para criação de matrizes

struct matrix create_matrix(int *data, int n_rows, int n_cols)
{
    struct matrix matrix;

    matrix.data[(n_rows * n_cols)];
    matrix.n_rows = n_rows;
    matrix.n_cols = n_cols;
    matrix.stride_rows = n_cols;
    matrix.stride_cols = 1;
    matrix.offset = 0;
    for (int i = 0; i < (n_rows * n_cols); i++)
    {
        matrix.data[i] = data[i];
    }

    return matrix;
}

struct matrix zeros_matrix(int n_rows, int n_cols)
{
    struct matrix zeros;

    zeros.data[(n_rows * n_cols)];
    zeros.n_rows = n_rows;
    zeros.n_cols = n_cols;
    zeros.stride_rows = n_cols;
    zeros.stride_cols = 1;
    zeros.offset = 0;
    for (int i = 0; i < (n_rows * n_cols); i++)
    {
        zeros.data[i] = 0;
    }

    return zeros;
}

struct matrix random_matrix(int n_rows, int n_cols, int b, int e)
{
    struct matrix random;

    random.data[(n_rows * n_cols)];
    for (int i = 0; i < (n_rows * n_cols); i++)
    {
        random.data[i] = b + (rand() % (e + 1 - b));
    }
    random.n_rows = n_rows;
    random.n_cols = n_cols;
    random.stride_rows = n_cols;
    random.stride_cols = 1;
    random.offset = 0;

    return random;
}

struct matrix i_matrix(int n)
{
    struct matrix ident;

    ident.data[(n * n)];
    ident.n_rows = n;
    ident.n_cols = n;
    ident.stride_rows = n;
    ident.stride_cols = 1;
    ident.offset = 0;
    int aux = 0;
    for (int i = 0; i < (n * n); i++)
    {
        if (i == aux)
        {
            ident.data[i] = 1;
            aux = aux + n + 1;
        }
        else
        {
            ident.data[i] = 0;
        }
    }

    return ident;
}

// Funções para manipulação de dimensões

struct matrix transpose(struct matrix a_matrix)
{
    struct matrix transpose;

    transpose.data[(a_matrix.n_rows * a_matrix.n_cols)];
    transpose.n_rows = a_matrix.n_cols;
    transpose.n_cols = a_matrix.n_rows;
    transpose.stride_rows = transpose.n_cols;
    transpose.stride_cols = 1;
    transpose.offset = 0;
    for (int i = 0; i < transpose.n_rows; i++)
    {
        for (int j = 0; j < transpose.n_cols; j++)
        {
            transpose.data[transpose.offset] = a_matrix.data[(a_matrix.offset + i)];
            a_matrix.offset = (a_matrix.offset + a_matrix.stride_rows);
            transpose.offset++;
        }
        a_matrix.offset = 0;
    }
    transpose.offset = 0;

    return transpose;
}

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols)
{
    if ((new_n_rows * new_n_cols) != (a_matrix.n_rows * a_matrix.n_cols))
    {
        printf("\nError ao redimensionar\n   Dimensões invalidas\n");
        return a_matrix;
    }
    else
    {
        struct matrix reshape;

        reshape.data[(new_n_rows * new_n_cols)];
        reshape.n_rows = new_n_rows;
        reshape.n_cols = new_n_cols;
        reshape.stride_rows = new_n_cols;
        reshape.stride_cols = 1;
        reshape.offset = 0;
        for (int i = 0; i < (new_n_rows * new_n_cols); i++)
        {
            reshape.data[i] = a_matrix.data[i];
        }

        return reshape;
    }
}

struct matrix flatten(struct matrix a_matrix)
{
    struct matrix flatten;

    flatten.data[(a_matrix.n_rows * a_matrix.n_cols)];
    flatten.n_rows = 1;
    flatten.n_cols = (a_matrix.n_rows * a_matrix.n_cols);
    flatten.stride_rows = 0;
    flatten.stride_cols = 1;
    flatten.offset = 0;
    for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
    {
        flatten.data[i] = a_matrix.data[i];
    }

    return flatten;
}

struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce)
{

    struct matrix slice;

    slice.data[((re - rs) + 1) * ((ce - cs) + 1)];
    slice.n_rows = ((re - rs) + 1);
    slice.n_cols = ((ce - cs) + 1);
    slice.stride_rows = slice.n_cols;
    slice.stride_cols = 1;
    slice.offset = 0;
    for (int i = 0; i < ((re - rs) + 1); i++)
    {
        for (int j = 0; j < ((ce - cs) + 1); j++)
        {
            slice.data[a_matrix.offset] = a_matrix.data[(((a_matrix.stride_rows) * (rs + i))) + (cs) + j];
            a_matrix.offset++;
        }
    }

    return slice;
}

// Funções para acessar elementos

int get_element(struct matrix a_matrix, int ri, int ci)
{
    int element = a_matrix.data[((a_matrix.stride_rows * ri) - a_matrix.stride_rows) + (ci - 1)];

    return element;
}
//                                *****OBS*****                                //
void put_element(struct matrix a_matrix, int ri, int ci, int elem)
{
    a_matrix.data[((a_matrix.stride_rows * ri) - a_matrix.stride_rows) + (ci - 1)] = elem;
    //printf("%d\n", a_matrix.data[((a_matrix.stride_rows * ri) - a_matrix.stride_rows) + (ci - 1)]);

    //return a_matrix;
}
//                                *****OBS*****                                //
void print_matrix(struct matrix a_matrix)
{
    for (int x = 0; x < a_matrix.n_rows; x++)
    {
        if (x == 0)
        {
            printf("\n{");
        };
        printf("{");
        for (int y = 0; y < a_matrix.n_cols; y++)
        {
            printf("%d", a_matrix.data[a_matrix.offset]);
            a_matrix.offset++;
            if (y == a_matrix.n_cols - 1)
            {
                printf("}");
            }
            else
            {
                printf(",");
            }
        }
        if (x == a_matrix.n_rows - 1)
        {
            printf("}");
        }
        printf("\n ");
    }
}

// Funções de agregação

int sum(struct matrix a_matrix)
{
    int sum = 0;
    for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
    {
        sum = sum + a_matrix.data[i];
    }

    return sum;
}

float mean(struct matrix a_matrix)
{
    float mean, sum = 0, div = 0;
    for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
    {
        sum = sum + a_matrix.data[i];
        div++;
    }
    mean = (sum / div);

    return mean;
}

int min(struct matrix a_matrix)
{
    int min = a_matrix.data[0];
    for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
    {
        if (a_matrix.data[i] < min)
        {
            min = a_matrix.data[i];
        }
        else
        {
            continue;
        }
    }

    return min;
}

int max(struct matrix a_matrix)
{
    int max = a_matrix.data[0];
    for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
    {
        if (a_matrix.data[i] > max)
        {
            max = a_matrix.data[i];
        }
        else
        {
            continue;
        }
    }

    return max;
}

// Funções de operações aritméticas

struct matrix add(struct matrix a_matrix, struct matrix b_matrix)
{
    if (a_matrix.n_rows != b_matrix.n_rows && a_matrix.n_cols != b_matrix.n_cols)
    {
        printf("Error\n   Matrizes distintas");
    }
    else
    {
        struct matrix add;
        add.data[(a_matrix.n_rows * a_matrix.n_cols)];
        for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
        {
            add.data[i] = (a_matrix.data[i] + b_matrix.data[i]);
        }
        add.n_rows = a_matrix.n_rows;
        add.n_cols = a_matrix.n_cols;
        add.stride_rows = add.n_cols;
        add.stride_cols = 1;
        add.offset = 0;

        return add;
    }
}

struct matrix sub(struct matrix a_matrix, struct matrix b_matrix)
{
    if (a_matrix.n_rows != b_matrix.n_rows && a_matrix.n_cols != b_matrix.n_cols)
    {
        printf("Error\n   Matrizes distintas");
    }
    else
    {
        struct matrix sub;
        sub.data[(a_matrix.n_rows * a_matrix.n_cols)];
        for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
        {
            sub.data[i] = (a_matrix.data[i] - b_matrix.data[i]);
        }
        sub.n_rows = a_matrix.n_rows;
        sub.n_cols = a_matrix.n_cols;
        sub.stride_rows = sub.n_cols;
        sub.stride_cols = 1;
        sub.offset = 0;

        return sub;
    }
}

struct matrix division(struct matrix a_matrix, struct matrix b_matrix)
{
    if (a_matrix.n_rows != b_matrix.n_rows && a_matrix.n_cols != b_matrix.n_cols)
    {
        printf("Error\n   Matrizes distintas");
    }
    else
    {
        struct matrix div;
        div.data[(a_matrix.n_rows * a_matrix.n_cols)];
        for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
        {
            div.data[i] = (a_matrix.data[i] / b_matrix.data[i]);
        }
        div.n_rows = a_matrix.n_rows;
        div.n_cols = a_matrix.n_cols;
        div.stride_rows = div.n_cols;
        div.stride_cols = 1;
        div.offset = 0;

        return div;
    }
}

struct matrix mul(struct matrix a_matrix, struct matrix b_matrix)
{
    if (a_matrix.n_rows != b_matrix.n_rows && a_matrix.n_cols != b_matrix.n_cols)
    {
        printf("Error\n   Matrizes distintas");
    }

    {
        struct matrix mul;
        mul.data[(a_matrix.n_rows * a_matrix.n_cols)];
        for (int i = 0; i < (a_matrix.n_rows * a_matrix.n_cols); i++)
        {
            mul.data[i] = (a_matrix.data[i] * b_matrix.data[i]);
        }
        mul.n_rows = a_matrix.n_rows;
        mul.n_cols = a_matrix.n_cols;
        mul.stride_rows = mul.n_cols;
        mul.stride_cols = 1;
        mul.offset = 0;

        return mul;
    }
}

struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix) {}
