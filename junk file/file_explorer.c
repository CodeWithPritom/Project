#include <stdio.h>

int main(void) {
    int i, j;
    int width = 7;   // width of the top line
    int height = 7;  // total height of the letter

    // Print the top horizontal line
    for (j = 0; j < width; j++) {
        printf("T");
    }
    printf("\n");

    // Print the vertical stem
    for (i = 1; i < height; i++) {
        for (j = 0; j < width/2; j++) {  // spaces before the stem
            printf(" ");
        }
        printf("|\n");
    }

    return 0;
}
