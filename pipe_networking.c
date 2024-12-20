#include "pipe_networking.h"
#define READ 0
#define WRITE 1
//UPSTREAM = to the server / from the client
//DOWNSTREAM = to the client / from the server
/*=========================
  server_setup

  returns the file descriptor for the upstream pipe.
  creates the WKP and opens it, waiting for a  connection.
  removes the WKP once a connection has been made

  =========================*/
int server_setup() {
  int from_client = 0;
  //fdread should be 0
  int fdread;
  fdread= mkfifo("WKP",0666);
//  read(fdread,,256)
  open("WKP",0666);

  if(WKP[READ]!=NULL){
    close(fdread);
  }
  from_client = WKP[0];



  return from_client;
}

/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe (Client's private pipe).

  returns the file descriptor for the upstream pipe (see server setup).
  =========================*/
int server_handshake(int *to_client) {
  int from_client;
  int pipeArray[2];
  pipe(pipeArray);
  *to_client = pipeArray[0];//you are afraid of life, Little Man, deadly afraid. You will mur

  from_client = WKP[1];

  return from_client;

}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int from_server;
  //Private pipe
  int pipeArray[2];
  pipe(pipeArray);
  open("WKP",0666);

  //Replace x with pid
  write(WKP[READ],"x",256);

  *to_server = WKP[1];

  from_server = WKP[WRITE];


  return from_server;
}


/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {
  int to_client  = 0;
  return to_client;
}
