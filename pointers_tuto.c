#include <iostream>

int main()
{
    // declaration and initialization of a variable that holds the value 30
    int A = 30;
    printf("The value of A is %d\n", A);
    printf("The memory adresse of A is %p\n", &A);
    printf("The size of A is %d\n", sizeof(A));
    printf("\n\n");


// declaration and initialization of a pointer that holds the memory adress of A
    int *PA = &A;
    printf("The value of PA  is %p (the memory adress of a)\n", PA);
    printf("The memory adresse of PA is %p\n", &PA);
    printf("The size of PA is %d\n", sizeof(PA));
    printf("The value PA is pointing at is %d (value of a)\n", *PA);
    printf("\n\n");


//declaration and initialization of a pointer that stores the memory adress of the pointer PA that stores the memory adress of A
    int **PPA = &PA;
    printf("The value of PPA which is the adress of PA is %p\n", PPA);
    printf("The memory adresse of PPA is %p\n", &PPA);
    printf("The size of PPA is %d\n", sizeof(PPA));
    printf("The adress PPA is pointing at is %p (the value of PA which is the adress of A)\n", *PPA);
    printf("The value stored in A which is %d is accessible by deferencing PPA 2 times, %d\n", A, **PPA);
    printf("\n\n");


//declaration and initialization of a pointer that stores the memory of the pointer PPA
//that points the memory adress of PA that stores the memory adress of A

    int ***PPPA = &PPA;
    printf("To access the value of A you need to dereference 3 times, %d", ***PPPA);
}
