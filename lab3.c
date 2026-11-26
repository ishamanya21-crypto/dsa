#include <stdio.h>
#define MAX 16
int stack[MAX], top = -1;
void push() {
int x;
if (top == MAX - 1)
printf("Stack Overflow\n");
else {
printf("Enter element\n");
scanf("%d", &x);
stack[++top] = x;
}
}
void pop() {
if (top == -1)
printf("Stack Underflow\n");
else
printf("Popped element: %d\n", stack[top--]);
}
void display() {
int i;
if (top == -1)
printf("Stack is Empty\n");

else {
printf("Stack elements\n ");
for (i = top; i >= 0; i--)
printf("[%d] -> %d\n ",i, stack[i]);

}
}
void main() {
int ch;
do {
printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("Enter choice\n");
scanf("%d", &ch);
switch (ch) {
case 1: push(); break;
case 2: pop(); break;
case 3: display(); break;
case 4: printf("Program Exit\n"); break;
default: printf("Invalid Choice\n");
}
} while (ch != 4);

}
