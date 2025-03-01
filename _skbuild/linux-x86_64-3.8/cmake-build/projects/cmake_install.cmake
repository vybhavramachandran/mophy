# Install script for directory: /opt/biogears/core/projects

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/biogears/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/biogears-common/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/biogears/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/test_driver/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/howto/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/unit/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/circuit_profiler/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/zip/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/cli/cmake_install.cmake")
  include("/opt/biogears/core/_skbuild/linux-x86_64-3.8/cmake-build/projects/website/cmake_install.cmake")

endif()

