///Write a program with name exec1.c

#include <stdio.h>

int main() {
    printf("Hello, Memory image replacement successful\n");

    int a, b;
    printf("Enter the values of A and B\n");
    scanf("%d %d", &a, &b);

    int sum = a + b;
    printf("The Sum of A and B is %d\n", sum);

    return 0;
}
//Save the program


//create another program with name exec2.c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec: This will be replaced\n");
    execl("./exec1", "./exec1", NULL);
    printf("This line won't be executed\n");
    return 0;
}

/*execution steps:
$ gcc -o exec1 exec1.c
$ gcc -o exec2 exec2.c
$ ./exec1
$ ./exec2*/
