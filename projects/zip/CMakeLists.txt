#***************************************************************************
# Copyright (C) 2017-2019 Nathan Moinvaziri
#                         https://github.com/nmoinvaz/minizip
# Copyright (C)      2016 Matthias Schmieder
#                         schmieder.matthias@gmail.com
#***************************************************************************

cmake_minimum_required(VERSION 3.0.2)

message(STATUS "Using CMake version ${CMAKE_VERSION}")

option(MZ_COMPAT "Enables compatibility layer" ON)
option(MZ_ZLIB "Enables ZLIB compression" ON)
option(MZ_BZIP2 "Enables BZIP2 compression" OFF)
option(MZ_LZMA "Enables LZMA compression" OFF)
option(MZ_PKCRYPT "Enables PKWARE traditional encryption" OFF)
option(MZ_WZAES "Enables WinZIP AES encryption" ON)
option(MZ_LIBCOMP "Enables Apple compression" OFF)
option(MZ_OPENSSL "Enables OpenSSL for encryption" OFF)
option(MZ_BRG "Enables Brian Gladman's encryption library" OFF)
option(MZ_SIGNING "Enables zip signing support" ON)
option(MZ_COMPRESS_ONLY "Only support compression" OFF)
option(MZ_DECOMPRESS_ONLY "Only support decompression" OFF)
option(MZ_BUILD_TEST "Builds minizip test executable" OFF)
option(MZ_BUILD_UNIT_TEST "Builds minizip unit test project" OFF)
option(MZ_BUILD_FUZZ_TEST "Builds minizip fuzzer executables" OFF)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 OLD)
endif()
# ZLIB_ROOT - Parent directory of zlib installation
# BZIP2_ROOT - Parent directory of BZip2 installation
# OPENSSL_ROOT - Parent directory of OpenSSL installation

enable_language(C)

# Minizip library version
set(VERSION "2.9.0")

# Minizip api version
set(SOVERSION "2.5")

include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckTypeSize)
include(GNUInstallDirs)
include(ExternalProject)

set(INSTALL_BIN_DIR ${CMAKE_INSTALL_FULL_BINDIR} CACHE PATH "Installation directory for executables")
set(INSTALL_LIB_DIR ${CMAKE_INSTALL_FULL_LIBDIR} CACHE PATH "Installation directory for libraries")
set(INSTALL_INC_DIR ${CMAKE_INSTALL_FULL_INCLUDEDIR} CACHE PATH "Installation directory for headers")
set(INSTALL_MAN_DIR ${CMAKE_INSTALL_FULL_MANDIR} CACHE PATH "Installation directory for manual pages")
set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")
set(INSTALL_CMAKE_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/cmake/minizip" CACHE PATH "Installation directory for cmake files.")

set(MINIZIP_PC ${CMAKE_CURRENT_BINARY_DIR}/minizip.pc)
configure_file(minizip.pc.cmakein ${MINIZIP_PC} @ONLY)

# Check if zlib installation is present
if(MZ_ZLIB AND NOT MZ_LIBCOMP)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/zlib/)
endif()

# Check if bzip2 installation is present
if(MZ_BZIP2)
    find_package(BZip2)
    if(BZIP2_FOUND)
        message(STATUS "Using BZIP2 ${BZIP2_VERSION_STRING}")
        include_directories(${BZIP2_INCLUDE_DIRS})
        add_definitions(-DHAVE_BZIP2)
    endif()
endif()

# Check to see if openssl installation is present
if(MZ_OPENSSL)
    find_package(OpenSSL)
    if (OPENSSL_FOUND)
        message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")

        include_directories(${OPENSSL_INCLUDE_DIR})
        if(OPENSSL_INCLUDE_DIRS)
            include_directories(${OPENSSL_INCLUDE_DIRS})
        endif()
    endif()
endif()

# Check for system includes
check_include_file(stdint.h   HAVE_STDINT_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)

if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()
if(HAVE_INTTYPES_H)
    add_definitions(-DHAVE_INTTYPES_H)
