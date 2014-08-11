AC_PREREQ([2.69])
AC_INIT([GSL-INT], [0.1], [dbarajassolano@gmail.com])
AC_CONFIG_SRCDIR([src/gsl_rvgen.c])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_HEADERS([config.h])

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB

AC_CHECK_LIB([gslcblas], [cblas_dgemm], [], [echo "GSL CBLAS interface is required" && exit -1])
AC_CHECK_LIB([gsl], [gsl_blas_dgemm], [], [echo "GSL is required" && exit -1])

AC_CONFIG_FILES([
	Makefile
	lib/Makefile
	])
AC_OUTPUT
