#include <stdio.h>


// Demonstration of "higher-level" resource management in C

// This it the MACRO being demoed
#define with_file(f, mode, filename) \
    f = fopen(filename, mode);                                            \
    for (int _break = (tag_prologue(f, filename), 1); _break;                       \
        _break = 0, tag_epilogue(f, filename)) 

void tag_prologue(FILE* f, char* filename) {
    if (f != NULL) {
        printf("file %s opened.\n", filename);
    } else {
        printf("ERROR. File not opened.\n");
    }
}

void tag_epilogue(FILE* f, char* filename) {
    int ret = fclose(f);
    if (ret == 0) {
        printf("File %s closed succesfully.\n", filename);
    } else {
        printf("ERROR. File %s not closed successfully!\n", filename);
    }
}




int main(int argc, char* argv[]) {
    printf("running.\n");

    FILE* f;

    with_file(f, "r", "somefile.txt") {
        // file should be closed automatically
        int len = 1000;
        char buffer[len];
        if(fgets(buffer, len, f) != NULL) {
            printf("the file contains the string:\n%s", buffer);
        };
        
    }

    return 0;
}