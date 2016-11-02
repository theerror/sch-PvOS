---

1. Viz priklad 1 z predchoziho tutorialu. 
   Potomci budou koncit s nahodnym cislem status exit( ?? );
   Rodic bude sledovat navratovy kod. 
   Potomci budou nahodile havarovat, napr. spatny pointer, deleni 0...
   Rodic tyto havarie pozna. 
  
1. SIGIO pro dva zdroje. 
   Nastavit sigaction.sa_flags spravne, aby zpracovani signalu 
   bylo mozne i se strukturou siginfo_t. 
   Dle struktury rozlisit zdroj dat.
   
1. AIO - opet dva potomci posilaji data rodici dvema rourami.
   Zpracovani pomoci vlaken. 
   Pro sigevent.sigev_notify nastavit SIGEV_THREAD.

---
