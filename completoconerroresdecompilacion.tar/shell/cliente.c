#include "tcp.h"
#include "leercadena.h"

void enviar_comando(int sockfd, char *comando) {

  TCP_Write_String(sockfd, comando);

}

void enviar_archivo(int sockfd, char *filename) {

  TCP_Send_File(sockfd, filename);

}

void recibir_respuesta(int sockfd) {

  char buffer[256];

  TCP_Read_String(sockfd, buffer, 256);

  printf("Respuesta del servidor: %s\n", buffer);

}

void recibir_archivo(int sockfd, char *filename) {

  TCP_Recv_File(sockfd, filename);

}

void cerrar_conexion(int sockfd) {

  char buffer[100]; 
  
  TCP_Write_String(sockfd, "salida");
  
  TCP_Read_String(sockfd, buffer, 100);

  TCP_Close(sockfd);
  
}

int main(int argc, char **argv) {

  int sockfd = TCP_Open(argv[1], atoi(argv[2]));

  char *comando;

  while(1) {

    comando = leer_entrada();

    if(strcmp(comando,"salida") == 0) {
      printf("Saliendo del programa cliente...\n");
      break;
    }
    
    if(es_comando_archivo(comando)) {
    
      enviar_archivo(sockfd, obtener_nombre_archivo(comando));
    
    } else {

      enviar_comando(sockfd, comando);  

      recibir_respuesta(sockfd);
    
    }

  }

  TCP_Close(sockfd);

  return 0;
}
