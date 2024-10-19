lv_color_t colorg = lv_color_make(0, 255, 0);

    /*Create a button and use the new styles*/
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    /* Remove the styles coming from the theme
     * Note that size and position are also stored as style properties
     * so lv_obj_remove_style_all will remove the set size and position too */
 //   lv_obj_remove_style_all(btn);
    lv_obj_set_pos(btn, 0, 10);
    lv_obj_set_size(btn, 90, 25);
	lv_color_t color = lv_color_make(255, 0, 0);  // Red color
lv_obj_set_style_bg_color(btn, color, LV_PART_MAIN);

    /*Add a label to the button*/
    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "RED_RIGHT");
    lv_obj_center(label);

    /*Create another button and use the red style too*/
    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    //lv_obj_remove_style_all(btn2);                      /*Remove the styles coming from the theme*/
    lv_obj_set_pos(btn2, 0, 180);
    lv_obj_set_size(btn2, 90, 25);
	//lv_color_t color = lv_color_make(255, 0, 0);  // Red color
lv_obj_set_style_bg_color(btn2, color, LV_PART_MAIN);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "RED_LEFT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(btn2, btn_event_cb2, LV_EVENT_ALL, NULL);

    lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
    //lv_obj_remove_style_all(btn2);                      /*Remove the styles coming from the theme*/
    lv_obj_set_pos(btn3, 390, 10);
    lv_obj_set_size(btn3, 90, 25);
	lv_color_t colorb = lv_color_make(0, 0, 255);  // Red color
lv_obj_set_style_bg_color(btn3, colorb, LV_PART_MAIN);

    label = lv_label_create(btn3);
    lv_label_set_text(label, "BLUE_LEFT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn3, btn_event_cb3, LV_EVENT_ALL, NULL);



	    lv_obj_t * btn4 = lv_btn_create(lv_scr_act());
    //lv_obj_remove_style_all(btn2);                      /*Remove the styles coming from the theme*/
    lv_obj_set_pos(btn4, 390, 180);
    lv_obj_set_size(btn4, 90, 25);
	//lv_color_t colorb = lv_color_make(0, 0, 255);  // Red color
lv_obj_set_style_bg_color(btn4, colorb, LV_PART_MAIN);

    label = lv_label_create(btn4);
    lv_label_set_text(label, "BLUE_RIGHT");
    lv_obj_center(label);
	lv_obj_add_event_cb(btn4, btn_event_cb4, LV_EVENT_ALL, NULL);
