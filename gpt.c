#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int User_choice();
int **Allocate_2d_Array(int r, int c);
void free_array(int **array, int r);
void accept_array(int **array, int r, int c);
void show_array(int **array, int r, int c);
void Arithmetic(int **arr1, int **arr2, int r, int c, int choice, int **result);
void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {

    printf("\e[J");

    int row = 0, col = 0;

    int choice = User_choice();
    gotoxy(18, 24);
    printf("What is the number of rows: ");
    scanf("%d", &row);
    gotoxy(18, 24);
    printf("What is the number of columns: ");
    scanf("%d", &col); 

    int **array1 = Allocate_2d_Array(row, col);
    int **array2 = Allocate_2d_Array(row, col);
    int **result = Allocate_2d_Array(row, col);
    
    gotoxy(18, 24);
    printf("\e[3m Enter the elements of the first array:\n\n");
    accept_array(array1, row, col);
    gotoxy(18, 24);
    printf("\e[1;31m Enter the elements of the second array:\n");
    accept_array(array2, row, col);
    printf("\e[2J");

    
    gotoxy(10, 4);
    printf("************************************* Result *********************************************\n");
    switch (choice)
    {
    case 1:
        gotoxy(38, 8);
        printf("\e[1;31mADDITION OF MATRIX");
        break;
    case 2:
        gotoxy(38, 8);
        printf("\e[1;32mSUBTRACTION OF MATRIX");
        break;
    case 3:
        gotoxy(38, 8);
        printf("\e[1;33mMULTIPLICATION OF MATRIX");
        break;
    case 4:
        gotoxy(38, 8);
        printf("\e[1;34mDIVISION OF MATRIX");
        break;
    case 5:
        gotoxy(38, 8);
        printf("\e[1;35mREMAINDERS OF MATRIX");
        break;
    
    }

    printf("\nFirst array:\n");
    show_array(array1, row, col);
    printf("--------------------");
    printf("\nSecond array:\n");
    show_array(array2, row, col);
    printf("--------------------");
    Arithmetic(array1, array2, row, col, choice, result);
    printf("\nRESULT : \n\n");
    show_array(result, row, col);
    printf("--------------------");

    printf("\n************************************* END ************************************************\n");

    free_array(result, row);
    free_array(array2, row);
    free_array(array1, row);

    printf("\e[0m");

    return 0;
}

int **Allocate_2d_Array(int r, int c) {
    int **arr = (int **)calloc(r, sizeof(int *));
    if (arr == NULL) {
        printf("\nMemory not allocated\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < r; i++) {
        arr[i] = (int *)calloc(c, sizeof(int));
        if (arr[i] == NULL) {
            printf("\nMemory not allocated\n");
            exit(EXIT_FAILURE);
        }
    }
    return arr;
}

void free_array(int **array, int r) {
    for (int i = 0; i < r; i++) {
        free(array[i]);
    }
    free(array);
}

void accept_array(int **array, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            gotoxy(20, 26);
            printf("   Enter element of row %d and Col %d -> ",i,j);
            scanf("%d", &array[i][j]);
            
        }
    }
}

void show_array(int **array, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

int User_choice()
{
     int choice = 0;
    do{
     
     gotoxy(21,8);
    printf("\e[1;30m \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 MATRIX MATH \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    gotoxy(21,10);
    printf("\e[1;33m \xb2\xb2\xb2\xb2 1. Addition ");
    gotoxy(21,12);
    printf("\e[1;33m \xb2\xb2\xb2\xb2 2. Subtraction ");
    gotoxy(21,14);
    printf("\e[1;33m \xb2\xb2\xb2\xb2 3. Multiply ");
    gotoxy(21,16);
    printf("\e[1;33m \xb2\xb2\xb2\xb2 4. Division ");
    gotoxy(21,18);
    printf("\e[1;33m \xb2\xb2\xb2\xb2 5. Remainders");
    gotoxy(21,20);
    printf("\e[1;30m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
    printf(" \n\t\tEnter your choice : ");
    scanf("%d", &choice);
    }while (choice > 5 || choice < 1);
    
    return choice;
}

void Arithmetic(int **arr1, int **arr2, int r, int c, int choice, int **result)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(choice == 1) result[i][j] = arr1[i][j] + arr2[i][j];
            if(choice == 2) result[i][j] = arr1[i][j] - arr2[i][j];
            if(choice == 3) result[i][j] = arr1[i][j] * arr2[i][j];
            if(choice == 4) result[i][j] = arr1[i][j] / arr2[i][j];
            if(choice == 5) result[i][j] = arr1[i][j] % arr2[i][j];
        }
        printf("\n");
    }
}
