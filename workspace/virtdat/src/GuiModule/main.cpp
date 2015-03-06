#include <gtk/gtk.h>
#include <gtkmm/button.h>
#include <vector>
#include <string>
#include "../CommandAndControllModule/CommandAndControll.h"
CommandAndControll* comAndcontrol;
std::vector<GtkImage*> tables;
std::vector<bool> tablesMov;

GtkWidget *label;
GtkWindow *windowLabel;
GtkWidget *window;
GtkWidget *window2;
GtkWidget *fixed;
GtkButton *button;
GtkWidget *frame;
bool isMouse1;
bool labelMov;
int sx,sy;

char buf[20];
static gboolean delete_event( GtkWidget *widget, GdkEvent  *event, gpointer   data ) {
    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete_event". */

    return false;
}

static gboolean button_press_event( GtkWidget *widget, GdkEventButton *event , gpointer   user_data) {
	if (event->button == 1 ) printf("but down  %i , %i\n", (int)event->x, (int)event->y);
	sx=(int)event->x;
	sy=(int)event->y;
	GdkModifierType state;
	int x, y;
	GdkWindow* win = GDK_WINDOW (window);
	//gdk_window_get_device_position(win, event->device,&x, &y, &state);
	gtk_fixed_move( (GtkFixed*)fixed,(GtkWidget*)widget, x, y);
	return false;
}
gboolean on_button_released (GtkWidget* widget,
  GdkEventButton * event, GdkWindowEdge edge)
{
	printf("released");

	for(int i =0; i< tablesMov.size();++i){
		tablesMov[i] = false;
	}
  isMouse1 =  false;
  labelMov = false;
  return FALSE;
}
gboolean on_button_press (GtkWidget* widget,
  GdkEventButton * event, GdkWindowEdge edge)
{
  if (event->type == GDK_BUTTON_PRESS)
  {
    if (event->button == 1) {

    	isMouse1 =  true;
    }
  }else if(event->type == GDK_BUTTON_RELEASE){
		printf("released");
	  isMouse1 =  false;
  }

  return FALSE;
}
static gboolean
motion_notify_event( GtkWidget *widget, GdkEventMotion *event ) {

	int x, y;
	GdkModifierType state;
	printf("move down  %i , %i\n", (int)event->x, (int)event->y);
	//GdkWindow* win = GDK_WINDOW (window);
	//gdk_window_get_device_position(win, event->device,&x, &y, &state);
	//gtk_fixed_move( (GtkFixed*)fixed,(GtkWidget*)widget, (int)event->x, (int)event->y );
	gint wx, wy;
	int i = 0;
	for(std::vector<GtkImage*>::iterator it = tables.begin();
			it != tables.end(); ++it,i++){
	gtk_widget_translate_coordinates(GTK_WIDGET((*it)), gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0, 0, &wx, &wy);
	if(tablesMov[i] == true){
		gtk_fixed_move( (GtkFixed*)fixed,(GtkWidget*)GTK_WIDGET((*it)), ((int)event->x), ((int)event->y));
	}
	}
	i = 0;
	for(std::vector<GtkImage*>::iterator it = tables.begin();
			it != tables.end(); ++it,i++){
	gtk_widget_translate_coordinates(GTK_WIDGET((*it)), gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0, 0, &wx, &wy);
	if(isMouse1 && ((int)event->y+50> wy &&(int)event->y-50<wy)&&((int)event->x+50> wx &&(int)event->x-50<wx)){
		tablesMov[i] = true;
	}
	}

	if(labelMov){
	//gtk_fixed_move( (GtkFixed*)fixed,(GtkWidget*)label, ((int)event->x)-100, ((int)event->y)-575);
	}
	if(isMouse1 && ((int)event->y+50> wy &&(int)event->y-50<wy)&&((int)event->x+50> wx &&(int)event->x-50<wx)){
	labelMov = true;
	}
	if (state & GDK_BUTTON1_MASK) {
		printf(" %i , %i \n", x-sx, y-sy);

		//gtk_fixed_move( (GtkFixed*)fixed,(GtkWidget*)label, x-sx, y-sy );

	}

	return TRUE;
}


