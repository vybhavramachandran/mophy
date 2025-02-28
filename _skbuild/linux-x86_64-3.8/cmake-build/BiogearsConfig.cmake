
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was BiogearsConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

####################################################################################

include(CMakeFindDependencyMacro)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
set(Biogears_XSD_SCHEMA_DIR ${PACKAGE_PREFIX_DIR}/share/biogears/xsd/ CACHE PATH "Directory containing all of the CDM XSD Schema files") 
file(GLOB_RECURSE Biogears_XSD_SCHEMA_LIST ${PACKAGE_PREFIX_DIR}/share/biogears/xsd/*.xsd "Exsact list of XSD files for the current Biogears Release") 
set(Biogears_XML_DATA_DIR ${PACKAGE_PREFIX_DIR}/share/biogears/data CACHE PATH "Directory containing all of the data files Biogears needs to run")
file(GLOB_RECURSE Biogears_XSD_DATA_LIST ${PACKAGE_PREFIX_DIR}/share/biogears/data/*.xml "Exsact list of XML files for the current Biogears Release") 

include ( "${CMAKE_CURRENT_LIST_DIR}/Biogears.cmake" )

find_dependency(Eigen3)
find_dependency(Log4cpp)
find_dependency(CodeSynthesis)

#
# Function Stage_BioGears_Schema
# Param: DESTINATION - Directory to stage the contents of Biogears_XSD_SCHEMA_DIR
# Param: RESULTS_VAR - Variable to store the results in
#
# Places the value of Biogears_XSD_SCHEMA_LIST in to DIR
# Each file will become its on custom_target and will be staged before by runtime
function(stage_biogears_schema )
  cmake_parse_arguments(_
                     ""
                     "DESTINATION;RESULTS_VAR"
                     "" ${ARGN})
 if(NOT __DESTINATION)
  message(FATAL_ERROR "DESTINATION required but not given")
 endif()
 if(NOT __RESULTS_VAR)
  set(__RESULTS_VAR _stage_biogears_schema_results)
 endif()
 foreach( file IN LISTS Biogears_XSD_SCHEMA_LIST )
	 string(REPLACE "${Biogears_XSD_SCHEMA_DIR}" "${__DESTINATION}/xsd" destination_file "${file}" )
   list(APPEND ${__RESULTS_VAR} ${destination_file} )
	 add_custom_command(
		 OUTPUT  ${destination_file}
		 DEPENDS ${file}
     COMMAND ${CMAKE_COMMAND} -E copy ${file} ${destination_file}
	 )
  endforeach()
  add_custom_target( stage_biogears_schema
    DEPENDS 
	  ${${__RESULTS_VAR}}
	  COMMENT "Scanning for need to stage runtime dir"
  )	
  set(${__RESULTS_VAR} ${${__RESULTS_VAR}} PARENT_SCOPE)
endfunction()

#
# Function Stage_BioGears_Data
# Param: DESTINATION - Directory to stage the contents of Biogears_XSD_SCHEMA_DIR
# Param: RESULTS_VAR - Variable to store the results in
#
# Places the value of Biogears_XSD_DATA_LIST in to DIR
# Each file will become its on custom_target and will be staged before by runtime
function(stage_biogears_data)
  cmake_parse_arguments(_
                     ""
                     "DESTINATION;RESULTS_VAR"
                     "" ${ARGN})
 if(NOT __DESTINATION)
  message(FATAL_ERROR "DESTINATION required but not given")
 endif()
 if(NOT __RESULTS_VAR)
  set(__RESULTS_VAR _stage_biogears_data_results)
 endif()
 foreach( file IN LISTS Biogears_XSD_DATA_LIST )
	 string(REPLACE "${Biogears_XML_DATA_DIR}" "${__DESTINATION}" destination_file "${file}" )
   list(APPEND ${__RESULTS_VAR} ${destination_file} )
	 add_custom_command(
		 OUTPUT  ${destination_file}
		 DEPENDS ${file}
     COMMAND ${CMAKE_COMMAND} -E copy ${file} ${destination_file}
	 )
 endforeach()
 add_custom_target(stage_biogears_data
    DEPENDS 
	  ${${__RESULTS_VAR}}
    COMMENT "Scanning for need to stage runtime dir"
 )	
 set(${__RESULTS_VAR} ${${__RESULTS_VAR}} PARENT_SCOPE)
endfunction()
