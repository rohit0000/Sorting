#define MAX 5
#define TRUE 1
#define FALSE 0



typedef struct{
	int front;
	int rear;
	char entry[MAX];
} queue;

bool empty(queue *q)
{
	if(q->rear<q->front)
		return TRUE;
	else
		return FALSE;
}

bool isFull(queue *q)
{
	if(q->rear>5)
		return TRUE;
	else
		return FALSE;
}

void insert(queue *q, char newitem[MAX])
{
	if(empty(q)){
        q->rear++;
		strcpy(q->front, newitem);
		printf("\n%s\n", q->entry);
		return;
    }
	else{
		q->rear++;
		  if(q->rear == 5 && q->front >= 1){
      strcpy(q->entry, newitem);
		  printf("\n%s\n", q->entry);
		  q->front = 0;
		  return;
      }
      else if(q->rear == 5 && q->front == 0){     
        printf("OVERFLOW!!");
        q->rear = 4;
      return;
    }
      else{
        strcat(q->entry, newitem);
		printf("\n%s\n", q->entry);
		return;
    }
        }
	return;
}

char remove(queue *q)
{
	char x;
	x=q->entry[q->front];
	q->entry[q->front]=' ';
	q->front++;
	return x;
}
