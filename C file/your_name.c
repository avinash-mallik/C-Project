#include<stdio.h>

void print(char *,char);

int main()
{
    FILE *fptr;
    char n[100],c1[12],f[]="binary_a.txt",v,c;
    int i,j,l,s=0,b,d;
    printf("Enter a string: ");
    gets(n);
    l=strlen(n);
    for(j=0;j<6;j++)
    {
        for(i=0;i<l;i++)
        {
            v=n[i];
            if(v==' ')
                continue;
            f[7]=v;
            fptr = fopen(f, "r");
            if (fptr == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            while(s!=j)
            {
                c = fgetc(fptr);
                if(c == ' ')
                    s++;
            }
            s = 0;
            b = 0;
            c = fgetc(fptr);
            while (c != ' ')
            {
                c1[b++]=c;
                c = fgetc(fptr);
            }
            c1[b]='\0';
            fclose(fptr);
            print(c1,v);
        }
        printf("\n");
    }
       return 0;
}
void print(char *c1,char c)
{
    int l,i,j,d;
    l=strlen(c1);
    for(i=0;i<l;i++)
    {
        d=c1[i]-64;
        if(i%2==0)
            for(j=0;j<d;j++)
                printf(" ");
        else
            for(j=0;j<d;j++)
                printf("#");
    }
}
