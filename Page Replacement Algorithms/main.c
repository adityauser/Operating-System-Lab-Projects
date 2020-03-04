#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"
#include "optimal.h"
#include "lru.h"

int main(int argc, char * argv[]) {

    int num_frames;
    int page_refs[argc - 1];
    int page_refs_size;
    int i;

    if (argc > 1) {
        num_frames = atoi(argv[1]);

        for (i = 2; i < argc; i++) {
            page_refs[i - 2] = atoi(argv[i]);
        }

        page_refs_size = (sizeof(page_refs) / sizeof(page_refs[0])) - 1;
    }

    fifo(num_frames, page_refs, page_refs_size);
    optimal(num_frames, page_refs, page_refs_size);
    lru(num_frames, page_refs, page_refs_size);
    return 0;
}