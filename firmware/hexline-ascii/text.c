#include "text.h"

#include <string.h>

void text_type(char *text, char v) {
    int p = strlen(text);

    switch(v) {
        default:
            text[p] = v;
    }
}