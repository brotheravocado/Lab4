#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *password = "hidden";
GtkWidget *plusbutton;
GtkWidget *minusbutton, *press_one, *press_two,
    *press_three, *press_five, *press_four, *press_seven,
    *press_six, *press_eight, *press_nine, *press_zero;
GtkWidget *dividebutton, *multiplybutton, *total, *clear, *press_one_del;
GtkWidget *user_entry;

void button_clicked(GtkWidget *button, gpointer data);
void input_completed(GtkWidget *entry, gpointer data);
void quit(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

void print_active(char *name, GtkButton
                                  *button)
{
    gboolean active =
        gtk_toggle_button_get_active(button);
    printf("%s 는 현재 %s 상태입니다.\n", name, active ? "활성" : "비활성");
}
void result()
{
    sprintf("result is %d", result);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    
    GtkWidget *message_label;
    GtkWidget *user_hbox;
    GtkWidget *box;
    GtkWidget *user_label;
    GtkWidget *vbox, *v1box, *v2box, *v3box, *hbox, *v4box, *v5box;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "calculator");
    gtk_window_set_default_size(GTK_WINDOW(window),
                                300, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);
    gtk_container_add(GTK_CONTAINER(v4box), user_entry);
    user_label = gtk_label_new("Input");
        user_entry = malloc(sizeof(GtkWidget));
    memset(user_entry, 0, sizeof(GtkWidget));
    user_entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(user_entry), FALSE);
    gtk_widget_set_direction(user_entry, GTK_TEXT_DIR_RTL);    
    gtk_entry_set_text(GTK_ENTRY(user_entry), "0");
    gtk_widget_show(user_entry);
    user_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(user_hbox), user_label,
                       TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(user_hbox), user_entry,
                       TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), user_hbox, FALSE,
                       FALSE, 10);
   
    /*user_entry = malloc(sizeof(GtkWidget));
    memset(user_entry, 0, sizeof(GtkWidget));
    user_entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(user_entry), FALSE);
    gtk_entry_set_text(GTK_ENTRY(user_entry), "0");    
    gtk_widget_set_direction(user_entry, GTK_TEXT_DIR_RTL);*/

    //gtk_widget_show(user_entry);
    
    /*g_signal_connect(user_entry, "clicked",
                     input_completed,
                     message_label);
    user_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(user_hbox), user_label,
                       TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(user_hbox), user_entry,
                       TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), user_hbox, FALSE,
                       FALSE, 10);
    gtk_box_pack_start(GTK_BOX(box), message_label,
                       FALSE, FALSE, 10);*/

    plusbutton = gtk_button_new_with_label("+");
    minusbutton = gtk_button_new_with_label("-");
    dividebutton = gtk_button_new_with_label("/");
    multiplybutton = gtk_button_new_with_label("*");
    total = gtk_button_new_with_label("=");
    clear = gtk_button_new_with_label("del");
    press_one = gtk_button_new_with_label("1");
    press_two = gtk_button_new_with_label("2");
    press_three = gtk_button_new_with_label("3");
    press_four = gtk_button_new_with_label("4");
    press_five = gtk_button_new_with_label("5");
    press_six = gtk_button_new_with_label("6");
    press_seven = gtk_button_new_with_label("7");
    press_eight = gtk_button_new_with_label("8");
    press_nine = gtk_button_new_with_label("9");
    press_zero = gtk_button_new_with_label("0");
    press_one_del = gtk_button_new_with_label("<-");
    g_signal_connect(press_zero, "clicked", G_CALLBACK(button_clicked), (gpointer)'0');
    
    g_signal_connect(press_one, "clicked", G_CALLBACK(button_clicked), (gpointer)'1');
    g_signal_connect(press_two, "clicked", G_CALLBACK(button_clicked), (gpointer)'2');
    g_signal_connect(press_three, "clicked", G_CALLBACK(button_clicked), (gpointer)'3');
    g_signal_connect(press_four, "clicked", G_CALLBACK(button_clicked), (gpointer)'4');
    g_signal_connect(press_five, "clicked", G_CALLBACK(button_clicked), (gpointer)'5');
    g_signal_connect(press_six, "clicked", G_CALLBACK(button_clicked), (gpointer)'6');
    g_signal_connect(press_seven, "clicked", G_CALLBACK(button_clicked), (gpointer)'7');
    g_signal_connect(press_eight, "clicked", G_CALLBACK(button_clicked), (gpointer)'8');
    g_signal_connect(press_nine, "clicked", G_CALLBACK(button_clicked), (gpointer)'9');
    g_signal_connect(plusbutton, "clicked", G_CALLBACK(button_clicked), (gpointer)'+');
    g_signal_connect(minusbutton, "clicked", G_CALLBACK(button_clicked), (gpointer)'-');
    g_signal_connect(dividebutton, "clicked", G_CALLBACK(button_clicked), (gpointer)'*');
    g_signal_connect(multiplybutton, "clicked", G_CALLBACK(button_clicked), (gpointer)'*');
    g_signal_connect(total, "clicked", G_CALLBACK(button_clicked), (gpointer)'=');
    g_signal_connect(clear, "clicked", G_CALLBACK(button_clicked), (gpointer)'d');
    g_signal_connect(press_one_del, "clicked", G_CALLBACK(button_clicked), (gpointer)'o');

    hbox = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL, 5);
    vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL,
                       10);
    v1box = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL,
                        5);
    v2box = gtk_vbox_new(GTK_ORIENTATION_VERTICAL,
                        5);
    v3box = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL,
                        5);
    v4box = gtk_vbox_new(GTK_ORIENTATION_VERTICAL,
                        10);
    v5box = gtk_hbox_new(GTK_ORIENTATION_HORIZONTAL,
                        5);
    gtk_box_pack_start(GTK_BOX(hbox), press_seven, TRUE,
                       FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), press_eight, TRUE,
                       FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), press_nine, TRUE,
                       FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), plusbutton, TRUE,
                       FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE,
                       FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), v1box, FALSE,
                       FALSE, 15);
    gtk_box_pack_start(GTK_BOX(v1box), press_four, FALSE,
                       FALSE, 17);
    gtk_box_pack_start(GTK_BOX(v1box), press_five, FALSE,
                       FALSE, 17);
    gtk_box_pack_start(GTK_BOX(v1box), press_six, FALSE,
                       FALSE, 17);
    gtk_box_pack_start(GTK_BOX(v1box), minusbutton, FALSE,
                       FALSE, 17);

    gtk_box_pack_start(GTK_BOX(v2box), v1box, FALSE,
                       FALSE, 10);
    gtk_box_pack_start(GTK_BOX(v2box), v3box, FALSE,
                       FALSE, 10);
    gtk_box_pack_start(GTK_BOX(v3box), press_one, TRUE,
                       FALSE, 5);
    gtk_box_pack_start(GTK_BOX(v3box), press_two, TRUE,
                       FALSE, 5);
    gtk_box_pack_start(GTK_BOX(v3box), press_three, TRUE,
                       FALSE, 5);
    gtk_box_pack_start(GTK_BOX(v3box), multiplybutton, TRUE,
                       FALSE, 5);
    gtk_box_pack_start(GTK_BOX(v4box), v3box, FALSE,
                       FALSE, 10);
    gtk_box_pack_start(GTK_BOX(v4box), v5box, FALSE,
                       FALSE, 10);
    gtk_box_pack_start(GTK_BOX(v5box), press_one_del, TRUE,
                       FALSE, 7);
    gtk_box_pack_start(GTK_BOX(v5box), press_zero, TRUE,
                       FALSE, 7);
    gtk_box_pack_start(GTK_BOX(v5box), clear, TRUE,
                       FALSE, 7);
    gtk_box_pack_start(GTK_BOX(v5box), total, TRUE,
                       FALSE, 7);


    
    gtk_container_add(GTK_CONTAINER(v2box), v4box);
    gtk_container_add(GTK_CONTAINER(vbox), v2box);
    gtk_container_add(GTK_CONTAINER(box), vbox);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
