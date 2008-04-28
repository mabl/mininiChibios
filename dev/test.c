#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "minIni.h"

int main(void)
{
  char str[100];
  long n;

  /* string reading */
  n = ini_gets("first", "string", "aap", str, 100, "test.ini");
  assert(n==4 && strcmp(str,"noot")==0);
  n = ini_gets("second", "string", "aap", str, 100, "test.ini");
  assert(n==4 && strcmp(str,"mies")==0);
  n = ini_gets("first", "dummy", "aap", str, 100, "test.ini");
  assert(n==3 && strcmp(str,"aap")==0);
  printf("1. String reading tests passed\n");

  /* value reading */
  n = ini_getl("first", "val", -1, "test.ini");
  assert(n==1);
  n = ini_getl("second", "val", -1, "test.ini");
  assert(n==2);
  n = ini_getl("first", "dummy", -1, "test.ini");
  assert(n==-1);
  printf("2. Value reading tests passed\n");

  /* string writing */
  n = ini_puts("first", "alt", "correct", "test.ini");
  assert(n==1);
  n = ini_gets("first", "alt", "aap", str, 100, "test.ini");
  assert(n==7 && strcmp(str,"correct")==0);
  /* ----- */
  n = ini_puts("second", "alt", "correct", "test.ini");
  assert(n==1);
  n = ini_gets("second", "alt", "aap", str, 100, "test.ini");
  assert(n==7 && strcmp(str,"correct")==0);
  /* ----- */
  n = ini_puts("third", "alt", "correct", "test.ini");
  assert(n==1);
  n = ini_gets("third", "alt", "aap", str, 100, "test.ini");
  assert(n==7 && strcmp(str,"correct")==0);
  /* ----- */
  printf("3. String writing tests passed\n");

  /* string deletion */
  n = ini_puts("first", "alt", NULL, "test.ini");
  assert(n==1);
  n = ini_puts("second", "alt", NULL, "test.ini");
  assert(n==1);
  n = ini_puts("third", NULL, NULL, "test.ini");
  assert(n==1);

  return 0;
}

