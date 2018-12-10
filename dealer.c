#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int 
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, optopt;
  
  int pcnt, numt;
  int pflag, vflag, nflag;
  int opt;
  
  int index;
  
  pcnt = 0;
  vflag = 0;
  numt = 0;
  pflag = 0;
  nflag = 0;
  
  while ((opt = getopt(argc, argv, "p:vn:")) != -1)
    switch (opt) {
    case 'p':
      pcnt = atoi(optarg);
      pflag = 1;
      break;
    case 'v':
      vflag = 1;
      break;
    case 'n':
      numt = atoi(optarg);
      nflag = 1;
      break;
  }
  
  
  
  printf ("pcnt = %d, vflag = %d, numt = %d\n",
          pcnt, vflag, numt);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  
  return 0;
}