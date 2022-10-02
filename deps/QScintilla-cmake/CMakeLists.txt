
project(QScintilla)

file(GLOB_RECURSE SCINTILLA_SRC "QScintilla/scintilla/*.cpp" "QScintilla/scintilla/*.h")
add_library(scintilla ${SCINTILLA_SRC})
target_include_directories(scintilla PUBLIC "QScintilla/scintilla/include" "QScintilla/scintilla/lexlib" "QScintilla/src/")
target_compile_features(scintilla PUBLIC cxx_std_20)
target_link_libraries(scintilla PUBLIC Qt6::Core Qt6::Widgets Qt6::Gui)

file(GLOB_RECURSE QSCINTILLA_SRC "QScintilla/src/*.cpp" "QScintilla/src/*.h")
add_library(QScintilla ${QSCINTILLA_SRC})
target_include_directories(QScintilla PUBLIC "QScintilla/src/" "QScintilla/scintilla/src/")
target_compile_features(QScintilla PUBLIC cxx_std_20)
target_link_libraries(QScintilla PUBLIC Qt6::Core Qt6::Widgets Qt6::PrintSupport Qt6::Gui scintilla)