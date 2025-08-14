#pragma once
#include <grrlib.h>
#include "menu_png.h"
#include "cursor_png.h"


GRRLIB_texImg *tex_cursor = GRRLIB_LoadTexture(cursor_png);
GRRLIB_texImg *tex_menu_button = GRRLIB_LoadTexture(menu_png);
#pragma endregion