#include "mytools.h"
#include <assert.h>
#include <unistd.h>

int 
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, optopt;
  int opt;
  
  int pcnt, pflag;
  
  pcnt = 0;
  pflag = 0;
  
  while ((opt = getopt(argc, argv, "p:")) != -1)
    switch(opt) {
    case 'p':
      pcnt = atoi(optarg);
      pflag = 1;
      break;
    }
  
  assert( init_mytool() == 0);
  
  int attempt = get_random_number() * 100;
  
  //printf("Random num = %f\n", get_random_number());
  //printf("Attempt = %i\n", attempt);
  
  finalize_mytool();
  
  if (attempt <= pcnt) {
    printf("Success!\n");
  }
  else if (attempt > pcnt) {
    printf("Failure...\n");
  }
  
  return 0;

}