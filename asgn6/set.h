#ifndef SET_H_
#define SET_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct setnode {
	char* key;
	void* item;
	struct setnode *next;
	struct setnode *prev;
} setnode_t;

typedef struct set {
	setnode_t *head;
} set_t;

/* Create a new (empty) set; return NULL if error. */
set_t* set_new(void);

/* Insert item, identified by a key (string), into the given set.
 * The key string is copied for use by the set.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool set_insert(set_t *set, const char *key, void *item);

void *move_to_head(set_t *set, setnode_t *node);

void *find_helper(setnode_t *node, const char *key);
/* Return the item associated with the given key;
 * return NULL if set is NULL, key is NULL, or key is not found.
 */
void *set_find(set_t *set, const char *key);

/* Print the whole set; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL set.
 * Print a set with no items if NULL itemprint.
*/
void set_print(set_t *set, FILE *fp,
               void (*itemprint)(FILE *fp, const char *key, void *item) );

/* Iterate over all items in the set, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If set==NULL or itemfunc==NULL, do nothing.
 */
void set_iterate(set_t *set, void *arg,
                 void (*itemfunc)(void *arg, const char *key, void *item) );

/* Delete the whole set; ignore NULL set.
 * Provide a function that will delete each item (may be NULL).
 */
void set_delete(set_t *set);

#endif // SET_H_
