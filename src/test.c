
#include <R.h>
#include <Rinternals.h>

#include <ft2build.h>
#include FT_FREETYPE_H

SEXP C_test(SEXP font, SEXP index) {
    FT_Library  library;
    FT_Face     face; 
    int err;

    err = FT_Init_FreeType(&library);
    if (err) {
        error("Intialisation failed");
    } 

    err = FT_New_Face(library,
                      CHAR(STRING_ELT(font, 0)),
                      0,
                      &face);
    if (err == FT_Err_Unknown_File_Format) {
        error("Unknown font format");
    } else if (err) {
        error("Font read failed");
    } 
    printf("unitsPerEM %d\n", face->units_per_EM);

    err = FT_Set_Char_Size(face, 0, 12*64, 96, 0);
    if (err) {
        error("Set char size failed");
    }
    
    err = FT_Load_Glyph(face, INTEGER(index)[0], FT_LOAD_NO_SCALE);
    if (err) {
        error("Glyph load failed");
    }
    printf("width %ld\n", face->glyph->metrics.horiAdvance);
    printf("left %ld\n", face->glyph->metrics.horiBearingX);
    printf("right %ld\n", 
           face->glyph->metrics.horiBearingX + face->glyph->metrics.width);
    printf("top %ld\n", face->glyph->metrics.horiBearingY);
    printf("bottom %ld\n", 
           face->glyph->metrics.horiBearingY - face->glyph->metrics.height);

    err = FT_Done_Face(face);
    if (err) {
        error("Face clean up failed");
    }

    err = FT_Done_FreeType(library);
    if (err) {
        error("Shut down failed");
    }

    return R_NilValue;
}
