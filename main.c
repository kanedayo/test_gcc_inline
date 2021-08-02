//  gcc -g -O2 -c *.c [-fno-inline]
//  gcc *.o
//  objdump.exe -S -d a.exe
#include <stdio.h>
#include "mylib.h"

int main(void)
{
  int a=0x11,b=0x22;
  //int x,y;
  volatile int x,y;
  x = myadd (0x11, 0x22); // (1)
  y = myadd (   a,    b); // (2)
  x = myadd2(0x11, 0x22); // (3)
  y = myadd2(   a,    b); // (4)
  return 0;
}
/*
00000001004016a0 <main>:
int main(void)
{
   1004016a0:	48 83 ec 38          	sub    $0x38,%rsp
   1004016a4:	e8 07 fa ff ff       	call   1004010b0 <__main>
  int a=0x11,b=0x22;
  //int x,y;
  volatile int x,y;
  x = myadd (0x11, 0x22); // (1)
   1004016a9:	ba 22 00 00 00       	mov    $0x22,%edx
   1004016ae:	b9 11 00 00 00       	mov    $0x11,%ecx
   1004016b3:	e8 d8 f9 ff ff       	call   100401090 <myadd> // (1) 関数呼び出し
  y = myadd (   a,    b); // (2)
   1004016b8:	ba 22 00 00 00       	mov    $0x22,%edx
   1004016bd:	b9 11 00 00 00       	mov    $0x11,%ecx
  x = myadd (0x11, 0x22); // (1)
   1004016c2:	89 44 24 28          	mov    %eax,0x28(%rsp)   // (1) xに代入
  y = myadd (   a,    b); // (2)
   1004016c6:	e8 c5 f9 ff ff       	call   100401090 <myadd> // (2) 関数呼び出し
   1004016cb:	89 44 24 2c          	mov    %eax,0x2c(%rsp)   // (2) yに代入
  x = myadd2(0x11, 0x22); // (3)
  y = myadd2(   a,    b); // (4)
  return 0;
}
   1004016cf:	31 c0                	xor    %eax,%eax
  x = myadd2(0x11, 0x22); // (3)
   1004016d1:	c7 44 24 28 33 00 00 	movl   $0x33,0x28(%rsp)  // (3) xに代入
   1004016d8:	00 
  y = myadd2(   a,    b); // (4)
   1004016d9:	c7 44 24 2c 33 00 00 	movl   $0x33,0x2c(%rsp)  // (4) yに代入
   1004016e0:	00 
}
   1004016e1:	48 83 c4 38          	add    $0x38,%rsp
   1004016e5:	c3                   	ret    
*/
