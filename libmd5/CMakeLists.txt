set( MD5_HEADERS md5.h md5_loc.h )
set( MD5_SRC md5.c )

qt4_wrap_cpp( MD5_MOC ${MD5_HEADERS} )

add_library( md5 ${MD5_SRC} ${MD5_MOC} )

