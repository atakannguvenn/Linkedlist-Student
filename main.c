#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    int id;
    char name[10];
    float grade;
    struct node *next;
};

void build_link(struct node *ap);
void happy(struct node *bp);
void delete_fail(struct node *cp);

main()
{
    struct node head;
    head.next=NULL;
    build_link(&head);
    printf("Student list before deleting\n");
    happy(head.next);
    delete_fail(&head);
    printf("\nStudent list after deleting\n");
    happy(head.next);
    return 0;
}

void build_link(struct node*tmp)
{
    int nu_id;
    char nu_nam[10];
    float nu_grade;
    struct node *np;
    FILE *fp;
    fp=fopen("Student.txt","r");
    while (fscanf(fp,"%d %s %f",&nu_id,&nu_nam,&nu_grade)!=EOF)
    {
        np=(struct node*) malloc(sizeof(struct node));
        strcpy(np->name,nu_nam);
        np->id=nu_id;
        np->grade=nu_grade;
        np->next=NULL;
        tmp->next=np;
        tmp=tmp->next;
    }
}

void happy(struct node *np)
{
    while(np!=NULL)
    {
        printf("%d %s %.2f\n",np->id,np->name,np->grade);
        np=np->next;
    }
}

void delete_fail(struct node *cp)
{

    while(cp->next!=NULL)
    {
        if(cp->next->grade<60)
        {
            cp->next=cp->next->next;
        }
        else
        {
            cp=cp->next;
        }
    }

}
