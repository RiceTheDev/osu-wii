#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <grrlib.h>
#include "textures.h"

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_MAROON 0x800000FF
#define GRRLIB_GREEN 0x008000FF
#define GRRLIB_OLIVE 0x808000FF
#define GRRLIB_NAVY 0x000080FF
#define GRRLIB_PURPLE 0x800080FF
#define GRRLIB_TEAL 0x008080FF
#define GRRLIB_GRAY 0x808080FF
#define GRRLIB_SILVER 0xC0C0C0FF
#define GRRLIB_RED 0xFF0000FF
#define GRRLIB_LIME 0x00FF00FF
#define GRRLIB_YELLOW 0xFFFF00FF
#define GRRLIB_BLUE 0x0000FFFF
#define GRRLIB_FUCHSIA 0xFF00FFFF
#define GRRLIB_AQUA 0x00FFFFFF
#define GRRLIB_WHITE 0xFFFFFFFF

void _exit(int code) {
    GRRLIB_Exit();
    exit(code);
}

int main() {
    GRRLIB_Init();
    WPAD_Init();

    ir_t ir1;
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    while(1) {
        WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
        WPAD_IR(WPAD_CHAN_0, &ir1);
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;
        
        GRRLIB_FillScreen(GRRLIB_BLACK);
        
        GRRLIB_DrawImg(224, 144, tex_menu_button, 0, 1.5, 1.5, 0xFFFFFFFF);
        
        // TODO: load cursor from skin
        GRRLIB_DrawImg(ir1.sx, ir1.sy, tex_cursor, 0, 1, 1, 0xFFFFFFFF);
        GRRLIB_Render();
    }

    _exit(0);
}
