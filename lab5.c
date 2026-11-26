#include <stdio.h>
#include <stdlib.h>

struct node
{
int c, p;
struct node *next;
};

struct node *create()
{
struct node *h, *t, *n;
int x, i;

h = malloc(sizeof(struct node));
h->next = h;
t = h;

printf("Enter number of terms: ");
scanf("%d", &x);

for(i = 0; i < x; i++)

{
n = malloc(sizeof(struct node));
scanf("%d%d", &n->c, &n->p);
t->next = n;
t = n;
}

t->next = h;
return h;
}
void display(struct node *h)
{
struct node *t;
int first = 1, c;

for(t = h->next; t != h; t = t->next)
{
if(t->c == 0)
continue;

if(t->c < 0)
printf(first ? "-" : " - ");
else if(!first)
printf(" + ");

c = abs(t->c);

if(c != 1 || t->p == 0)
printf("%d", c);
if(t->p > 0)
printf("x");
if(t->p > 1)
printf("^%d", t->p);

first = 0;
}

if(first)
printf("0");
}

struct node *add(struct node *p1, struct node *p2)
{
struct node *s, *t, *n;
struct node *a = p1->next, *b = p2->next;

s = malloc(sizeof(struct node));
t = s;

while(a != p1 || b != p2)
{
n = malloc(sizeof(struct node));

if(a == p1 || (b != p2 && b->p > a->p))
{
n->c = b->c;
n->p = b->p;
b = b->next;
}
else if(b == p2 || a->p > b->p)
{
n->c = a->c;
n->p = a->p;
a = a->next;
}
else
{
n->c = a->c + b->c;
n->p = a->p;
a = a->next;
b = b->next;
}

t->next = n;
t = n;
}

t->next = s;
return s;
}

int main()
{
struct node *p1, *p2;

printf("POLY1:\n");
p1 = create();

printf("POLY2:\n");
p2 = create();

printf("\nPOLY1 = ");
display(p1);

printf("\nPOLY2 = ");
display(p2);

printf("\nPOLYSUM = ");
display(add(p1, p2));

return 0;
}


	
	
