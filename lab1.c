#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{

int id;
char title[30], author[30], status[10];
float price;
};
struct Book * b;
int n;
void create()
{
printf("Enter number of books\n ");
scanf("%d", & n);
b = malloc(n * sizeof(struct Book));
for (int i = 0; i < n; i++)
{
printf("Enter Book ID\n");
scanf("%d", & b[i].id);
printf("Enter Title\n");
scanf(" %[^\n]", b[i].title);
printf("Enter Author\n");
scanf(" %[^\n]", b[i].author);
printf("Enter Price\n");
scanf("%f", & b[i].price);
strcpy(b[i].status, "Available");
}
}
void display()
{

if (b == NULL)
printf("No books found\n");
else
{

printf("Books available\n");
for (int i = 0; i < n; i++)
printf("\nID:%d\nTitle:%s\nAuthor:%s\nPrice:%.2f\nStatus:%s\n",
b[i].id, b[i].title, b[i].author, b[i].price, b[i].status);
}
}
void search()
{
int id;
printf("Enter Book ID: ");
scanf("%d", & id);
for (int i = 0; i < n; i++)
{
if (b[i].id == id)
{
printf("ID:%d\nTitle:%s\nAuthor:%s\nPrice:%.2f\nStatus:%s\n",
b[i].id, b[i].title, b[i].author, b[i].price, b[i].status);
return;
}
}
printf("Book not found\n");
}
void issueBook()
{

int id;
printf("Enter Book ID: ");
scanf("%d", & id);
for (int i = 0; i < n; i++)
{
if (b[i].id == id)
{
if (strcmp(b[i].status, "Available") == 0)
{
strcpy(b[i].status, "Issued");
printf("Book issued successfully\n");
}
else
printf("Book already issued\n");
return;
}
}
printf("Book not found\n");
}

void returnBook()
{
int id;
printf("Enter Book ID: ");
scanf("%d", & id);

for (int i = 0; i < n; i++)
{

if (b[i].id == id && strcmp(b[i].status, "Issued") == 0)
{
strcpy(b[i].status, "Available");
printf("Book returned successfully\n");
return;
} else if (b[i].id == id && strcmp(b[i].status, "Available") == 0)
{
printf("Book was not issued\n");
return;
}
}

printf("Book not found!\n");
}
void main()
{
int ch;
do
{
printf("\n\nEnter 1.Add 2.Display 3.Search 4.Issue 5.Return 6.Exit\n");
printf("Enter choice\n ");
scanf("%d", & ch);
switch (ch)
{
case 1:
create();
break;
case 2:
display();

break;
case 3:
search();
break;
case 4:
issueBook();
break;
case 5:
returnBook();
break;
case 6:
free(b);
break;
default:
printf("Invalid choice\n");
}
} while (ch != 6);

}
