#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{

    printf("[Datatype] char (%ld bytes)\n", sizeof(char));

    printf("[unsigned char] MAX : %d\n", UCHAR_MAX);
    printf("[unsigned char] MIN : %d\n", 0);

    printf("[signed char] MAX : %d\n", CHAR_MAX);
    printf("[signed char] MIN : %d\n\n", CHAR_MIN);

    printf("[Datatype] short (%ld bytes)\n", sizeof(short));

    printf("[unsigned short] MAX : %d\n", USHRT_MAX);
    printf("[unsigned short] MIN : %d\n", 0);

    printf("[signed short] MAX : %d\n", SHRT_MAX);
    printf("[signed short] MIN : %d\n\n", SHRT_MIN);

    printf("[Datatype] int (%ld bytes)\n", sizeof(int));

    printf("[unsigned int] MAX : %u\n", UINT_MAX);
    printf("[unsigned int] MIN : %d\n", 0);

    printf("[signed int] MAX : %d\n", INT_MAX);
    printf("[signed int] MIN : %d\n\n", INT_MIN);

    printf("[Datatype] float (%ld bytes)\n", sizeof(float));

    printf("MAX : %g\n", FLT_MAX);
    printf("MIN : %g\n\n", FLT_MIN);

    printf("[Datatype] double (%ld bytes)\n", sizeof(double));

    printf("MAX : %g\n", DBL_MAX);
    printf("MIN : %g\n\n", DBL_MIN);

    printf("[Datatype] long (%ld bytes)\n", sizeof(long));

    printf("[unsigned long] MAX : %lu\n", ULONG_MAX);
    printf("[unsigned long] MIN : %d\n", 0);

    printf("[signed long] MAX : %ld\n", LONG_MAX);
    printf("[signed long] MIN : %ld\n\n", LONG_MIN);
}