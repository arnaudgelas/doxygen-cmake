find_package( Qt3 )

set( QTOOLS_HEADER
      qarray.h 
      qbuffer.h 
      qcache.h 
      qgcache.h 
      qcollection.h 
      qconfig.h 
      qcstring.h 
      scstring.h 
      qdatastream.h 
      qdatetime.h 
      qdict.h 
      qdir.h 
      qfeatures.h 
      qfile.h 
      qfiledefs_p.h 
      qfileinfo.h 
      qgarray.h 
      qgdict.h 
      qgeneric.h 
      qglist.h 
      qglobal.h 
      qgstring.h 
      qgvector.h 
      qintdict.h 
      qiodevice.h 
      qlist.h 
      qptrdict.h 
      qqueue.h 
      qregexp.h 
      qshared.h 
      qsortedlist.h 
      qstack.h 
      qstring.h 
      qstringlist.h 
      qstrlist.h 
      qstrvec.h 
      qtextstream.h 
      qtl.h 
      qvaluelist.h 
      qvector.h 
      qxml.h 
      qvaluestack.h 
      qmap.h 
      qmodules.h 
      qthread.h 
      qthread_p.h 
      qmutex.h 
      qmutex_p.h 
      qutfcodec.h 
      qwaitcondition.h
  )

set( QTOOLS_SRC
  qbuffer.cpp 
  qcollection.cpp 
  scstring.cpp 
  qdatastream.cpp 
  qdatetime.cpp 
  qdir.cpp 
  qfile.cpp 
  qfileinfo.cpp 
  qgarray.cpp 
  qgcache.cpp 
  qgdict.cpp 
  qglist.cpp 
  qglobal.cpp 
  qgstring.cpp 
  qgvector.cpp 
  qiodevice.cpp 
  qregexp.cpp 
  qstring.cpp 
  qtextstream.cpp 
  qtextcodec.cpp 
  qstringlist.cpp 
  qxml.cpp 
  qmap.cpp 
  qthread.cpp 
  qmutex.cpp 
  qutfcodec.cpp
)

if( UNIX )
  set( QTOOLS_SRC
    ${QTOOLS_SRC}
    qfile_unix.cpp 
    qdir_unix.cpp 
    qfileinfo_unix.cpp 
    qthread_unix.cpp 
    qmutex_unix.cpp 
    qwaitcondition_unix.cpp
    )
endif()

if( WIN32 )
  set( QTOOLS_SRC
    ${QTOOLS_SRC}
    qfile_win32.cpp
    qdir_win32.cpp
    qfileinfo_win32.cpp
    qthread_win32.cpp
    qmutex_win32.cpp
    qwaitcondition_win32.cpp  
  )

endif()

qt_wrap_cpp( QTOOLS_MOC ${QTOOLS_HEADER} )

add_library( QTools ${QTOOLS_MOC} ${QTOOLS_SRC} )
target_link_libraries( QTools ${QT_LIBRARIES} )

