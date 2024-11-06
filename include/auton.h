ASSET (blue_right_txt);
ASSET (blue_left_txt);
ASSET (red_right_txt);
ASSET (red_left_txt);
lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
lv_obj_t * btn = lv_btn_create(lv_scr_act());
lv_obj_t * btn4 = lv_btn_create(lv_scr_act());
int sel = 0;
int delb();
void lv_example_img_1(void)
{
    LV_IMG_DECLARE(fieldr);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &fieldr);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);
  //  lv_obj_set_size(img1, 200, 200);

}


static void btn_event_cb(lv_event_t * e)
{
	lv_color_t colorg = lv_color_make(0, 255, 0);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
    lv_obj_t * label = lv_obj_get_child(btn, 0);
    lv_label_set_text_fmt(label, "Selected");
	sel = 1;
	lv_obj_set_style_bg_color(btn, colorg, LV_PART_MAIN);
    LV_IMG_DECLARE(robot);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &robot);
    lv_obj_set_pos(img1,137.5,70);
    lv_img_set_angle(img1, 1800);
    lv_obj_add_state(btn3, LV_STATE_DISABLED);
    lv_obj_add_state(btn2, LV_STATE_DISABLED);
    lv_obj_add_state(btn4, LV_STATE_DISABLED);
    }
}
static void btn_event_cb2(lv_event_t * e)
{

    lv_event_code_t code2 = lv_event_get_code(e);
	lv_color_t colorg = lv_color_make(0, 255, 0);
    lv_obj_t * btn2 = lv_event_get_target(e);
    if(code2 == LV_EVENT_CLICKED) {
	sel = 2;
    lv_obj_t * label2 = lv_obj_get_child(btn2, 0);
    lv_label_set_text_fmt(label2, "Selected");
	lv_obj_set_style_bg_color(btn2, colorg, LV_PART_MAIN);
    seli = 1;
    LV_IMG_DECLARE(robot);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &robot);
    lv_obj_set_pos(img1,137.5,145);
    lv_img_set_angle(img1, 1800);
    lv_obj_add_state(btn, LV_STATE_DISABLED);
    lv_obj_add_state(btn3, LV_STATE_DISABLED);
    lv_obj_add_state(btn4, LV_STATE_DISABLED);
    }
}
static void btn_event_cb3(lv_event_t * e)
{
    lv_event_code_t code3 = lv_event_get_code(e);
	lv_color_t colorg = lv_color_make(0, 255, 0);
    lv_obj_t * btn3 = lv_event_get_target(e);
    if(code3 == LV_EVENT_CLICKED) {
	sel = 3;
    lv_obj_t * label3 = lv_obj_get_child(btn3, 0);
    lv_label_set_text_fmt(label3, "Selected");
	lv_obj_set_style_bg_color(btn3, colorg, LV_PART_MAIN);
    LV_IMG_DECLARE(robot);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &robot);
    lv_obj_set_pos(img1,320,75);
    lv_obj_add_state(btn, LV_STATE_DISABLED);
    lv_obj_add_state(btn2, LV_STATE_DISABLED);
    lv_obj_add_state(btn4, LV_STATE_DISABLED);
    }
}
static void btn_event_cb4(lv_event_t * e)
{
    lv_event_code_t code4 = lv_event_get_code(e);
	lv_color_t colorg = lv_color_make(0, 255, 0);
    lv_obj_t * btn4 = lv_event_get_target(e);
    if(code4 == LV_EVENT_CLICKED) {
	sel = 4;
    lv_obj_t * label4 = lv_obj_get_child(btn4, 0);
    lv_label_set_text_fmt(label4, "Selected");
	lv_obj_set_style_bg_color(btn4, colorg, LV_PART_MAIN);
    LV_IMG_DECLARE(robot);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &robot);
    lv_obj_set_pos(img1,320,145);
    lv_obj_add_state(btn, LV_STATE_DISABLED);
    lv_obj_add_state(btn2, LV_STATE_DISABLED);
    lv_obj_add_state(btn3, LV_STATE_DISABLED);
    }
}
/**
 * Create styles from scratch for buttons.
 */
void lv_example_get_started_3(void)
{
lv_color_t colorg = lv_color_make(0, 255, 0);
    lv_obj_set_pos(btn, 0, 40);
    lv_obj_set_size(btn, 90, 25);
	lv_color_t color = lv_color_make(255, 0, 0);  // Red color
lv_obj_set_style_bg_color(btn, color, LV_PART_MAIN);
    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "RED_RIGHT");
    lv_obj_center(label);
    lv_obj_set_pos(btn2, 0, 180);
    lv_obj_set_size(btn2, 90, 25);
lv_obj_set_style_bg_color(btn2, color, LV_PART_MAIN);
    label = lv_label_create(btn2);
    lv_label_set_text(label, "RED_LEFT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(btn2, btn_event_cb2, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(btn3, 390, 40);
    lv_obj_set_size(btn3, 90, 25);
	lv_color_t colorb = lv_color_make(0, 0, 255);
lv_obj_set_style_bg_color(btn3, colorb, LV_PART_MAIN);
    label = lv_label_create(btn3);
    lv_label_set_text(label, "BLUE_LEFT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn3, btn_event_cb3, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(btn4, 390, 180);
    lv_obj_set_size(btn4, 90, 25);
lv_obj_set_style_bg_color(btn4, colorb, LV_PART_MAIN);
    label = lv_label_create(btn4);
    lv_label_set_text(label, "BLUE_RIGHT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn4, btn_event_cb4, LV_EVENT_ALL, NULL);

}


/**
 * Create a button with a label and react on click event.
 */


void auton(){
//int auton = 1;
int d;
sel =4;
pneumatics_up();
if (sel == 1) {
	chassis.setPose(-58, -47,90);
	chassis.follow(red_right_txt,38,1000,false,false);
} else if (sel == 2)
{
	chassis.setPose(58,47,0);
	chassis.follow(blue_right_txt,38,1000,false,false);
} else if (sel == 3) {
	chassis.setPose(58,-46,0);
	chassis.follow(blue_left_txt,38,1000,false,false);
} else if (sel == 4) {
	chassis.setPose(-58,46,0);
	chassis.follow(red_left_txt,38,1000,false,false);
}
//pros::delay(50);
//pneumatics_down();
while (!clamp.get()<= 25){
}
pneumatics_down();
pros::delay(2000);
intakeon();
//lv_example_get_started_3();

//lv_example_get_started_22();
	//	lv_obj_del(btn2);

}