#include <gtk/gtk.h>
#include <gtkmm/button.h>
#include <vector>
#include <string>
#include "myarea.h"
#include "LineParams.h"
#include "../CommandAndControllModule/CommandAndControll.h"
#include "NewVirtTable.h"
#define WINDOW_WIDTH  1730
#define WINDOW_HEIGHT 800
CommandAndControll* comAndcontrol;
std::vector<GtkImage*> tables;
std::vector<bool> tablesMov;
std::vector<LineParams> lines;
static cairo_surface_t *surface = NULL;
GtkWidget *label;
GtkWindow *windowLabel;
GtkWidget *window;
GtkWidget *window2;
GtkWidget *fixed;
GtkButton *virtTableButton;
GtkButton *virtConnectionButton;
GtkWidget *frame;
GtkWidget *darea;
GtkBuilder  *builder;
NewVirtTable newVirtTable;
bool isMouse1;
bool labelMov;
bool isLine;
bool isLineEnd;

int sx, sy;

char buf[20];
static void clear_surface(void) {
	cairo_t *cr;

	cr = cairo_create(surface);

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_paint(cr);

	cairo_destroy(cr);
}
static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event,
		gpointer data) {
	if (surface)
		cairo_surface_destroy(surface);
	surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
			CAIRO_CONTENT_COLOR, gtk_widget_get_allocated_width(widget),
			gtk_widget_get_allocated_height(widget));
	clear_surface();
	return TRUE;
}
static gboolean delete_event(GtkWidget *widget, GdkEvent *event,
		gpointer data) {
	g_print("delete event occurred\n");

	return false;
}

gboolean on_button_released(GtkWidget* widget, GdkEventButton * event,
		GdkWindowEdge edge) {
	printf("released");

	for (int i = 0; i < tablesMov.size(); ++i) {
		tablesMov[i] = false;
	}
	isMouse1 = false;
	isLine = false;
	labelMov = false;
	return FALSE;
}
gboolean on_button_press(GtkWidget* widget, GdkEventButton * event,
		GdkWindowEdge edge) {
	gint wx, wy;
	cairo_t *cr;
	int i = 0;
	if (event->type == GDK_BUTTON_PRESS) {
		if (event->button == 1) {

			isMouse1 = true;
			if (isLineEnd) {

						for (std::vector<GtkImage*>::iterator it = tables.begin();
								it != tables.end(); ++it, i++) {
							gtk_widget_translate_coordinates(GTK_WIDGET((*it)),
									gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0,
									0, &wx, &wy);
							printf("line end x:%i x1:%i \n",(int)event->x ,wx);
							if (isMouse1
									&& ((int) event->y + 50 > wy
											&& (int) event->y - 50 < wy)
									&& ((int) event->x + 50 > wx
											&& (int) event->x - 50 < wx)) {
								lines.back().setEndImage((*it));
								cr = cairo_create(surface);
								cairo_set_source_rgb(cr, 0, 0, 0);
								cairo_set_line_width(cr, 6);
								int imageX1;
								int imageY1;
								gtk_widget_translate_coordinates(
										GTK_WIDGET((lines.back().getBeginImage())),
										gtk_widget_get_toplevel(
												GTK_WIDGET(
														(lines.back().getBeginImage()))),
										0, 0, &imageX1, &imageY1);
								int imageX2;
								int imageY2;
								gtk_widget_translate_coordinates(
										GTK_WIDGET((lines.back().getEndImage())),
										gtk_widget_get_toplevel(
												GTK_WIDGET(
														(lines.back().getEndImage()))),
										0, 0, &imageX2, &imageY2);
								cairo_move_to(cr, imageX1-70, imageY1-25);
								cairo_line_to(cr, imageX2-70, imageY2-25);
								gtk_widget_queue_draw_area(darea,0,0,1730,800);
								cairo_stroke(cr);
								isLineEnd = false;
								isLine = false;
								break;

							}
						}
					}

			if (isLine && !isLineEnd){

				for (std::vector<GtkImage*>::iterator it = tables.begin();
						it != tables.end(); ++it, i++) {
					gtk_widget_translate_coordinates(GTK_WIDGET((*it)),
							gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0, 0,
							&wx, &wy);
					printf("x:%i x1:%i \n",(int)event->x ,wx);
					if (isMouse1
							&& ((int) event->y + 50 > wy
									&& (int) event->y - 50 < wy)
							&& ((int) event->x + 50 > wx
									&& (int) event->x - 50 < wx)) {

						LineParams newLine(*it, NULL);
						lines.push_back(newLine);
						isLineEnd = true;
						break;

					}
				}
			}

		}
	} else if (event->type == GDK_BUTTON_RELEASE) {
		printf("released");
		isMouse1 = false;
	}
	return FALSE;
}

