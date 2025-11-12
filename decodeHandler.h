#ifndef DECODE_HANDLER_H
#define DECODE_HANDLER_H

#include <stdint.h>

uint16_t getTileForChar(unsigned int c);
unsigned int utf8Next(const unsigned char **p);

#endif
