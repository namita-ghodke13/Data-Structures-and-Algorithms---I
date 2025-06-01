#include<stdio.h>
typedef struct record
{
  char name[30];
  int age;
}record;
int fileread(record a[20])
{
    FILE *fp;
    int i=0;

    fp=fopen("emp.txt","r");
    if(fp==NULL)
        printf("File Not Exist");
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d", a[i].name, &a[i].age);
            i++;
        }
        fclose(fp);
    }
    return i-1;
}
void bubblesort(int n)
{
    record a[20],b[30];
    n=fileread(a);
    int i,j,temp,k;
    char str[20];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j].age>a[j+1].age)
            {
                for(k=0;k<='\0';k++)
                b[k]=a[j];
                a[j]=a[j+1];
                for(k=0;k<='\0';k++)
                a[j+1]=b[k];
            }
        }
    }
    printf("Sorted list:\n");
    for(int i=0; i<n; i++)
        printf("%s = %d\n",a[i].name,a[i].age);

}
int main()
{
    int i, n;

    record a[20];
    n = fileread(a);

    for(i=0; i<n; i++)
        printf("%s = %d\n", a[i].name, a[i].age);
    bubblesort(n);
}