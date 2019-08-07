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
        initial_permutation_8[8]={2,6,3,1,4,8,5,7},
        expand_permutation_8[8]={4,1,2,3,2,3,4,1},
        permutation_4[4]={2,4,3,1},
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
        numeric_key,
        num_pt,pt[8],per_pt[8],l_per_pt[4],r_per_pt[4],r_expanded_pt[8],
        ex_or[8],l_ex_or[4],r_ex_or[4],ex_or2[4],
        s_0_box[4][4]={ (1),(1),(3),(2),
        				(3),(2),(1),(0),
        				(0),(2),(1),(3),
        				(3),(1),(3),(2) },
        				
        s_1_box[4][4]={ (0),(1),(2),(3),
        				(2),(0),(1),(3),
        				(3),(0),(1),(0),
        				(2),(1),(0),(3) },
        s_box_decimal1,s_box_decimal2,s_box_binary[4],permuted_S_box[4],
        l_row_1,l_row_2,l_column_1,l_column_2,l_row_1_decimal,l_column_1_decimal,
        r_row_1,r_row_2,r_column_1,r_column_2,r_row_1_decimal,r_column_1_decimal,
        decimal1,decimal2;

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

    printf("\nenter the plain-text(8 bit) : ");
    scanf("%d",&num_pt);
    for(i = 7; i >= 0; i--)
    {
        pt[i]=num_pt%10;
        num_pt=num_pt/10;
    }
    
    for(i = 0; i < 8; i++)
    {
        per_pt[i] = pt[initial_permutation_8[i]-1];
    }

    printf("permuted plain text : ");
    for (i = 0; i < 8; i++)
    {
        printf("%d",per_pt[i]);
    }

//-------------------------Division of IP-8 in two eqal halfs-------------------------  
    j=0;
    for(i = 0; i < 8; i++)
    {
        if(i < 4)
        {
            l_per_pt[i] = per_pt[i];
        }
        else
        {
            r_per_pt[j++] = per_pt[i];
        }
    }

//-------------------------Printing two eqal halfs of IP-8-------------------------
    printf("\nleft permuted plain text : ");
    for(i = 0; i < 4; i++)
    {
        printf("%d",l_per_pt[i]);
    }
    printf("\nright permuted plain text : ");
    for(i = 0; i < 4; i++)
    {
        printf("%d",r_per_pt[i]);
    }

//-------------------------Performing Expansion of Right Half of IP-8-------------------------
    for(i = 0; i < 8; i++)
    {
        r_expanded_pt[i] = r_per_pt[expand_permutation_8[i]-1];
    }

//-------------------------Printing Expansion of Right Half of IP-8-------------------------
    printf("\nright expanded permuted plain text : ");
    for (i = 0; i < 8; i++)
    {
        printf("%d",r_expanded_pt[i]);
    }
    
//-------------------------Calculating EX-OR--------------------------
    for(i = 0; i < 8; i++)
    {
        if(r_expanded_pt[i] == key_1[i])
        {
            ex_or[i] = 0;
        }
        else
        {
            ex_or[i] = 1;
        }
    }
    
//-------------------------Printing EX-OR-------------------------
    printf("\nex-or : ");
    for (i = 0; i < 8; i++)
    {
        printf("%d",ex_or[i]);
    }
    
    for(i = 0; i < 4; i++)
    {
        l_ex_or[i] = ex_or[i];
    }
    for(i = 0; i < 4; i++)
    {
        r_ex_or[i] = ex_or[i+4];
    }
    
//-------------------------for left ex-or-------------------------
    l_row_1 = l_ex_or[0];
    l_row_2 = l_ex_or[3];
    l_column_1 = l_ex_or[1];
    l_column_2 = l_ex_or[2];
      
    if(l_row_1 == 0 && l_row_2 == 0) 
    	l_row_1_decimal = 0;
    if(l_row_1 == 1 && l_row_2 == 0) 
    	l_row_1_decimal = 2;
    if(l_row_1 == 0 && l_row_2 == 1) 
    	l_row_1_decimal = 1;
    if(l_row_1 == 1 && l_row_2 == 1) 
    	l_row_1_decimal = 3;
    	
    if(l_column_1 == 0 && l_column_2 == 0) 
    	l_column_1_decimal = 0;
    if(l_column_1 == 1 && l_column_2 == 0) 
    	l_column_1_decimal = 2;
    if(l_column_1 == 0 && l_column_2 == 1) 
    	l_column_1_decimal = 1;
    if(l_column_1 == 1 && l_column_2 == 1) 
    	l_column_1_decimal = 3;
	
