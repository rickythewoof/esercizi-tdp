#include "mat.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int conditionalSum(Mat* src, int flag);
int next_step(Mat *mat, char direction);

int main(){
  Mat *mm1=mat_alloc(2,3);
	Mat *mm2=mat_alloc(3,2);
	mm1->rows_pt[0][0]=1;
	mm1->rows_pt[0][1]=0;
	mm1->rows_pt[0][2]=2;
	mm1->rows_pt[1][0]=0;
	mm1->rows_pt[1][1]=3;
	mm1->rows_pt[1][2]=-1;

	mm2->rows_pt[0][0]=4;
	mm2->rows_pt[0][1]=1;
	mm2->rows_pt[1][0]=-2;
	mm2->rows_pt[1][1]=2;
	mm2->rows_pt[2][0]=0;
	mm2->rows_pt[2][1]=3;
}

int conditionalSum(Mat* src, int flag){
  int sum = 0;
  for (int )
}
