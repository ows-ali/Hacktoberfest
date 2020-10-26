/*
 * =====================================================================================
 *
 *       Filename:  CHEFEZQ.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/10/20 21:45:58
 *       Compiler:  gcc
 *
 *         Author:  cazz (Francisco Rodriguez Jimenez), cazz@correo.ugr.es
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{	
    int t, n, k, q, total_q, total_days;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        cin >> k;
        total_q = 0;
        for(int j = 0; j < n; ++j){
            cin >> q;
            total_q += q;
        }
        total_days = 0;
        while(total_q >= 0){
            total_q -= k;
            total_days++;
        }
        cout << total_days << endl;
    }

    return EXIT_SUCCESS;
}



