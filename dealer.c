#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

int 
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, optopt;
  
  int pcnt, numt;
  int pflag, vflag, nflag;
  int opt;
  
  int index;
  
  pid_t pid;
  
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
    case '?':
      fprintf(stderr, "%s: Unknown input\n", argv[0]);
  }
  
  if (!pflag || !nflag)
  {
    fprintf(stderr, "%s: Requires -p AND -n.\n", argv[0]);
    exit(1);
  }
  else if ((pcnt > 100) || (pcnt == 0))
  {
    fprintf(stderr, "%s: Invalid percentage value.\n", argv[0]);
    exit(1);
  }
  else if (numt == 0)
  {
    fprintf(stderr, "%s: Invalid number_of_trials value.\n", argv[0]);
    exit(1);
  }
  
  //printf ("pcnt = %d, vflag = %d, numt = %d\n", pcnt, vflag, numt);

  //for (index = optind; index < argc; index++)
    //printf ("Non-option argument %s\n", argv[index]);
    
  int result, wins, losses;
  wins = 0;
  losses = 0;
  int childs;
  childs = 0;
  
  for(index = 0; index < numt;index++) {
    pid = vfork();
  
    if(pid == 0) 
    {
      result = execv("hand", argv);
      exit(0);
    }
    else if (pid > 0)
    {
      if (vflag)
        printf("PID %i returned \n", pid); 

      pid = wait(&result);   
      if (WEXITSTATUS(result) == 0)
        wins++;
      else
        losses++;
    }
    else 
    {
      fprintf(stderr, "%s: Fork failed.\n", argv[0]);
      exit(1)
    }
  }
  
  double winrate;
  winrate = wins/(float)numt;
  double lossrate;
  lossrate = losses/(float)numt;
  
  printf("\n\nCreated %i processes.\n", numt);
  printf("Success - %i%%\n", (int)(winrate*100));
  printf("Failure - %i%%\n", (int)(lossrate*100));
  
  
  
  return 0;
}