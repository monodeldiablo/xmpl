NULL = 

#Build in these directories:

SUBDIRS = \
	include \
	vapi \
	data \
	src \
	po \
	$(NULL)

xmpldocdir = ${docdir}
xmpldoc_DATA = \
	ChangeLog \
	README \
	COPYING \
	AUTHORS \
	INSTALL \
	NEWS\
	$(NULL)

EXTRA_DIST = \
	$(doc_DATA) \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in\
	$(NULL)

DISTCLEANFILES = \
	intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache \
	$(NULL)

