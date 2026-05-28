#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;

    char invalid[100];

    while (1) {
        int result = fscanf(fp, "%d", &num);

        if (result == 1) {
            sum += num;
        }
        else if (result == EOF) {
            break;
        }
        else {
            fscanf(fp, "%s", invalid);
            fprintf(stderr, "invalid input %s\n", invalid);
        }
    }

    printf("sum: %d\n", sum);

    fclose(fp);

    return 0;
}
