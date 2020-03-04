#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optimal.h"

void optimal(int num_frames, int * page_refs, int page_refs_size) {

    int frames[num_frames];
    int check_frame[num_frames];
    int num_pages = page_refs_size;
    int k = 0, i, j, t, q, f, max, x, check, temp, current, dist = 0, page_faults = 0, hit_count=0;

    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
        check_frame[i] = 0;
    }
    printf("\n");
    printf("\n Optimal output:\n");
    for (i = 0; i<num_pages; i++) {
        check = 0;
        temp = page_refs[i];
        for (j = 0; j < num_frames; j++) {
            if (temp == frames[j]) {
                check = 1;
                break;
            }
        }

        if(check == 1)
          hit_count++;

        if (check == 0 && (k < num_frames)) {
            page_faults++;
            frames[k] = temp;
            k++;
        }
        else if (check == 0 && (k == num_frames)) {
            page_faults++;

            for (j = 0; j < num_frames; j++) {
                current = frames[j];

                for (q = i; q < num_pages; q++) {
                    if (current != page_refs[q]) {
                        check_frame[j]++;
                    }
                    else {
                        break;
                    }
                }
            }
            max = 0;

            for (f = 0; f < num_frames; f++) {
                if (check_frame[f] > max) {
                    max = check_frame[f];
                    t = f;
                }
            }

            frames[t] = temp;
        }

        printf("\n");
        for (x = 0; x < num_frames; x++) {
            printf("%d\t", frames[x]);
        }
    }
    printf("\n");
    printf("\nTotal page faults: %d", page_faults);
    printf("\n\nHit Ratio = %f",(double)hit_count/(double)page_refs_size);
}