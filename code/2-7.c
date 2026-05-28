#include <stdio.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");

    if (fp == NULL) {
        return;
    }

    fscanf(fp, "%*[^=]=%63s", config_ptr->InputFileName);
    fscanf(fp, "%*[^=]=%d", &config_ptr->Options);
    fscanf(fp, "%*[^=]=%63s", config_ptr->SectionName);
    fscanf(fp, "%*[^=]=%llx", &config_ptr->Address);

    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config = {0};

    config_parser(&config);

    printf("config: %s %d %s %llu\n",
           config.InputFileName,
           config.Options,
           config.SectionName,
           config.Address);

    return 0;
}
