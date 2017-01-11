//
//  main.cpp
//  COJ2342
//
//  Created by Alitzel Méndez Bustillo on 26/05/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;


int main() {

    int T, maxA=0, maxB=0, acumA=0, acumB=0, n, f,i;
    string A, B, result;

    scanf("%d", &T);

    while (T--) {

        maxA=-100, maxB=-100, acumA=0, acumB=0;

        scanf("%d",&f);
        cin>>A;

        scanf("%d", &acumA);
        maxA=acumA;

        for (i=0; i<f-1; ++i) {
            scanf("%d", &n);

            acumA = acumA+n>n? acumA+n:n;

            if (acumA>maxA) {
                maxA=acumA;
            }
        }


        cin>>B;
        scanf("%d", &acumB);
        maxB=acumB;

        for (i=0; i<f-1; ++i) {
            scanf("%d", &n);

             acumB = acumB+n>n? acumB+n:n;

            if (acumB>maxB) {
                maxB=acumB;
            }

        }

        if (maxA>maxB)cout<<A<<" "<<maxA<<"\n";
        else if (maxB>maxA)cout<<B<<" "<<maxB<<"\n";
        else cout<<"Tied "<<maxA<<"\n";


    }

    return 0;
}