int get_entry_value()
{
    const char* entry_string = gtk_entry_get_text(GTK_ENTRY(user_entry));
    int entry_int = *entry_string - '0';
    entry_string++;
    while(*entry_string != '\0')
    {
        entry_int = entry_int * 10 + (*entry_string - '0');
        entry_string++;
    }
    return entry_int;
}

void button_clicked(GtkWidget *button, gpointer data)
{
    /*print_active("+",GTK_BUTTON(plusbutton));
    print_active("-",GTK_BUTTON(minusbutton));
    print_active("/",GTK_BUTTON(dividebutton));
    print_active("*",GTK_BUTTON(multiplybutton));

    printf(" ");*/
    char* button_num = (char*)data;
    char input = (char)data;
    g_print("%c ", input);
   // gtk_entry_set_text(GTK_ENTRY(user_entry), button_num);
    //input_completed(user_entry,data);

    int entry_int = get_entry_value();
    //int entry_int = gtk_editable_get_position(user_entry);;
    //g_print("%d ", entry_int);
    //gtk_editable_get_position(user_entry);
    if(entry_int == 0)
        gtk_entry_set_text(GTK_ENTRY(user_entry), button_num);
    
    else    
        gtk_editable_insert_text(GTK_ENTRY(user_entry), button_num,10,entry_int+1);
     //   gtk_entry_append_text(GTK_ENTRY(user_entry), button_num);
    
        //gtk_entry_append_text(GTK_ENTRY(user_entry), button_num);
    
}
int delete_event(GtkWidget *window, GdkEvent *event, gpointer data)
{
    gtk_main_quit();
    return FALSE;
}


