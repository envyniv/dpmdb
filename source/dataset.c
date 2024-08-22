#include "./dataset.h"

const char *___print_string = "\
Entries:\t%d\n\
Row length:\t%d\n\
Unkown1:\t%d (%x)\n\
Unkown2:\t%d (%x)\n\
Unkown3:\t%d (%x)\n\
Unkown4:\t%d (%x)\n\
Unkown5:\t%d (%x)\n\
Strings parameter:\t%d\n\
Unkown6:\t%d (%02x)\n\
Strings :\t%s\n\
Internal name:\t%s\n\
";

char* Dataset_get_unk7() {
  return '\0';
}

int Dataset_set_unk7() {
  return 1;
}

void Dataset_init(Dataset db) {
  if (db.strings_unk != '\0') {
    /*if (db.unk_optional) {
      //
      }*/
    db.strings = (char**)0x30;
    for (int i = 0; i < db.strings_unk; i++)
  } else {
    db.identifier = (char*)0x30;
  }
}

void Dataset_print(Dataset db) {
  printf(___print_string,
         db.entries,
         db.entry_byte_length,
         db.unknown1, db.unknown1,
         db.unknown2, db.unknown2,
         db.unknown3, db.unknown3,
         db.unknown4, db.unknown4,
         db.unknown5, db.unknown5,
         db.strings_unk,
         db.unknown6, db.unknown6,
         db.strings,
         db.identifier);
}
