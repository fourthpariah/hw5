hand: hand.c mytools.c
	gcc -I$$HOME/src/gsl-2.5/include -o hand hand.c mytools.c -L$$HOME/src/gsl-2.5/lib -lgsl -lgslcblas -lm
