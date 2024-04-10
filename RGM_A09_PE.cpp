//RUIZ GONZALEZ MARCOS
// 03/04/24
// MENU QUE TRABAJE CON VECTORES Y MATRICES
//RGM_A09_PE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Ragruz.h"
#define N 15
#define C 4
void Menu(void);
int Msge(void);
int Busqueda(int vect[],int dato,int m);
void Llena_vect(int vect[],int m,int ri,int rf);
void Llena_mat(int mat[][C],int m,int n,int ri, int rf);
void Imp_vect(int vect[],int m);
void Imp_mat(int mat[][C],int m);
void Ordena_vect(int vect[],int m);
void Busq_val(int vect[],int m);
int main()
{
    Menu();
}
void Menu(void)
{
    int opc;
    int vect[N];
    int mat[4][C];
    opc = 1;
    while (opc!=0)
    {
        opc = Msge();
        switch (opc)
        {
        case 1:
            Llena_vect(vect,N,100,200);
            break;
        case 2:
            Llena_mat(mat,4,C,1,16);
            break;
        case 3:
            Imp_vect(vect,N);
            break;
        case 5:
            Ordena_vect(vect,N);
            break;
        case 6:
            Busq_val(vect,N);
        case 0:
            break;
        default:
            printf("INTRODUJO UN VALOR INVALIDO\n");
            break;
        }
    }
}
int Msge(void)
{
    int op;
    printf("1.- LLENAR VECTOR\n");
    printf("2.- LLENAR MATRIZ\n");
    printf("3.- IMPRIMIR VECTOR\n");
    printf("4.- IMPRIMIR MATRIZ\n");
    printf("5.- ORDENAR VECTOR\n");
    printf("6.- BUSCAR VALOR EN VECTOR\n");
    printf("0.- SALIR\n");
    printf("ELIJA LA OPCION QUE DESEE\n");
    scanf("%d",&op);
    return op;
}
void Llena_vect(int vect[],int m,int ri,int rf)
{
    int i, rango, num;
    i=0;
    rango=((rf-ri)+1);
    srand(time(NULL));
    while(i<m)
    {
        num=(rand()%rango)+ri;
        if(Busqueda(vect,num,m) ==0)
        {
            vect[i]=num;
        }
        else
        {
            continue;
        }
        i++;
    }
}
void Llena_mat(int mat[][C],int m,int n,int ri, int rf)
{
    int i, j,num,rango;
    int vect_sin_rep[8];
    rango=((rf-ri)+1);
    for(i=0;i<m;i++)
    {
        for(j=0;i<n;j++)
        {
            num=(rand()%rango)+ri;
            while(mat_sin_rep(mat,4,num))
            {
                num=(rand()%rango)+ri;
            }
            mat[i][j]=num;
        }
    }
}
int Busqueda(int vect[],int dato,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(vect[i]==dato)
        {
            return 1;
            break;
        }
    }
    return 0;
}
void Imp_vect(int vect[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("%d --->[%d]\n",i,vect[i]);
    }
}
void Imp_mat(int mat[][C],int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
void Ordena_vect(int vect[],int m)
{
    int i,j;
    int temp;
    for(i=0;i<(m-1);i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(vect[j]<vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}
void Busq_val(int vect[],int m)
{
    int num,ind;
    printf("INTRODUCE EL NUMERO QUE DESEAS BUSCAR EN EL VECTOR\n");
    scanf("%d",&num);
    ind=Busq_sec(vect,m,num);
    if(ind!=-1)
    {
        printf("EL NUMERO SE ENCUENTRA EN EL INDICE: %d\n",ind);
    }
    else
    {
        printf("NO SE ENCONTRO EL NUMERO QUE BUSCABA\n");
    }
}
