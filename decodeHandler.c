#include <stdint.h>
#include "constants.h"

uint16_t getTileForChar(unsigned int charSymb) {
  switch (charSymb) {
  // Uppercase
  case 0x0410:
    return A; // А
  case 0x0411:
    return A0; // Б
  case 0x0412:
    return A1; // В
  case 0x0413:
    return A2; // Г
  case 0x0490:
    return A3; // Ґ
  case 0x0414:
    return A4; // Д
  case 0x0415:
    return A5; // Е
  case 0x0404:
    return A6; // Є
  case 0x0416:
    return A7; // Ж
  case 0x0417:
    return A8; // З
  case 0x0418:
    return A9; // И
  case 0x0406:
    return A10; // І
  case 0x0407:
    return A11; // Ї
  case 0x0419:
    return A12; // Й
  case 0x041A:
    return A13; // К
  case 0x041B:
    return A14; // Л
  case 0x041C:
    return A15; // М
  case 0x041D:
    return A16; // Н
  case 0x041E:
    return A17; // О
  case 0x041F:
    return A18; // П
  case 0x0420:
    return A19; // Р
  case 0x0421:
    return A20; // С
  case 0x0422:
    return A21; // Т
  case 0x0423:
    return A22; // У
  case 0x0424:
    return A23; // Ф
  case 0x0425:
    return A24; // Х
  case 0x0426:
    return A25; // Ц
  case 0x0427:
    return A26; // Ч
  case 0x0428:
    return A27; // Ш
  case 0x0429:
    return A28; // Щ
  case 0x042C:
    return A29; // Ь
  case 0x042E:
    return A30; // Ю
  case 0x042F:
    return A31; // Я
  // Lowercase
  case 0x0430:
    return A33; // а
  case 0x0431:
    return A34; // б
  case 0x0432:
    return A35; // в
  case 0x0433:
    return A36; // г
  case 0x0491:
    return A37; // ґ
  case 0x0434:
    return A38; // д
  case 0x0435:
    return A39; // е
  case 0x0454:
    return A40; // є
  case 0x0436:
    return A41; // ж
  case 0x0437:
    return A42; // з
  case 0x0438:
    return A43; // и
  case 0x0456:
    return A44; // і
  case 0x0457:
    return A45; // ї
  case 0x0439:
    return A46; // й
  case 0x043A:
    return A47; // к
  case 0x043B:
    return A48; // л
  case 0x043C:
    return A49; // м
  case 0x043D:
    return A50; // н
  case 0x043E:
    return A51; // о
  case 0x043F:
    return A52; // п
  case 0x0440:
    return A53; // р
  case 0x0441:
    return A54; // с
  case 0x0442:
    return A55; // т
  case 0x0443:
    return A56; // у
  case 0x0444:
    return A57; // ф
  case 0x0445:
    return A58; // х
  case 0x0446:
    return A59; // ц
  case 0x0447:
    return A60; // ч
  case 0x0448:
    return A61; // ш
  case 0x0449:
    return A62; // щ
  case 0x044C:
    return A63; // ь
  case 0x044E:
    return A64; // ю
  case 0x044F:
    return A65; // я
    // Apostrophe and space
    // Numbers
  case 0x0030:
    return A69; // 0
  case 0x0031:
    return A70; // 1
  case 0x0032:
    return A71; // 2
  case 0x0033:
    return A72; // 3
  case 0x0034:
    return A73; // 4
  case 0x0035:
    return A74; // 5
  case 0x0036:
    return A75; // 6
  case 0x0037:
    return A76; // 7
  case 0x0038:
    return A77; // 8
  case 0x0039:
    return A78; // 9

  // Symbols
  case 0x0021:
    return A66; // !
  case 0x003F:
    return A67; // ?
  case 0x002E:
    return A68; // .
  case 0x0022:
    return A79; // "
  case 0x003A:
    return A80; // :
  case 0x003B:
    return A81; // ;
  case 0x003D:
    return A82; // =
  case 0x002C:
    return A83; // ,
  case 0x0027:
    return A32; // '
  case 0x002B:
    return A84; // +
  case 0x002D:
    return A85; // -
  case 0x0025:
    return A86; // %
  case 0x002A:
    return A87; // * -> x
  case 0x003C:
    return A88; // <
  case 0x003E:
    return A89; // >
  case 0x002F:
    return A90; // /
  case 0x0020:
    return 0x16; // space (empty tile)
  }
  return 0;
}

unsigned int utf8Next(const unsigned char **p) {
    unsigned int c = **p;
    if (c < 0x80) {
        (*p)++;
        return c;
    } else if ((c >> 5) == 0x6) {
        unsigned int ch = ((c & 0x1F) << 6) | ((*p)[1] & 0x3F);
        (*p) += 2;
        return ch;
    } else if ((c >> 4) == 0xE) {
        unsigned int ch = ((c & 0x0F) << 12)
                        | (((*p)[1] & 0x3F) << 6)
                        | ((*p)[2] & 0x3F);
        (*p) += 3;
        return ch;
    } else {
        (*p)++;
        return 0;
    }
}