endif()

# Check for large file support
check_type_size(off64_t OFF64_T)
if(HAVE_OFF64_T)
    add_definitions(-D__USE_FILE_OFFSET64)
    add_definitions(-D__USE_LARGEFILE64)
    add_definitions(-D_LARGEFILE64_SOURCE)
    add_definitions(-D_FILE_OFFSET_BITS=64)
endif()
# Check for fseeko support
check_function_exists(fseeko HAVE_FSEEKO)
if(NOT HAVE_FSEEKO)
    add_definitions(-DNO_FSEEKO)
endif()

# Enable compiler warnings
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/W3)
else()
    add_compile_options(-W -Wall)
endif()
# Enable x86 optimizations if supported
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    include(CheckCCompilerFlag)

    macro(enable_option_if_supported option variable)
        check_c_compiler_flag(
            "-Werror=unused-command-line-argument ${option}" ${variable})
        if(${variable})
            add_compile_options("$<$<CONFIG:Release>:${option}>")
        endif()
    endmacro()

    enable_option_if_supported(-msse3 check_opt_sse3)
    enable_option_if_supported(-msse4.1 check_opt_sse41)
    enable_option_if_supported(-maes check_opt_aes)
endif()
# Set compiler options
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options(
        $<$<CONFIG:Debug>:/Zi>
        $<$<CONFIG:Debug>:/Od>
        $<$<CONFIG:Release>:/Ox>
        $<$<CONFIG:Release>:/Os>)
else()
    add_compile_options(
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Release>:-Os>)
endif()

# Initial source files
set(MINIZIP_SRC
    mz_crypt.c
    mz_os.c
    mz_strm.c
    mz_strm_buf.c
    mz_strm_mem.c
    mz_strm_split.c
    mz_zip.c
    mz_zip_rw.c)

# Initial header files
set(MINIZIP_PUBLIC_HEADERS
    mz.h
    mz_os.h
    mz_crypt.h
    mz_strm.h
    mz_strm_buf.h
    mz_strm_mem.h
    mz_strm_split.h
    mz_strm_os.h
    mz_zip.h
    mz_zip_rw.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Setup predefined macros
if(MZ_COMPRESS_ONLY)
    add_definitions(-DMZ_ZIP_NO_DECOMPRESSION)
endif()
if(MZ_DECOMPRESS_ONLY)
    add_definitions(-DMZ_ZIP_NO_COMPRESSION)
endif()
if(NOT MZ_PKCRYPT AND NOT MZ_WZAES)
    add_definitions(-DMZ_ZIP_NO_ENCRYPTION)
endif()
if(MZ_SIGNING)
    add_definitions(-DMZ_ZIP_SIGNING)
endif()

# Windows specific
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)

    list(APPEND MINIZIP_SRC "mz_os_win32.c" "mz_strm_os_win32.c")
    if (MZ_PKCRYPT OR MZ_WZAES)
        if (NOT MZ_OPENSSL AND NOT OPENSSL_FOUND AND NOT MZ_BRG)
            list(APPEND MINIZIP_SRC "mz_crypt_win32.c")
        endif()
    endif()
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "WindowsStore")
    add_definitions(-DMZ_WINRT_API)
endif()