void configure_callback(GtkWidget * widget, GtkWindow * window)
{
    gtk_widget_hide (GTK_WIDGET (window));
    gtk_window_set_position (GTK_WINDOW (window),  GTK_WIN_POS_MOUSE);
    gtk_widget_show_all (GTK_WIDGET (window));
	  sprintf(buf, "virtual tables: %d", 2);
	  gtk_label_set_text(GTK_LABEL(label), buf);
}
void createVirtualTable(GtkWidget *widget, gpointer label){
	std::vector<std::VirtColum> columns;
	std::VirtColum column1("column1" ,std::TYPE::TEXT,false, false);
	std::VirtColum column2("column2" ,std::TYPE::BOOLEAN,true, false);
	std::VirtColum column3("column3" ,std::TYPE::BLOB,false, true);
	std::VirtColum column4("column4" ,std::TYPE::INTEGER,true, true);
	std::VirtColum column5("column5" ,std::TYPE::TEXT,false, true);
	columns.push_back(column1);
	columns.push_back(column2);
	columns.push_back(column3);
	columns.push_back(column4);
	columns.push_back(column5);

	comAndcontrol->createTable(columns);
	GtkImage *img = GTK_IMAGE(gtk_image_new_from_file("virtTable.png"));
	gtk_widget_set_size_request(GTK_WIDGET(img),50, 50);
	//gtk_fixed_put( (GtkFixed*)fixed,GTK_WIDGET(img),0,0 );
	tables.push_back(img);
	gtk_fixed_put( (GtkFixed*)fixed,GTK_WIDGET(img),500, 120);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(img), 500, 120);
	tablesMov.push_back(false);
	printf("---------------------------");
	  gtk_widget_show_all(window);

	gtk_main();
}
int main(int argc, char *argv[]) {



	comAndcontrol = new CommandAndControll();

	gtk_init(&argc, NULL);
	label = gtk_label_new("virTables");
	isMouse1 = false;
	labelMov = false;
	  frame = gtk_fixed_new();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	fixed=gtk_fixed_new();
	gtk_container_add((GtkContainer*)window,(GtkWidget*)fixed);
	gtk_fixed_put( (GtkFixed*)fixed,label,0,0 );
	GtkWidget *img =gtk_image_new_from_file("virtTable.png");
	button = GTK_BUTTON(gtk_button_new());
	gtk_widget_set_size_request(window, 2000, 1000);
	gtk_widget_set_size_request(GTK_WIDGET(button), 50, 50);
	gtk_widget_set_size_request(label,50, 50);
	gtk_fixed_put( (GtkFixed*)fixed,GTK_WIDGET(button),150,150 );
	gtk_widget_set_margin_left(label, 100);
	gtk_widget_set_margin_right(label, 100);
	gtk_widget_set_margin_top(label, 550);
	gtk_widget_set_margin_bottom(label, 300);

	gtk_button_set_image(button,gtk_image_new_from_file("virtTable.png"));
	gtk_widget_set_margin_left(GTK_WIDGET(button), 100);
	gtk_widget_set_margin_right(GTK_WIDGET(button), 100);
	gtk_widget_set_margin_top(GTK_WIDGET(button), 850);
	gtk_widget_set_margin_bottom(GTK_WIDGET(button), 100);
	gtk_widget_queue_resize(GTK_WIDGET(button));
	g_signal_connect(G_OBJECT(window), "button-press-event",
	    G_CALLBACK(on_button_press), NULL);
	g_signal_connect(G_OBJECT(window), "button-release-event",
	    G_CALLBACK(on_button_released), NULL);
	//g_signal_connect (button, "button_press_event",G_CALLBACK (button_press_event), NULL);
	g_signal_connect (window, "motion-notify-event",G_CALLBACK (motion_notify_event), NULL);

//	gtk_drag_source_set(window,
//	                    GDK_BUTTON1_MASK,
//	                    queuelike_targets,
//	                    sizeof queuelike_targets / sizeof *queuelike_targets,
//	                    GDK_ACTION_MOVE);
//	gtk_drag_dest_set(label,
//			GtkDestDefaults::GTK_DEST_DEFAULT_ALL,
//	                  queuelike_targets,
//	                  sizeof queuelike_targets / sizeof *queuelike_targets,
//	 GDK_ACTION_MOVE);
	gtk_fixed_put( (GtkFixed*)fixed,img,150,150 );
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(button), 50, 80);
	gtk_fixed_put(GTK_FIXED(frame), label, 100, 80);
	gtk_fixed_put(GTK_FIXED(frame), img, 500, 120);
	gtk_container_add(GTK_CONTAINER(window), img);
	gtk_widget_set_events(window, GDK_EXPOSURE_MASK
				 | GDK_LEAVE_NOTIFY_MASK
				 | GDK_BUTTON_PRESS_MASK
				 | GDK_BUTTON_RELEASE_MASK
				 | GDK_POINTER_MOTION_MASK
				 | GDK_POINTER_MOTION_HINT_MASK);
	//gtk_container_add (GTK_CONTAINER (window2), label);
	  g_signal_connect(label, "configure_callback",
	      G_CALLBACK(configure_callback), window2);
	  g_signal_connect(button, "clicked",
	      G_CALLBACK(createVirtualTable), NULL);
	  g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	  //gtk_widget_show (fixed);
	  gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
