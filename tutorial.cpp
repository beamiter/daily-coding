#include <cmath>

#include <iostream>

#include <cmath>
#include <vector>
#include <cassert>
#include <stdio.h>



#include "old.h"


int main(int args, char** argv)
{
    std::vector<float>p, r;
    int n = 10;
    p.resize(n + 2);
    r.resize(n + 2);
    p[0] = 0.0;
    p[1] = 1.0;
    p[2] = 2.5;
    p[3] = 3.9;
    p[4] = 4.7;
    p[5] = 6.0;
    p[6] = 7.0;
    p[7] = 8.5;
    p[8] = 8.9;
    p[9] = 17.0;
    p[10] = 17.1;
    dp_crop(p, n, r);
    return 0;
}