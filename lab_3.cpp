#include <iostream>
#include <ctime>

int main()
{

    srand(time(0));
    long long n ,m;
    n   =rand()%5+3;
    m   =rand()%5+3;
   // m=5;
     long long arrayA[m][m];
     //long long arrayB[n];
    for (size_t i = 0; i < m ;i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arrayA[i][j]=rand()%9+3;
            
        }

    }
    
    
    int a=0;
    //long long arrayC[m]={};
    long long *A_array_start=&arrayA[0][0];
    long long *A_array_end=&arrayA[m-1][m-1];
    long long  *n1=&m;
        asm (

         "movq $0,%%rax\n\t"
          "movq %[A_array_start],%%rbx\n\t"
          "movq %[m],%%r10\n\t"
          "movq $1 ,(%%rbx)\n\t"

          " start1: \n\t"
            "movq %%r10, %%rcx \n\t"
          "s: \n\t"
            "addq $8, %%rbx \n\t"
            "movq $0 ,(%%rbx)\n\t"
          "loop s \n\t"
            "addq $8, %%rbx \n\t"
            "movq $1 ,(%%rbx)\n\t"
          "cmpq %%rbx, %[A_array_end]\n\t"
         "jne start1\n\t"

        "decq %%r10\n\t"
         "start2:\n\t "
         "movq %%r10, %%rcx \n\t"
        "s1: \n\t"
            "subq $8, %%rbx \n\t"
          "loop s1 \n\t"
            "movq $1 ,(%%rbx)\n\t"
         "cmpq %%rbx, %[A_array_start]\n\t"
         "jne start2\n\t"


            ://"=a"(a)
            :[arrayA]"m"(arrayA),[A_array_end]"m"(A_array_end),
            [A_array_start]"m"(A_array_start),[m]"m"(m),[n1]"m"(n1)
            :"%rbx", "%rcx","%rdx","cc","memory","%r9","%r10","%r11"
        );
    
        
        for (size_t i = 0; i < m ;i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout<<arrayA[i][j]<<"\t";
        }
        std::cout<<'\n';
    }
    
    return 0 ;
    }
