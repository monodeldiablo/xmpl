NULL = 

AM_VALAFLAGS = \
	--vapidir $(top_srcdir)/vapi \
	--pkg config \
	--pkg xmpl \
	$(NULL)

lib_LTLIBRARIES = \
	libxmpl.la \
	$(NULL)

libxmpl_la_SOURCES = \
	xmpl.h \
	xmpl.c \
	$(NULL)

libxmpl_la_CFLAGS = \
	-I../include \
	`pkg-config --cflags --libs exempi-2.0` \
	$(NULL)

libxmpl_la_LDFLAGS = \
	-shared \
	-Wl,-rpath \
	-Wl,LIBDIR \
	$(NULL)

bin_PROGRAMS = \
	xmpl-test \
	$(NULL)

xmpl_test_SOURCES = \
	xmpl-test.vala \
	$(NULL)

xmpl_test_CFLAGS = \
	-I../include \
	`pkg-config --cflags --libs gobject-2.0` \
	`pkg-config --cflags --libs exempi-2.0` \
	-lxmpl \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

