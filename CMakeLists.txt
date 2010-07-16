project( Doxygen )

cmake_minimum_required( VERSION 2.6 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${DOXYGEN_SOURCE_DIR}/CMake/"
  )

find_package( Dot )

