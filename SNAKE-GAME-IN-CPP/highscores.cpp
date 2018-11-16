//DOUBLE LINKED LIST
struct data
{
    int score;
    string name;
};
struct hnode
{
    struct data D;
    struct hnode *next;
    struct hnode *prev;
};

class HighScores
{
    struct hnode* head;
    struct hnode* tail;
    public:
    HighScores()
    {
        head=NULL;
        tail=NULL;
    }
    struct hnode* create(struct data D)
    {
        struct hnode* newNode = new hnode;
        newNode->D = D;
        newNode->next=NULL;
        newNode->prev=NULL;
    }
    void insert_head(struct data D)
    {

    }
    void insert_tail(struct data D)
    {

    }
    void insert_at_middle_using_value(struct data D)
    {

    }
    void free()
    {

    }
};