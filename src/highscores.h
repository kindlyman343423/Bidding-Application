/*structure for highscores*/
struct highscorenode;

/*highscore list functions*/
void insert_head(int,char*,int);
void insert_node(int,char*,int);
void freelist();
void print_list();
void highscores();