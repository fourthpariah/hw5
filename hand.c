#include "mytools.h"
#include <assert.h>
#include <unistd.h>

int 
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, optopt;
  int opt;
  
  int pcnt, pflag, vflag;
  
  pcnt = 0;
  pflag = 0;
  vflag = 0;
  
  while ((opt = getopt(argc, argv, "p:vn")) != -1)
    switch(opt) {
    case 'p':
      pcnt = atoi(optarg);
      pflag = 1;
      break;
    case 'v':
      vflag = 1;
      break;
    }
    
  if (!pflag)
  {
    fprintf(stderr, "%s: Requires -p.\n", argv[0]);
    exit(1);
  }
  else if ((pcnt > 100) || (pcnt == 0))
  {
    fprintf(stderr, "%s: Invalid percentage value.\n", argv[0]);
    exit(1);
  }
  
  assert( init_mytool() == 0);
  
  int attempt = get_random_number() * 100;
  
  //printf("Random num = %f\n", get_random_number());
  //printf("Attempt = %i\n", attempt);
  
  finalize_mytool();
  
  if (attempt <= pcnt) {
    if (vflag)
      printf("Success\n");
      
    exit(0);
  }
  else if (attempt > pcnt) {
    if (vflag)
      printf("Failure\n");
      
    exit(1);
  }

}