#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

void fifo(int num_frames, int * page_refs, int page_refs_size) {

  int page_faults = 0;
  int frames[num_frames];
  int num_pages = page_refs_size;
  int k, i, j, hit_count=0;

  for (i = 0; i<num_frames; i++){
    frames[i] = -1;
  }

  printf("\n FIFO output:\n");
  for(i = 0; i<num_pages; i++){
      k = 0;

      for (j = 0; j<num_frames; j++){
        if(page_refs[i] == frames[j]){
          k++;
          page_faults--;
        }
      }
      page_faults++;
      if(k>0)
        hit_count++;


      if(page_faults <= num_frames && k == 0) {
        frames[i] = page_refs[i];
      }
      else if(k == 0) {
        frames[(page_faults-1)% num_frames] = page_refs[i];
      }

      printf("\n");
       for(j=0; j<num_frames; j++){
          printf("%d\t", frames[j]);
       }
    }
    printf("\n");
    printf("\nTotal page faults: %d",page_faults);
    printf("\n\nHit Ratio = %f",(double)hit_count/(double)page_refs_size);
}