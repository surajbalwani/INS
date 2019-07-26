#include<stdio.h>

int i,key[10];
void convert(int number)
{
    for(i = 9; i >= 0; i--)
    {
        key[i]=number%10;
        number=number/10;
    }
}
int main()
{
    int j=0,
        permuted_key[10],
        permutation_10[10]={3,5,2,7,4,10,1,9,8,6},
        permutation_8[8]={6,3,7,4,8,5,10,9},
        ls_m_per_key[10],
        l_per_key[5],
        r_per_key[5],
        ls_l_per_key[5],
        ls_r_per_key[5],
        key_1[8],
        ls_2_l_per_key[5],
        ls_2_r_per_key[5],
        ls_2_m_per_key[10],
        key_2[8],
        numeric_key;

    printf("enter the key : ");
    scanf("%d",&numeric_key);
    convert(numeric_key);

    printf("Key : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",key[i]);
    }
    
    for(i = 0; i < 10; i++)
    {
        permuted_key[i] = key[permutation_10[i]-1];
    }

    printf("\npermuted key : ");
    for(i = 0; i < 10; i++)
    {
        printf("%d",permuted_key[i]); 
    }

    for(i = 0; i < 5; i++)
    {
        l_per_key[i] = permuted_key[i];
    }
    for(i = 0; i < 5; i++)
    {
        r_per_key[i] = permuted_key[i+5];
    }

    printf("\nleft permuted key : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d",l_per_key[i]);
    }
    printf("\nright permuted key : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d",r_per_key[i]);
    }

    ls_l_per_key[4] = l_per_key[0];
    for(i = 0; i < 4; i++)
    {
        ls_l_per_key[i] = l_per_key[i+1]; 
    }

    ls_r_per_key[4] = r_per_key[0];
    for(i = 0; i < 4; i++)
    {
        ls_r_per_key[i] = r_per_key[i+1]; 
    }

    printf("\nleft shifted left permuted key : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d",ls_l_per_key[i]);
    }
    printf("\nleft shifted right permuted key : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d",ls_r_per_key[i]);
    }

    for(i = 0; i < 10; i++)
    {
        if(i < 5)
        {
            ls_m_per_key[i] = ls_l_per_key[i];
        }
        else
        {
            ls_m_per_key[i] = ls_r_per_key[j++];
        }
    }

    printf("\nleft shifted merged permuted key : ");
    for(i = 0; i < 10; i++)
    {
        printf("%d",ls_m_per_key[i]);
    }

    for(i = 0; i < 8; i++)
    {
        key_1[i] = ls_m_per_key[permutation_8[i]-1];
    }

    printf("\n8 bit key 1 : ");
    for(i = 0; i < 8; i++)
    {
        printf("%d",key_1[i]);
    }
    
    ls_2_l_per_key[4] = ls_l_per_key[0];
    ls_2_l_per_key[3] = ls_l_per_key[1];
    for(i = 0; i < 3; i++)
    {
        ls_2_l_per_key[i] = ls_l_per_key[i+2]; 
    }

    ls_2_r_per_key[4] = ls_r_per_key[0];
    ls_2_r_per_key[3] = ls_r_per_key[1];
    for(i = 0; i < 3; i++)
    {
        ls_2_r_per_key[i] = ls_r_per_key[i+2]; 
    }
    printf("\n2-left shifted left permuted key : ");
    for(i = 0; i < 5; i++)
    {
        ls_2_m_per_key[i] = ls_2_l_per_key[i];
        printf("%d",ls_2_l_per_key[i]);
    }
    printf("\n2-left shifted right permuted key : ");
    for(i = 0; i < 5; i++)
    {
        ls_2_m_per_key[i+5] = ls_2_r_per_key[i];
        printf("%d",ls_2_r_per_key[i]);
    }
    printf("\n2nd left shifted merged permuted key : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d",ls_2_m_per_key[i]);
    }

    for(i = 0; i < 8; i++)
    {
        key_2[i] = ls_2_m_per_key[permutation_8[i]-1];
    }
    printf("\n8 bit key 2 : ");   
    for(i = 0; i < 8; i++)
    {
        printf("%d",key_2[i]);
    }

    printf("\n");
    return 0;
}