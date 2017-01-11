//
//  main.cpp
//  COJ1049
//
//  Created by Alitzel Méndez Bustillo on 21/06/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int  main() {
  int n;
  long int r=0;

  scanf("%d", &n );

  r = n>=0? (n*(n+1)) /2 : (((n*-1)*((n*-1)+1)/2)*-1)+1;

  printf("%ld\n",r);

  return 0;
}