# Unix specific
if(UNIX)
    add_definitions(-D_POSIX_C_SOURCE=200112L)
    list(APPEND MINIZIP_SRC "mz_os_posix.c" "mz_strm_os_posix.c")

    if ((MZ_PKCRYPT OR MZ_WZAES) AND NOT (MZ_OPENSSL AND OPENSSL_FOUND))

        if (APPLE AND NOT MZ_BRG)
            check_include_file(CommonCrypto/CommonCrypto.h COMMONCRYPTO_FOUND)
            if (COMMONCRYPTO_FOUND)
                list(APPEND MINIZIP_SRC "mz_crypt_apple.c")
            else()
                message(STATUS "CommonCrypto not found, using BRG instead")
                set(MZ_BRG TRUE)
            endif()
        else()
            set(MZ_BRG TRUE)
        endif()

        # Check to see which random generation functions we have
        check_symbol_exists("getrandom" "sys/random.h" HAVE_GETRANDOM)
        if (HAVE_GETRANDOM)
            add_definitions(-DHAVE_GETRANDOM)
        endif()
        check_symbol_exists("arc4random_buf" "stdlib.h" HAVE_ARC4RANDOM_BUF)
        #if (HAVE_ARC4RANDOM_BUF)
        #    add_definitions(-DHAVE_ARC4RANDOM_BUF)
        #else()
        #    check_symbol_exists("arc4random" "stdlib.h" HAVE_ARC4RANDOM)
        #    if (HAVE_ARC4RANDOM)
        #        add_definitions(-DHAVE_ARC4RANDOM)
        #    endif()
        #endif()

        #if(NOT HAVE_ARC4RANDOM_BUF)
        #    find_package(PkgConfig REQUIRED)

        #    pkg_check_modules(LIBBSD libbsd)
        #    if (LIBBSD_FOUND)
        #        check_library_exists("${LIBBSD_LIBRARIES}" carc4random_buf"
        #            "${LIBBSD_LIBRARY_DIRS}" HAVE_LIBBSD_ARC4RANDOM_BUF)
        #        if (HAVE_LIBBSD_ARC4RANDOM_BUF)
        #            add_definitions(-DHAVE_LIBBSD)
        #            add_definitions(-DHAVE_ARC4RANDOM_BUF)
        #            include_directories(${LIBBSD_INCLUDE_DIRS})
        #            link_directories(${LIBBSD_LIBRARY_DIRS})
        #        endif()
        #    endif()
        #endif()
    endif()

    find_package(Iconv QUIET)
    if (Iconv_FOUND)
        message(STATUS "Using Iconv")
        include_directories(${Iconv_INCLUDE_DIRS})
    endif()
endif()

