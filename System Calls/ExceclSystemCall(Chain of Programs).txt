1) program1.c

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Program 1 is starting...\n");
    printf("Program 1 is executing...\n");
    printf("This is program 1!\n");

    execl("./program2", "program2", NULL);
    perror("execl");
    return 0;
}

---------------------------------------------------------------------------------------

2) program2.c

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Program 2 is starting...\n");
    printf("Program 2 is executing...\n");
    printf("This is program 2!\n");

    execl("./program3", "program3", NULL);
    perror("execl");
    return 0;
}

-------------------------------------------------------------------------------------------

3) program3.c

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Program 3 is starting...\n");
    printf("Program 3 is executing...\n");
    printf("This is program 3!\n");

    execl("./program4", "program4", NULL);
    perror("execl");
    return 0;
}

----------------------------------------------------------------------------------------------------------------------
4) program4.c

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Program 4 is starting...\n");
    printf("Program 4 is executing...\n");
    printf("This is program 4!\n");

    execl("./program5", "program5", NULL);
    perror("execl");
    return 0;
}

---------------------------------------------------------------------------------------------------------------------
5) program5.c

#include <stdio.h>

int main() {
    printf("Program 5 is starting...\n");
    printf("Program 5 is executing...\n");
    printf("This is program 5!\n");
    return 0;
}

-----------------------------------------------------------------------------------------------------------------------

Compile each program separately:

gcc program1.c -o program1
gcc program2.c -o program2
gcc program3.c -o program3
gcc program4.c -o program4
gcc program5.c -o program5

-------------------------------------------------------------------------------------------------------------------------

Run program1:

./program1



Sample OutPut:

Program 1 is starting...
Program 1 is executing...
This is program 1!
Program 2 is starting...
Program 2 is executing...
This is program 2!
Program 3 is starting...
Program 3 is executing...
This is program 3!
Program 4 is starting...
Program 4 is executing...
This is program 4!
Program 5 is starting...
Program 5 is executing...
This is program 5!



