#include<stdio.h>
#include<stdlib.h>
struct queue{
        int *data;
        int rear;
        int front;
        int size;
};

typedef struct queue *Queue;

Queue createIntegerQueue(int queuesize){
        Queue q=(Queue)malloc(sizeof(struct queue));
        if(q == NULL){
                printf("memory allocation for queue failed");
                return NULL;
        }
        q->data=(int*)malloc(queuesize*sizeof(int));
        if(q->data == NULL){
                free(q);
                return NULL;
        }
        q->front=q->rear= -1;
        q->size=queuesize;
        return q;
}

int isIntegerQueueFull(Queue q){
        if((q->rear+1)%q->size == q->front)
                return 1;
        return 0;
}

int isIntegerQueueEmpty(Queue q){
        if(q->front== -1)
                return 1;
        return 0;
}

int enqueueInteger(Queue q, int d){
        if(isIntegerQueueFull(q))
                return 0;
        if(isIntegerQueueEmpty(q))
                q->front=q->rear=0;
        else
                q->rear = (q->rear+1)%q->size;
        q->data[q->rear]=d;
        return 1;
}

int dequeueInteger(Queue q,int* dp){
        if(isIntegerQueueEmpty(q))
                return 0;
        *dp=q->data[q->front];
        if(q->front == q->rear)
                q->front=q->rear= -1;
        else
                q->front =(q->front +1)%q->size;
        return 1;
}

int freeIntegerQueue(Queue q){
        if(q==NULL)
                return 0;
        free(q->data);
        free(q);
        return 1;
}

int main(){
        int N,n;
        printf("Enter size of queue: ");
        scanf("%d",&N);
        struct queue *myQueue=createIntegerQueue(N);
        for(int i=0; i<N;i++){
                printf("enter a positive no: ");
                scanf("%d",&n);
                enqueueInteger(myQueue,n);
        }
        int qElement,rValue;
        while(dequeueInteger(myQueue,&qElement)){
                if(qElement >0){
                        rValue=rand() % 9 + 1;
                        qElement-=rValue;
                        enqueueInteger(myQueue,qElement);
                }
        }
        if(isIntegerQueueEmpty(myQueue))
                printf("now queue is empty");

        freeIntegerQueue(myQueue);
        return 0;
}


