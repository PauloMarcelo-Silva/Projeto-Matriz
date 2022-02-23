
//  Aluno: Paulo Marcelo Ribeiro Soeiro da Silva
//  Matricula: 20190040030

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct matrix my_matrix;

    my_matrix = create_matrix(array, 3, 3);
    //my_matrix = random_matrix(3, 3, 3, 9);
    //my_matrix = i_matrix(4);

    //my_matrix = transpose(my_matrix);
    //my_matrix = reshape(my_matrix, 2, 4);
    //my_matrix = flatten(my_matrix);
    my_matrix = slice(my_matrix, 1, 2, 0, 2);

    //printf("\n%d\n", get_element(my_matrix, 3, 1));
    //put_element(my_matrix, 3, 1, 0); **** OBS ****
    //my_matrix = put_element(my_matrix, 1, 1, 5);

    print_matrix(my_matrix);

    //struct matrix a_matrix, b_matrix, c_matrix;
    //a_matrix = create_matrix(array, 3, 3);
    //b_matrix = create_matrix(array, 3, 3);

    //c_matrix = add(a_matrix, b_matrix);
    //c_matrix = sub(a_matrix, b_matrix);
    //c_matrix = division(a_matrix, b_matrix);
    //c_matrix = mul(a_matrix, b_matrix);

    //print_matrix(c_matrix);

    return 0;
}
