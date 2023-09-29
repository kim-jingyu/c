#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int * a, int * b);

int main(void) {
    int arr[] = { 5, 10, 15 };
    int *ptr = arr; // arr 배열의 시작 주소
    printf("%d\n", ptr);
    
    for (int i = 0; i < 3; i++) {
        printf("ptr[%d] = %d \n", i, ptr[i]);
    }

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    for (int i = 0; i < 3; i++) {
        // printf("arr[%d] = %d \n", i, arr[i]);
        printf("arr[%d] = %d \n", i, *(arr + i));
    }

    // *(arr + i) 와 arr[i] 는 똑같은 표현이다.
    printf("%d, ", arr);
    printf("%d\n", arr + 1);

    printf("arr 자체의 값 : %d\n", arr);
    printf("arr[0] 시작 주소값 : %d\n", &arr[0]);

    printf("arr 자체 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr + 0)
    printf("arr[0]의 실제 값 : %d\n", *&arr[0]);

    // *& 는 상쇄된다. 왜냐하면, & 는 그 변수의 주소이고, *는 그 변수의 주소에 있는 값이기 때문이다. 
    printf("%d\n", &arr[1]);

    // SWAP. Call By Value : 값만 복사한다는 의미. 즉, 메모리 주소가 다르다.
    // 그렇다면 메모리 공간에 있는 주소 자체를 넘기면?
    int a = 10;
    int b = 20;
    printf("a의 주소 : %d\n", &a);
    printf("b의 주소 : %d\n", &b);

    swap(&a, &b);

    printf("a의 값 : %d\n", a);
    printf("b의 값 : %d\n", b);

    // scanf에서 &num과 같이 &를 같이 사용하는 이유

    printf("%ld\n", clock());

    return 0;
}

void swap(int * a, int * b) {
    printf("a의 주소 : %d\n", a);
    printf("b의 주소 : %d\n", b);
    
    int temp = *a;
    *a = *b;
    *b = temp;
}