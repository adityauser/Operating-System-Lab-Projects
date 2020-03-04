#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lru.h"

void lru(int num_frames, int * page_refs, int page_refs_size) {

    int frames[num_frames];
    int check_frame[num_frames];
    int num_pages = page_refs_size;
    int k, i, j, h, x, flag1 = 0, flag2 = 0, page_faults = 0, index, hit_count=0;

    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    printf("\n");
    printf("\n LRU output:\n");

    for (j = 0; j < page_refs_size; j++) {
        flag1 = 0, flag2 = 0;
        for (i = 0; i < num_frames; i++) {
            if (frames[i] == page_refs[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 1)
          hit_count++;

        if (flag1 == 0) {
            for (i = 0; i < num_frames; i++) {
                if (frames[i] == -1) {
                    frames[i] = page_refs[j];
                    page_faults++;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            for (i = 0; i < num_frames; i++)
                check_frame[i] = 0;
            for (x = j-1, h = 1; h < num_frames-1; h++, x--) {
                for (k = 0; k < num_frames; k++) {
                    if (frames[k] == page_refs[x])
                        check_frame[k] = 1;
                }
            }
            for (i = 0; i < num_frames; i++) {
                if (check_frame[i] == 0)
                    index = i;

            }
            frames[index] = page_refs[j];
            page_faults++;
        }
        printf("\n");
        for (i = 0; i < num_frames; i++) {
            printf("%d\t", frames[i]);
        }
    }
    printf("\n");
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("\nHit Ratio = %f\n\n",(double)hit_count/(double)page_refs_size);
}