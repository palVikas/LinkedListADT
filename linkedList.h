typedef struct Node * node_ptr;
typedef struct linkedList LinkedList;
typedef struct Node Node;
typedef void (traverseFunc)(void *data);

struct Node {
	void* data;	
	node_ptr next;
};

struct linkedList{
	node_ptr head;
	node_ptr tail;
	int count;
};

LinkedList createList(void);

Node* create_node(void *data);

int add_to_list(LinkedList *,Node *);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

void traverse(LinkedList, traverseFunc* travers);

void * getElementAt(LinkedList list, int );

int indexOf(LinkedList, void *);

void * deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **);