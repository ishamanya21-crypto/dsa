#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

void add()
{
int id;

if (count == MAX) {
printf("Queue Overflow! The printer queue is full.\n");
return;
}

printf("Enter the print job ID: ");
scanf("%d", &id);

rear = (rear + 1) % MAX;
queue[rear] = id;
count++;

printf("The job %d added\n", id);
}

void process()
{
if (count == 0) {
printf("Queue Underflow! No print jobs are waiting.\n");
return;
}

printf("Processing the job %d\n", queue[front]);
front = (front + 1) % MAX;
count--;
}

void display()
{
int index=front;
if(count==0)
{
printf("Number of print jobs waiting: %d\n", count);
return;
}
else
{
printf("Jobs in queue are\n");
for(int i=0; i<count; i++)
{
printf(" Job %d\n",queue[index]);
index=(index+1)%MAX;
}

}
}

void main() {
int ch;

do {
printf("\n1.Add Job\n2.Process Job\n3.Display Jobs\n4.Exit");
printf("\nEnter choice: ");
scanf("%d", &ch);

switch(ch) {
case 1:
add();
break;
case 2:
process();
break;
case 3:
display();
break;
case 4:
printf("Exit\n");
break;
default:
printf("Invalid Choice!\n");
}
} while(ch != 4);

}
