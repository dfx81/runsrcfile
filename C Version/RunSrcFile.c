/* RunSrcFile
 *
 * Author   : Danial "dfx" Fitri
 * Function : A program made to compile and run sorce files of various
 *            programming languages without using any IDEs or typing frequently
 *            on the terminal/ shell.
 * Version  : V3.0 (cleanup edition)
 * Build    : 0.1a (Linux version)
 * Changes  : - Codebase rewrite in C
 *            - Support for Linux
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run(int mode);
void cls();
void ui();
void pause();
int launch();
void pth(int mode);

int main()
{
  int mode = launch();
  pth(mode);
  int flag = 1;

  while (flag != 0)
  {
    cls();
    ui();
    flag = run(mode);
  }

  return 0;
}

int run(int mode)
{
  char name[50];
  char command[100];

  printf("Filename: ");
  fgets(name, 50, stdin);
  name[strcspn(name, "\n")] = 0;
  cls();

  if (strcmp("-e", name) == 0)
  {
    cls();
    printf("Thanks for using this program!\n");
    printf("-dfx\n");
    pause();
    cls();
    return 0;
  }

  else if (strcmp("-c", name) == 0)
  {
    if (mode == 0)
    {
      char command[100] = "javac ";
      char source[100];
    
      printf("Enter the name of the file to compile: ");
      fgets(source, 100, stdin);
      source[strcspn(source, "\n")] = 0;

      strcat(source, ".java");
      strcat(command, source);
      printf("\n");
      system(command);
      //printf("\nPress any key to continue...\n");
      pause();
      cls();

      return 1;
    }

    else if (mode == 1)
    {
      char command[100] = "gcc ";
      char source[100];
    
      printf("Enter the name of the file to compile: ");
      fgets(source, 100, stdin);
      source[strcspn(source, "\n")] = 0;

      strcat(command, source);
      strcat(command, ".c ");
      strcat(command, "-o ");
      strcat(command, source);
      strcat(command, ".exe");
      printf("\n");
      system(command);
      //printf("\nPress any key to continue...\n");
      pause();
      cls();

      return 1;
    }

    else
    {
      char command[100] = "g++ ";
      char source[100];
    
      printf("Enter the name of the file to compile: ");
      fgets(source, 100, stdin);
      source[strcspn(source, "\n")] = 0;

      strcat(command, source);
      strcat(command, ".c ");
      strcat(command, "-o ");
      strcat(command, source);
      strcat(command, ".exe");
      printf("\n");
      system(command);
      //printf("\nPress any key to continue...\n");
      pause();
      cls();

      return 1;
    }
  }
  
  else
  {
    char args[200];

    printf("Type in the arguments for your program.\n");
    printf("Separate multiple arguments with space.\n");
    printf("Type a // for no arguments.\n\n");
    printf("args[]: ");
    fgets(args, 200, stdin);
    args[strcspn(args, "//")] = 0;
    cls();

    if (mode == 0)
    {
      char command[100] = "java ";
      strcat(command, name);
      strcat(command, " ");
      strcat(command, args);
      system(command);
      //printf("\nPress any key to continue...\n");
      pause();
      cls();

      return 1;
    }

    else
    {
      char command[100] = "./";
      strcat(command, name);
      strcat(command, ".exe");
      strcat(command, args);
      system(command);
      //printf("\nPress any key to continue...\n");
      pause();
      cls();

      return 1;
    }
  }
}

void cls()
{
  //system("clear");
  system("cls");
}

void ui()
{
  printf("Source File Compiler & Executable Tool v3.0\n");
  printf("Created by Danial \"dfx\" Fitri\n\n");
  printf("Commands: [-e]xit [-c]ompile\n\n");
}

void pause()
{
  //getchar();
  system("pause");
}

int launch()
{
  cls();
  FILE *fp = fopen("config.txt", "r");
  char cfg[5];
  char path[200];

  if (fp == NULL)
  {
    FILE *fp =fopen("config.txt", "w");
    fprintf(fp, "JAVA\n");

    printf("Enter the filepath to your Java compiler:\n > ");
    fgets(path, 200, stdin);
    fprintf(fp, "%s", path);
    printf("Enter the filepath to your C compiler:\n > ");
    fgets(path, 200, stdin);
    fprintf(fp, "%s", path);
    printf("Enter the filepath to your C++ compiler:\n > ");
    fgets(path, 200, stdin);
    fprintf(fp, "%s", path);

    fclose(fp);

    printf("\nYou can edit your path through the config.txt\n");
    printf("You can now edit the compiler to use in line 1 of\n");
    printf("the config.txt file. Supported compilers : \n\n");
    printf("[JAVA], [C], [C++]\n\n");
    pause();
    char cfg[5] = "JAVA";
    return 0;
  }

  else
  {
    fscanf(fp, "%s", cfg);
    fclose(fp);
  }

  if (strcmp(cfg, "JAVA") == 0)
    return 0;

  else if (strcmp(cfg, "C") == 0)
    return 1;

  else
    return 2;
}

void pth(int mode)
{
  char path[200];
  char envpth[300] = "set path=";

  FILE *fp = fopen("config.txt", "r");
  fscanf(fp, "%*[^\n]");

  if (mode == 0)
  {
    fscanf(fp, "%s", path);
  }

  else if (mode == 1)
  {
    fscanf(fp, "%*[^\n]");
    fscanf(fp, "%s", path);
  }

  else
  {
    fscanf(fp, "%*[^\n]");
    fscanf(fp, "%*[^\n]");
    fscanf(fp, "%s", path);
  }

  fclose(fp);
  strcat(envpth, path);
  system(envpth);

}