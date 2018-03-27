
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 39; i >=0; i--) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS], xx[MAXCOLS];

  clearPlot();
  int i = 0;
  double x = xx[i] + (maxX - minX) * i / MAXCOLS;
  double y = rpn_eval(funcFile, x);
  xx[i] = x;
  yy[i] = y;
  double minx1 = minX;
  double MINy, MAXy;

  // Evaluate function and store in vector yy
	for(int i = 0; i < 80; i++){
		yy[i] = rpn_eval(funcFile, minx1);
		minx1 += (maxX - minX)/80;
		if(MINy > yy[i]) MINy = yy[i];
		if(MAXy < yy[i]) MAXy = yy[i];
	}
  //Compute maximum and minimum y in vector yy
  
  //Plot x axis
	for(i = 0; i < MAXCOLS; i++){
		int x = i;
		int y = (int)((0-MINy) * MAXROWS /(MAXy-MINy));
		plotXY(x, y, '_');
	}
  //Plot y axis
	for(i = 0; i < MAXROWS; i++){
		plotXY(40, i, '|');
	}
  // Plot function. Use scaling.
  	minx1 = minX;
	int xxx, yyy;
	for (i = 0; i < MAXCOLS; i++) {
		xxx = (minx1 - minX)*80/(maxX- minX );
		yyy=(yy[i] - MINy) * 40/ ( MAXy - MINy);
		plotXY(xxx,yyy,'*');
		minx1 += (maxX - minX)/MAXCOLS;
	}
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1

  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  char * FILE = argv[1];
  double minX = atof(argv[2]);
  double maxX = atof(argv[3]);
  createPlot(FILE, minX, maxX);
  //createPlot(funcName, xmin, xmax);
}
