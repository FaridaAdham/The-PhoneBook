#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 50

typedef struct
{
    char last[size];
    char first[size];
    char address[size];
    char city[size];
    char number[size];
} contact;

contact a[1000];
int coun=0;

void start()
{
    printf("\t\t\t  Welcome To Telephone Book ^_^");
    printf("\n\t\t\t ----------------------------");
    printf("\n\t\t\t------------------------------");
    printf("\n Menu:-");
    printf("\n--------");
    printf("\n\t 1-Load\t\t\t\t2-Query");
    printf("\n\t 3-Add\t\t\t\t4-Delete");
    printf("\n\t 5-Modify\t\t\t6-Print");
    printf("\n\t 7-Save\t\t\t\t8-Exit");
}

void load()
{
    FILE * f;
    f = fopen("phonebook.txt","r");
    if (f != NULL)
    {
        printf("\nYour File Is Loaded Successfully. !\n");
        while(!(feof(f)))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%s",a[coun].last,a[coun].first,a[coun].address,a[coun].city,a[coun].number);
            fscanf(f,"\n");
            coun++;
        }
        fclose(f);
    }
    else
    {
        printf("\nFile Not Found. !!\n");
    }
}

void query()
{
    char lastname[size];
    printf("\nPlease Enter The Person's Last Name : ");
    scanf("%s",lastname);
    int j,i=0;
    for(j=0; j<coun; j++)
    {
        if(stricmp(lastname,a[j].last)==0)
        {
            i++;
            printf("\n\t(%d)\nLast Name : %s\nFirst Name : %s\nAddress : %s\nCity : %s\nPhone Number : %s \n",i,a[j].last,a[j].first,a[j].address,a[j].city,a[j].number);
        }
    }
    if(i==0)
        printf("\nContact Is Not Found. !!\n");
}

void add()
{
    printf("\n Enter The Last Name : ");
    scanf("%s",a[coun].last);
    printf("\n Enter The First Name : ");
    scanf("%s",a[coun].first);
    printf("\n Enter The Address : ");
    getchar();
    scanf("%[^\n]",a[coun].address);
    printf("\n Enter The city : ");
    scanf("%s",a[coun].city);
    printf("\n Enter The Phone Number : ");
    scanf("%s",a[coun].number);
    coun++;
    printf("\nThe Contact Is Added Successfully. !\n");
}

void del()
{
    int n,m;
    int l[size];
    int index[size];
    char firstname[size];
    char lastname[size];
    printf("\nPlease Enter The Person's Last Name : ");
    scanf("%s",lastname);
    printf("\nPlease Enter The Person's First Name : ");
    scanf("%s",firstname);
    int j,i=0,k=0,c;
    for(j=0; j<coun; j++)
    {
        if(stricmp(lastname,a[j].last)==0)
        {
            if(stricmp(firstname,a[j].first)==0)
            {
                i++;
                printf("\n\t(%d)\nLast Name : %s\nFirst Name : %s\nAddress : %s\nCity : %s\nPhone Number : %s \n",i,a[j].last,a[j].first,a[j].address,a[j].city,a[j].number);
                index[k]=j;
                l[k]=i;
                k++;
            }
        }
    }
    if(i==0)
        printf("\nContact Is Not Found. !!\n");
    printf("\nEnter The Number Of The Contact You Want To Delete : ");
    scanf("%d",&n);
    for(m=0; m<i; m++)
        if(n==l[m])
        {
            c=index[m];
            for(; c<coun; c++)
                a[c]=a[c+1];
        }
    coun--;
    printf("\nThe Contact Is Deleted Successfully. !\n");
}

void modify()
{
    int n,m;
    int l[size];
    int index[size];
    char lastname[size];
    printf("\nPlease Enter The Person's Last Name : ");
    scanf("%s",lastname);
    int j,i=0,k=0,c;
    for(j=0; j<coun; j++)
    {
        if(stricmp(lastname,a[j].last)==0)
        {
            i++;
            printf("\n\t(%d)\nLast Name : %s\nFirst Name : %s\nAddress : %s\nCity : %s\nPhone Number : %s \n",i,a[j].last,a[j].first,a[j].address,a[j].city,a[j].number);
            index[k]=j;
            l[k]=i;
            k++;
        }
    }
    if(i==0)
        printf("\nContact Is Not Found. !!\n");
    printf("\nEnter The Number Of The Contact You Want To Modify : ");
    scanf("%d",&n);
    for(m=0; m<i; m++)
        if(n==l[m])
        {
            c=index[m];
            printf("\n Enter The Last Name : ");
            scanf("%s",a[c].last);
            printf("\n Enter The First Name : ");
            scanf("%s",a[c].first);
            printf("\n Enter The Address : ");
            getchar();
            scanf("%[^\n]",a[c].address);
            printf("\n Enter The city : ");
            scanf("%s",a[c].city);
            printf("\n Enter The Phone Number : ");
            scanf("%s",a[c].number);
        }
    printf("\nThe Contact Is Modified Successfully. !\n");
}

void print()
{
    contact b[1000];
    int i,j,k;
    for(i=1; i<coun; i++)
    {
        for(j=1; j<coun; j++)
        {
            if(stricmp(a[j-1].last,a[j].last)>0)
            {
                b[j]=a[j-1];
                a[j-1]=a[j];
                a[j]=b[j];
            }
            if(stricmp(a[j-1].last,a[j].last)==0)
            {
                if(stricmp(a[j-1].first,a[j].first)>0)
                {
                    b[j]=a[j-1];
                    a[j-1]=a[j];
                    a[j]=b[j];
                }
                if(strcmp(a[j-1].last,a[j].last)>0)
                {
                    b[j]=a[j-1];
                    a[j-1]=a[j];
                    a[j]=b[j];
                }
            }
        }
    }
    for(k = 0; k< coun ; k++)
    {
        printf("\n\t(%d)\nLast Name : %s\nFirst Name : %s\nPhone Number : %s\nAddress : %s\nCity : %s \n",k+1,a[k].last,a[k].first,a[k].number,a[k].address,a[k].city);
    }
    printf("\nYour Contacts Is Printed Successfully. !\n");
}

void save()
{
    int k=0;
    FILE * f;
    f = fopen("phonebook.txt","w");
    for(k=0; k<coun; k++)
    {
        fprintf(f,"%s,%s,%s,%s,%s\n",a[k].last,a[k].first,a[k].address,a[k].city,a[k].number);
    }
    printf("\nYour File Is Saved Successfully. !\n");
    fclose(f);
}

void commands(int c)
{
    switch(c)
    {
    case 1:
        load();
        break;
    case 2:
        query();
        break;
    case 3:
        add();
        break;
    case 4:
        del();
        break;
    case 5:
        modify();
        break;
    case 6:
        print();
        break;
    case 7:
        save();
        break;
    case 8:
        break;
    default:
        printf("Your Choice Number Is Invalid. !!");
        break;
    }
}
int main()
{
    system("COLOR 1E");
    int cn;
    start();
    printf("\nEnter Your Choice Number : ");
    scanf("%d",&cn);
    if(cn!=1)
        printf("\nPlease You Must Load A File First. !!\n");
    else
        commands(cn);
    while(cn!=8)
    {
        printf("\nEnter Your Choice Number : ");
        scanf("%d",&cn);
        commands(cn);
    }
    printf("\nThanks For Using Our Telephonebook. !!\n");
    return 0;
}
