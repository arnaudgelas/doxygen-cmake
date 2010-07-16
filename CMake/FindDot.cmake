FIND_PROGRAM(DOT_EXECUTABLE
 NAMES dot
 PATHS 
 "$ENV{ProgramFiles}/Graphviz 2.21/bin"
 "C:/Program Files/Graphviz 2.21/bin"
 "$ENV{ProgramFiles}/ATT/Graphviz/bin"
 "C:/Program Files/ATT/Graphviz/bin"
 [HKEY_LOCAL_MACHINE\\SOFTWARE\\ATT\\Graphviz;InstallPath]/bin
 /Applications/Graphviz.app/Contents/MacOS
 /Applications/Doxygen.app/Contents/Resources
 /Applications/Doxygen.app/Contents/MacOS
 DOC "Graphviz Dot tool for using Doxygen"
 )

if(DOT_EXECUTABLE)
  set(DOT_FOUND TRUE)
  # The Doxyfile wants the path to Dot, not the entire path and executable
  get_filename_component(DOT_PATH "${DOT_EXECUTABLE}" PATH CACHE)
endif()

mark_as_advanced( DOT_EXECUTABLE
  DOT_PATH
  )

