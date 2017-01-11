//
//  main.cpp
//  COJ 1655
//
//  Created by Alitzel Méndez Bustillo on 24/05/16.
//  Copyright © 2016 Ali. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B, R;
    int j;
    bool possible=false;

    while (cin>>A) {
        cin>>B;

        j=0;
        possible=false;

        if (A.length()<=B.length()) {
            for (int i=0; i<B.length(); i++) {
                if (A[j] == B[i]) {
                    j++;
                    if (j==A.length()) {
                        possible=true;
                        break;
                    }
                }

                if (A.length()-j > B.length()-i) {
                    break;
                }
            }
        }


        R = possible? "Yes" : "No";
        cout<<R<<"\n";

    }

    return 0;
}
