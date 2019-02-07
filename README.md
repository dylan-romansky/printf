WHAT DIS?

-an implementation of printf as coded by me. There's a lot I could do to optimize it but I'm just happy it's done and graded.

HOW USE?

-write yourself a nice lil main.c

-in order to make use of fancy things you need to include the happy lil printf.h

-Makefile has options for 'compile' to (re)compile a lovely libftprintf.a then compile yourself a happy lil a.out, 'test' to (re)compile libftprintf.a, your a.out, and run your happy lil a.out, and 'run' to just compile and run your a.out.

-of course there's also the standard 42school options for compiling the library and cleaning your directory.

-there's also a couple nifty bonuses in that ft_dprintf lets you print to a file descriptor and if you put {'colour of choice'} into your string you get some limited colour functionality. To see the colours I've included take a look at the colours.h file. I will probably be adding more colours and updating my code accordingly as time goes on.\

PROBLEMS?

-it failed one of moulinette's float tests. I suspect it's for minimum possible float values. I'm not too worried about it though. If any o' y'all figure it out feel free to let me know and I can update my code at that point. Till then though it's remaining as is.
