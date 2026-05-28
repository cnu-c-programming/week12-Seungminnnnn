#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        return 0;
    }

    FILE* fp = fopen(argv[1], "r");

    FILE* fp1 = fopen("myfile.txt","w");

    int count[26] = {0};
    char alpha;

    while(fscanf(fp,"%c", &alpha) == 1) {
        if (alpha >= 'a' && alpha <= 'z') {
            count[alpha - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        fprintf(fp1, "%c: %d\n", 'a'+i, count[i]);
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}
