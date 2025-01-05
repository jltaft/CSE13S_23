#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"
#include "hashtable.h"


/* Create a new (empty) hashtable; return NULL if error. */
hashtable_t *hashtable_new(const int num_slots){
	//if the num_slots is not valid, return null
	if(num_slots <= 0){
		return NULL;
	}
	/*set_t table[num_slots];
	hashtable_t *out;
	out->head = table[0]; */
	
	int i;
	hashtable_t *out = (hashtable_t*)malloc(sizeof(hashtable_t));
	//hashtable_t *out;
	if(out == NULL){
		return NULL;
	}
	//creates bins
	out->nodes = (set_t**)malloc(sizeof(set_t*)*num_slots);
	out->size = num_slots;
	for(i = 0; i < num_slots;i++){
		//memory is being allocated here
		out->nodes[i] = set_new();
	}
	
	return out;
	
}

/* Insert item, identified by key (string), into the given hashtable.
 * The key string is copied for use by the hashtable.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
	//set_t *set = ht->nodes[0];
	//setnode_t *setnode = set->head;
	int i;
	
	//char* newkey = (char*)malloc(sizeof(key));
	//newkey = strcpy(newkey,key);
	
	//look through this bin for the key, if not found, then return false, else set_insert
	if(ht == NULL || key == NULL || item == NULL){
		return false;
	}
	//printf("finished null check\n");
	//iterates through entire hash table to check if key exists
	for(i=0; i < ht->size;i++){
		//for( ; setnode != NULL; setnode = setnode->next){ 
		if(set_find(ht->nodes[i],key) != NULL){
			return false;
		}
			/*if(strcmp(setnode->key,key)==0){
				return false;
			} */
	} 
	//printf("finished for loop\n");
	char* newkey = strdup(key);
	int index = atoi(newkey)%(ht->size);
	set_insert(ht->nodes[index],newkey,item);
	//printf("finished insert\n");
	free(newkey);
	//printf("freed key");
	return true;
}

/* Return the item associated with the given key;
 * return NULL if hashtable is NULL, key is NULL, key is not found.
 */
void *hashtable_find(hashtable_t *ht, const char *key){
	int i;
	//checks if any of the parameters are null
	if(ht == NULL || key == NULL){
		return NULL;
	}
	//printf("passed null check");
	//checks if key is found
	/*for(i=0; i < ht->size;i++){
		printf("%s", key);
		//if statement checks each bin's set for the given key
		if(set_find(ht->nodes[i],key) == NULL){
			return NULL;
		}
	} */
	
	//for loop iterates through ht array
	//returns NULL if key is not found due to nature of set_find
	//or returns item if key is found
	for(i=0; i < ht->size;i++){
		return set_find(ht->nodes[i],key);
	}
	return set_find(ht->nodes[i],key);
}

/* Print the whole table; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL ht.
 * Print a table with no items if NULL itemprint.
 */
void hashtable_print(hashtable_t *ht, FILE *fp,
                     void (*itemprint)(FILE *fp, const char *key, void *item)){
	int i;
	if(fp != NULL){
		if(ht == NULL){
			fprintf(fp, "(null)");
		}
		for(i=0; i < ht->size; i++){
			if(itemprint != NULL){
				set_print(ht->nodes[i],fp,itemprint);
			}
		}
	}
}

/* Iterate over all items in the table; in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If ht==NULL or itemfunc==NULL, do nothing.
 */
void hashtable_iterate(hashtable_t *ht, void *arg,
               void (*itemfunc)(void *arg, const char *key, void *item) ){
       	int i;
        if(ht != NULL && itemfunc != NULL){
        	for(i=0; i < ht->size; i++){
			set_iterate(ht->nodes[i],arg,itemfunc);
		}
        }
}

/* Delete the whole hashtable; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ){
	int i;
	if(ht != NULL){
		//for loop iterates through hashtable/bins
		for(i=0; i < ht->size; i++){
			//if the item is a record
			/*if(itemdelete != NULL){
				//frees up allocated memory for each bin's set
				//deletes the sets in each bin
				itemdelete(ht->nodes[i]);
				//set_delete(ht->nodes[i],itemdelete);
				//free(ht->nodes[i]);
			} */
			if(ht->nodes[i] != NULL){
			//will delete the set in the given bin
				set_delete(ht->nodes[i],itemdelete);
				//printf("deleted set!");
			}
		}
		//frees the bins
		free(ht->nodes);
		//printf("freed bins");
		//frees the hashtable
		free(ht);
		//printf("freed ht");
	}
} 
