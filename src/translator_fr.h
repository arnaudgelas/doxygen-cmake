/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2004 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 * The translation into French was provided by
 *   Christophe Bordeux (bordeux@lig.di.epfl.ch)
 *   and after version 1.2.0 by Xavier Outhier (xouthier@yahoo.fr)
 *   member of the non for profit association D2SET (http://d2set.free.fr)
 */

/******************************************************************************
 * History of content
 *
 *   Date       | Description
 *  ============+=============================================================
 *  2001-11-22  | Removed obsolet methods:
 *              |  QCString latexBabelPackage()
 *              |  QCString trAuthor()
 *              |  QCString trAuthors()
 *              |  QCString trFiles()
 *              |  QCString trIncludeFile()
 *              |  QCString trVerbatimText(const char *f)
 * -------------+------------------------------------------------------------
 *  2002-01-23  | Update for new since 1.2.13
 * -------------+------------------------------------------------------------
 *  2002-07-11  | Update for new since 1.2.16
 * -------------+------------------------------------------------------------
 *  2002-09-24  | Update for new since 1.2.17
 * -------------+------------------------------------------------------------
 *  2002-10-22  | Update for new since 1.2.18
 * -------------+------------------------------------------------------------
 *  2003-02-04  | Corrected typo. Thanks to Bertrand M. :)
 * -------------+------------------------------------------------------------
 *  2003-03-29  | Update for new since 1.3
 * -------------+------------------------------------------------------------
 *  2003-03-29  | Changed fonction into m�thode. 
 * -------------+------------------------------------------------------------
 *  2003-06-06  | Fixed code page problem appeared between 1.42 and 1.43 in CVS
 * -------------+------------------------------------------------------------
 *  2003-06-10  | Update for new since 1.3.1
 * -------------+------------------------------------------------------------
 *  2003-09-12  | Update for new since 1.3.3
 * -------------+------------------------------------------------------------
 *  2004-04-30  | Updates by Jacques Bouchard <jacques.bouchard@noos.fr>:
 *              | - spaces between ':' removed (should be added by the renderer)
 *              | - missing spaces added
 *              | - missing tests for OPTIMIZE_OUTPUT_FOR_C added
 *              | - translations corrected
 *              | - translator_fr.h now conforms exactly to translator_en.h
 *              |   (try: gvim -d translator_en.h translator_fr.h)
 * -------------+------------------------------------------------------------
 */ 
#ifndef TRANSLATOR_FR_H
#define TRANSLATOR_FR_H

// When defining a translator class for the new language, follow
// the description in the documentation.  One of the steps says
// that you should copy the translator_en.h (this) file to your
// translator_xx.h new file.  Your new language should use the
// Translator class as the base class.  This means that you need to
// implement exactly the same (pure virtual) methods as the
// TranslatorEnglish does.  Because of this, it is a good idea to
// start with the copy of TranslatorEnglish and replace the strings
// one by one.
//
// It is not necessary to include "translator.h" or
// "translator_adapter.h" here.  The files are included in the
// language.cpp correctly.  Not including any of the mentioned
// files frees the maintainer from thinking about whether the
// first, the second, or both files should be included or not, and
// why.  This holds namely for localized translators because their
// base class is changed occasionaly to adapter classes when the
// Translator class changes the interface, or back to the
// Translator class (by the local maintainer) when the localized
// translator is made up-to-date again.

class TranslatorFrench : public Translator
{
  public:

    // --- Language control methods -------------------
    
    /*! Used for identification of the language. The identification 
     * should not be translated. It should be replaced by the name 
     * of the language in English using lower-case characters only
     * (e.g. "czech", "japanese", "russian", etc.). It should be equal to 
     * the identification used in language.cpp.
     */
    virtual QCString idLanguage()
    { return "french"; }

    /*! Used to get the LaTeX command(s) for the language support. 
     *  This method should return string with commands that switch
     *  LaTeX to the desired language.  For example 
     *  <pre>"\\usepackage[german]{babel}\n"
     *  </pre>
     *  or
     *  <pre>"\\usepackage{polski}\n"
     *  "\\usepackage[latin2]{inputenc}\n"
     *  "\\usepackage[T1]{fontenc}\n"
     *  </pre>
     */
    virtual QCString latexLanguageSupportCommand()
    {
      return "\\usepackage[french]{babel}\n";
    }

    /*! return the language charset. This will be used for the HTML output */
    virtual QCString idLanguageCharset()
    {
        return "iso-8859-1";
    }

    // --- Language translation methods -------------------

    /*! used in the compound documentation before a list of related functions. */
    virtual QCString trRelatedFunctions()
    { return "Fonctions associ�es"; }

    /*! subscript for the related functions. */
    virtual QCString trRelatedSubscript()
    { return "(Noter que ce ne sont pas des fonctions membres)"; }

    /*! header that is put before the detailed description of files, classes and namespaces. */
    virtual QCString trDetailedDescription()
    { return "Description d�taill�e"; }

    /*! header that is put before the list of typedefs. */
    virtual QCString trMemberTypedefDocumentation()
    { return "Documentation des typedef membres"; }
    
    /*! header that is put before the list of enumerations. */
    virtual QCString trMemberEnumerationDocumentation()
    { return "Documentation des �num�rations membres"; }
    
    /*! header that is put before the list of member functions. */
    virtual QCString trMemberFunctionDocumentation()
    { return "Documentation des fonctions membres"; }
    
    /*! header that is put before the list of member attributes. */
    virtual QCString trMemberDataDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Documentation des champs"; 
      }
      else
      {
        return "Documentation des donn�es membres";
      }
    }

    /*! this is the text of a link put after brief descriptions. */
    virtual QCString trMore()
    { return "Plus de d�tails..."; }

    /*! put in the class documentation */
    virtual QCString trListOfAllMembers()
    { return "Liste de tous les membres"; }

    /*! used as the title of the "list of all members" page of a class */
    virtual QCString trMemberList()
    { return "Liste des membres"; }

    /*! this is the first part of a sentence that is followed by a class name */
    virtual QCString trThisIsTheListOfAllMembers()
    { return "Liste compl�te des membres de "; }

    /*! this is the remainder of the sentence after the class name */
    virtual QCString trIncludingInheritedMembers()
    { return ", y compris les membres h�rit�s:"; }
    
    /*! this is put at the author sections at the bottom of man pages.
     *  parameter s is name of the project name.
     */
    virtual QCString trGeneratedAutomatically(const char *s)
    { QCString result="G�n�r� automatiquement par Doxygen"; 
      if (s) result+=(QCString)" pour "+s;
      result+=" � partir du code source."; 
      return result;
    }

    /*! put after an enum name in the list of all members */
    virtual QCString trEnumName()
    { return "�num�ration"; }
    
    /*! put after an enum value in the list of all members */
    virtual QCString trEnumValue()
    { return "valeur �num�r�e"; }
    
    /*! put after an undocumented member in the list of all members */
    virtual QCString trDefinedIn()
    { return "d�fini dans"; }

    // quick reference sections

    /*! This is put above each page as a link to the list of all groups of 
     *  compounds or files (see the \\group command).
     */
    virtual QCString trModules()
    { return "Modules"; }
    
    /*! This is put above each page as a link to the class hierarchy */
    virtual QCString trClassHierarchy()
    { return "Hi�rarchie des classes"; }
    
    /*! This is put above each page as a link to the list of annotated classes */
    virtual QCString trCompoundList()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Structures de donn�es";
      }
      else
      {
        return "Liste des classes"; 
      }
    }
    
    /*! This is put above each page as a link to the list of documented files */
    virtual QCString trFileList()
    { return "Liste des fichiers"; }

    /*! This is put above each page as a link to the list of all verbatim headers */
    virtual QCString trHeaderFiles()
    { return "Fichiers d'en-t�te"; }

    /*! This is put above each page as a link to all members of compounds. */
    virtual QCString trCompoundMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Champs de donn�e"; 
      }
      else
      {
        return "Membres de classe"; 
      }
    }

    /*! This is put above each page as a link to all members of files. */
    virtual QCString trFileMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Port�e globale"; 
      }
      else
      {
        return "Membres de fichier"; 
      }
    }

    /*! This is put above each page as a link to all related pages. */
    virtual QCString trRelatedPages()
    { return "Pages associ�es"; }

    /*! This is put above each page as a link to all examples. */
    virtual QCString trExamples()
    { return "Exemples"; }

    /*! This is put above each page as a link to the search engine. */
    virtual QCString trSearch()
    { return "Recherche"; }

    /*! This is an introduction to the class hierarchy. */
    virtual QCString trClassHierarchyDescription()
    { return "Cette liste d'h�ritage est class�e "
             "approximativement par ordre alphab�tique:";
    }

    /*! This is an introduction to the list with all files. */
    virtual QCString trFileListDescription(bool extractAll)
    {
      QCString result="Liste de tous les fichiers ";
      if (!extractAll) result+="document�s ";
      result+="avec une br�ve description:";
      return result;
    }

    /*! This is an introduction to the annotated compound list. */
    virtual QCString trCompoundListDescription()
    {

      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Liste des structures de donn�es avec une br�ve description:"; 
      }
      else
      {
        return "Liste des classes, structures, "
               "unions et interfaces avec une br�ve description:"; 
      }
    }

    /*! This is an introduction to the page with all class members. */
    virtual QCString trCompoundMembersDescription(bool extractAll)
    {
      QCString result="Liste de tous les ";
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="champs de structure et d'union ";
      }
      else
      {
        result+="membres de classe ";
      }
      if (!extractAll)
      {
        result+="document�s ";
      }
      result+="avec liens vers ";
      if (!extractAll) 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="la documentation de structure/union de chaque champ:";
        }
        else
        {
          result+="la documentation de classe de chaque membre:";
        }
      }
      else 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="les structures/unions auxquelles ils appartiennent:";
        }
        else
        {
          result+="les classes auxquelles ils appartiennent:";
        }
      }
      return result;
    }

    /*! This is an introduction to the page with all file members. */
    virtual QCString trFileMembersDescription(bool extractAll)
    {
      QCString result="Liste ";
      
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="des fonctions, variables, macros, enum�rations, et typedefs ";
      }
      else
      {
        result+="de tous les membres de fichier ";
      }
      if (!extractAll) result+="document�s ";
      result+="avec liens vers ";
      if (extractAll) 
        result+="les fichiers auxquels ils appartiennent:";
      else 
        result+="la documentation:";
      return result;
    }

    /*! This is an introduction to the page with the list of all header files. */
    virtual QCString trHeaderFilesDescription()
    { return "Liste des fichiers d'en-t�te constituant l'interface de programmation:"; }

    /*! This is an introduction to the page with the list of all examples */
    virtual QCString trExamplesDescription()
    { return "Liste de tous les exemples:"; }

    /*! This is an introduction to the page with the list of related pages */
    virtual QCString trRelatedPagesDescription()
    { return "Liste de toutes les pages de documentation associ�es:"; }

    /*! This is an introduction to the page with the list of class/file groups */
    virtual QCString trModulesDescription()
    { return "Liste de tous les modules:"; }

    /*! This sentences is used in the annotated class/file lists if no brief
     * description is given. 
     */
    virtual QCString trNoDescriptionAvailable()
    { return "Aucune description disponible"; }
    
    // index titles (the project name is prepended for these) 


    /*! This is used in HTML as the title of index.html. */
    virtual QCString trDocumentation()
    { return "Documentation"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * index of all groups.
     */
    virtual QCString trModuleIndex()
    { return "Index des modules"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * class hierarchy.
     */
    virtual QCString trHierarchicalIndex()
    { return "Index hi�rarchique"; }

    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index.
     */
    virtual QCString trCompoundIndex()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      { 
        return "Index des structures de donn�es";
      }
      else
      {
        return "Index des classes"; 
      }
    }

    /*! This is used in LaTeX as the title of the chapter with the
     * list of all files.
     */
    virtual QCString trFileIndex() 
    { return "Index des fichiers"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all groups.
     */
    virtual QCString trModuleDocumentation()
    { return "Documentation des modules"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all classes, structs and unions.
     */
    virtual QCString trClassDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Documentation des structures de donn�es"; 
      }
      else
      {
        return "Documentation des classes"; 
      }
    }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all files.
     */
    virtual QCString trFileDocumentation()
    { return "Documentation des fichiers"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all examples.
     */
    virtual QCString trExampleDocumentation()
    { return "Documentation des exemples"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all related pages.
     */
    virtual QCString trPageDocumentation()
    { return "Documentation des pages associ�es"; }

    /*! This is used in LaTeX as the title of the document */
    virtual QCString trReferenceManual()
    { return "Manuel de r�f�rence"; }
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of defines
     */
    virtual QCString trDefines()
    { return "Macros"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of function prototypes
     */
    virtual QCString trFuncProtos()
    { return "Prototypes de fonction"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of typedefs
     */
    virtual QCString trTypedefs()
    { return "Typedefs"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of enumerations
     */
    virtual QCString trEnumerations()
    { return "�num�rations"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) functions
     */
    virtual QCString trFunctions()
    { return "Fonctions"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trVariables()
    { return "Variables"; }

    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    virtual QCString trEnumerationValues()
    { return "Valeurs �num�r�es"; }
    
    /*! This is used in the documentation of a file before the list of
     *  documentation blocks for defines
     */
    virtual QCString trDefineDocumentation()
    { return "Documentation des macro"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for function prototypes
     */
    virtual QCString trFunctionPrototypeDocumentation()
    { return "Documentation des prototypes de fonction"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for typedefs
     */
    virtual QCString trTypedefDocumentation()
    { return "Documentation des typedef"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration types
     */
    virtual QCString trEnumerationTypeDocumentation()
    { return "Documentation du type de l'�num�ration"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration values
     */
    virtual QCString trEnumerationValueDocumentation()
    { return "Documentation de la valeur �num�r�e"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for functions
     */
    virtual QCString trFunctionDocumentation()
    { return "Documentation des fonctions"; }

    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for variables
     */
    virtual QCString trVariableDocumentation()
    { return "Documentation des variables"; }

    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds
     */
    virtual QCString trCompounds()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Structures de donn�es"; 
      }
      else
      {
        return "Classes"; 
      }
    }

    /*! This is used in the standard footer of each page and indicates when 
     *  the page was generated 
     */
    virtual QCString trGeneratedAt(const char *date,const char *projName)
    { 
      QCString result=(QCString)"G�n�r� le "+date;
      if (projName) result+=(QCString)" pour "+projName;
      result+=(QCString)" par";
      return result;
    }
    /*! This is part of the sentence used in the standard footer of each page.
     */
    virtual QCString trWrittenBy()
    {
      return "�crit par";
    }

    /*! this text is put before a class diagram */
    virtual QCString trClassDiagram(const char *clName)
    {
      return (QCString)"Graphe d'h�ritage de "+clName+":";
    }
    
    /*! this text is generated when the \\internal command is used. */
    virtual QCString trForInternalUseOnly()
    { return "� usage interne uniquement."; }

    /*! this text is generated when the \\reimp command is used. */
    virtual QCString trReimplementedForInternalReasons()
    { return "R�impl�ment� pour des raisons internes; "
             "l'interface de programmation n'est pas modifi�e."; 
    }

    /*! this text is generated when the \\warning command is used. */
    virtual QCString trWarning()
    { return "Avertissement"; }

    /*! this text is generated when the \\bug command is used. */
    virtual QCString trBugsAndLimitations()
    { return "Bogues et limitations"; }

    /*! this text is generated when the \\version command is used. */
    virtual QCString trVersion()
    { return "Version"; }

    /*! this text is generated when the \\date command is used. */
    virtual QCString trDate()
    { return "Date"; }

    /*! this text is generated when the \\return command is used. */
    virtual QCString trReturns()
    { return "Renvoie"; }

    /*! this text is generated when the \\sa command is used. */
    virtual QCString trSeeAlso()
    { return "Voir �galement"; }

    /*! this text is generated when the \\param command is used. */
    virtual QCString trParameters()
    { return "Param�tres"; }

    /*! this text is generated when the \\exception command is used. */
    virtual QCString trExceptions()
    { return "Exceptions"; }
    
    /*! this text is used in the title page of a LaTeX document. */
    virtual QCString trGeneratedBy()
    { return "G�n�r� par"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990307
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of page containing all the index of all namespaces. */
    virtual QCString trNamespaceList()
    { return "Liste des namespaces"; }

    /*! used as an introduction to the namespace list */
    virtual QCString trNamespaceListDescription(bool extractAll)
    {
      QCString result="Liste de tous les namespaces ";
      if (!extractAll) result+="document�s ";
      result+="avec une br�ve description:";
      return result;
    }

    /*! used in the class documentation as a header before the list of all
     *  friends of a class
     */
    virtual QCString trFriends()
    { return "Amis"; }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990405
//////////////////////////////////////////////////////////////////////////
    
    /*! used in the class documentation as a header before the list of all
     * related classes 
     */
    virtual QCString trRelatedFunctionDocumentation()
    { return "Documentation des fonctions amies et associ�es"; }
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990425
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of the HTML page of a class/struct/union */
    virtual QCString trCompoundReference(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool isTemplate)
    {
      QCString result="R�f�rence de ";
      switch(compType)
      {
        case ClassDef::Class:      result+="la classe "; break;
        case ClassDef::Struct:     result+="la structure "; break;
        case ClassDef::Union:      result+="l'union "; break;
        case ClassDef::Interface:  result+="l'interface "; break;
        case ClassDef::Protocol:   result+="le protocol "; break; 
        case ClassDef::Category:   result+="la cat�gorie "; break; 
        case ClassDef::Exception:  result+="l'exception "; break;
      }
      result+=(QCString)clName;
      if (isTemplate) result+=" (mod�le)";
      return result;
    }

    /*! used as the title of the HTML page of a file */
    virtual QCString trFileReference(const char *fileName)
    {
      QCString result= "R�f�rence du fichier ";
      result+=fileName;
      return result;
    }

    /*! used as the title of the HTML page of a namespace */
    virtual QCString trNamespaceReference(const char *namespaceName)
    {
      QCString result= "R�f�rence du namespace ";
      result+=namespaceName;
      return result;
    }
    
    virtual QCString trPublicMembers()
    { return "Fonctions membres publiques"; }
    virtual QCString trPublicSlots()
    { return "Connecteurs publics"; }
    virtual QCString trSignals()
    { return "Signaux"; }
    virtual QCString trStaticPublicMembers()
    { return "Fonctions membres publiques statiques"; }
    virtual QCString trProtectedMembers()
    { return "Fonctions membres prot�g�es"; }
    virtual QCString trProtectedSlots()
    { return "Connecteurs prot�g�s"; }
    virtual QCString trStaticProtectedMembers()
    { return "Fonctions membres prot�g�es statiques"; }
    virtual QCString trPrivateMembers()
    { return "Fonctions membres priv�es"; }
    virtual QCString trPrivateSlots()
    { return "Connecteurs priv�s"; }
    virtual QCString trStaticPrivateMembers()
    { return "Fonctions membres priv�es statiques"; }
    
    /*! this function is used to produce a comma-separated list of items.
     *  use generateMarker(i) to indicate where item i should be put.
     */
    virtual QCString trWriteList(int numEntries)
    {
      QCString result;
      int i;
      // the inherits list contain `numEntries' classes
      for (i=0;i<numEntries;i++) 
      {
        // use generateMarker to generate placeholders for the class links!
        result+=generateMarker(i); // generate marker for entry i in the list
                                   // (order is left to right)
        
        if (i!=numEntries-1)  // not the last entry, so we need a separator
        {
          if (i<numEntries-2) // not the fore last entry
            result+=", ";
          else                // the fore last entry
            result+=", et ";
        }
      }
      return result; 
    }
    
    /*! used in class documentation to produce a list of base classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritsList(int numEntries)
    {
      return "Est d�riv�e de "+trWriteList(numEntries)+".";
    }

    /*! used in class documentation to produce a list of super classes,
     *  if class diagrams are disabled.
     */
    virtual QCString trInheritedByList(int numEntries)
    {
      return "D�riv�e par "+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of 
     *  members that are hidden by this one.
     */
    virtual QCString trReimplementedFromList(int numEntries)
    {
      return "R�impl�ment�e � partir de "+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of
     *  all member that overwrite the implementation of this member.
     */
    virtual QCString trReimplementedInList(int numEntries)
    {
      return "R�impl�ment�e dans "+trWriteList(numEntries)+".";
    }

    /*! This is put above each page as a link to all members of namespaces. */
    virtual QCString trNamespaceMembers()
    { return "Membres de namespace"; }

    /*! This is an introduction to the page with all namespace members */
    virtual QCString trNamespaceMemberDescription(bool extractAll)
    { 
      QCString result="Liste de tous les membres de namespace ";
      if (!extractAll) result+="document�s ";
      result+="avec liens vers ";
      if (extractAll) 
        result+="la documentation de namespace de chaque membre:";
      else 
        result+="les namespaces auxquels ils appartiennent:";
      return result;
    }
    /*! This is used in LaTeX as the title of the chapter with the 
     *  index of all namespaces.
     */
    virtual QCString trNamespaceIndex()
    { return "Index des namespaces"; }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all namespaces.
     */
    virtual QCString trNamespaceDocumentation()
    { return "Documentation des namespaces"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990522
//////////////////////////////////////////////////////////////////////////

    /*! This is used in the documentation before the list of all
     *  namespaces in a file.
     */
    virtual QCString trNamespaces()
    { return "Namespaces"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990728
//////////////////////////////////////////////////////////////////////////

    /*! This is put at the bottom of a class documentation page and is
     *  followed by a list of files that were used to generate the page.
     */
    virtual QCString trGeneratedFromFiles(ClassDef::CompoundType compType,
        bool single)
    { // here s is one of " Class", " Struct" or " Union"
      // single is true implies a single file
      QCString result=(QCString)"La documentation de ";
      switch(compType)
      {
        case ClassDef::Class:      result+="cette classe"; break;
        case ClassDef::Struct:     result+="cette structure"; break;
        case ClassDef::Union:      result+="cette union"; break;
        case ClassDef::Interface:  result+="cette interface"; break;
        case ClassDef::Protocol:   result+="ce protocol"; break; 
        case ClassDef::Category:   result+="cette cat�gorie"; break; 
        case ClassDef::Exception:  result+="cette exception"; break;
      }
      result+=" a �t� g�n�r�e � partir ";
      if (single) result+="du fichier suivant:"; 
      else result+="des fichiers suivants:";
      return result;
    }

    /*! This is in the (quick) index as a link to the alphabetical compound
     * list.
     */
    virtual QCString trAlphabeticalList()
    { return "Liste alphab�tique"; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990901
//////////////////////////////////////////////////////////////////////////

    /*! This is used as the heading text for the retval command. */
    virtual QCString trReturnValues()
    { return "Valeurs retourn�es"; }

    /*! This is in the (quick) index as a link to the main page (index.html)
     */
    virtual QCString trMainPage()
    { return "Page principale"; }

    /*! This is used in references to page that are put in the LaTeX
     *  documentation. It should be an abbreviation of the word page.
     */
    virtual QCString trPageAbbreviation()
    { return "p."; }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991003
//////////////////////////////////////////////////////////////////////////

    virtual QCString trSources()
    {
      return "Sources";
    }
    virtual QCString trDefinedAtLineInSourceFile()
    {
      return "D�finition � la ligne @0 du fichier @1.";
    }
    virtual QCString trDefinedInSourceFile()
    {
      return "D�finition dans le fichier @0.";
    }

//////////////////////////////////////////////////////////////////////////
// new since 0.49-991205
//////////////////////////////////////////////////////////////////////////

    virtual QCString trDeprecated()
    {
      return "Obsol�te";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.0.0
//////////////////////////////////////////////////////////////////////////

    /*! this text is put before a collaboration diagram */
    virtual QCString trCollaborationDiagram(const char *clName)
    {
      return (QCString)"Graphe de collaboration de "+clName+":";
    }
    /*! this text is put before an include dependency graph */
    virtual QCString trInclDepGraph(const char *fName)
    {
      return (QCString)"Graphe des d�pendances par inclusion de "+fName+":";
    }
    /*! header that is put before the list of constructor/destructors. */
    virtual QCString trConstructorDocumentation()
    {
      return "Documentation des contructeurs et destructeur"; 
    }
    /*! Used in the file documentation to point to the corresponding sources. */
    virtual QCString trGotoSourceCode()
    {
      return "Aller au code source de ce fichier.";
    }
    /*! Used in the file sources to point to the corresponding documentation. */
    virtual QCString trGotoDocumentation()
    {
      return "Aller � la documentation de ce fichier.";
    }
    /*! Text for the \\pre command */
    virtual QCString trPrecondition()
    {
      return "Pr�condition";
    }
    /*! Text for the \\post command */
    virtual QCString trPostcondition()
    {
      return "Postcondition";
    }
    /*! Text for the \\invariant command */
    virtual QCString trInvariant()
    {
      return "Invariant";
    }
    /*! Text shown before a multi-line variable/enum initialization */
    virtual QCString trInitialValue()
    {
      return "Valeur initiale:";
    }
    /*! Text used the source code in the file index */
    virtual QCString trCode()
    {
      return "code";
    }
    virtual QCString trGraphicalHierarchy()
    {
      return "Graphe hi�rarchique des classes";
    }
    virtual QCString trGotoGraphicalHierarchy()
    {
      return "Aller au graphe hi�rarchique des classes";
    }
    virtual QCString trGotoTextualHierarchy()
    {
      return "Aller � la hi�rarchie des classes en mode texte";
    }
    virtual QCString trPageIndex()
    {
      return "Index des pages";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.0
//////////////////////////////////////////////////////////////////////////
    
    virtual QCString trNote()
    {
      return "Note";
    }
    virtual QCString trPublicTypes()
    {
      return "Types publics";
    }
    virtual QCString trPublicAttribs()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Champs de donn�es";
      }
      else
      {
        return "Attributs publics";
      }
    }
    virtual QCString trStaticPublicAttribs()
    {
      return "Attributs publics statiques";
    }
    virtual QCString trProtectedTypes()
    {
      return "Types prot�g�s";
    }
    virtual QCString trProtectedAttribs()
    {
      return "Attributs prot�g�s";
    }
    virtual QCString trStaticProtectedAttribs()
    {
      return "Attributs prot�g�s statiques";
    }
    virtual QCString trPrivateTypes()
    {
      return "Types priv�s";
    }
    virtual QCString trPrivateAttribs()
    {
      return "Attributs priv�s";
    }
    virtual QCString trStaticPrivateAttribs()
    {
      return "Attributs priv�s statiques";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a marker that is put before a \\todo item */
    virtual QCString trTodo()
    {
      return "� faire";
    }
    /*! Used as the header of the todo list */
    virtual QCString trTodoList()
    {
      return "Liste des choses � faire";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.1.4
//////////////////////////////////////////////////////////////////////////

    virtual QCString trReferencedBy()
    {
      return "R�f�renc� par";
    }
    virtual QCString trRemarks()
    {
      return "Remarques";
    }
    virtual QCString trAttention()
    {
      return "Attention";
    }
    virtual QCString trInclByDepGraph()
    {
      return "Ce graphe montre quels fichiers incluent directement "
             "ou indirectement ce fichier:";
    }
    virtual QCString trSince()
    {
      return "Depuis";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.1.5
//////////////////////////////////////////////////////////////////////////

    /*! title of the graph legend page */
    virtual QCString trLegendTitle()
    {
      return "L�gende du graphe";
    }
    /*! page explaining how the dot graph's should be interpreted 
     *  The %A in the text below are to prevent link to classes called "A".
     */
    virtual QCString trLegendDocs()
    {
      return 
        "Cette page explique comment interpr�ter les graphes g�n�r�s "
        "par doxygen.<p>\n"
        "Consid�rez l'exemple suivant:\n"
        "\\code\n"
        "/*! Classe invisible � cause d'une troncature */\n"
        "class Invisible { };\n\n"
        "/*! Classe tronqu�e, la relation d'h�ritage est masqu�e */\n"
        "class Truncated : public Invisible { };\n\n"
        "/*! Classe non document�e avec des commentaires Doxygen */\n"
        "class Undocumented { };\n\n"
        "/*! Classe d�riv�e par h�ritage public */\n"
        "class PublicBase : public Truncated { };\n\n"
        "/*! Un mod�le de classe */\n"
        "template<class T> class Templ { };\n\n"
        "/*! Classe d�riv�e par h�ritage prot�g� */\n"
        "class ProtectedBase { };\n\n"
        "/*! Classe d�riv�e par h�ritage priv� */\n"
        "class PrivateBase { };\n\n"
        "/*! Classe utilis�e par la classe d�riv�e */\n"
        "class Used { };\n\n"
        "/*! Super-classe qui h�rite de plusieurs autres classes */\n"
        "class Inherited : public PublicBase,\n"
        "                  protected ProtectedBase,\n"
        "                  private PrivateBase,\n"
        "                  public Undocumented\n"
        "                  public Templ<int>\n"
        "{\n"
        "  private:\n"
        "    Used *m_usedClass;\n"
        "};\n"
        "\\endcode\n"
        "Si la valeur 240 est attribu�e au tag \\c MAX_DOT_GRAPH_HEIGHT "
        "du fichier de configuration, cela g�n�rera le graphe suivant:"
        "<p><center><img alt=\"\" src=\"graph_legend."+Config_getEnum("DOT_IMAGE_FORMAT")+"\"></center>\n"
        "<p>\n"
        "Les rectangles du graphe ci-dessus ont la signification suivante:\n"
        "<ul>\n"
        "<li>Un rectangle plein noir repr�sente la structure ou la classe pour laquelle "
        "le graphe est g�n�r�.\n"
        "<li>Un rectangle avec un bord noir indique une classe ou une structure document�e.\n"
        "<li>Un rectangle avec un bord gris indique une classe ou une structure non document�e.\n"
        "<li>Un rectangle avec un bord rouge indique une structure ou une classe document�e\n"
        "pour laquelle des relations d'h�ritage ou de collaboration manquent. Un graphe est "
        "tronqu� s'il n'entre pas dans les limites sp�cifi�es."
        "</ul>\n"
        "Les fl�ches ont la signification suivante:\n"
        "<ul>\n"
        "<li>Une fl�che bleu fonc� est utilis�e pour visualiser une relation d'h�ritage public "
        "entre deux classes.\n"
        "<li>Une fl�che vert fonc� est utilis�e pour une relation d'h�ritage prot�g�.\n"
        "<li>Une fl�che rouge fonc� est utilis�e pour une relation d'h�ritage priv�.\n"
        "<li>Une fl�che violette en pointill�s est utilis�e si une classe est contenue ou "
        "utilis�e par une autre classe. La fl�che est �tiquet�e avec la ou les variable(s) "
        "qui permettent d'acc�der � la classe ou structure point�e. \n"
        "<li>Une fl�che verte en pointill�s indique une relation entre une classe instanci�e et "
        "le mod�le de classe utilis�. La fl�che est �tiquet�e avec "
        "les param�tres de mod�le de la classe instanci�e.\n"
        "</ul>\n";
    }
    /*! text for the link to the legend page */
    virtual QCString trLegend()
    {
      return "l�gende";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.0
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a test item */
    virtual QCString trTest()
    {
      return "Test";
    }
    /*! Used as the header of the test list */
    virtual QCString trTestList()
    {
      return "Liste des tests";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.1
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for KDE-2 IDL methods */
    virtual QCString trDCOPMethods()
    {
      return "Fonctions membres DCOP";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.2
//////////////////////////////////////////////////////////////////////////

    /*! Used as a section header for IDL properties */
    virtual QCString trProperties()
    {
      return "Propri�t�s";
    }
    /*! Used as a section header for IDL property documentation */
    virtual QCString trPropertyDocumentation()
    {
      return "Documentation des propri�t�s";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.4
//////////////////////////////////////////////////////////////////////////

    /*! Used for Java interfaces in the summary section of Java packages */
    virtual QCString trInterfaces()
    {
      return "Interfaces";
    }
    /*! Used for Java classes in the summary section of Java packages */
    virtual QCString trClasses()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Structures de donn�es";
      }
      else
      {
        return "Classes";
      }
    }
    /*! Used as the title of a Java package */
    virtual QCString trPackage(const char *name)
    {
      return (QCString)"Paquetage "+name;
    }
    /*! Title of the package index page */
    virtual QCString trPackageList()
    {
      return "Liste des paquetages";
    }
    /*! The description of the package index page */
    virtual QCString trPackageListDescription()
    {
      return "Liste des paquetages avec une br�ve description (si disponible):";
    }
    /*! The link name in the Quick links header for each page */
    virtual QCString trPackages()
    {
      return "Paquetages";
    }
    /*! Used as a chapter title for Latex & RTF output */
    virtual QCString trPackageDocumentation()
    {
      return "Documentation des paquetages";
    }
    /*! Text shown before a multi-line define */
    virtual QCString trDefineValue()
    {
      return "Valeur:";
    }
    
//////////////////////////////////////////////////////////////////////////
// new since 1.2.5
//////////////////////////////////////////////////////////////////////////
    
    /*! Used as a marker that is put before a \\bug item */
    virtual QCString trBug()
    {
      return "Bogue";
    }
    /*! Used as the header of the bug list */
    virtual QCString trBugList()
    {
      return "Liste des bogues";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.6
//////////////////////////////////////////////////////////////////////////

    /*! Used as ansicpg for RTF file 
     * 
     * The following table shows the correlation of Charset name, Charset Value and 
     * <pre>
     * Codepage number:
     * Charset Name       Charset Value(hex)  Codepage number
     * ------------------------------------------------------
     * DEFAULT_CHARSET           1 (x01)
     * SYMBOL_CHARSET            2 (x02)
     * OEM_CHARSET             255 (xFF)
     * ANSI_CHARSET              0 (x00)            1252
     * RUSSIAN_CHARSET         204 (xCC)            1251
     * EE_CHARSET              238 (xEE)            1250
     * GREEK_CHARSET           161 (xA1)            1253
     * TURKISH_CHARSET         162 (xA2)            1254
     * BALTIC_CHARSET          186 (xBA)            1257
     * HEBREW_CHARSET          177 (xB1)            1255
     * ARABIC _CHARSET         178 (xB2)            1256
     * SHIFTJIS_CHARSET        128 (x80)             932
     * HANGEUL_CHARSET         129 (x81)             949
     * GB2313_CHARSET          134 (x86)             936
     * CHINESEBIG5_CHARSET     136 (x88)             950
     * </pre>
     * 
     */
    virtual QCString trRTFansicp()
    {
      return "1252";
    }
    

    /*! Used as ansicpg for RTF fcharset 
     *  \see trRTFansicp() for a table of possible values.
     */
    virtual QCString trRTFCharSet()
    {
      return "0";
    }

    /*! Used as header RTF general index */
    virtual QCString trRTFGeneralIndex()
    {
      return "Index";
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trClass(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Classe" : "classe"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trFile(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Fichier" : "fichier"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trNamespace(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Namespace" : "namespace"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGroup(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Groupe" : "groupe"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trPage(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Page" : "page"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trMember(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Membre" : "membre"));
      if (!singular)  result+="s";
      return result; 
    }
   
    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trField(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Champ" : "champ"));
      if (!singular)  result+="s";
      return result; 
    }

    /*! This is used for translation of the word that will possibly
     *  be followed by a single name or by a list of names 
     *  of the category.
     */
    virtual QCString trGlobal(bool first_capital, bool singular)
    { 
      QCString result((first_capital ? "Global(e)" : "global(e)"));
      if (!singular)  result+="s";
      return result; 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.7
//////////////////////////////////////////////////////////////////////////

    /*! This text is generated when the \\author command is used and
     *  for the author section in man pages. */
    virtual QCString trAuthor(bool first_capital, bool singular)
    {                                                                         
      QCString result((first_capital ? "Auteur" : "auteur"));
      if (!singular)  result+="s";
      return result; 
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.11
//////////////////////////////////////////////////////////////////////////

    /*! This text is put before the list of members referenced by a member
     */
    virtual QCString trReferences()
    {
      return "R�f�rences";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.13
//////////////////////////////////////////////////////////////////////////

    /*! used in member documentation blocks to produce a list of 
     *  members that are implemented by this one.
     */
    virtual QCString trImplementedFromList(int numEntries)
    {
      return "Impl�mente "+trWriteList(numEntries)+".";
    }

    /*! used in member documentation blocks to produce a list of
     *  all members that implement this abstract member.
     */
    virtual QCString trImplementedInList(int numEntries)
    {
      return "Impl�ment� dans "+trWriteList(numEntries)+".";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.16
//////////////////////////////////////////////////////////////////////////

    /*! used in RTF documentation as a heading for the Table
     *  of Contents.
     */
    virtual QCString trRTFTableOfContents()
    {
      return "Table des mati�res";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.17
//////////////////////////////////////////////////////////////////////////

    /*! Used as the header of the list of item that have been 
     *  flagged deprecated 
     */
    virtual QCString trDeprecatedList()
    {
      return "Liste des �l�ments obsol�tes";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.2.18
//////////////////////////////////////////////////////////////////////////

    /*! Used as a header for declaration section of the events found in 
     * a C# program
     */
    virtual QCString trEvents()
    {
      return "Ev�nements";
    }
    /*! Header used for the documentation section of a class' events. */
    virtual QCString trEventDocumentation()
    {
      return "Documentation des �v�nements";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3
//////////////////////////////////////////////////////////////////////////

    /*! Used as a heading for a list of Java class types with package scope.
     */
    virtual QCString trPackageTypes()
    { 
      return "Types de paquetage";
    }
    /*! Used as a heading for a list of Java class functions with package 
     * scope. 
     */
    virtual QCString trPackageMembers()
    { 
      return "Fonctions de paquetage";
    }
    /*! Used as a heading for a list of static Java class functions with 
     *  package scope.
     */
    virtual QCString trStaticPackageMembers()
    { 
      return "Fonctions statiques de paquetage";
    }
    /*! Used as a heading for a list of Java class variables with package 
     * scope.
     */
    virtual QCString trPackageAttribs()
    { 
      return "Attributs de paquetage";
    }
    /*! Used as a heading for a list of static Java class variables with 
     * package scope.
     */
    virtual QCString trStaticPackageAttribs()
    { 
      return "Attributs statiques de paquetage";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3.1
//////////////////////////////////////////////////////////////////////////

    /*! Used in the quick index of a class/file/namespace member list page 
     *  to link to the unfiltered list of all members.
     */
    virtual QCString trAll()
    {
      return "Tout";
    }
    /*! Put in front of the call graph for a function. */
    virtual QCString trCallGraph()
    {
      return "Voici le graphe d'appel pour cette fonction:";
    }

//////////////////////////////////////////////////////////////////////////
// new since 1.3.3
//////////////////////////////////////////////////////////////////////////

    /*! When the search engine is enabled this text is put in the header 
     *  of each page before the field where one can enter the text to search 
     *  for. 
     */
    virtual QCString trSearchForIndex()
    {
      return "Rechercher";
    }
    /*! This string is used as the title for the page listing the search
     *  results.
     */
    virtual QCString trSearchResultsTitle()
    {
      return "R�sultats de la recherche";
    }
    /*! This string is put just before listing the search results. The
     *  text can be different depending on the number of documents found.
     *  Inside the text you can put the special marker $num to insert
     *  the number representing the actual number of search results.
     *  The @a numDocuments parameter can be either 0, 1 or 2, where the 
     *  value 2 represents 2 or more matches. HTML markup is allowed inside
     *  the returned string.
     */
    virtual QCString trSearchResults(int numDocuments)
    {
      if (numDocuments==0)
      {
        return "Sorry, no documents matching your query.";
      }
      else if (numDocuments==1)
      {
        return "Trouv� <b>1</b> document correspondant � votre requ�te.";
      }
      else 
      {
        return "Trouv�  <b>$num</b> documents correspondant � votre requ�te.. "
               "Class� par ordre de pertinence d�croissant.";
      }
    }
    /*! This string is put before the list of matched words, for each search 
     *  result. What follows is the list of words that matched the query.
     */
    virtual QCString trSearchMatches()
    {
      return "Correspondances:";
    }

};

#endif
