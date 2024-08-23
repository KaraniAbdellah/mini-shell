#ifndef READING
#define READING

#define MAX_WORD 20
#define MAX_INPUT 1024

typedef struct list {
    char word[MAX_WORD];
    struct list *next;
    struct list *prev;
} list;



    list *read_input();
    void tokenize_input(char *input, list **head);
    void insert_at_list(list **head, char *word);
    void print_list(list *head);





#endif

