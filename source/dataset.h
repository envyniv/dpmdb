typedef struct {
  int16_t entries;
  //long entries;
  char ___spacer[2];
  /*
    this makes sense, but how do we separate a field
    from one another?!?!
  */
  uint16_t entry_byte_length;
  //long entry_byte_length;
  uint16_t ___spacer2;
  /*
    0x30 in dpm1
  */
  char marker[2]; //  "0\0"
  uint16_t ___spacer3;
  int16_t unknown1;
  uint16_t ___spacer4;
  int16_t unknown2;
  uint16_t ___spacer5;
  int16_t unknown3;
  uint16_t ___spacer6;
  int16_t unknown4;
  uint16_t ___spacer7;
  char unknown5[2];
  char ___spacer8[7]; // {'\0'}
  /*
    whenever multiple filenames are embedded, this is non-0.
   */
  int16_t strings_unk;
  uint16_t ___spacer9;
  int16_t unknown6;
  //uint48_t ___spacer10;
  char ___spacer10[6]; //={'\0'}
  /*
    stores filenames of "imported" files, divided in "sets".
    also used for frames of reference? in
   */
  union {
    struct {
      char unknown7[4];
      uint16_t ___spacer11;
    } optional;
  } unk_optional;
  char **strings;
  /*
    16B by default, is expanded 16 bytes each time that is not enough.
    Coincides w/ the filename, w/out the `.bin`,
    and the first letter capitalized.
   */
  char *identifier;
  char ___spacer12[3]; //={'\0'}
  char data[];
} Dataset;

char* Dataset_get_unk7();
  /*
    To make sure we only access unknown7 only when it is actually available,
    This getter method and its setter counterpart ensure proper usage.
   */

int Dataset_set_unk7();
  /*
    To make sure we only access unknown7 only when it is actually available,
    This getter method and its setter counterpart ensure proper usage.
   */

void Dataset_init(Dataset db);
  /*
    This inits all the string pointers to the proper locations.
   */

void Dataset_print(Dataset db);
  /*
    This function allows you to print a dataset provided as argument.
   */
