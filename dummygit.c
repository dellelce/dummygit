//

#include <stdio.h>
#include <errno.h>
#include <string.h>

char *fn = "/c/android/tmp/args.txt";
char *fn_fb = "args.txt";

//
//
//
void usage(void)
{
  puts("dgit git arguments");
}


//
// MAIN
//

int
main (int argc, char **argv)
{
 FILE *fh;
 int   pos = 0;
 int   eno = 0;

 if (argc == 1 && argv[1] == NULL) { usage(); return 0; }

 if (argc == 1 && (strcmp(argv[1], "--version") == 0))
 {
   printf("git version 2.4.4");
 }
 
 fh = fopen(fn, "a");

 if (fh == NULL && errno == 2)
 {
   fh = fopen(fn_fb, "a");

   if (fh == NULL)
   {
     eno = errno;
     fh = stderr;
   } 
 }

 if (eno != 0)
 {
   fprintf(fh, "errno = %d\n", eno);
 }

 fprintf(fh,"argc = %d\n", argc);

 while (pos <= argc)
 {
   fprintf (fh, "arg: %d = %s\n", pos, argv[pos]);
   pos += 1; 
 }

 fclose(fh);
 return 0;
}

// EOF