static gboolean motion_notify_event(GtkWidget *widget, GdkEventMotion *event) {

	int x, y;
	GdkModifierType state;
	//printf("move down  %i , %i\n", (int) event->x, (int) event->y);

	gint wx, wy;
	int i = 0;
	for (std::vector<GtkImage*>::iterator it = tables.begin();
			it != tables.end(); ++it, i++) {
		gtk_widget_translate_coordinates(GTK_WIDGET((*it)),
				gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0, 0, &wx, &wy);
		if (tablesMov[i] == true) {
			gtk_fixed_move((GtkFixed*) fixed, (GtkWidget*) GTK_WIDGET((*it)),
					((int) event->x), ((int) event->y));
		}
	}
	i = 0;
	for (std::vector<GtkImage*>::iterator it = tables.begin();
			it != tables.end(); ++it, i++) {
		gtk_widget_translate_coordinates(GTK_WIDGET((*it)),
				gtk_widget_get_toplevel(GTK_WIDGET((*it))), 0, 0, &wx, &wy);
		if (isMouse1 && ((int) event->y + 50 > wy && (int) event->y - 50 < wy)
				&& ((int) event->x + 50 > wx && (int) event->x - 50 < wx)) {
			tablesMov[i] = true;
			break;
		}
	}
	if (state & GDK_BUTTON1_MASK) {
		printf(" %i , %i \n", x - sx, y - sy);

	}

	return TRUE;
}

void enabelLine(GtkWidget* widget, GdkEventButton * event, GdkWindowEdge edge) {
	isLine = true;
}
void configure_callback(GtkWidget * widget, GtkWindow * window) {
	gtk_widget_hide(GTK_WIDGET(window));
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
	gtk_widget_show_all(GTK_WIDGET(window));
	sprintf(buf, "virtual tables: %d", 2);
	gtk_label_set_text(GTK_LABEL(label), buf);
}
void createVirtualTable(GtkWidget *widget, gpointer label) {
	std::vector<std::VirtColum> columns;
	std::VirtColum column1("column1", std::TYPE::TEXT,NULL, false, false);
	std::VirtColum column2("column2", std::TYPE::BOOLEAN,NULL, true, false);
	std::VirtColum column3("column3", std::TYPE::BLOB,NULL, false, true);
	std::VirtColum column4("column4", std::TYPE::INTEGER,NULL, true, true);
	std::VirtColum column5("column5", std::TYPE::TEXT,NULL, false, true);
	columns.push_back(column1);
	columns.push_back(column2);
	columns.push_back(column3);
	columns.push_back(column4);
	columns.push_back(column5);

	comAndcontrol->createTable(columns);
	GtkImage *img = GTK_IMAGE(gtk_image_new_from_file("virtTable.png"));
	gtk_widget_set_size_request(GTK_WIDGET(img), 50, 50);
	//gtk_fixed_put( (GtkFixed*)fixed,GTK_WIDGET(img),0,0 );
	tables.push_back(img);
	gtk_fixed_put((GtkFixed*) fixed, GTK_WIDGET(img), 500, 120);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(img), 500, 120);
	tablesMov.push_back(false);
	printf("---------------------------");
	gtk_widget_show_all(window);

	gtk_main();
}
static gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data) {
	cairo_set_source_surface(cr, surface, 0, 0);
	cairo_paint(cr);

	return FALSE;
}
void creatingDone(){
	GtkImage *img = GTK_IMAGE(gtk_image_new_from_file("virtTable.png"));
	gtk_widget_set_size_request(GTK_WIDGET(img), 50, 50);
	//gtk_fixed_put( (GtkFixed*)fixed,GTK_WIDGET(img),0,0 );
	tables.push_back(img);
	gtk_fixed_put((GtkFixed*) fixed, GTK_WIDGET(img), 500, 120);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(img), 500, 120);
	tablesMov.push_back(false);
	printf("---------------------------");
	gtk_widget_show_all(window);

	gtk_main();
}
void create_window(GtkWidget *button, gpointer window) {
	std::vector<std::string> tags;
	newVirtTable.createNewTable(comAndcontrol,&creatingDone);
}

