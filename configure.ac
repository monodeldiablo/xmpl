AC_INIT([xmpl: A Vala-friendly interface to Exempi], [0.1.0], [brian.william.davis@gmail.com], [xmpl], [http://github.com/monodeldiablo/xmpl])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([dist-bzip2])
AM_MAINTAINER_MODE

AC_PROG_CC
AM_PROG_CC_C_O
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

AC_PATH_PROG(VALAC, valac, valac)
AC_SUBST(VALAC)

AH_TEMPLATE([GETTEXT_PACKAGE], [xmpl: A Vala-friendly interface to Exempi])
GETTEXT_PACKAGE=snap
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE")
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.35.0])

# Set up prefix-relative directories
if test "x${prefix}" = "xNONE"; then
  PREFIX="${ac_default_prefix}"
else
  PREFIX="${prefix}"
fi
AC_DEFINE_UNQUOTED(PACKAGE_DATADIR, "${PREFIX}/${DATADIRNAME}/${PACKAGE}",[Package data directory])
AC_DEFINE_UNQUOTED(PACKAGE_BINDIR, "${PREFIX}/bin",[Package executable directory])

AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)

EXEMPI_REQUIRED=2.1.1

PKG_CHECK_MODULES(XMPL, exempi-2.0 >= $EXEMPI_REQUIRED)
AC_SUBST(XMPL_CFLAGS)
AC_SUBST(XMPL_LIBS)

AC_CONFIG_FILES([Makefile
	include/Makefile
	src/Makefile
	data/Makefile
	po/Makefile.in])

AC_OUTPUT
