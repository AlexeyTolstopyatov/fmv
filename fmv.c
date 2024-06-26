#include <stdio.h>
#include <stdlib.h>

int fcopy(char* from, char* to);
int fmove(char* from, char* to);

int main(int argc, char* argv[]) { 
    int err = 0;

    switch (argv[2][0]) {
    case '-':
        err = fmove(argv[1], argv[3]);
        break;

    case '+':
        err = fcopy(argv[1], argv[3]);
        break;

    default:
        printf("COPYING : fmv path\\file.ext + newpath\\file.ext \n MOVING : fmv path\\file.ext - newpath\\file.ext\n\n");
        printf("\nEXIT\n======\n0 --> no errors.\n1 -- source is NULL\n2 -- source_copy is NULL\n");
        break;
    }

    printf("process done. (exit: %d)", err);
}

//File movement from FILE to FILE
//Returns exit state.
//0 - process complete
int fmove(char* from, char* to) {
    int result = fcopy(from, to);
    // remove reading file after copy

    return result;
}


// File copying from FILE to FILE
// 
// * Creates 2 references of file.
//      From-file opens with read attribures
//      To-file opens with write attribures.
// 
// I don't know, why... but file structure corrupts while transfering 
// (indev...)
int fcopy(char* from, char* to) {
    FILE* fromfile;
    FILE* tofile;

    fromfile = fopen(from, "r");

    char buffer[4096];

    if (fromfile == NULL) {
        printf("failed to open %s for reading\n", from);
        return 1;
    }

    tofile = fopen(to, "w");

    if (tofile == NULL) {
        printf("failed to open %s for writing\n", to);
        return 2;
    }
    
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), fromfile)) > 0) {
        fwrite(buffer, 1, bytes, tofile);
    }

    printf("\n");

    fclose(fromfile);
    fclose(tofile);

    return 0;
}
