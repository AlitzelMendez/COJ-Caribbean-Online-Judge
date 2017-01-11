//
//  main.cpp
//  COJ1005
//
//  Created by Alitzel Méndez Bustillo on 18/05/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct rentAirplane{
    int st, d, p;

    bool operator<(const rentAirplane &t) const
    {
        return st < t.st;
    }

    bool operator<(const int a) const
    {
        return st < a;
    }
};

int main() {

    int t, n;
    scanf("%d",&t);


    while (t--) {
        scanf("%d",&n);

        vector<int> DP(n+1);
        vector<rentAirplane> arrRentAirplane(n);

        for (int i=0; i<n; i++) {
            scanf("%d%d%d", &arrRentAirplane[i].st, &arrRentAirplane[i].d,&arrRentAirplane[i].p);
        }

        sort(arrRentAirplane.begin(), arrRentAirplane.end());

        DP[n-1] = arrRentAirplane[n-1].p;
        for (int i=n-2; i>=0; i--) {

            int j=lower_bound(arrRentAirplane.begin()+i+1,arrRentAirplane.end(),arrRentAirplane[i].st+arrRentAirplane[i].d)-arrRentAirplane.begin();


            DP[i] = max (DP[i+1], arrRentAirplane[i].p +DP[j]);

        }

        printf("%d\n", DP[0]);

    }
    return 0;
}
