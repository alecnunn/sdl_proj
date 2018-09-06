#include <stdio.h>

#include "engine_utils.h"

const char* version() {
    return "v0.0.1";
}

void red() {
    printf("\033[0;31m");
}

void yellow() {
    printf("\033[0;33m");
}

void blue() {
    printf("\033[0;34m");
}

void green() {
    printf("\033[0;32m");
}

void reset() {
    printf("\033[0m");
}

void bold() {
    printf("\033[1m");
}

#ifdef DEBUG
void engine_log(const char* msg, char type) {
    switch(type) {
        case 'i': {
                      blue();
                      bold();
                      printf("[INFO] ");
                      break;
                  }
        case 'w': {
                      yellow();
                      bold();
                      printf("[WARN] ");
                      break;
                  }
        case 'e': {
                      red();
                      bold();
                      printf("[ERROR] ");
                      break;
                  }
        case 's': {
                      green();
                      bold();
                      printf("[SUCCESS] ");
                      break;
                  }
    }

    reset();
    printf("%s\n", msg);
}
#else
void engine_log(const char* msg, char type) {}
#endif
