#include "growing_arrays.h"
#include <string.h>
#include <stdlib.h>

// returns the index of the item added  
int add_record(Record record) {
    // Your code here
    //nval points to the next available space in the record array
    table.record[table.nval] = record; //assigns record to the next available space in record 
    table.nval++; //increases the current number of records by 1
    
    if(table.nval >= table.max){ //if the current number of records is equal to the max amount of records, + the size
    	table.max *= GROW_SIZE;
    	table.record = realloc(table.record, table.max * sizeof(record));
    }
    
    return table.nval-1; 
}

// return 0 if there is no matching record
// return 1 if there is a matching record and deletes it and 
// moves records
int del_record(const char *name) {
    // Your code here
    int i;
    for(i = 0; i < table.nval; i++){
    	//if statement that checks if the names of the records are equal (it finds the index of the record to delete)
    	if (strcmp(name,table.record[i].name) == 0){ 
    	//memmove to shift the array to fill in where the record was deleted
    		memmove(&(table.record[i]),&(table.record[i+1]),table.max * sizeof(table.record[i]));
    		//table.max--;
    		table.nval--;
    		return 1;
    	}
    } 

    return 0;
}

// returns id of student record of the first matching record
int get_id(const char *name) {
    // Your code here
    int i;
    //printf("%d %d\n", table.max, table.nval);
    for (i = 0; i < table.nval; i++){
    	if(strcmp(name,table.record[i].name) == 0){
    		return table.record[i].id;
    	}
    }
   return 0;
}

// returns record with a valid index, 0 to max-1 
Record get_record(int index) {
    // Your code here
    if (index < table.max){
    	return table.record[index];
    } else{
    	printf("Error: Invalid index\n");
    	exit(1);
    }
    
}

// Testing code. You can modify this and check your own test cases.
/*struct Table table; // If you are using another .c file to test your program comment this line as well.
int main() {
    table.nval = 0;
    int i;
    Record r7;
    table.max = INIT_SIZE;
    table.record = malloc(sizeof(Record) * table.max);

    // test add_record
    Record r1 = {"Alice", 1};
    Record r2 = {"Bob", 2};
    Record r3 = {"Charlie", 3};
    Record r4 = {"Steve", 4};
    Record r5 = {"test",1};
    Record r6 = {"Alice", 1};
    Record r8 = {"Bob", 2};
    Record r9 = {"Charlie", 3}; 
    //Record r10 = {"Steve", 4};
    //Record r11 = {"test",1};
    int i1 = add_record(r1);
    int i2 = add_record(r2);
    int i3 = add_record(r3);
    int i4 = add_record(r4); 
    int i5 = add_record(r5);
    int i6 = add_record(r6);
    int i8 = add_record(r8);
    int i9 = add_record(r9);
    //int i10 = add_record(r10); 
    //int i11 = add_record(r11);
    //printf("added records at indices %d, %d, %d, %d\n", i1, i2, i3, i4);

    // test get_id and get_record
    int id = get_id("Bob");
    int id1 = get_id("Steve");
    Record r = get_record(i1); 
    //Record r5 = get_record(i4);
    
    for(i=0;i<table.max;i++){
    	r7 = table.record[i];
    	printf("record at index %d: name=%s, id=%d\n", i, r7.name, r7.id);
    }
    printf("record at index %d: name=%s, id=%d\n", i1, r.name, r.id);
    printf("record at index %d: name=%s, id=%d\n", i4, r5.name, r5.id);
    printf("record at index %d: name=%s, id=%d\n", i4, r6.name, r6.id);
    printf("record with name 'Bob': id=%d\n", id);
    printf("record with name 'Steve': id=%d\n", id1); 

    // test del_record
    printf("\n");
    int success = del_record("Bob");
    //printf("deleted record with name 'Bob': %d\n", success);
    //Record r6 = get_record(4);
    
    for(i=0;i<table.max;i++){
    	r7 = table.record[i];
    	printf("record at index %d: name=%s, id=%d\n", i, r7.name, r7.id);
    }
    printf("%d\n", r6.id);
    int id2 = get_id("Alice");
    id = get_id("Bob");
    int id3 = get_id("Charlie");
    id1 = get_id("Steve");
    
    printf("record at index %d: name=%s, id=%d\n", i4, r5.name, r5.id);
	//should return 1
    printf("record with name 'Alice': id=%d\n", id2);
    	//should return 0
    printf("record with name 'Bob': id=%d\n", id);
    	//should return 
    printf("record with name 'Charlie': id=%d\n", id3);
    printf("record with name 'Steve': id=%d\n", id1); 

    //free(table.record);
    //return 0; 
} */

/*
Output for the above testing code:

added records at indices 0, 1, 2
record at index 0: name=Alice, id=1
record with name 'Bob': id=2
deleted record with name 'Bob': 1
record with name 'Bob': id=0


*/
