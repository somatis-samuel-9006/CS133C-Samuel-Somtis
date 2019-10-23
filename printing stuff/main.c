#include <stdio.h>
#include <stdlib.h>
int a = 5;
char letter = 'S';
char name[] = "Samuel";
float b = 5.5;
long long bignum = 453453452664356;
unsigned int c = 1;

int main()
{
    printf("%d is an integer\n", a);
    printf("%f is a float\n", b);
    printf("%u is an unsigned int\n", c);
    printf("%lli is a long long int\n", bignum);
    printf("%c is a character\n", letter);
    printf("%s is a name", name);
    return 0;
}
