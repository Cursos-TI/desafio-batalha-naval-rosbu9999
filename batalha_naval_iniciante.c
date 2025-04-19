#include <stdio.h>

int main (){
    
char * mapa[10][10]={

{"a", "b", "c", "d", "e", "f","g", "h", "i", "j"},
{"1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"2","0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"3", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"5", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"6", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"7", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"8", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"9", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
{"10", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
}; 


int barco1_linhas[3] = {4,4,4};
int barco1_colunas[3] = {4,5,6};

int barco2_linhas[3]= {4,5,6};
int barco2_colunas[3]={8,8,8};

for (int i = 0; i < 3; i++)
{
    int linhas = barco1_linhas[i];
    int colunas = barco1_colunas[i];
    
    mapa[linhas][colunas] = "3";
} 

for (int j = 0; j < 3; j++)
    {
    int linhas = barco2_linhas[j];
    int colunas = barco2_colunas[j];
    mapa[linhas][colunas] = "3";
    }


for (int i = 0; i < 10; i++)
{
   for (int j = 0; j < 10; j++)
   {
    printf("%s\t", mapa[i][j]);
   }
   printf("\n");
}



}
