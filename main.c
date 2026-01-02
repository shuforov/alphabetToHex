#include <stdio.h>
#include <stdint.h>
#include "constants.h"
#include "decodeHandler.h"

int main(void) {
    const char *text = "+10% до шкоди";  // Cyrillic text to convert
    const unsigned char *p = (const unsigned char *)text;

    uint16_t result[256];
    int i = 0;

    printf("Input: %s\nOutput: { ", text);

    while (*p) {
        unsigned int code = utf8Next(&p);
        uint16_t tile = getTileForChar(code);

        // preserve spaces but skip unmapped
        if (code == 0x20) { // space
            result[i++] = 0x16;
            printf("0x16, ");
        } else if (tile) {
            result[i++] = tile;
            printf("0x%X, ", tile);
        }
    }

    printf("};\nTotal %d tiles.\n", i);
    return 0;
}
