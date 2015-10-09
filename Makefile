SUBDIR= \
	include \
	openbsd-compat \
	lib/libbsd_auth \
	libexec/login_passwd

.for target in all install deinstall clean
${target}:
.for dir in ${SUBDIR}
	@echo "==> ${dir} (${target})" 
	@${MAKE} ${target} -C ${dir}
	@echo
.endfor
.endfor
