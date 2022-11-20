#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int pid;

void signal_catcher(int the_sig)
{
signal(the_sig, signal_catcher); //reset immediately
cout << endl << "Signal " << the_sig << " received." <<endl;
if(the_sig == 2){

pid_t ppid;

    ppid = getppid();
FILE *fp = fopen("./nane.txt", "a");


    fprintf(fp, "Cocuk: selam \n");

    fclose(fp);
    kill(ppid, 3);
}
if(the_sig == 3){
FILE *fp = fopen("./nane.txt", "a");


fprintf(fp, "Baba: Merhaba evlat \n");


    fclose(fp);
    kill(pid,2);
}

}


int
main(){

  pid = fork ( );
cout << "signal deneme deneme pid: " << pid << endl;
while(1)
{
cout << "signal has received" << endl;

 if(pid == 0){
signal(SIGINT, signal_catcher);
}
else
{
signal(SIGQUIT, signal_catcher);
}

pause( );

}

  return 2;
}
