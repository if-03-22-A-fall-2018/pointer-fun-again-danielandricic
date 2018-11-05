#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LENGTH 64

struct PlayStruct{
  unsigned int int_value;
  double double_value;
  char a_string[MAX_LENGTH];
};

void change_struct(struct PlayStruct ps, struct PlayStruct *pps);
void print_struct(struct PlayStruct ps, struct PlayStruct *pps);
void print_string(char string[64]);
char * change_string(char string[16]);

int main(int argc, char *argv[])
{
  srand(time(NULL));
  struct PlayStruct play_struct = {34, 5.5, "Hallo Pointer!\n"};
  struct PlayStruct *play_struct_pointer = &play_struct;
  print_struct(play_struct, play_struct_pointer);
  change_struct(play_struct, play_struct_pointer);
  /*
  Die Werte von beiden Structs werden geändert,
  da der pointer struct auf die Speicheradresse vom ersten struct zeigt,
  das heißt alles was im pointer verändert wird,
  wird auch im struct verändert.
  */
  print_struct(play_struct, play_struct_pointer);

  print_string(play_struct.a_string);
  strcpy(change_string(play_struct.a_string), play_struct.a_string);
  return 0;
}

void print_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  printf("<%d>, <%lf>, <%s>\n", ps.int_value, ps.double_value, ps.a_string);
  printf("<%d>, <%lf>, <%s>", pps->int_value, pps->double_value, pps->a_string);
}
void change_struct(struct PlayStruct ps, struct PlayStruct *pps)
{
  (pps)->int_value = rand();
  (pps)->double_value = (double)rand();
  //strcpy("Ich wurde verändert!", pps->a_string);
}
void print_string(char string[64])
{
  printf("String: %s", string);
}
char * change_string(char string[16])
{
  string[0] = '\0';
  strcpy(string, "Ich wurde verändert!");
  printf("String wurde geändert!\n");
  return string;
}
