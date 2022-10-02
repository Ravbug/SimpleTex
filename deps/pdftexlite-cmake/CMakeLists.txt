project(pdftexlite-cmake)

add_subdirectory(libpng-cmake)

add_library(xpdf 
    PdfTeXLite/xpdf/FoFiBase.cc 
    PdfTeXLite/xpdf/FoFiEncodings.cc 
    PdfTeXLite/xpdf/FoFiIdentifier.cc 
    PdfTeXLite/xpdf/FoFiTrueType.cc 
    PdfTeXLite/xpdf/FoFiType1.cc 
    PdfTeXLite/xpdf/FoFiType1C.cc
	PdfTeXLite/xpdf/FixedPoint.cc 
    PdfTeXLite/xpdf/gfile.cc 
    PdfTeXLite/xpdf/GHash.cc 
    PdfTeXLite/xpdf/GList.cc 
	PdfTeXLite/xpdf/gmem.cc 
    PdfTeXLite/xpdf/gmempp.cc 
    PdfTeXLite/xpdf/GString.cc 
    PdfTeXLite/xpdf/AcroForm.cc 
	PdfTeXLite/xpdf/PDF417Barcode.cc 
    PdfTeXLite/xpdf/Annot.cc 
	PdfTeXLite/xpdf/Array.cc 
	PdfTeXLite/xpdf/BuiltinFont.cc 
	PdfTeXLite/xpdf/BuiltinFontTables.cc 
	PdfTeXLite/xpdf/CMap.cc 
	PdfTeXLite/xpdf/Catalog.cc 
	PdfTeXLite/xpdf/CharCodeToUnicode.cc 
	PdfTeXLite/xpdf/Decrypt.cc 
	PdfTeXLite/xpdf/Dict.cc 
	PdfTeXLite/xpdf/Error.cc 
	PdfTeXLite/xpdf/FontEncodingTables.cc 
	PdfTeXLite/xpdf/Form.cc 
	PdfTeXLite/xpdf/Function.cc 
	PdfTeXLite/xpdf/Gfx.cc 
	PdfTeXLite/xpdf/GfxFont.cc 
	PdfTeXLite/xpdf/GfxState.cc 
	PdfTeXLite/xpdf/GlobalParams.cc 
	PdfTeXLite/xpdf/JArithmeticDecoder.cc 
	PdfTeXLite/xpdf/JBIG2Stream.cc 
	PdfTeXLite/xpdf/JPXStream.cc 
	PdfTeXLite/xpdf/Lexer.cc 
	PdfTeXLite/xpdf/Link.cc 
	PdfTeXLite/xpdf/NameToCharCode.cc 
	PdfTeXLite/xpdf/Object.cc 
	PdfTeXLite/xpdf/OptionalContent.cc 
	PdfTeXLite/xpdf/Outline.cc 
	PdfTeXLite/xpdf/OutputDev.cc 
	PdfTeXLite/xpdf/PDFDoc.cc 
	PdfTeXLite/xpdf/PDFDocEncoding.cc 
	PdfTeXLite/xpdf/PSTokenizer.cc 
	PdfTeXLite/xpdf/Page.cc 
	PdfTeXLite/xpdf/Parser.cc 
	PdfTeXLite/xpdf/SecurityHandler.cc 
	PdfTeXLite/xpdf/Stream.cc 
	PdfTeXLite/xpdf/TextString.cc 
	PdfTeXLite/xpdf/UnicodeMap.cc 
	PdfTeXLite/xpdf/UnicodeRemapping.cc 
	PdfTeXLite/xpdf/UTF8.cc 
	PdfTeXLite/xpdf/XFAForm.cc 
	PdfTeXLite/xpdf/XRef.cc 
	PdfTeXLite/xpdf/Zoox.cc 
    PdfTeXLite/pdftexdir/pdftoepdf.cc
)
target_include_directories(xpdf PUBLIC PdfTeXLite/xpdf/ PdfTeXLite/)

add_library(pdftex
    PdfTeXLite/pdftexdir/avl.c PdfTeXLite/pdftexdir/avlstuff.c 
    PdfTeXLite/pdftexdir/mapfile.c PdfTeXLite/pdftexdir/utils.c PdfTeXLite/pdftexdir/subfont.c PdfTeXLite/pdftexdir/tounicode.c 
    PdfTeXLite/pdftexdir/vfpacket.c PdfTeXLite/pdftexdir/writezip.c PdfTeXLite/pdftexdir/writet3.c PdfTeXLite/pdftexdir/writettf.c
    PdfTeXLite/pdftexdir/writefont.c PdfTeXLite/pdftexdir/writeimg.c PdfTeXLite/pdftexdir/writejpg.c PdfTeXLite/pdftexdir/writepng.c 
    PdfTeXLite/pdftexdir/writeenc.c PdfTeXLite/pdftexdir/writet1.c PdfTeXLite/pdftexdir/pkin.c PdfTeXLite/pdftexdir/epdf.c PdfTeXLite/pdftexdir/writejbig2.c
)
target_include_directories(pdftex PUBLIC PdfTeXLite/pdftexdir/ PdfTeXLite/tex/ PdfTeXLite/)
target_compile_definitions(pdftex PRIVATE -DDISABLE_OUTLINE=1 -DPDF_PARSER_ONLY=1 )
target_include_directories(pdftex PRIVATE "libpng-cmake/libpng/" "${CMAKE_BINARY_DIR}/deps/pdftexlite-cmake/libpng-cmake/libpng" )
target_link_libraries(pdftex PRIVATE png_static)
