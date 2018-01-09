/*Minkowski 1D curviliear coordinate representation*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOLUMN 4
#define ITERATION 3
#define p 3.0 //resolution


struct column{
  int cvalue;  //Base
  int c[MAXCOLUMN]; //Digits
};


struct column nullbase(int base);
void increament (struct column *cptr);
int print_structures(struct column cptr);
int last_column(struct column *cptr);
double direction_change(int last);

int main(){
  struct column cptr=nullbase(8);// set initial as 0.0.0.0
  //print_structures(cptr);

  double angle=0;
  double x=0;
  double y=0;

  printf("%2.3f %2.3f\n",x,y); //print 1st position segment

  for(int row=0;row<pow(8,ITERATION-1);row++){
    increament(&cptr);

    /*the position of the segments in curvilinear coordinates*/
    print_structures(cptr);

    /*create the cartesan coordinates to plot*/
    /* this step is simply to check we are getting the fractal that we want*/
    x=x+pow(1.0/p,ITERATION)*cos(angle*M_PI/180);
    y=y+pow(1.0/p,ITERATION)*sin(angle*M_PI/180);

    angle=angle+direction_change(last_column(&cptr));
    //printf("%2.3f %2.3f\n",x,y);

  }
}

//===============================================================
/*algorithm for characterising fractal using curvilinear coordinate system */
struct column nullbase(int base){

  struct column rtn;
  rtn.cvalue=base; //stores the cvalues to your base

  for(int nthcolumn=0;nthcolumn<MAXCOLUMN;nthcolumn++)
    rtn.c[nthcolumn]=0;
  return rtn;

}

void increament (struct column *cptr){
  for (int nthcolumn=0;nthcolumn<MAXCOLUMN;nthcolumn++){

    if(cptr->c[nthcolumn]==cptr->cvalue-1)
      cptr->c[nthcolumn]=0;
    else {
      cptr->c[nthcolumn]=cptr->c[nthcolumn]+1;
      break;
    }
  }

}

int last_column(struct column *cptr){
  for (int nthcolumn=0;nthcolumn<MAXCOLUMN;nthcolumn++) {
    if (cptr->c[nthcolumn]!=0){
      return cptr->c[nthcolumn];
    }
  }
  return 0;
}

/* the minkowski sausage seed */
double direction_change(int last){
if (last==1)return 90;
  if (last==2)return -90;
  if(last==3)return -90;
  if(last==4)return 0;
  if(last==5)return 90;
  if(last==6)return 90;
  if(last==7)return -90;

}

/* print the curvilinier coordinate system */
int print_structures(struct column cptr){
  for(int nthcolumn=0;nthcolumn<MAXCOLUMN;nthcolumn++)
    printf("%d.",cptr.c[MAXCOLUMN-1-nthcolumn]);

  printf("\n");

  return 1;

}
