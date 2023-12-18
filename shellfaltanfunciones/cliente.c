#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "doc_code/tcp.h"
#include "doc_code/leercadena.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH BUFSIZ

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "%sUso: %s <ip_servidor> <puerto>%s\n", ANSI_COLOR_RED, argv[0], ANSI_COLOR_RESET);
    return 1;
  }

  char *serverIP = argv[1];
  int serverPort = atoi(argv[2]);

  int clientSocket = TCP_Open(serverIP, serverPort);

  if (clientSocket == -1)
  {
    fprintf(stderr, "%sError al intentar conectar. Reintentando en 1 segundo...%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    return 1;
  }

  while (1)
  {
    char comando[MAX_COMMAND_LENGTH];
    bzero(comando, MAX_COMMAND_LENGTH);

    printf("%sDigite su comando (escriba '%ssalida%s' para salir): %s", ANSI_COLOR_BLUE, ANSI_COLOR_RED, ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    leer_de_teclado(MAX_COMMAND_LENGTH, comando);

    TCP_Write_String(clientSocket, comando);

    if (strcmp(comando, "salida") == 0)
    {
      break;
    }

    char response[MAX_RESPONSE_LENGTH];
    bzero(response, MAX_RESPONSE_LENGTH);

    // Leer hasta encontrar la marca de fin de respuesta
    while (1)
    {
      TCP_Read_String(clientSocket, response, MAX_RESPONSE_LENGTH);
      if (strcmp(response, "$") == 0)
      {
        break;
      }
      printf("%s -> \n%s%s\n", ANSI_COLOR_GREEN, response, ANSI_COLOR_RESET);
      bzero(response, MAX_RESPONSE_LENGTH);
    }
    bzero(comando, MAX_COMMAND_LENGTH);
  }

  TCP_Close(clientSocket);
  return 0;
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../doc_code/tcp.h"
#include "../doc_code/leercadena.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH BUFSIZ

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "%sUso: %s <ip_servidor> <puerto>%s\n", ANSI_COLOR_RED, argv[0], ANSI_COLOR_RESET);
    return 1;
  }

  char *serverIP = argv[1];
  int serverPort = atoi(argv[2]);

  int clientSocket = TCP_Open(serverIP, serverPort);

  if (clientSocket == -1) {
    fprintf(stderr, "%sError al intentar conectar. Reintentando en 1 segundo...%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    return 1;
  }

  while (1) {
    char comando[MAX_COMMAND_LENGTH];
    bzero(comando, MAX_COMMAND_LENGTH);

    printf("%sDigite su comando (escriba '%ssalida%s' para salir): %s", ANSI_COLOR_BLUE, ANSI_COLOR_RED, ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    leer_de_teclado(MAX_COMMAND_LENGTH, comando);

    TCP_Write_String(clientSocket, comando);

    if (strcmp(comando, "salida") == 0) {
      break;
    }

    char response[MAX_RESPONSE_LENGTH];
    bzero(response, MAX_RESPONSE_LENGTH);
    TCP_Read_String(clientSocket, response, MAX_RESPONSE_LENGTH);

    printf("%s -> \n%s%s\n", ANSI_COLOR_GREEN, response, ANSI_COLOR_RESET);
    bzero(response, MAX_RESPONSE_LENGTH);
  }

  TCP_Close(clientSocket);
  return 0;
} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../doc_code/tcp.h"
#include "../doc_code/leercadena.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH BUFSIZ

// Definir códigos de color ANSI
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "%sUso: %s <ip_servidor> <puerto>%s\n", ANSI_COLOR_RED, argv[0], ANSI_COLOR_RESET);
    return 1;
  }

  char *serverIP = argv[1];
  int serverPort = atoi(argv[2]);

  int clientSocket = TCP_Open(serverIP, serverPort);

  if (clientSocket == -1)
  {
    fprintf(stderr, "%sError al intentar conectar. Reintentando en 1 segundo...%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    return 1;
  }

  while (1)
  {
    char comando[MAX_COMMAND_LENGTH];
    bzero(comando, MAX_COMMAND_LENGTH);

    fprintf(stdout, "%sDigite su comando (escriba '%ssalida%s' para salir): %s", ANSI_COLOR_BLUE, ANSI_COLOR_RED, ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    leer_de_teclado(MAX_COMMAND_LENGTH, comando);

    TCP_Write_String(clientSocket, comando);

    if (strcmp(comando, "salida") == 0)
    {
      break;
    }

    char response[MAX_RESPONSE_LENGTH];
    bzero(response, MAX_RESPONSE_LENGTH);
    TCP_Read_String(clientSocket, response, MAX_RESPONSE_LENGTH);

    printf("%s -> \n%s%s\n", ANSI_COLOR_GREEN, response, ANSI_COLOR_RESET);
    bzero(response, MAX_RESPONSE_LENGTH);
  }

  TCP_Close(clientSocket);
  return 0;
} */

/*Cliente*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../doc_code/tcp.h"
#include "../doc_code/leercadena.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH BUFSIZ

// Definir códigos de color ANSI
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "%sUso: %s <ip_servidor> <puerto>%s\n", ANSI_COLOR_RED, argv[0], ANSI_COLOR_RESET);
    return 1;
  }

  char *serverIP = argv[1];
  int serverPort = atoi(argv[2]);

  int clientSocket = TCP_Open(serverIP, serverPort);

  if (clientSocket == -1)
  {
    fprintf(stderr, "%sError al intentar conectar. Reintentando en 1 segundo...%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    return 1;
  }

  while (1)
  {
    char comando[MAX_COMMAND_LENGTH];

    fprintf(stdout, "%sDigite su comando (escriba '%ssalida%s' para salir): %s", ANSI_COLOR_BLUE, ANSI_COLOR_RED, ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    leer_de_teclado(MAX_COMMAND_LENGTH, comando);

    TCP_Write_String(clientSocket, comando);

    if (strcmp(comando, "salida") == 0)
    {
      break;
    }

    char response[MAX_RESPONSE_LENGTH];
    TCP_Read_String(clientSocket, response, MAX_RESPONSE_LENGTH);

    printf("%s -> \n%s%s\n", ANSI_COLOR_GREEN, response, ANSI_COLOR_RESET);
    bzero(response, MAX_RESPONSE_LENGTH);
  }

  TCP_Close(clientSocket);
  return 0;
}
 */