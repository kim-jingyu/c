#include <stdio.h>

int main(void)
{
    // 문자 vs 문자열
    // 문자열 끝에는 끝을 의미하는 널 문자 \0 가 포함되어야 한다.
    // 배열 사이즈를 더 크게 잡으면, 널 문자가 알아서 들어간다.
    char str[] = "coding";
    printf("%s\n", str);
    printf("%lu\n", sizeof(str));

    // UTF-8: 영어는 한글자가 1바이트, 한글은 한글자가 3바이트
    // char 크기 : 1바이트
    char kor[] = "나도코딩";
    printf("%s\n", kor);
    printf("%ul\n", sizeof(kor)); // 13l

    // 아스키 코드. null 문자는 0으로 입력됨.
    char c_arr[10] = "coding";
    for (int i = 0; i < sizeof(c_arr); i++)
    {
        printf("%d\n", c_arr[i]);
    }

    return 0;
}