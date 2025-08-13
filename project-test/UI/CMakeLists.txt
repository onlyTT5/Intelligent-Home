SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_light_off_png.c
    images/ui_img_curtain_off_png.c
    images/ui_img_air_conditioner_png.c
    images/ui_img_loudspeaker_off_png.c
    fonts/ui_font_Font1.c)

add_library(ui ${SOURCES})
