//
//  main.cpp
//  COJ1079
//
//  Created by Alitzel Méndez Bustillo on 24/05/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int DP[110][110];
using namespace std;

int main() {

    int n, t, i,j, maxi;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &t);

        for (i=1; i<=t; i++) {
            for (j=1; j<=i; j++) {
                scanf("%d", &DP[i][j]);
            }
        }


        for (i=t-1; i>0; i--) {
            for (j=1; j<=i; j++) {
                maxi = max(DP[i+1][j], DP[i+1][j+1]);
                DP[i][j] += maxi;
            }
        }

        printf("%d\n", DP[1][1]);

    }

    return 0;
}
