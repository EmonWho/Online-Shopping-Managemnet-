#include<stdio.h>
#include<string.h>
struct admin
{
    char name[20];
    char password[20];

};

struct product
{
    char name[40];
    float cost;
    char country_name[40];

};

void adminModule()
{
    struct admin array1[20];
    char name[20];
    char password[20];
    FILE* fp = fopen("Admin.txt","r");
    printf("Write your user name.no<space> in username\n");
    scanf("%s",name);
    printf("Enter your password.\n");
    scanf("%s",password);
    int i = 0;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",array1[i].name,array1[i].password);
        i++;


    }
    int j,flag = 0;
    for(j = 0 ; j<i-1; j++)
    {
        if(strcmp(name,array1[j].name) == 0 &&strcmp(password,array1[j].password) == 0)
        {

            printf("Log in succssful\n");
            flag = 1;
            break;

        }

    }
    fclose(fp);
    if(flag == 0)
    {
        printf("Unsuccessful\n");

        return;
    }
    printf("1 for add item,2 for delete item,3 for update item\n");
    int flag1;
    scanf("%d",&flag1);


    fp = fopen("EmonText.txt","r");
    struct product array[20];
    i = 0;
    while (!feof(fp))
    {
        fscanf(fp,"%s %f %s",array[i].name,&array[i].cost,array[i].country_name);
        i++;
    }
    fclose(fp);
    for(j = 0; j<i-1; j++)
    {
        printf("Product no.:%d  ",j+1);
        printf("Product Name :%s  ",array[j].name);
        printf("Cost :%f ",array[j].cost);
        printf("Manufactured By:%s  ",array[j].country_name);
        printf("\n");


    }
    if(flag1 == 3)
    {
        int no;
        printf("Product number\n");
        scanf("%d",no);
        printf("Product Name \n");
        scanf("%s",array[no-1].name);
        printf("Cost\n");
        scanf("%s ",array[no-1].cost);
        printf("Manufactured By:  \n");
        scanf("%s",array[no-1].country_name);
        FILE *fp = fopen("kausarText.txt","w");
        int counter = 0;

        for(counter = 0; counter < j; counter++)
        {
            fprintf(fp,"%s %d %s\n",array[counter].name,array[counter].cost,array[counter].country_name);

        }
    }
    else if(flag1 == 2)
    {
        int no;
        printf("Which product will you delete? product number\n");
        scanf("%d",no);
        int i;
        for(i = no; i < j; i++)
        {
            strcpy(array[i-1].name,array[i].name);
            array[i-1].cost = array[i].cost;
            strcpy(array[i-1].country_name,array[i].country_name);
        }
        FILE *fp = fopen("EmonText.txt","w");
        int counter;
        for(counter = 0; counter < j - 1; counter++)
        {
            fprintf(fp,"%s %d %s\n",array[counter].name,array[counter].cost,array[counter].country_name);

        }

    }
    else
    {
        printf("Add your item.\n");
        printf("Product Name\n");
        scanf("%s",array[j].name);
        printf("Cost\n");
        scanf("%f",&array[j].cost);
        printf("Manufactured By:\n");
        scanf("%s",array[j].country_name);
        int counter = 0;
        printf("%s",array[j].country_name);
        FILE *fp = fopen("EmonText.txt","a");

        fprintf(fp,"%s %f %s\n",array[j].name,array[j].cost,array[j].country_name);
        printf("\n");
       fclose(fp);

    }

}

void customerModule()
{
    char ch;
    printf("Have you any account? Press 1 for yes and 0 for no.\n");
    scanf("%c",&ch);

    if(ch == '1')
    {
        printf("You are registered customer so you can sell your product.\n");
        FILE *fp = fopen("EmonText.txt","r");
        struct product array[20];
        int i = 0;
        while (!feof(fp))
        {
            fscanf(fp,"%s %f %s",array[i].name,&array[i].cost,array[i].country_name);
            i++;
        }
        fclose(fp);
        printf("Add your item.\n");
        printf("Product Name\n");
        scanf("%s",array[i].name);
        printf("Cost\n");
        scanf("%f",&array[i].cost);
        printf("Manufactured By:\n");
        scanf("%s",array[i].country_name);
        int counter = 0;
        fp = fopen("kausarText.txt","a");


        fprintf(fp,"%s %f %s\n",array[i].name,array[i].cost,array[i].country_name);


        fclose(fp);

    }



    else
    {
        struct product array[20];
        FILE *fp = fopen("EmonText.txt","r");
        int i = 0,j;
        while (!feof(fp))
        {
            fscanf(fp,"%s %f %s",array[i].name,&array[i].cost,array[i].country_name);
            i++;
        }
        printf("Currently available products are:\n");
        for(j = 0; j < i-1; j++)
        {
            printf("Product no.:%d  ",j+1);
            printf("Product Name :%s  ",array[j].name);
            printf("Cost :%f ",array[j].cost);
            printf("Manufactured By:%s  ",array[j].country_name);
            printf("\n");
        }
        fclose(fp);
        printf("Press 1 to purchase otherwise 0\n");
        int purvar;
        scanf("%d",&purvar);
        if(purvar == 0)
        {
            return;

        }
        else
        {
            int k = 0;
            float costing = 0;
            int ch1;
            struct product demo_array[10];
            int quan_array[10];
            int quantity;
            do
            {

                printf("Enter the product no(Press 0 for quit)\n");


                scanf("%d",&ch1);
                if(ch1)
                {
                    printf("Quantity? \n");

                    scanf("%d",&quantity);

                    quan_array[k] = quantity;

                    costing += quantity*array[ch1-1].cost;
                    strcpy(demo_array[k].name,array[ch1-1].name);
                    demo_array[k].cost = array[ch1-1].cost;

                    k++;
                }
            }
            while(ch1);
            int x;
            for(x = 0; x < k; x++)
            {
                printf("Product Name :%s ",demo_array[x].name);
                printf("Cost :%f ",demo_array[x].cost);
                printf("Quantity:%d ",quan_array[x]);
                printf("\n");

            }
            printf("total :%f",costing);
        }

    }
}
    int main()
    {
        char ch;

        printf("=========================================================\n");
        printf(".....................Welcome To E-Shopping...............\n");
        printf("=========================================================\n");
        printf("Are you customer/seller? for seller press s and otherwise c\n");
        int x = 1;
        while(x == 1)
        {
            scanf("%c",&ch);
            switch(ch)
            {
            case 's' :
                {adminModule();
                break;}

            case 'c' :{customerModule();
                      break;
            }
            }


        }
    }




