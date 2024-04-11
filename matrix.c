#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_martix(int, int, int **);
int addition_matrix(int, int, int **, int **);
int subtraction_matrix(int, int, int **, int **);
int transpose_matrix(int, int, int **, int **);
int multiply_matrix(int, int, int **, int **);
int** create_matrix(int, int); 
int free_matrix(int, int, int **);

int main(){
    int row, column; // 행과 열의 크기 입력
    scanf("행을 입력하세요: %d", &row);
    scanf("열을 입력하세요: %d", &column);

    int **mat1 = create_matrix(row, column); // 첫 번째 행렬 생성
    printf("첫 번째 행렬의 요소를 입력하세요:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    int **mat2 = create_matrix(row, column); // 두 번째 행렬 생성
    printf("두 번째 행렬의 요소를 입력하세요:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("덧셈 행렬:\n"); // 덧셈 행렬 출력
    addition_matrix(row, column, mat1, mat2);

    printf("뺄셈 행렬:\n"); // 뺄셈 행렬 출력
    subtraction_matrix(row, column, mat1, mat2);

    printf("첫 번째 행렬의 전치 행렬:\n"); // 전치 행렬 출력
    int **transposed_mat = create_matrix(column, row);
    transpose_matrix(row, column, mat1, transposed_mat);
    print_matrix(column, row, transposed_mat);
    free_matrix(column, transposed_mat);

    printf("곱셈 행렬:\n"); // 곱셈 행렬 출력
    multiply_matrix(row, column, mat1, mat2);

    free_matrix(row, mat1); // 메모리 해제
    free_matrix(row, mat2);

    return 0;
}

void print_martix(int a, int b, int ** c){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int addition_matrix(int a, int b, int ** c, int ** d){
    int ** sum = create_matrix(a,b);
    for(int i=0;i<a;i++){
        for(int j=0; j<b; j++){
            sum[i][j] = c[i][j] + d[i][j];
        }
        printf("\n");
    }
    print_matrix(sum, a, b);
    free_matrix(sum, a, b);
    return 1;
}

int subtraction_matrix(int a, int b, int ** c, int ** d){
    int ** sub = create_mattrix(a, b);

    for(int i=0; i<a, i++){
        for(int j=0; j<b; j++){
            sub[i][j] = c[i][j] - d[i][j];
        }
        printf("\n");
    }
    print_matrix(sub, a, b);
    free_matrix(sub, a, b);
    return 1;
}

int transpose_matrix(int a, int b, int ** c, int ** d){
    for(int i=0;i<a,i++){
        for(int j=0;j<b;j++){
            d[i][j] = c[i][j];
        }
    }
    return 1;
}

int multiply_matrix(int a, int b, int ** c, int ** d){
    int sum = 0;
    int ** mul = create_matrix(a, a);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            for(int k=0;k<b;k++){
                sum += (c[i][j]*d[i][j]);
            }
        mul[i][j] = sum;
        sum = 0;     
        }
        printf("\n");
    }
    print_matrix(mul, a, a);
    free_matrix(mul, a, a);
    return 1;
}

int** create_matrix(int a, int b){
    int ** x = (int **)malloc(sizeof(int *)*a); //이중포인터형 변수 x에 동적할당

    for(int i=0;i<a;i++){
        x[i] = (int*)malloc(sizeof(int)); //배열 x에 int사이즈로 동적할당
    }
    return x;
}

int free_matrix(int a, int ** c){ //배열의 실제 값이 들어간 부분 해제
    for(int i=0;i<a;i++){
        free(c[i]);
    }
    free(c); //배열의 각 행의 주소들을 저장한 동적할당 해제
}