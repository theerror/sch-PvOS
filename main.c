#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
//#include <iostream.h>
//#include <random>

//
//int main(int argc, char **argv)
//{
//	printf("hello world\n");
//	return 0;
//}

//1. Viz priklad 1 z predchoziho tutorialu. 
//   Potomci budou koncit s nahodnym cislem status exit( ?? );
//   Rodic bude sledovat navratovy kod. 
//   Potomci budou nahodile havarovat, napr. spatny pointer, deleni 0...
//   Rodic tyto havarie pozna. */

int main(void){	
    
pid_t pids[10];
int i, pds;
int n = 10;
    
for (i = 0; i < n; ++i) {
    if ((pids[i] = fork()) < 0) {
        perror("fork");
        abort();
    } else if (pids[i] == 0) {
        srand(time(NULL) ^ (getpid()<<16));
        int ex_out = (rand() % 10) + 1;
		printf("Syn s PID=%d a vratim %d \n", getpid(), ex_out);
        if ((ex_out == 1) || (ex_out == 5)){
            printf("Dnes neni dobry den, delime nulou\n");
            double b = 23/0;
        } else {
            printf("Syn s PID=%d a vratim %d \n", getpid(), ex_out);
            exit(ex_out);
        }
        exit(ex_out);
    } else {
        printf("Rodic s pid %d \n", getpid());
		
    }
}
    int status;
    while ((pds = wait(&status)) > 0)
    {
        if(WIFEXITED(status) != 0){
            printf("Synator vratil %d \n", WEXITSTATUS(status));
        }
        else {
            printf("Synator se prepocital (%d) \n", WEXITSTATUS(status));
        }
    }
    
    return 0;
}
    
    //int f = fork();
    
    
    
//  if(f == 0){
//        int ex_out = rand() % 10 + 1;
//		printf("Syn s PID=%d a vratim %d \n", getpid(), ex_out);
//       exit(ex_out);
//	}
//	else {
//		
//    
//    return 0;
//}
	
