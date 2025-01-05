#include "hashtable.h"
#include "lru.h"

/* Create a new (empty) lru; return NULL if error. */
lru_t *lru_new(const int capacity){
	if(capacity <= 0){
		return NULL;
	}
	lru_t *out = (lru_t*)malloc(sizeof(lru_t));
	out->cache = hashtable_new(capacity);
	out->capacity = capacity;
	
	return out;
}

/* Insert item, identified by key (string), into the given lru.
 * The key string is copied for use by the lru.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool lru_insert(lru_t *ht, const char *key, void *item){
	int i;
	//checks if parameters are null
	if( ht == NULL || key == NULL || item == NULL){
		return false;
	}
	//checks if key is in lru hashtable
	for(i=0; i < ht->capacity;i++){
		if(hashtable_find(ht->cache,key) != NULL){
			return false;
		}
	} 
	
	if(ht->cache->size >= ht->capacity){
		
	}
	
	hashtable_insert(ht->cache,strdup(key),item);
	return true;
}

/* Return the item associated with thz	e given key;
 * return NULL if lru is NULL, key is NULL, key is not found.
 */
void *lru_find(lru_t *ht, const char *key){
	if(ht == NULL || key == NULL){
		return NULL;
	}
	return hashtable_find(ht->cache,key);
}

/* Print the whole table; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL ht.
 * Print a table with no items if NULL itemprint.
 */
void lru_print(lru_t *ht, FILE *fp,
                     void (*itemprint)(FILE *fp, const char *key, void *item)){
        if(ht == NULL){
		printf("(null)");
	}           
        if(fp != NULL){
        	hashtable_print(ht->cache, fp, itemprint);
        }
 }

/* Iterate over all items in the table; in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If ht==NULL or itemfunc==NULL, do nothing.
 */
void lru_iterate(lru_t *ht, void *arg,
               void (*itemfunc)(void *arg, const char *key, void *item) ){
        if(ht != NULL && itemfunc != NULL){
        	hashtable_iterate(ht->cache,arg,itemfunc);
        }
}

/* Delete the whole lru; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void lru_delete(lru_t *ht, void (*itemdelete)(void *item) ){
	if(ht != NULL){
		hashtable_delete(ht->cache, itemdelete);
		
	}
	free(ht);
}