void create_num_button(GtkWidget *box, GtkWidget *button, char* button_num)
{
    button = gtk_button_new_with_label(button_num);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(click_number), (gpointer)button_num);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
    gtk_widget_show(button);
}

void click_number(GtkWidget *widget, gpointer data)
{
    if(need_clear)
    {
        gtk_entry_set_text(GTK_ENTRY(entry), "0");
        need_clear = 0;
    }
    char* button_num = (char*)data;
    int entry_int = get_entry_value();
    if(entry_int == 0)
        gtk_entry_set_text(GTK_ENTRY(entry), button_num);
    else
        gtk_entry_append_text(GTK_ENTRY(entry), button_num);
    has_press_number = 1;
    has_press_symbol = 0;
}



void clear(GtkWidget *widget, gpointer data)
{
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
    first_number = -1;
    second_number = -1;
    has_press_number = 0;
    has_press_symbol = 0;
    need_clear = 0;
    symbol = '+';
}

void click_symbol(GtkWidget *widget, gpointer data)
{
    if(has_press_symbol == 0)
    {
        if(second_number == -1 && first_number == -1 && has_press_number == 0)
        {}
        else if(second_number == -1 && first_number == -1 && has_press_number == 1)
        {
            first_number = get_entry_value();
            has_press_number = 0;
        }
        else if(second_number == -1 && first_number != -1 && has_press_number == 1)
        {
            second_number = get_entry_value();
            first_number = calculator(symbol);
            second_number = -1;
            char* result_string = malloc(sizeof(char) * 10);
            memset(result_string, 0, 10);
            sprintf(result_string, "%d", first_number);
            gtk_entry_set_text(GTK_ENTRY(entry), result_string);
        }
        symbol = (char)data;
        need_clear = 1;
        has_press_symbol = 1;
    }
}

void submit(GtkWidget *widget, gpointer data)
{
    second_number = get_entry_value();
    int result = calculator(symbol);
    second_number = -1;
    has_press_symbol = 0;
    has_press_number = 0;
    first_number = result;
    char* result_string = malloc(sizeof(char) * 10);
    memset(result_string, 0, 10);
    sprintf(result_string, "%d", result);
    gtk_entry_set_text(GTK_ENTRY(entry), result_string);
}

int calculator(char symbol)
{
    int result;
    switch(symbol)
    {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '*':
            result = first_number * second_number;
            break;
        case '/':
            result = first_number / second_number;
            break;
        default:
            printf("error\n");
            return;
    }
    return result;
}

