#include <cstring>
#include <cstdio>

int main() {
    char s1[] = "Hello, ";
    char s2[] = "World!";
    char s3[14];
    strcpy(s3, s1);
    strcat(s3, s2);
    printf("%s", s3);
    return 0;
}