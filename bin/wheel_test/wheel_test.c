#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <bsd_auth.h>

int main(int ac, char **av)
{
    if(ac < 2) {
        fprintf(stderr, "Usage: %s username\n", av[0]);
        return 10;
    }

    char *wheel = "no";
    struct passwd *pwd = getpwnam(av[1]);
    if(pwd->pw_gid == 0) {
        wheel = "yes";
    } else {
        struct group *gr = getgrgid(0);
        for(char **mem = gr->gr_mem; *mem; mem++) {
            if(! strcmp(*mem, av[1])) {
                wheel = "yes";
                break;
            }
        }
    }

    auth_session_t *as = auth_open();
    auth_setoption(as, "wheel", wheel);
    auth_verify(as, "passwd", av[1], (char*)NULL);
    int ok = auth_close(as);

    if(ok) puts("Success!");
    else puts("Wrong password!");

    return ! ok;
}
