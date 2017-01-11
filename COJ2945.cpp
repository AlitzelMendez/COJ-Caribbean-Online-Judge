//
//  main.cpp
//  COJ2945
//
//  Created by Alitzel Méndez Bustillo on 27/06/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

struct circle{
  char L;
  bool D;
  bool V;
};

circle A[14][12];
circle B[14][12];
int eliminados = 0;
char letter;
int sum=0;

void eliminar (int x, int y,  circle (&X) [14][12]){
  if (X[x][y].L == letter && X[x][y].L != '0' && !X[x][y].D){
      eliminados++;
      X[x][y].D = true;
      eliminar (x+1, y, X);
      eliminar (x, y+1, X);
      eliminar (x-1, y, X);
      eliminar (x, y-1, X);

  }
}

void copiar (circle (&X) [14][12], circle (&Y) [14][12]){

    int columna = 1;
    int fila = 12;

    for (int j = 1; j <= 10; ++j){
      for ( int i = 12; i >0; --i) {
        if (!X[i][j].D && X[i][j].L!='0') { Y[fila][columna] = X[i][j]; fila--;}
      }
      if (fila<12){fila=12; columna++;}
    }

}


void resetValue (circle (&X) [14][12]){
  for (int i = 0; i < 14; ++i) {
    for (int j = 0; j < 12; ++j) {
        X[i][j].L ='0';
        X[i][j].D = false;
        X[i][j].V = false;
    }
  }
}

void isPossible(int x, int y,  circle X [14][12]){
  if (sum>2) return;
  if (X[x][y].L == letter && X[x][y].L != '0' && !X[x][y].V){
      sum++;
      X[x][y].V = true;
      isPossible (x+1, y, X);
      isPossible (x, y+1, X);
      isPossible (x-1, y, X);
      isPossible (x, y-1, X);
  }

}

int main() {
  int t, result, locx, locy, it;
  char location;

  while (scanf(" %d", &t) && t>0) {
      resetValue(A);
      resetValue(B);

      result = 120;
      eliminados=0;
      it = 2;
      for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= 10; ++j) {
            scanf(" %c", &A[i][j].L);
          }
        }

      while (t--) {
        scanf(" %c%d",&location, &locx);
        locy = (int)location - 96;
        locx = 12-locx+1;

        if (it%2==0){
          letter = A[locx][locy].L;
          sum=0;
          isPossible(locx, locy, A);

          if (sum>2) {
            eliminar(locx, locy, A);
            resetValue(B);
            copiar(A,B);
            it++;
          }

        }
        else {
          letter = B[locx][locy].L;
          sum=0;
          isPossible(locx,locy,B);

          if(sum>2){
          eliminar(locx, locy, B);
          resetValue(A);
          copiar(B, A);
          it++;
        }
        }

      }

      printf("%d\n", result-eliminados);

  }


  return 0;
}
