project( DOXYGEN )

cmake_minimum_required( VERSION 2.6 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${DOXYGEN_SOURCE_DIR}/CMake/"
  )

# find Qt package
#find_package( Qt4 )

# find dot (part of GraphViz)
find_package( Dot )

# find perl
find_package( Perl )

# find flex
find_package( FLEX )

# find bison
find_package( BISON )

# find pThreads
find_package( Threads )

find_package( Iconv )

# -------------------------------------------------------------------------
# Creating VERSION file.
set( DOXYGEN_MAJOR_VERSION "1" )
set( DOXYGEN_MINOR_VERSION "7" )
set( DOXYGEN_PATCH_VERSION "1" )
set( DOXYGEN_VERSION 
  "${DOXYGEN_MAJOR_VERSION}.${DOXYGEN_MINOR_VERSION}.${DOXYGEN_PATCH_VERSION}" )

configure_file( ${DOXYGEN_SOURCE_DIR}/VERSION.in
  ${DOXYGEN_BINARY_DIR}/VERSION @ONLY IMMEDIATE
)

include_directories( BEFORE
  ${DOXYGEN_SOURCE_DIR}/qtools
  ${DOXYGEN_BINARY_DIR}/qtools
  ${DOXYGEN_SOURCE_DIR}/libmd5
  ${DOXYGEN_BINARY_DIR}/libmd5
  ${DOXYGEN_SOURCE_DIR}/src
  ${DOXYGEN_BINARY_DIR}/src
  ${ICONV_INCLUDE_DIR}
)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${DOXYGEN_BINARY_DIR}/bin
)

# all target static libraries will be in ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${DOXYGEN_BINARY_DIR}/lib
)

# all shared libraries will be in ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
# Note that modules (plugins) are considered as shared libraries
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY
   ${DOXYGEN_BINARY_DIR}/lib
)

LINK_DIRECTORIES(
      ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
      ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
      ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
      )

option( BUILD_DOXYWIZARD "Build the doxywizard" ON )
option( BUILD_DOXYAPP "Build the doxyapp" ON )

add_subdirectory( qtools )
add_subdirectory( libmd5 )
add_subdirectory( src )

