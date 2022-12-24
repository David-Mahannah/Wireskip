
typedef int msg_type;

#define TEXT 0;
#define FILE 1;

list_node_t * queue;

typedef struct msg
{
    char * text;
    int time_stamp;
    msg_type type;
} msg_t;


typedef struct list_node
{
    msg_t * msg;
    list_node * next;
} list_node_t;


msg_t_free(msg_t * m)
{
    free(m->text);
    free(m);
}

void queue_init()
{
    queue = malloc(sizeof(list_node_t));
    queue->msg = NULL;   
}

void queue_add(msg_list * msg)
{
    // LOCK
    list_node_t * curr = queue;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = msg;
    // UNLOCK
}

msg_t * queue_pop()
{
    // LOCK
    list_node_t * temp;
    temp = queue->next;

    if (temp != NULL)
        queue->next = temp->next;

    // UNLOCK
    return temp; 
}