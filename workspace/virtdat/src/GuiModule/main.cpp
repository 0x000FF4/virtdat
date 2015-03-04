#include <gtk/gtk.h>
#include <gtkmm/button.h>
#include <vector>
#include <string>
#include "../CommandAndControllModule/CommandAndControll.h"
CommandAndControll* comAndcontrol;
GtkWidget *label;
char buf[20];
static const GtkTargetEntry queuelike_targets[] = {
  {
    (char *)"text/x-disorder-queued-tracks",
    GTK_TARGET_SAME_WIDGET,
    0
  },
  {
    (char *)"text/x-disorder-playable-tracks",
    GTK_TARGET_SAME_APP|GTK_TARGET_OTHER_WIDGET,
    1
  },
};
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
	for(int i = 0; i < 10000;i++){
	comAndcontrol->createTable(columns);
	}
	int size = comAndcontrol->tableSize();
	  sprintf(buf, "virtual tables: %d", size);
	  gtk_label_set_text(GTK_LABEL(label), buf);
}
int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *frame;
	comAndcontrol = new CommandAndControll();
	GtkWidget *button;
	gtk_init(&argc, NULL);
	label = gtk_label_new("virTables");

	  frame = gtk_fixed_new();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Window");


	button = gtk_button_new_with_label("create new virtual table");
	gtk_widget_set_size_request(window, 2000, 1500);
	gtk_widget_set_size_request(button, 1000, 50);
	gtk_widget_set_size_request(label, 1000, 50);

	gtk_widget_set_margin_left(label, 100);
	gtk_widget_set_margin_right(label, 100);
	gtk_widget_set_margin_top(label, 550);
	gtk_widget_set_margin_bottom(label, 300);

	gtk_widget_set_margin_left(button, 100);
	gtk_widget_set_margin_right(button, 100);
	gtk_widget_set_margin_top(button, 850);
	gtk_widget_set_margin_bottom(button, 100);
	gtk_widget_queue_resize(button);
	gtk_drag_source_set(window,
	                    GDK_BUTTON1_MASK,
	                    queuelike_targets,
	                    sizeof queuelike_targets / sizeof *queuelike_targets,
	                    GDK_ACTION_MOVE);
	gtk_drag_dest_set(label,
			GtkDestDefaults::GTK_DEST_DEFAULT_ALL,
	                  queuelike_targets,
	                  sizeof queuelike_targets / sizeof *queuelike_targets,
	 GDK_ACTION_MOVE);
	gtk_fixed_put(GTK_FIXED(frame), button, 50, 80);
	gtk_fixed_put(GTK_FIXED(frame), label, 100, 80);
	gtk_container_add(GTK_CONTAINER(window), frame);
	  g_signal_connect(button, "clicked",
	      G_CALLBACK(createVirtualTable), label);
	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	  gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