//-------------------------for right ex-or-------------------------
	r_row_1 = r_ex_or[0];
    r_row_2 = r_ex_or[3];
    r_column_1 = r_ex_or[1];
    r_column_2 = r_ex_or[2];
    
	if(r_row_1 == 0 && r_row_2 == 0) 
    	r_row_1_decimal = 0;
    if(r_row_1 == 1 && r_row_2 == 0) 
    	r_row_1_decimal = 2;
    if(r_row_1 == 0 && r_row_2 == 1) 
    	r_row_1_decimal = 1;
    if(r_row_1 == 1 && r_row_2 == 1) 
    	r_row_1_decimal = 3;
    	
    if(r_column_1 == 0 && r_column_2 == 0) 
    	r_column_1_decimal = 0;
    if(r_column_1 == 1 && r_column_2 == 0) 
    	r_column_1_decimal = 2;
    if(r_column_1 == 0 && r_column_2 == 1) 
    	r_column_1_decimal = 1;
    if(r_column_1 == 1 && r_column_2 == 1) 
    	r_column_1_decimal = 3;
    	
//-------------------------Extracting the decimals for s_box-------------------------
 	s_box_decimal1 = s_0_box[l_row_1_decimal][l_column_1_decimal];
 	s_box_decimal2 = s_1_box[r_row_1_decimal][r_column_1_decimal];
 	
//-------------------------for s_box decimal2(Decimal to Binary conversion)------------------------- 	
 	if(s_box_decimal1 == 0)
 	{
 		s_box_binary[0] = 0;
 		s_box_binary[1] = 0;
 	}
 	if(s_box_decimal1 == 1)
 	{
 		s_box_binary[0] = 0;
 		s_box_binary[1] = 1;
 	}
 	if(s_box_decimal1 == 2)
 	{
		s_box_binary[0] = 1;
 		s_box_binary[1] = 0;
 	}
	if(s_box_decimal1 == 3)
 	{
 		s_box_binary[0] = 1;
 		s_box_binary[1] = 1;
 	}
 	
//-------------------------for s_box decimal2(Decimal to Binary conversion)------------------------- 	
 	if(s_box_decimal2 == 0)
 	{
 		s_box_binary[2] = 0;
 		s_box_binary[3] = 0;
 	}
 	if(s_box_decimal2 == 1)
 	{
 		s_box_binary[2] = 0;
 		s_box_binary[3] = 1;
 	}
 	if(s_box_decimal2 == 2)
 	{
		s_box_binary[2] = 1;
 		s_box_binary[3] = 0;
 	}
	if(s_box_decimal2 == 3)
 	{
 		s_box_binary[2] = 1;
 		s_box_binary[3] = 1;
 	}	   
    
//-------------------------Printing the output of s_box-------------------------
	printf("\ns_box_binary : ");
	for(i = 0; i < 4; i++)
	{
		printf("%d",s_box_binary[i]);
	}
    
//-------------------------Permuting the output of s_box-------------------------    
	for(i = 0; i < 4; i++)
    {
        permuted_s_box[i] = s_box_binary[permutation_4[i]-1];
    }
    
//-------------------------Printing the output of permuted s_box-------------------------
    printf("\npermuted s_box : ");
    for(i = 0; i < 4; i++)
    {
        printf("%d",permuted_s_box[i]);
    }

//-------------------------Calculating the EX-OR of -------------------------
	for(i = 0; i < 4; i++)
	{
		if(permuted_s_box[i] == l_per_pt[i])
		{
			ex_or2[i] = 0;
		}
		else
		{
			ex_or2[i] = 1;
		}
	}   
	
//-------------------------Printing the EX-OR of -------------------------
	printf("\nex_or2 : ")
	for(i = 0; i < 4; i++)
	{
		printf("%d",ex_or2[i]);
	}
    printf("\n");
    return 0;
}
