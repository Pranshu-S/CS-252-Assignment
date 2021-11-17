#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool CheckFile (char *input);
void Copy (char *out, char *in);
void GetFile ();

bool CheckFile (char *input)
{
  FILE *ptr = fopen (input, "r");
  if (!ptr)
    {
      return false;
    }
  return true;
}

void Copy (char *out, char *in)
{
  int c;
  FILE *inputPtr = fopen (in, "r");
  FILE *outputPtr = fopen (out, "w");
  if (!inputPtr)
    {
      perror ("Source file can't be opened: ");
      exit (1);
    }
  if (!outputPtr)
    {
      perror ("Destination file can't be opened: ");
      exit (1);
    }
  while ((c = fgetc (inputPtr)) != EOF)
    {
      fputc (c, outputPtr);
    }
  printf ("\n Content Copied!\n");
  fclose (inputPtr);
  fclose (outputPtr);
}

void GetFile ()
{
  char str[32], inStr[32], outStr[32];
  char *strPtr = str;
  char *inPtr = inStr;
  char *outPtr = outStr;

  while (strcmp (inStr, ""))
    {
      printf ("Enter name of input file: ");
      scanf ("%s", strPtr);
      if (CheckFile (strPtr))
        {
          strcpy (inStr, str);
          break;
        }
      else
        {
          printf ("File does not exist. \n");
          continue;
        }
    }
  while (strcmp (outStr, ""))
    {
      printf ("Enter name of target file: ");
      scanf ("%s", strPtr);
      if (!CheckFile (strPtr))
        {
          strcpy (outStr, str);
          break;
        }
      else
        {
          printf ("File already exists! Please enter a different namme.\n");
          continue;
        }
    }
  Copy (outStr, inStr);
}

int main ()
{
  GetFile ();
  return EXIT_SUCCESS;
}