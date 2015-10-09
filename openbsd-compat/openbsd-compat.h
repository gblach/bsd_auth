#ifndef _OPENBSD_COMPAT_H_
#define _OPENBSD_COMPAT_H_

#define BI_UNSETENV     "unsetenv"              /* unset environment variable */
#define BI_FDPASS       "fd"                    /* child is passing an fd */
#define LOGIN_NAME_MAX          32      /* max login name length w/ NUL */

#define _warn warn
#define _warnx warnx
#define crypt_checkpass(pass, goodhash) (strcmp(crypt(pass, goodhash), goodhash))
#define login_check_expire(back, pwd, class, lastchance) 0 //FIXME
#define secure_path(path) _secure_path(path, 0, 0)

void explicit_bzero(void *, size_t)__attribute__ ((__bounded__(__buffer__,1,2)));

#endif /* _OPENBSD_COMPAT_H_ */