int main(int argc, char *argv[]) {

	comAndcontrol = new CommandAndControll();

	gtk_init(&argc, NULL);
	label = gtk_label_new("virTables");
	isMouse1 = false;
	labelMov = false;
	isLineEnd = false;
	frame = gtk_fixed_new();
    builder = gtk_builder_new ();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Virtdat");

	fixed = gtk_fixed_new();
	darea = gtk_drawing_area_new();
	gtk_widget_set_size_request(darea, WINDOW_WIDTH, WINDOW_HEIGHT);
	gtk_container_add((GtkContainer*) window, (GtkWidget*) fixed);
	gtk_fixed_put((GtkFixed*) fixed, label, 0, 0);

	virtTableButton = GTK_BUTTON(gtk_button_new());
	virtConnectionButton = GTK_BUTTON(gtk_button_new());
	gtk_widget_set_size_request(window, 2000, 1000);
	gtk_widget_set_size_request(GTK_WIDGET(virtConnectionButton), 50, 50);
	gtk_widget_set_size_request(GTK_WIDGET(virtTableButton), 50, 50);
	gtk_widget_set_size_request(label, 50, 50);
	gtk_fixed_put((GtkFixed*) fixed, GTK_WIDGET(darea), 100, 50);
	gtk_fixed_put((GtkFixed*) fixed, GTK_WIDGET(virtTableButton), 20, 150);
	gtk_fixed_put((GtkFixed*) fixed, GTK_WIDGET(virtConnectionButton), 20, 210);
	gtk_widget_set_margin_left(label, 100);
	gtk_widget_set_margin_right(label, 100);
	gtk_widget_set_margin_top(label, 550);
	gtk_widget_set_margin_bottom(label, 300);
	isLine = false;
	gtk_button_set_image(virtTableButton,
			gtk_image_new_from_file("virtTable.png"));
	gtk_button_set_image(virtConnectionButton,
			gtk_image_new_from_file("virtConnection.png"));

	gtk_widget_queue_resize(GTK_WIDGET(window));
	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(draw_cb), NULL);
	g_signal_connect(G_OBJECT(darea), "configure-event",
			G_CALLBACK (configure_event_cb), NULL);

	g_signal_connect(G_OBJECT(window), "button-press-event",
			G_CALLBACK(on_button_press), NULL);
	g_signal_connect(G_OBJECT(window), "button-release-event",
			G_CALLBACK(on_button_released), NULL);

	g_signal_connect(window, "motion-notify-event",
			G_CALLBACK (motion_notify_event), NULL);

	cairo_surface_t *surface;
	cairo_t *cr;

	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 120, 120);
	cr = cairo_create(surface);
	cairo_set_line_width(cr, 0.1);
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_rectangle(cr, 0.25, 0.25, 0.5, 0.5);
	cairo_stroke(cr);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(virtTableButton), 50, 80);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(virtConnectionButton), 50, 140);
	gtk_fixed_put(GTK_FIXED(frame), label, 100, 80);
	gtk_container_add(GTK_CONTAINER(window), darea);

	gtk_widget_set_events(window,
			GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_BUTTON_PRESS_MASK
					| GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK
					| GDK_POINTER_MOTION_HINT_MASK);

	g_signal_connect(label, "configure_callback",
			G_CALLBACK(configure_callback), window2);
	g_signal_connect(virtTableButton, "clicked", G_CALLBACK(create_window), NULL);

//g_signal_connect(virtTableButton, "clicked", G_CALLBACK(createVirtualTable),
//		NULL);
	g_signal_connect(virtConnectionButton, "clicked", G_CALLBACK(enabelLine),
			NULL);
	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_widget_show(darea);
	gtk_widget_show(window);
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
