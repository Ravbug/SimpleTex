cmake_minimum_required(VERSION 3.20)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${DEPS_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")

# LTO on release and profile
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE CACHE INTERNAL "")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE CACHE INTERNAL "")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL TRUE CACHE INTERNAL "")
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_PROFILE TRUE CACHE INTERNAL "")

if(MSVC)
    add_definitions("/MP")
endif()

project("SimpleTex")

list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.4.0/macos")
list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.4.0/msvc2019_64")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport Pdf PdfWidgets)
qt_standard_project_setup()

# libcurl
if (MSVC)
    # use Windows native SSL instead of OpenSSL or MbedTLS
    set(CURL_USE_SCHANNEL ON CACHE INTERNAL "")
else()
    # for curl SSL
    set(ENABLE_TESTING OFF CACHE INTERNAL "")
    set(ENABLE_PROGRAMS OFF CACHE INTERNAL "")
    set(CURL_USE_MBEDTLS ON CACHE INTERNAL "")
    add_subdirectory(deps/mbedtls EXCLUDE_FROM_ALL)
    set(MBEDTLS_LIBRARIES "mbedtls")   
endif()
            
set(BUILD_TESTING OFF)
set(USE_OPENSSL OFF)
set(CURL_USE_LIBSSH2 OFF)
set(CURL_DISABLE_FTP ON)      # disable unused features & protocols
set(CURL_DISABLE_FILE ON)
set(CURL_DISABLE_TELNET ON)
set(CURL_DISABLE_LDAP ON)
set(CURL_DISABLE_DICT ON)
set(CURL_DISABLE_TFTP ON)
set(CURL_DISABLE_GOPHER ON)
set(CURL_DISABLE_IMAP ON)
set(CURL_DISABLE_SMB ON)
set(CURL_DISABLE_SMTP ON)
set(CURL_DISABLE_RTSP ON)
set(CURL_DISABLE_MQTT ON)
set(CURL_DISABLE_POP3 ON)
add_subdirectory(deps/curl EXCLUDE_FROM_ALL)

file(GLOB SOURCES src/*.cpp src/*.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    QScintilla 
    Qt6::Pdf 
    Qt6::PdfWidgets
    pdftex 
    CURL::libcurl
)

# scintilla and pdftex
add_subdirectory(deps/QScintilla-cmake EXCLUDE_FROM_ALL)
add_subdirectory(deps/pdftexlite-cmake EXCLUDE_FROM_ALL)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
    XCODE_GENERATE_SCHEME ON
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    INSTALL(CODE 
        "include(BundleUtilities)
        fixup_bundle(\"${CMAKE_BINARY_DIR}/$<CONFIGURATION>/${PROJECT_NAME}.app\" \"\" \"\")
        " 
        COMPONENT Runtime
    )
endif()
