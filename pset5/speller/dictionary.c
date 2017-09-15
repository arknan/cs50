/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// root or the base of the trie or tree :P 
    node *root = NULL ;

    // we also need a pointer to the root node in order to carry out manipulations without losing the root pointer !
    node *trav = NULL ; 
    int dict_size = 0 ;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int inword_len = strlen(word);
    trav = root ; 
    for ( int i = 0 ; i < inword_len ; i ++)
    {
        int c = a_to_node(word[i]);
        if ( trav->children[c] == NULL)
            return false;
        trav = trav->children[c];
    }
    if (trav->is_word == true)
        return true;
    else
        return false;
}


/**
 * Loads dictionary into memory. Returns true if successful else false.
 */

bool load(const char *dictionary)
{
    root = my_malloc();
    trav = root ; 

    FILE *dict = fopen(dictionary, "r") ;
    if ( dict == NULL )
    {
        fprintf(stderr, "Could not open %s", dictionary);
        return false;
    }
    char word[LENGTH + 1] ;
    while (fscanf(dict, "%s", word) != EOF )
    {
        int word_len = strlen(word);
        for ( int i = 0 ; i < word_len ; i ++) 
        {
            int temp = a_to_node(word[i]) ;
            if ( trav->children[temp] == NULL )
            {
                trav->children[temp] = my_malloc();
                trav = trav->children[temp];
            }
            else
            {
                trav = trav->children[temp] ;
            }
        }
        trav->is_word = true ;
        dict_size ++ ; 
        trav = root;
    }

    fclose(dict);

    return true ; 
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dict_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    free_mem(root);
    return true;
}

int a_to_node (char c)
{
    if ( (c >= 'a') && (c <='z') )
        return ( c - 97) ;
    else if ( (c >= 'A') && (c <= 'Z'))
        return (c - 65) ;
    else if ( c == '\'' )
        return 26 ;
    else
        return -1 ;
}

node* my_malloc(void)
{
    node *ptr = calloc(1, sizeof(node));
    if ( ptr == NULL )
    {
        fprintf(stderr, "Unable to allocate memory of size %lu bytes, exiting now\n", sizeof(node));
        exit(-99) ;
    }
    else
    {
        return ptr ;
    }
}

void free_mem(node *trav)
{
    for ( int i = 0 ; i < 27 ; i ++ )
    {
        if (trav->children[i] != NULL)
            free_mem(trav->children[i]);
    }
    free(trav);
    return ;
}
