#include <stdio.h>
#include <stdint.h>
//#include <stdbool.h>
#include "./dataset.c"

int main(int argc, char *argv[]) {
  //puts("Bruh what\n");
  /* char *filename; */
  FILE *fiptr;
  if (argc > 1) {
    //filename = argv[1];
    fiptr = fopen(argv[1], "rb");
  }
  //FILE *foptr;
  //foptr = fopen(filename+".yml", "w");
  if (fiptr == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Define the struct to read into
  Dataset source;

  // Read the data from the file into the struct
  fread(&source, sizeof(Dataset), 1, fiptr);
  Dataset_init(source);
  // Print the data
  Dataset_print(source);

  // Close the file
  fclose(fiptr);

  return 0;
}