# Include compatibility layer
if(MZ_COMPAT)
    list(APPEND MINIZIP_SRC "mz_compat.c")
    list(APPEND MINIZIP_PUBLIC_HEADERS "mz_compat.h")

    set(COMPAT_HEADER "\
/* file.h -- Compatibility layer shim\n\
   part of the MiniZip project\n\n\
   This program is distributed under the terms of the same license as zlib.\n\
   See the accompanying LICENSE file for the full text of the license.\n\
*/\n\n\
#ifndef MZ_COMPAT_FILE\n\
#define MZ_COMPAT_FILE\n\n\
#include \"mz_compat.h\"\n\n\
#endif\n")

    string(REPLACE "file.h" "zip.h" ZIP_COMPAT_HEADER ${COMPAT_HEADER})
    string(REPLACE "MZ_COMPAT_FILE" "MZ_COMPAT_ZIP" ZIP_COMPAT_HEADER ${ZIP_COMPAT_HEADER})
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/zip.h" ${ZIP_COMPAT_HEADER})
    list(APPEND MINIZIP_PUBLIC_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/zip.h")

    string(REPLACE "file.h" "unzip.h" UNZIP_COMPAT_HEADER ${COMPAT_HEADER})
    string(REPLACE "MZ_COMPAT_FILE" "MZ_COMPAT_UNZIP" UNZIP_COMPAT_HEADER ${UNZIP_COMPAT_HEADER})
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/unzip.h" ${UNZIP_COMPAT_HEADER})
    list(APPEND MINIZIP_PUBLIC_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/unzip.h")

    if(MZ_COMPAT_VERSION)
        add_definitions(-DMZ_COMPAT_VERSION=${MZ_COMPAT_VERSION})
    endif()
endif()

# Include PKCRYPT
if(MZ_PKCRYPT)
    add_definitions(-DHAVE_PKCRYPT)

    list(APPEND MINIZIP_SRC "mz_strm_pkcrypt.c")
    list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_pkcrypt.h")
endif()

# Include WinZIP AES
if(MZ_WZAES)
    add_definitions(-DHAVE_WZAES)

    list(APPEND MINIZIP_SRC "mz_strm_wzaes.c")
    list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_wzaes.h")
endif()

# Include BRG
if(MZ_BRG)
    list(APPEND MINIZIP_SRC "mz_crypt_brg.c")

    set(BRG_SRC
        lib/brg/aescrypt.c
        lib/brg/aeskey.c
        lib/brg/aestab.c
        lib/brg/hmac.c
        lib/brg/sha1.c
        lib/brg/sha2.c)

    set(BRG_PUBLIC_HEADERS
        lib/brg/aes.h
        lib/brg/aesopt.h
        lib/brg/aestab.h
        lib/brg/brg_endian.h
        lib/brg/brg_types.h
        lib/brg/hmac.h
        lib/brg/sha1.h
        lib/brg/sha2.h)

    include_directories(lib/brg)

    source_group("BRG" FILES ${BRG_SRC} ${BRG_PUBLIC_HEADERS})
endif()

# Include OpenSSL
if(MZ_OPENSSL AND OPENSSL_FOUND)
    list(APPEND MINIZIP_SRC "mz_crypt_openssl.c")
endif()

# Include ZLIB
if(MZ_ZLIB)
    if(MZ_LIBCOMP)
        add_definitions(-DHAVE_LIBCOMP)

        list(APPEND MINIZIP_SRC "mz_strm_libcomp.c")
        list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_libcomp.h")
    else()
        add_definitions(-DHAVE_ZLIB)

        if(ZLIB_COMPAT)
            add_definitions(-DZLIB_COMPAT)
        endif()

        list(APPEND MINIZIP_SRC "mz_strm_zlib.c")
        list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_zlib.h")
    endif()
endif()

# Include BZIP2
if(MZ_BZIP2)
    add_definitions(-DHAVE_BZIP2)

    list(APPEND MINIZIP_SRC "mz_strm_bzip.c")
    list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_bzip.h")

    if(NOT BZIP2_FOUND)
        add_definitions(-DBZ_NO_STDIO)

        set(BZIP2_SRC
            lib/bzip2/blocksort.c
            lib/bzip2/bzlib.c
            lib/bzip2/compress.c
            lib/bzip2/crctable.c
            lib/bzip2/decompress.c
            lib/bzip2/huffman.c
            lib/bzip2/randtable.c)

        set(BZIP2_PUBLIC_HEADERS
            lib/bzip2/bzlib.h
            lib/bzip2/bzlib_private.h)

        include_directories(lib/bzip2)

        source_group("BZip2" FILES ${BZIP2_SRC} ${BZIP2_PUBLIC_HEADERS})
    endif()
endif()

# Include LZMA
if(MZ_LZMA)
    add_definitions(-DHAVE_LZMA)
    add_definitions(-DLZMA_API_STATIC)
    add_definitions(-DHAVE_CONFIG_H)

    check_include_file(limits.h     HAVE_LIMITS_H)
    check_include_file(string.h     HAVE_STRING_H)
    check_include_file(strings.h    HAVE_STRINGS_H)
    check_include_file(memory.h     HAVE_MEMORY_H)
    check_include_file(stdbool.h    HAVE_STDBOOL_H)
    check_include_file(immintrin.h  HAVE_IMMINTRIN_H)

    if(HAVE_LIMITS_H)
        add_definitions(-DHAVE_LIMITS_H)
    endif()
    if(HAVE_STRING_H)
        add_definitions(-DHAVE_STRING_H)
    endif()
    if(HAVE_STRINGS_H)
        add_definitions(-DHAVE_STRINGS_H)
    endif()
    if(HAVE_MEMORY_H)
        add_definitions(-DHAVE_MEMORY_H)
    endif()
    if(HAVE_STDBOOL_H)
        add_definitions(-DHAVE_STDBOOL_H)
    endif()
    if(HAVE_IMMINTRIN_H)
        add_definitions(-DHAVE_IMMINTRIN_H)
    endif()

    list(APPEND MINIZIP_SRC "mz_strm_lzma.c")
    list(APPEND MINIZIP_PUBLIC_HEADERS "mz_strm_lzma.h")

    set(LZMA_CHECK_SRC
        lib/liblzma/check/check.c
        lib/liblzma/check/crc32_fast.c
        lib/liblzma/check/crc32_table.c)
    set(LZMA_COMMON_SRC
        lib/liblzma/common/alone_decoder.c
        lib/liblzma/common/alone_encoder.c
        lib/liblzma/common/common.c
        lib/liblzma/common/filter_encoder.c)
    set(LZMA_LZ_SRC
        lib/liblzma/lz/lz_decoder.c
        lib/liblzma/lz/lz_encoder.c
        lib/liblzma/lz/lz_encoder_mf.c)
    set(LZMA_LZMA_SRC
        lib/liblzma/lzma/fastpos.h
        lib/liblzma/lzma/fastpos_table.c
        lib/liblzma/lzma/lzma_decoder.c
        lib/liblzma/lzma/lzma_encoder.c
        lib/liblzma/lzma/lzma_encoder_optimum_fast.c
        lib/liblzma/lzma/lzma_encoder_optimum_normal.c
        lib/liblzma/lzma/lzma_encoder_presets.c)
    set(LZMA_RANGECODER_SRC
        lib/liblzma/rangecoder/price_table.c)

    set(LZMA_CONFIG_HEADERS
        lib/liblzma/config.h)
    set(LZMA_API_HEADERS
        lib/liblzma/api/lzma.h
        lib/liblzma/api/lzma/base.h
        lib/liblzma/api/lzma/check.h
        lib/liblzma/api/lzma/container.h
        lib/liblzma/api/lzma/filter.h
        lib/liblzma/api/lzma/lzma12.h
        lib/liblzma/api/lzma/version.h
        lib/liblzma/api/lzma/vli.h)
    set(LZMA_CHECK_HEADERS
        lib/liblzma/check/check.h
        lib/liblzma/check/crc32_table_be.h
        lib/liblzma/check/crc32_table_le.h
        lib/liblzma/check/crc_macros.h)
    set(LZMA_COMMON_HEADERS
        lib/liblzma/common/alone_decoder.h
        lib/liblzma/common/common.h
        lib/liblzma/common/filter_encoder.h
        lib/liblzma/common/index.h
        lib/liblzma/common/memcmplen.h
        lib/liblzma/common/sysdefs.h
        lib/liblzma/common/tuklib_common.h
        lib/liblzma/common/tuklib_config.h
        lib/liblzma/common/tuklib_integer.h)
    set(LZMA_LZ_HEADERS
        lib/liblzma/lz/lz_decoder.h
        lib/liblzma/lz/lz_encoder.h
        lib/liblzma/lz/lz_encoder_hash.h
        lib/liblzma/lz/lz_encoder_hash_table.h)
    set(LZMA_LZMA_HEADERS
        lib/liblzma/lzma/lzma2_encoder.h
        lib/liblzma/lzma/lzma_common.h
        lib/liblzma/lzma/lzma_decoder.h
        lib/liblzma/lzma/lzma_encoder.h
        lib/liblzma/lzma/lzma_encoder_private.h)
    set(LZMA_RANGECODER_HEADERS
        lib/liblzma/rangecoder/price.h
        lib/liblzma/rangecoder/range_common.h
        lib/liblzma/rangecoder/range_decoder.h
        lib/liblzma/rangecoder/range_encoder.h)

    set(LZMA_PUBLIC_HEADERS
        ${LZMA_CONFIG_HEADERS}
        ${LZMA_API_HEADERS}
        ${LZMA_CHECK_HEADERS}
        ${LZMA_COMMON_HEADERS}
        ${LZMA_LZ_HEADERS}
        ${LZMA_LZMA_HEADERS}
        ${LZMA_RANGECODER_HEADERS})

    set(LZMA_SRC
        ${LZMA_CHECK_SRC}
        ${LZMA_COMMON_SRC}
        ${LZMA_LZ_SRC}
        ${LZMA_LZMA_SRC}
        ${LZMA_RANGECODER_SRC})

    include_directories(lib/liblzma
                        lib/liblzma/api
                        lib/liblzma/check
                        lib/liblzma/common
                        lib/liblzma/lz
                        lib/liblzma/lzma
                        lib/liblzma/rangecoder)

    source_group("LZMA" FILES ${LZMA_CONFIG_HEADERS})
    source_group("LZMA\\API" FILES ${LZMA_API_HEADERS})
    source_group("LZMA\\Check" FILES ${LZMA_CHECK_SRC} ${LZMA_CHECK_HEADERS})
    source_group("LZMA\\Common" FILES ${LZMA_COMMON_SRC} ${LZMA_COMMON_HEADERS})
    source_group("LZMA\\LZ" FILES ${LZMA_LZ_SRC} ${LZMA_LZ_HEADERS})
    source_group("LZMA\\LZMA" FILES ${LZMA_LZMA_SRC} ${LZMA_LZMA_HEADERS})
    source_group("LZMA\\RangeCoder" FILES ${LZMA_RANGECODER_SRC} ${LZMA_RANGECODER_HEADERS})
endif()

# Create minizip library
source_group("Minizip" FILES ${MINIZIP_SRC} ${MINIZIP_PUBLIC_HEADERS})

add_library(libminizip STATIC
                ${MINIZIP_SRC} ${MINIZIP_PUBLIC_HEADERS}
                ${BRG_SRC} ${BRG_PUBLIC_HEADERS}
                ${BZIP2_SRC} ${BZIP2_PUBLIC_HEADERS}
                ${LZMA_SRC} ${LZMA_PUBLIC_HEADERS})
add_library(minizip::lib ALIAS libminizip)
set_target_properties(libminizip PROPERTIES
                        VERSION ${VERSION}
                        SOVERSION ${SOVERSION}
                        FOLDER "Libraries/extern"
                        LINKER_LANGUAGE C
                        DEFINE_SYMBOL "MZ_EXPORTS")

target_include_directories(libminizip PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/minizip> 
)
if(NOT RISCOS)
    set_target_properties(libminizip PROPERTIES POSITION_INDEPENDENT_CODE 1)
endif()
if(MZ_LZMA)
    set_target_properties(libminizip PROPERTIES C_STANDARD 99)
endif()

# Link with external libraries
if(MZ_ZLIB AND NOT MZ_LIBCOMP)
    target_link_libraries(libminizip zlib::static)
endif()
if(MZ_BZIP2 AND BZIP2_FOUND)
    target_link_libraries(libminizip ${BZIP2_LIBRARIES})
endif()
if(MZ_LIBCOMP)
    target_link_libraries(libminizip compression)
endif()
if(Iconv_FOUND AND NOT Iconv_IS_BUILT_IN)
    target_link_libraries(libminizip ${Iconv_LIBRARIES})
endif()
if(MZ_OPENSSL AND OPENSSL_FOUND)
    target_link_libraries(libminizip ${OPENSSL_LIBRARIES})
elseif(UNIX)
    if(APPLE AND NOT MZ_BRG)
        message(STATUS "Using CoreFoundation Framework")
        find_library(COREFOUNDATION_LIBRARY CoreFoundation)
        target_link_libraries(libminizip ${COREFOUNDATION_LIBRARY})
        message(STATUS "Using Security Framework")
        find_library(SECURITY_LIBRARY Security)
        target_link_libraries(libminizip ${SECURITY_LIBRARY})
        set_target_properties(libminizip PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")
    else()
        target_link_libraries(libminizip ${LIBBSD_LIBRARIES})
    endif()
endif()

target_include_directories(libminizip PUBLIC $<INSTALL_INTERFACE:${INSTALL_INC_DIR}>)
