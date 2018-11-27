#ifndef _OLD_H
#define _OLD_H



float dp_crop(std::vector<float>p, int n, std::vector<float>r)
{
    assert(r.size() > (size_t)n);
    assert(p.size() > (size_t)n);
    std::vector<int> crop_array(r.size(), 0);
    float q = -100.0;

    r[0] = 0.0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            // q = std::max(q, p[j] + r[i - j]);
            if (q < p[j] + r[i - j]){
                q = p[j] + r[i - j];
                crop_array[i] = j;
            }
        }
        r[i] = q;
    }
    for (auto a : r){
        printf("%.1f    ", a);
    }
    printf("\n");
    for (auto a : crop_array){
        printf("%d      ", a);
    }
    printf("\n");
    
    for (int i = 1; i <= n; ++i){
        int a = i;
        printf("%d:    ", a);
        while(a > 0){
            printf("%d  ", crop_array[a]);
            a -= crop_array[a];
        }
        printf("\n");
    }


    return q;
}



#endif
