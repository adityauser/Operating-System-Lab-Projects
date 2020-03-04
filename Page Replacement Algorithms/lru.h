#ifndef LRU_H
#define LRU_H

/*LRU
*@param num_frames | number of frames user enters
*@param page_refs | array of frame inputs from user
*@param page_refs_size | size of page_refs array
*/
void lru(int num_frames, int * page_refs, int page_refs_size);

#endif