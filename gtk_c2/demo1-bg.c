/*************************************************************************
> FileName: demo1-bg.c
> Author  : DingJing
> Mail    : dingjing@live.cn
> Created Time: 2019年11月13日 星期三 15时47分33秒
 ************************************************************************/

#include <stdio.h>
#include <gtk/gtk.h>
 
int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *entry;
    PangoFontDescription *desc;
    static GdkColor red = {0, 0xffff, 0, 0};
    static GdkColor green = {0, 0, 0xffff, 0};
    static GdkColor blue = {0, 0, 0, 0xffff};
    static GdkColor yellow = {0, 0xffff, 0xffff, 0};
    static GdkColor cyan = {0, 0, 0xffff, 0xffff};
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(window), "设定控件的样式");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
 
    desc = pango_font_description_from_string("Simhei 24");
    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    button = gtk_button_new_with_label("绿色的按钮");
    gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &green);
    gtk_widget_modify_bg(button, GTK_STATE_ACTIVE, &cyan);
    gtk_widget_modify_bg(button, GTK_STATE_PRELIGHT, &red);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 8);
 
    button = gtk_button_new_with_label("红色字的按钮");
    gtk_widget_modify_fg(GTK_BIN(button)->child, GTK_STATE_NORMAL, &red);
    gtk_widget_modify_fg(GTK_BIN(button)->child, GTK_STATE_ACTIVE, &blue);
    gtk_widget_modify_fg(GTK_BIN(button)->child, GTK_STATE_PRELIGHT, &green);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 8);
    label = gtk_label_new("蓝色的标签文字\n主要是改变了前景颜色");
    gtk_widget_modify_fg(label, GTK_STATE_NORMAL, &blue);
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 8);
 
    desc = pango_font_description_from_string("Simsun 24");
    entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "红色的输入文字");
    gtk_widget_modify_font(entry, desc);
    gtk_widget_modify_text(entry, GTK_STATE_NORMAL, &red);
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 8);
    entry = gtk_entry_new();
    gtk_widget_modify_font(entry, desc);
    gtk_entry_set_text(GTK_ENTRY(entry), "绿色的背景");
    gtk_widget_modify_base(entry, GTK_STATE_NORMAL, &green);
    //gtk_widget_modify_text(entry, GTK_STATE_NORMAL, &red);
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 8);
 
    gtk_widget_show_all(window);
    gtk_main();
    return TRUE;
}
