#set( LIBDOXYGEN_HEADERS
#  bufstr.h
#  classdef.h
#  classlist.h
#  cmdmapper.h
#  code.h
#	commentcnv.h
#	commentscan.h
#  compound_xsd.h
#  config.h
#	constexp.h
#	cppvalue.h
#	debug.h
#  declinfo.h
#  defargs.h
#  defgen.h
#  define.h
#  definition.h
#  diagram.h
#  dirdef.h
#  docparser.h
#	docsets.h
#  doctokenizer.h
#  docvisitor.h
#	dot.h
#	doxygen.h
#	doxygen_css.h
#	eclipsehelp.h
#	entry.h
#	example.h
#	filedef.h
#	filename.h
#	formula.h
#	ftextstream.h
#	ftvhelp.h
#	groupdef.h
#	htags.h
#	htmlattrib.h
#  htmldocvisitor.h
#	htmlgen.h
#	htmlhelp.h
#	indexlog.h
#	image.h
#	index.h
#  index_xsd.h
#	instdox.h
#	language.h
#  latexdocvisitor.h
#	latexgen.h
#  layout.h
#  layout_default.h
#  lockingptr.h
#	logos.h
#	mandocvisitor.h
#	mangen.h
#  marshal.h
#	memberdef.h
#	membergroup.h
#	memberlist.h
#	membername.h
#	message.h
#  msc.h
#	namespacedef.h
#  objcache.h
#	outputgen.h
#	outputlist.h
#	pagedef.h
#	perlmodgen.h
#	lodepng.h
#	pre.h
#  printdocvisitor.h
#  pycode.h
#  pyscanner.h
#  fortrancode.h
#  fortranscanner.h
#  dbusxmlscanner.h
#	qhp.h
#	qhpxmlwriter.h
#	qtbc.h
#	reflist.h
#  rtfdocvisitor.h
#	rtfgen.h
#	rtfstyle.h
#	scanner.h
#	searchindex.h
#	search_css.h
#	search_js.h
#	search_php.h
#	section.h
#	sortdict.h
#	store.h
#	tagreader.h
#	textdocvisitor.h
#	translator.h
#	translator_adapter.h
#	translator_br.h
#	translator_ca.h
#	translator_cn.h
#	translator_cz.h
#	translator_de.h
#	translator_dk.h
#	translator_en.h
#	translator_es.h
#	translator_fi.h
#	translator_fr.h
#	translator_gr.h
#	translator_hr.h
#	translator_hu.h
#	translator_id.h
#	translator_it.h
#	translator_je.h
#	translator_jp.h
#	translator_ke.h
#	translator_kr.h
#	translator_nl.h
#	translator_no.h
#	translator_mk.h
#	translator_pl.h
#	translator_pt.h
#	translator_ro.h
#	translator_ru.h
#	translator_se.h
#	translator_si.h
#	translator_sk.h
#	translator_sr.h
#	translator_tw.h
#	translator_ua.h
#	translator_vi.h
#	translator_za.h
#	unistd.h
#	util.h
#	version.h
#	vhdlcode.h
#	vhdldocgen.h
#	vhdlscanner.h
#	xmldocvisitor.h
#	xmlgen.h
#  )

set( LIBDOXYGEN_SOURCES
#  ce_lex.cpp
#	ce_parse.cpp
	classdef.cpp
	classlist.cpp
	cmdmapper.cpp
#	code.cpp
#	commentcnv.cpp
#	commentscan.cpp
	cppvalue.cpp
	debug.cpp
	defgen.cpp
#	declinfo.cpp
#	defargs.cpp
	define.cpp
	definition.cpp
	diagram.cpp
	dirdef.cpp
	docparser.cpp
	docsets.cpp
#	doctokenizer.cpp
	dot.cpp
	doxygen.cpp
	eclipsehelp.cpp
	entry.cpp
	filedef.cpp
	filename.cpp
	formula.cpp
	ftextstream.cpp
	ftvhelp.cpp
#	fortrancode.cpp
#	fortranscanner.cpp    
	groupdef.cpp
	htags.cpp
	htmldocvisitor.cpp
	htmlgen.cpp
	htmlhelp.cpp
	indexlog.cpp
	image.cpp
	index.cpp
	instdox.cpp
	language.cpp
	latexdocvisitor.cpp
	latexgen.cpp
	layout.cpp
	lodepng.cpp
	logos.cpp
	mandocvisitor.cpp
	mangen.cpp
	marshal.cpp
	memberdef.cpp
	membergroup.cpp
	memberlist.cpp
	membername.cpp
	message.cpp
	msc.cpp
	namespacedef.cpp
	objcache.cpp
	outputgen.cpp
	outputlist.cpp
	pagedef.cpp
	perlmodgen.cpp
#	pre.cpp
#	pycode.cpp
#	pyscanner.cpp    
	qhp.cpp
	qhpxmlwriter.cpp
	reflist.cpp
	rtfdocvisitor.cpp
	rtfgen.cpp
	rtfstyle.cpp
#	scanner.cpp
	searchindex.cpp
	store.cpp
	tagreader.cpp
	textdocvisitor.cpp
	translator.cpp
	util.cpp
#	version.cpp
#	vhdlcode.cpp
	vhdldocgen.cpp
#	vhdlscanner.cpp
	xmldocvisitor.cpp
	xmlgen.cpp
	dbusxmlscanner.cpp
  )

qt4_wrap_cpp( LIBDOXYGEN_MOC ${LIBDOXYGEN_HEADERS} )

add_library( Doxygen ${LIBDOXYGEN_SOURCES} )

set( DOXYCFG_SOURCES 
  # config.cpp 
  configoptions.cpp 
  portable.cpp 
  portable_c.c ) 

add_library( Doxycfg ${DOXYCFG_SOURCES} )

add_executable( doxygen main.cpp )
target_link_libraries( doxygen 
  Doxygen
  Doxycfg
  QTools
  md5
  )


