#include "tcp.h"  

void ejecutar_comando(int sockfd, char *comando) {

  char buffer[256];
  
  FILE *output = popen(comando, "r");

  while(fgets(buffer, 256, output) != NULL) {

    TCP_Write_String(sockfd, buffer);

  }

  pclose(output);

}

void recibir_archivo(int sockfd, char *filename) {

  TCP_Recv_File(sockfd, filename);

}  

void atender_cliente(int sockfd) {

  char comando[100];

  while(1) {

    TCP_Read_String(sockfd, comando, 100);
    
    if(es_comando_archivo(comando)) {

      recibir_archivo(sockfd, obtener_nombre_archivo(comando));

    } else {

      ejecutar_comando(sockfd, comando);
    
    }

  }

}

int main(int argc, char **argv) {

  int sockfd = TCP_Server_Open(atoi(argv[1])); 
  
  while(1) {

    int connfd = TCP_Accept(sockfd);
        
    atender_cliente(connfd);

  }

  return 0;
}