//

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// log files
char *fn = "/tmp/dummygit.txt";
char *fn_fb = "/tmp/dummygit_args.txt";

// path to real git
#ifndef GIT
#define GIT "/bin/git"
#endif

//
// usage
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
 FILE  *fh;
 int    pos = 0;
 int    eno = 0;
 char  *str = 0;

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

 // replace windows paths (for cygwin use - cygwin functions should be used - TODO)
 while (pos < argc)
 {
  // replace  all occurrenece of backslashes with forward slashes if any
  str = strchr(argv[pos], '\\');

  while (str != NULL)
  {
   *str = '/';

   str = str + 1;
   str = strchr(str, '\\');
   fflush(stdout);
  }

  str = NULL;
  pos += 1; 
 }

 fclose(fh); // close file use to log input parameters

 execv(GIT, argv);

 return 0;
}

// EOF
