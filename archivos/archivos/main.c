#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE* pArchivo;
  char cadena[50]="hola";
 pArchivo=fopen("archivo.txt","w");
   if(pArchivo!=NULL)
   {
       fprintf(pArchivo,"%s %d",cadena,156);//guarda cadena,no enteros
       fclose(pArchivo);
       printf("guardado");
   }
   else
   {
       printf("imposible guaerdar");
          }


      pArchivo=fopen("archivo.txt","r");
      if(pArchivo!=NULL)
      {
          while(!feof(pArchivo))
          {
              fgets(cadena,50,pArchivo);
              puts(cadena);
          }
          fclose(pArchivo);
      }





    return 0;
}
