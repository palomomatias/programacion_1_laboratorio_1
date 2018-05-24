#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    char b;
} eDato;
int main()
{
/* primer ejemplo

    FILE* miArchivo;
    int numero=64;
    miArchivo =fopen("prueba1.txt","w");
   // funcion que sirve para escribir en archivos binarios, recibe direccion de memoria
   //si no uso el sizeof en otra arquitectura de 32 va a pasar como 2 enteros ¿cuanto pesa tam de enter?.el sizeof del int
   // 1 por que es 1 entero si son dos enteros pongo 2
    fwrite(&numero,sizeof(int),1,miArchivo);
    fclose(miArchivo);

    miArchivo=fopen("prueba1.txt","r");
    fread(&numero,sizeof(int),1,miArchivo);// recibe lo mismo que el fwrite cambia el sentido del flujo de dato
    fclose(miArchivo);
    printf("NUMERO: %d",numero);
    FILE* miArchivo;
    int numero;
    int i;
    int lista[5]={1,5,9,6,4};

   /* miArchivo =fopen("prueba2.txt","w");
    for(i=0;i<5;i++)
    {
        printf("ingrese un numero:");
        scanf("%d",&numero);

        fwrite(&numero,sizeof(int),1,miArchivo);
    }
    fclose(miArchivo);



  // FILE* miArchivo;
    miArchivo=fopen("prueba2.txt","r");
   //int i=0;
   //lista[5]={1,5,9,6,4};
   //int numero;
    while(!feof(miArchivo))
    {
        fread(&lista[i],sizeof(int),1,miArchivo);
        if(feof(miArchivo))
        {
            break;
        }
        i++;
    }
    fclose(miArchivo);
for(i=0;i<5;i++)
{
    printf("%d",lista[i]);
}
*/


FILE* miArchivo;
eDato d;// ={1,'b'};
miArchivo=fopen("miBinario.bin","rb");
if (miArchivo!=NULL)
{
    fread(&d,sizeof(eDato),1,miArchivo);
    fclose(miArchivo);
   printf("%d--%c",d.a,d.b);
}






return 0;
}

