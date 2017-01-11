//
//  main.cpp
//  COJ3337
//
//  Created by Alitzel Méndez Bustillo on 28/06/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>

long long int permutation(int x){
  long long int T = 1;
  for(int i=2; i<=x; ++i){
      T*=i;
  }
  return T;
}

long long int combinatorics(int x, int y){
  return permutation(x)/(permutation(y)* permutation(x-y));
}

int main () {
    long long int R=1,temp, repeticiones, prueba;
    int P,N,n,k,grupos, elementos;
    scanf("%d",&P);

    while (P--){
      R=0;
      scanf("%d%d%d",&N,&n,&k);
      if (k==1){
        R = permutation(n-1);
      }

      else {
        grupos = k-4;
        elementos = k-3;
        R = permutation(n-k) * permutation(k-2);

        for (int i = k-1; i >3 ; --i) {
          temp = combinatorics(elementos,grupos);
          temp*= permutation(i-2);
          R = R + (permutation(n-i)*temp);
          grupos--;
        }

        R+=permutation(n-3);

        R *= (k-2);

        if (k-1 > 2) R += permutation(n-k) * permutation(k-2);

        grupos = k-3;
        elementos = k-2;
        for (int i = k-1; i>2; --i) {
          temp = combinatorics(elementos,grupos);
          temp*= permutation(i-2);
          R = R + (permutation(n-i)*temp);
          grupos--;
        }

        R += permutation(n-2);

      }


      printf("%d %lld\n",N,R);

    }


}
