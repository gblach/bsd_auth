#include <stdio.h>
#include <sys/types.h>
#include <bsd_auth.h>

int main(int ac, char **av)
{
    if(ac < 2) {
        fprintf(stderr, "Usage: %s username\n", av[0]);
        return 10;
    }

    int ok = auth_userokay(av[1], "passwd", NULL, NULL);
    if(ok) puts("Success!");
    else puts("Wrong password!");

    return ! ok;
}
