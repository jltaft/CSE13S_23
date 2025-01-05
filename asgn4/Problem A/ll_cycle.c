#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    //1. Start with two-pointers at the head of the list, one fast, one slow
    node *fast_ptr = head;
    node *slow_ptr = head;
    if (head == NULL){
    	return 0;
    }
    while(1){
    	//2. Advance fast_ptr by two nodes if it is possible (AKA if there is no null pointer preventing it)
    	if(fast_ptr->next != NULL){
    	        fast_ptr = fast_ptr->next->next;
        
    	} else {
    		return 0;
    	}
    	//3. Advance slow_ptr by one node.
    	slow_ptr = slow_ptr->next;
    	if(fast_ptr == NULL){
    		return 0;
    	} 
    	//4. If fast and slow point to the same node, the list is cyclic
    	if(fast_ptr == slow_ptr){
    		return 1;
    	} 
    }
}
