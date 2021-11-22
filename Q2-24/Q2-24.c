#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool CheckFile (char *input);
void Copy (char *out, char *in);
void GetFile ();

// Boolean return function indicating if the file exists.
bool CheckFile (char *input)
{
  // Create a file pointer of object FILE and take value as the file name passed as argument in read mode.
  FILE *ptr = fopen (input, "r");

  // If pointer does not exist, file does not exits and hence return false else return true.
  if (!ptr)
    {
      return false;
    }
  return true;
}

// Copies the contents of the file of file string pointer *in to file string pointer *put
void Copy (char *out, char *in)
{

  // Create an intermediate character for transfer of contents
  char c;

  // Declare FILE pointers for input and output files.
  FILE *inputPtr = fopen (in, "r");
  FILE *outputPtr = fopen (out, "w");

  // Input pointer cannot open file show error
  if (!inputPtr)
    {
      // Prints standard error message indicating a failure to open file.
      perror ("Source file can't be opened: ");
      exit (1);
    }
  if (!outputPtr)
    {
      // Prints standard error message indicating a failure to open file.
      perror ("Destination file can't be opened: ");
      exit (1);
    }
  
  // After verification of all parts of the code, we put the contents of the file pointer from one file to another character by character.
  while ((c = fgetc (inputPtr)) != EOF)
    {
      fputc (c, outputPtr);
    }
  // Indicate to the user about the successful compilation.
  printf ("\n Content Copied!\n");
  fclose (inputPtr);
  fclose (outputPtr);
}

void GetFile ()
{
  //Initialize 3 strings - 
  // 1. str - Gets the file name for inputting or outputting from the user, not passed further unless valid.
  // 2. inStr - Final Name of the file from the user.
  // 3. outstr - Copying String - String that gets put inside the output folder.
  
  char str[32], inStr[32], outStr[32]; 

  // Initialize subsequent pointers to these strings
  char *strPtr = str;
  char *inPtr = inStr;
  char *outPtr = outStr;

  // While input string is not empty - implies that the input string is not yet finalized.
  while (strcmp (inStr, ""))
    {
      // Get the file name from the user
      printf ("Enter name of input file: ");
      scanf ("%s", strPtr);

      // Since we do not know the validity of the file, we check if the file name is valid or not.
      if (CheckFile (strPtr))
        {
          // IF file exists, copy the file name to the inStr which returns in termination of the current loop
          strcpy (inStr, str);
          break;
        }
      else
        {
          // File does not exits, ask user to input again.
          printf ("File does not exist. \n");
          continue;
        }
    }

  // Similarly with output string, if name of output file not finalized, keep the loop active.
  while (strcmp (outStr, ""))
    {
      // Ask for name and store in str
      printf ("Enter name of target file: ");
      scanf ("%s", strPtr);

      // Check validity of the file. In this case we check if the file does not exits or does.
      // If it exits, it'll return an error else it will run.
      if (!CheckFile (strPtr))
        {
          // Finalize the name of the output fule.
          strcpy (outStr, str);
          break;
        }
      else
        {
          // File exists, and hence cannot transfer content to existing file.
          printf ("File already exists! Please enter a different namme.\n");
          continue;
        }
    }

  // Copy the contents. Take input and output file name string as argument.
  Copy (outStr, inStr);
}

int main ()
{
  GetFile ();
  return EXIT_SUCCESS; //Successful Compilationn - EXIT_SUCCESS = 1
}