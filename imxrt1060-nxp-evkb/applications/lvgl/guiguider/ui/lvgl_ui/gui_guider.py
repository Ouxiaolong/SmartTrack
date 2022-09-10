# Copyright 2021 NXP
# SPDX-License-Identifier: MIT

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=272)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 272
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.add_flag(lv.obj.FLAG.HIDDEN)


screen1 = lv.obj()
# create style style_screen1_main_main_default
style_screen1_main_main_default = lv.style_t()
style_screen1_main_main_default.init()
style_screen1_main_main_default.set_bg_color(lv.color_make(0x40,0x35,0x35))
style_screen1_main_main_default.set_bg_opa(248)

# add style for screen1
screen1.add_style(style_screen1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_img_next = lv.img(screen1)
screen1_img_next.set_pos(240,235)
screen1_img_next.set_size(25,25)
screen1_img_next.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\NXP\\GUI-Guider-Projects\\SmartTrack\\generated\\mp1071563518.png','rb') as f:
        screen1_img_next_img_data = f.read()
except:
    print('Could not open C:\\NXP\\GUI-Guider-Projects\\SmartTrack\\generated\\mp1071563518.png')
    sys.exit()

screen1_img_next_img = lv.img_dsc_t({
  'data_size': len(screen1_img_next_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen1_img_next_img_data
})

screen1_img_next.set_src(screen1_img_next_img)
screen1_img_next.set_pivot(0,0)
screen1_img_next.set_angle(0)
# create style style_screen1_img_next_main_main_default
style_screen1_img_next_main_main_default = lv.style_t()
style_screen1_img_next_main_main_default.init()
style_screen1_img_next_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen1_img_next_main_main_default.set_img_recolor_opa(0)
style_screen1_img_next_main_main_default.set_img_opa(249)

# add style for screen1_img_next
screen1_img_next.add_style(style_screen1_img_next_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_btn_next = lv.btn(screen1)
screen1_btn_next.set_pos(240,235)
screen1_btn_next.set_size(22,22)
# create style style_screen1_btn_next_main_main_default
style_screen1_btn_next_main_main_default = lv.style_t()
style_screen1_btn_next_main_main_default.init()
style_screen1_btn_next_main_main_default.set_radius(50)
style_screen1_btn_next_main_main_default.set_bg_color(lv.color_make(0x17,0x16,0x16))
style_screen1_btn_next_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen1_btn_next_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_btn_next_main_main_default.set_bg_opa(1)
style_screen1_btn_next_main_main_default.set_shadow_color(lv.color_make(0x19,0x1a,0x1a))
style_screen1_btn_next_main_main_default.set_shadow_opa(0)
style_screen1_btn_next_main_main_default.set_border_color(lv.color_make(0x45,0x49,0x4a))
style_screen1_btn_next_main_main_default.set_border_width(2)
style_screen1_btn_next_main_main_default.set_border_opa(0)

# add style for screen1_btn_next
screen1_btn_next.add_style(style_screen1_btn_next_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_cont_header = lv.obj(screen1)
screen1_cont_header.set_pos(0,0)
screen1_cont_header.set_size(480,25)
screen1_label_logo = lv.label(screen1_cont_header)
screen1_label_logo.set_pos(0,5)
screen1_label_logo.set_size(140,15)
screen1_label_logo.set_text("Smart Track")
screen1_label_logo.set_long_mode(lv.label.LONG.WRAP)
screen1_label_logo.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_logo_main_main_default
style_screen1_label_logo_main_main_default = lv.style_t()
style_screen1_label_logo_main_main_default.init()
style_screen1_label_logo_main_main_default.set_radius(0)
style_screen1_label_logo_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_logo_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_logo_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_logo_main_main_default.set_bg_opa(0)
style_screen1_label_logo_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_logo_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_logo_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_logo_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_logo_main_main_default.set_text_letter_space(2)
style_screen1_label_logo_main_main_default.set_pad_left(0)
style_screen1_label_logo_main_main_default.set_pad_right(0)
style_screen1_label_logo_main_main_default.set_pad_top(0)
style_screen1_label_logo_main_main_default.set_pad_bottom(0)

# add style for screen1_label_logo
screen1_label_logo.add_style(style_screen1_label_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_hum = lv.label(screen1_cont_header)
screen1_label_hum.set_pos(340,5)
screen1_label_hum.set_size(50,15)
screen1_label_hum.set_text("56%")
screen1_label_hum.set_long_mode(lv.label.LONG.WRAP)
screen1_label_hum.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_hum_main_main_default
style_screen1_label_hum_main_main_default = lv.style_t()
style_screen1_label_hum_main_main_default.init()
style_screen1_label_hum_main_main_default.set_radius(0)
style_screen1_label_hum_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_hum_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_hum_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_hum_main_main_default.set_bg_opa(0)
style_screen1_label_hum_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_hum_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_hum_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_hum_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_hum_main_main_default.set_text_letter_space(0)
style_screen1_label_hum_main_main_default.set_pad_left(0)
style_screen1_label_hum_main_main_default.set_pad_right(0)
style_screen1_label_hum_main_main_default.set_pad_top(0)
style_screen1_label_hum_main_main_default.set_pad_bottom(0)

# add style for screen1_label_hum
screen1_label_hum.add_style(style_screen1_label_hum_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_temp = lv.label(screen1_cont_header)
screen1_label_temp.set_pos(410,5)
screen1_label_temp.set_size(50,15)
screen1_label_temp.set_text("25C")
screen1_label_temp.set_long_mode(lv.label.LONG.WRAP)
screen1_label_temp.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_temp_main_main_default
style_screen1_label_temp_main_main_default = lv.style_t()
style_screen1_label_temp_main_main_default.init()
style_screen1_label_temp_main_main_default.set_radius(0)
style_screen1_label_temp_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_temp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_temp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_temp_main_main_default.set_bg_opa(0)
style_screen1_label_temp_main_main_default.set_text_color(lv.color_make(0xff,0xfa,0xfa))
try:
    style_screen1_label_temp_main_main_default.set_text_font(lv.font_simsun_15)
except AttributeError:
    try:
        style_screen1_label_temp_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_screen1_label_temp_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_temp_main_main_default.set_text_letter_space(0)
style_screen1_label_temp_main_main_default.set_pad_left(0)
style_screen1_label_temp_main_main_default.set_pad_right(0)
style_screen1_label_temp_main_main_default.set_pad_top(0)
style_screen1_label_temp_main_main_default.set_pad_bottom(0)

# add style for screen1_label_temp
screen1_label_temp.add_style(style_screen1_label_temp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen1_cont_header_main_main_default
style_screen1_cont_header_main_main_default = lv.style_t()
style_screen1_cont_header_main_main_default.init()
style_screen1_cont_header_main_main_default.set_radius(0)
style_screen1_cont_header_main_main_default.set_bg_color(lv.color_make(0x0c,0x0d,0x0d))
style_screen1_cont_header_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_cont_header_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_cont_header_main_main_default.set_bg_opa(39)
style_screen1_cont_header_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_cont_header_main_main_default.set_border_width(0)
style_screen1_cont_header_main_main_default.set_border_opa(255)
style_screen1_cont_header_main_main_default.set_pad_left(0)
style_screen1_cont_header_main_main_default.set_pad_right(0)
style_screen1_cont_header_main_main_default.set_pad_top(0)
style_screen1_cont_header_main_main_default.set_pad_bottom(0)

# add style for screen1_cont_header
screen1_cont_header.add_style(style_screen1_cont_header_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_meter = lv.meter(screen1)
screen1_meter.set_pos(38,35)
screen1_meter.set_size(150,150)
screen1_meter_scale_1 = screen1_meter.add_scale()
screen1_meter.set_scale_ticks(screen1_meter_scale_1, 41, 2, 10,
    lv.color_make(0xff, 0x00, 0x00))
screen1_meter.set_scale_major_ticks(screen1_meter_scale_1, 8, 5, 15,
	lv.color_make(0xff, 0xff, 0x00), 10)
screen1_meter.set_scale_range(screen1_meter_scale_1, 0, 100, 300, 90)
screen1_meter_scale_1_needleLine_0 = screen1_meter.add_needle_line(screen1_meter_scale_1, 2,
    lv.color_make(0x00, 0x00, 0x00),
    -20)
screen1_meter.set_indicator_value(screen1_meter_scale_1_needleLine_0, 30)
# create style style_screen1_meter_main_main_default
style_screen1_meter_main_main_default = lv.style_t()
style_screen1_meter_main_main_default.init()
style_screen1_meter_main_main_default.set_bg_color(lv.color_make(0x2b,0x27,0x27))
style_screen1_meter_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen1_meter_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_meter_main_main_default.set_bg_opa(255)

# add style for screen1_meter
screen1_meter.add_style(style_screen1_meter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen1_meter_main_ticks_default
style_screen1_meter_main_ticks_default = lv.style_t()
style_screen1_meter_main_ticks_default.init()
style_screen1_meter_main_ticks_default.set_text_color(lv.color_make(0xff,0x00,0x00))
try:
    style_screen1_meter_main_ticks_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_meter_main_ticks_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_meter_main_ticks_default.set_text_font(lv.font_montserrat_16)

# add style for screen1_meter
screen1_meter.add_style(style_screen1_meter_main_ticks_default, lv.PART.TICKS|lv.STATE.DEFAULT)

screen1_cont_info = lv.obj(screen1)
screen1_cont_info.set_pos(271,38)
screen1_cont_info.set_size(182,182)
screen1_label_yaw_name = lv.label(screen1_cont_info)
screen1_label_yaw_name.set_pos(20,99)
screen1_label_yaw_name.set_size(40,20)
screen1_label_yaw_name.set_text("yaw")
screen1_label_yaw_name.set_long_mode(lv.label.LONG.WRAP)
screen1_label_yaw_name.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_yaw_name_main_main_default
style_screen1_label_yaw_name_main_main_default = lv.style_t()
style_screen1_label_yaw_name_main_main_default.init()
style_screen1_label_yaw_name_main_main_default.set_radius(0)
style_screen1_label_yaw_name_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_yaw_name_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_yaw_name_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_yaw_name_main_main_default.set_bg_opa(0)
style_screen1_label_yaw_name_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_yaw_name_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_yaw_name_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_yaw_name_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_yaw_name_main_main_default.set_text_letter_space(2)
style_screen1_label_yaw_name_main_main_default.set_pad_left(0)
style_screen1_label_yaw_name_main_main_default.set_pad_right(0)
style_screen1_label_yaw_name_main_main_default.set_pad_top(0)
style_screen1_label_yaw_name_main_main_default.set_pad_bottom(0)

# add style for screen1_label_yaw_name
screen1_label_yaw_name.add_style(style_screen1_label_yaw_name_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_yaw_data = lv.label(screen1_cont_info)
screen1_label_yaw_data.set_pos(90,99)
screen1_label_yaw_data.set_size(40,20)
screen1_label_yaw_data.set_text("123C")
screen1_label_yaw_data.set_long_mode(lv.label.LONG.WRAP)
screen1_label_yaw_data.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_yaw_data_main_main_default
style_screen1_label_yaw_data_main_main_default = lv.style_t()
style_screen1_label_yaw_data_main_main_default.init()
style_screen1_label_yaw_data_main_main_default.set_radius(0)
style_screen1_label_yaw_data_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_yaw_data_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_yaw_data_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_yaw_data_main_main_default.set_bg_opa(0)
style_screen1_label_yaw_data_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_yaw_data_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_label_yaw_data_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_label_yaw_data_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_yaw_data_main_main_default.set_text_letter_space(2)
style_screen1_label_yaw_data_main_main_default.set_pad_left(0)
style_screen1_label_yaw_data_main_main_default.set_pad_right(0)
style_screen1_label_yaw_data_main_main_default.set_pad_top(0)
style_screen1_label_yaw_data_main_main_default.set_pad_bottom(0)

# add style for screen1_label_yaw_data
screen1_label_yaw_data.add_style(style_screen1_label_yaw_data_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_roll_data = lv.label(screen1_cont_info)
screen1_label_roll_data.set_pos(90,64)
screen1_label_roll_data.set_size(40,20)
screen1_label_roll_data.set_text("115C")
screen1_label_roll_data.set_long_mode(lv.label.LONG.WRAP)
screen1_label_roll_data.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_roll_data_main_main_default
style_screen1_label_roll_data_main_main_default = lv.style_t()
style_screen1_label_roll_data_main_main_default.init()
style_screen1_label_roll_data_main_main_default.set_radius(0)
style_screen1_label_roll_data_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_roll_data_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_roll_data_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_roll_data_main_main_default.set_bg_opa(0)
style_screen1_label_roll_data_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_roll_data_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_label_roll_data_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_label_roll_data_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_roll_data_main_main_default.set_text_letter_space(2)
style_screen1_label_roll_data_main_main_default.set_pad_left(0)
style_screen1_label_roll_data_main_main_default.set_pad_right(0)
style_screen1_label_roll_data_main_main_default.set_pad_top(0)
style_screen1_label_roll_data_main_main_default.set_pad_bottom(0)

# add style for screen1_label_roll_data
screen1_label_roll_data.add_style(style_screen1_label_roll_data_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_roll_name = lv.label(screen1_cont_info)
screen1_label_roll_name.set_pos(20,64)
screen1_label_roll_name.set_size(40,20)
screen1_label_roll_name.set_text("roll")
screen1_label_roll_name.set_long_mode(lv.label.LONG.WRAP)
screen1_label_roll_name.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_roll_name_main_main_default
style_screen1_label_roll_name_main_main_default = lv.style_t()
style_screen1_label_roll_name_main_main_default.init()
style_screen1_label_roll_name_main_main_default.set_radius(0)
style_screen1_label_roll_name_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_roll_name_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_roll_name_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_roll_name_main_main_default.set_bg_opa(0)
style_screen1_label_roll_name_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_roll_name_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_label_roll_name_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_label_roll_name_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_roll_name_main_main_default.set_text_letter_space(2)
style_screen1_label_roll_name_main_main_default.set_pad_left(0)
style_screen1_label_roll_name_main_main_default.set_pad_right(0)
style_screen1_label_roll_name_main_main_default.set_pad_top(0)
style_screen1_label_roll_name_main_main_default.set_pad_bottom(0)

# add style for screen1_label_roll_name
screen1_label_roll_name.add_style(style_screen1_label_roll_name_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_pitch_data = lv.label(screen1_cont_info)
screen1_label_pitch_data.set_pos(90,29)
screen1_label_pitch_data.set_size(40,20)
screen1_label_pitch_data.set_text("120C")
screen1_label_pitch_data.set_long_mode(lv.label.LONG.WRAP)
screen1_label_pitch_data.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_pitch_data_main_main_default
style_screen1_label_pitch_data_main_main_default = lv.style_t()
style_screen1_label_pitch_data_main_main_default.init()
style_screen1_label_pitch_data_main_main_default.set_radius(0)
style_screen1_label_pitch_data_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_pitch_data_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_pitch_data_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_pitch_data_main_main_default.set_bg_opa(0)
style_screen1_label_pitch_data_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_pitch_data_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_pitch_data_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_pitch_data_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_pitch_data_main_main_default.set_text_letter_space(2)
style_screen1_label_pitch_data_main_main_default.set_pad_left(0)
style_screen1_label_pitch_data_main_main_default.set_pad_right(0)
style_screen1_label_pitch_data_main_main_default.set_pad_top(0)
style_screen1_label_pitch_data_main_main_default.set_pad_bottom(0)

# add style for screen1_label_pitch_data
screen1_label_pitch_data.add_style(style_screen1_label_pitch_data_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_pitch_name = lv.label(screen1_cont_info)
screen1_label_pitch_name.set_pos(20,29)
screen1_label_pitch_name.set_size(40,20)
screen1_label_pitch_name.set_text("pitch")
screen1_label_pitch_name.set_long_mode(lv.label.LONG.WRAP)
screen1_label_pitch_name.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_pitch_name_main_main_default
style_screen1_label_pitch_name_main_main_default = lv.style_t()
style_screen1_label_pitch_name_main_main_default.init()
style_screen1_label_pitch_name_main_main_default.set_radius(0)
style_screen1_label_pitch_name_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen1_label_pitch_name_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_pitch_name_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_pitch_name_main_main_default.set_bg_opa(0)
style_screen1_label_pitch_name_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen1_label_pitch_name_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_pitch_name_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_pitch_name_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_pitch_name_main_main_default.set_text_letter_space(1)
style_screen1_label_pitch_name_main_main_default.set_pad_left(0)
style_screen1_label_pitch_name_main_main_default.set_pad_right(0)
style_screen1_label_pitch_name_main_main_default.set_pad_top(0)
style_screen1_label_pitch_name_main_main_default.set_pad_bottom(0)

# add style for screen1_label_pitch_name
screen1_label_pitch_name.add_style(style_screen1_label_pitch_name_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_pos_title = lv.label(screen1_cont_info)
screen1_label_pos_title.set_pos(55,1)
screen1_label_pos_title.set_size(41,19)
screen1_label_pos_title.set_text("POS")
screen1_label_pos_title.set_long_mode(lv.label.LONG.WRAP)
screen1_label_pos_title.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_pos_title_main_main_default
style_screen1_label_pos_title_main_main_default = lv.style_t()
style_screen1_label_pos_title_main_main_default.init()
style_screen1_label_pos_title_main_main_default.set_radius(0)
style_screen1_label_pos_title_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_pos_title_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_pos_title_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_pos_title_main_main_default.set_bg_opa(0)
style_screen1_label_pos_title_main_main_default.set_text_color(lv.color_make(0xfc,0xfc,0xfc))
try:
    style_screen1_label_pos_title_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen1_label_pos_title_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen1_label_pos_title_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_pos_title_main_main_default.set_text_letter_space(2)
style_screen1_label_pos_title_main_main_default.set_pad_left(0)
style_screen1_label_pos_title_main_main_default.set_pad_right(0)
style_screen1_label_pos_title_main_main_default.set_pad_top(0)
style_screen1_label_pos_title_main_main_default.set_pad_bottom(0)

# add style for screen1_label_pos_title
screen1_label_pos_title.add_style(style_screen1_label_pos_title_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen1_cont_info_main_main_default
style_screen1_cont_info_main_main_default = lv.style_t()
style_screen1_cont_info_main_main_default.init()
style_screen1_cont_info_main_main_default.set_radius(0)
style_screen1_cont_info_main_main_default.set_bg_color(lv.color_make(0x2f,0x36,0x3c))
style_screen1_cont_info_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_cont_info_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_cont_info_main_main_default.set_bg_opa(0)
style_screen1_cont_info_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_cont_info_main_main_default.set_border_width(0)
style_screen1_cont_info_main_main_default.set_border_opa(255)
style_screen1_cont_info_main_main_default.set_pad_left(0)
style_screen1_cont_info_main_main_default.set_pad_right(0)
style_screen1_cont_info_main_main_default.set_pad_top(0)
style_screen1_cont_info_main_main_default.set_pad_bottom(0)

# add style for screen1_cont_info
screen1_cont_info.add_style(style_screen1_cont_info_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_speed_name = lv.label(screen1)
screen1_label_speed_name.set_pos(22,217)
screen1_label_speed_name.set_size(79,20)
screen1_label_speed_name.set_text("Speed")
screen1_label_speed_name.set_long_mode(lv.label.LONG.WRAP)
screen1_label_speed_name.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_speed_name_main_main_default
style_screen1_label_speed_name_main_main_default = lv.style_t()
style_screen1_label_speed_name_main_main_default.init()
style_screen1_label_speed_name_main_main_default.set_radius(0)
style_screen1_label_speed_name_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_name_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_name_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_speed_name_main_main_default.set_bg_opa(0)
style_screen1_label_speed_name_main_main_default.set_text_color(lv.color_make(0xfd,0xec,0xec))
try:
    style_screen1_label_speed_name_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_label_speed_name_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_label_speed_name_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_speed_name_main_main_default.set_text_letter_space(1)
style_screen1_label_speed_name_main_main_default.set_pad_left(0)
style_screen1_label_speed_name_main_main_default.set_pad_right(0)
style_screen1_label_speed_name_main_main_default.set_pad_top(0)
style_screen1_label_speed_name_main_main_default.set_pad_bottom(0)

# add style for screen1_label_speed_name
screen1_label_speed_name.add_style(style_screen1_label_speed_name_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_speed_data = lv.label(screen1)
screen1_label_speed_data.set_pos(75,208)
screen1_label_speed_data.set_size(84,37)
screen1_label_speed_data.set_text("32")
screen1_label_speed_data.set_long_mode(lv.label.LONG.WRAP)
screen1_label_speed_data.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_speed_data_main_main_default
style_screen1_label_speed_data_main_main_default = lv.style_t()
style_screen1_label_speed_data_main_main_default.init()
style_screen1_label_speed_data_main_main_default.set_radius(0)
style_screen1_label_speed_data_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_data_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_data_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_speed_data_main_main_default.set_bg_opa(0)
style_screen1_label_speed_data_main_main_default.set_text_color(lv.color_make(0xea,0xe0,0x57))
try:
    style_screen1_label_speed_data_main_main_default.set_text_font(lv.font_simsun_33)
except AttributeError:
    try:
        style_screen1_label_speed_data_main_main_default.set_text_font(lv.font_montserrat_33)
    except AttributeError:
        style_screen1_label_speed_data_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_speed_data_main_main_default.set_text_letter_space(1)
style_screen1_label_speed_data_main_main_default.set_pad_left(0)
style_screen1_label_speed_data_main_main_default.set_pad_right(0)
style_screen1_label_speed_data_main_main_default.set_pad_top(0)
style_screen1_label_speed_data_main_main_default.set_pad_bottom(0)

# add style for screen1_label_speed_data
screen1_label_speed_data.add_style(style_screen1_label_speed_data_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen1_label_speed_unit = lv.label(screen1)
screen1_label_speed_unit.set_pos(130,218)
screen1_label_speed_unit.set_size(79,20)
screen1_label_speed_unit.set_text("km/h")
screen1_label_speed_unit.set_long_mode(lv.label.LONG.WRAP)
screen1_label_speed_unit.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen1_label_speed_unit_main_main_default
style_screen1_label_speed_unit_main_main_default = lv.style_t()
style_screen1_label_speed_unit_main_main_default.init()
style_screen1_label_speed_unit_main_main_default.set_radius(0)
style_screen1_label_speed_unit_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_unit_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen1_label_speed_unit_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen1_label_speed_unit_main_main_default.set_bg_opa(0)
style_screen1_label_speed_unit_main_main_default.set_text_color(lv.color_make(0xfd,0xec,0xec))
try:
    style_screen1_label_speed_unit_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen1_label_speed_unit_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen1_label_speed_unit_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen1_label_speed_unit_main_main_default.set_text_letter_space(1)
style_screen1_label_speed_unit_main_main_default.set_pad_left(0)
style_screen1_label_speed_unit_main_main_default.set_pad_right(0)
style_screen1_label_speed_unit_main_main_default.set_pad_top(0)
style_screen1_label_speed_unit_main_main_default.set_pad_bottom(0)

# add style for screen1_label_speed_unit
screen1_label_speed_unit.add_style(style_screen1_label_speed_unit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen2 = lv.obj()
# create style style_screen2_main_main_default
style_screen2_main_main_default = lv.style_t()
style_screen2_main_main_default.init()
style_screen2_main_main_default.set_bg_color(lv.color_make(0x40,0x35,0x35))
style_screen2_main_main_default.set_bg_opa(248)

# add style for screen2
screen2.add_style(style_screen2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen2_img_previous = lv.img(screen2)
screen2_img_previous.set_pos(240,235)
screen2_img_previous.set_size(24,25)
screen2_img_previous.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\NXP\\GUI-Guider-Projects\\SmartTrack\\generated\\mp1357206209.png','rb') as f:
        screen2_img_previous_img_data = f.read()
except:
    print('Could not open C:\\NXP\\GUI-Guider-Projects\\SmartTrack\\generated\\mp1357206209.png')
    sys.exit()

screen2_img_previous_img = lv.img_dsc_t({
  'data_size': len(screen2_img_previous_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen2_img_previous_img_data
})

screen2_img_previous.set_src(screen2_img_previous_img)
screen2_img_previous.set_pivot(0,0)
screen2_img_previous.set_angle(0)
# create style style_screen2_img_previous_main_main_default
style_screen2_img_previous_main_main_default = lv.style_t()
style_screen2_img_previous_main_main_default.init()
style_screen2_img_previous_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen2_img_previous_main_main_default.set_img_recolor_opa(0)
style_screen2_img_previous_main_main_default.set_img_opa(255)

# add style for screen2_img_previous
screen2_img_previous.add_style(style_screen2_img_previous_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen2_btn_previous = lv.btn(screen2)
screen2_btn_previous.set_pos(240,235)
screen2_btn_previous.set_size(22,22)
# create style style_screen2_btn_previous_main_main_default
style_screen2_btn_previous_main_main_default = lv.style_t()
style_screen2_btn_previous_main_main_default.init()
style_screen2_btn_previous_main_main_default.set_radius(50)
style_screen2_btn_previous_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen2_btn_previous_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen2_btn_previous_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen2_btn_previous_main_main_default.set_bg_opa(0)
style_screen2_btn_previous_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_screen2_btn_previous_main_main_default.set_shadow_opa(0)
style_screen2_btn_previous_main_main_default.set_border_color(lv.color_make(0x01,0xa2,0xb1))
style_screen2_btn_previous_main_main_default.set_border_width(2)
style_screen2_btn_previous_main_main_default.set_border_opa(11)

# add style for screen2_btn_previous
screen2_btn_previous.add_style(style_screen2_btn_previous_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def screen2_btn_previous_clicked_1_event_cb(e,screen1):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(screen1, lv.SCR_LOAD_ANIM.OVER_RIGHT, 5, 0, False)
screen2_btn_previous.add_event_cb(lambda e: screen2_btn_previous_clicked_1_event_cb(e,screen1), lv.EVENT.CLICKED, None)


def screen2_img_previous_clicked_1_event_cb(e,screen2):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(screen2, lv.SCR_LOAD_ANIM.OVER_LEFT, 5, 0, False)
screen2_img_previous.add_event_cb(lambda e: screen2_img_previous_clicked_1_event_cb(e,screen2), lv.EVENT.CLICKED, None)


def screen1_btn_next_clicked_1_event_cb(e,screen2):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(screen2, lv.SCR_LOAD_ANIM.OVER_LEFT, 5, 0, False)
screen1_btn_next.add_event_cb(lambda e: screen1_btn_next_clicked_1_event_cb(e,screen2), lv.EVENT.CLICKED, None)



# content from custom.py

# Load the default screen
lv.scr_load(screen1)

while SDL.check():
    time.sleep_ms(5)
