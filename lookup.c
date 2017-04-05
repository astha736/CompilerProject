/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lookup.h"

hash_table *create_hash_table(int size) {
        hash_table *new_table;
        if (size<1) return NULL; 

        if ((new_table = malloc(sizeof(hash_table))) == NULL) {
            return NULL;
        }
        
        if ((new_table->table = malloc(sizeof(list_node *) * size)) == NULL) {
            return NULL;
        }
	int i;
        for(i=0; i<size; i++) new_table->table[i] = NULL;
        new_table->size = size;
	//printf("Table made.\n");
        return new_table;
    }
/*****************************************************************************************/

unsigned int hash(hash_table *hashtable, char str[]) {
        unsigned int hashval;
        hashval = 0;
        for(; *str != '\0'; str++) hashval = *str + (hashval << 5) - hashval;
        return hashval % hashtable->size;
}

int lookup_string(hash_table *hashtable, char str[]) {
        list_node *list;
        unsigned int hashval = hash(hashtable, str);

        for(list = hashtable->table[hashval]; list != NULL; list = list->next) {
		//printf("Here: 1\n");            
		if (strcmp(str, list->str) == 0) return list->enumval;
 	   // if (strcmp(str, list->str) == 0) return list;
        }
        return -1;
    }

int add_string(hash_table *hashtable, char str[], int enumval) {
        list_node *new_list;
	unsigned int hashval = hash(hashtable, str);
	//printf("Hashvalue %d\n", hashval);
        if ((new_list = malloc(sizeof(list_node))) == NULL) return 1;
	strcpy(new_list->str, str);
	new_list->enumval = enumval;
        int current = lookup_string(hashtable, str);
	//printf("Currentvalue %d\n", current);
        if (current > 0) return 2;
	//printf("Here3 %d\n", new_list->enumval);
	//printf("Adding %d\n", new_list->enumval);
        new_list->next = hashtable->table[hashval];
        hashtable->table[hashval] = new_list;
        return 0;
    }

void free_table(hash_table *hashtable) {
        int i;
        list_node *list, *temp;

        if (hashtable==NULL) return;
         
        for(i=0; i<hashtable->size; i++) {
            list = hashtable->table[i];
            while(list!=NULL) {
                temp = list;
                list = list->next;
                free(temp->str);
		free(&(temp->enumval));
                free(temp);
            }
        }
 
        free(hashtable->table);
        free(hashtable);
}

hash_table *init_hash_table(int size) {
	hash_table *hashtable = create_hash_table(size);
	FILE *fp = fopen("keywords.txt", "r");
	char str[25];
	int enumval;
	while (fscanf(fp, "%s %d\n", str, &enumval) > 0) {
	//printf("%s %d\n", str, enumval);
	add_string(hashtable, str, enumval);
	}
	return hashtable;
}

/*int main() {
	hash_table *ht;
	ht = init_hash_table(30);
	char str[25];
	list_node *list;
	int i;
	//for (i=0; i<30; i++) {
	/*for(list = ht->table[i]; list != NULL; list = list->next) {
		printf("%s %d\n", list->str, list->enumval);
	}
	}
	while(1) {
	scanf("%s", str);
	printf("%d\n", lookup_string(ht, str)); 
	}
}*/



