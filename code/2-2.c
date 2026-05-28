#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");

    int count = 0;
    Student student[64];

    while (fscanf(fp, "%s %d", student[count].name, &student[count].score) == 2) {
        count++;
    }

    int max = 0;
    float avg = 0;
    int sum = 0;

    for (int i = 0; i < count; i++) {
        if (student[i].score > max) {
            max = student[i].score;
        }

        sum += student[i].score;
    }

    if (count > 0) {
        avg = (float)sum / count;
    }

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}
