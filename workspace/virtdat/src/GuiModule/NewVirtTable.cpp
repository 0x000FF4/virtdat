/*
 * NewVirtTable.cpp
 *
 *  Created on: 8.03.2015 г.
 *      Author: x000ff4
 */

#include "NewVirtTable.h"
using namespace virtdat;
int numberOfColumns;
GtkGrid *table;
GtkEntry *tableName;
std::vector<GtkEntry*> entries;
std::vector<GtkWidget*> autoIncrs;
std::vector<GtkWidget*> isNulls;
std::vector<GtkComboBoxText*> types;
//NewVirtTable* NewVirtTable::ints = 0;
void NewVirtTable::createTableButton(GtkWidget *widget, gpointer data) {
	std::vector<VirtColum> columns;
	std::vector<GtkEntry*>::iterator e = entries.begin();
	auto a = autoIncrs.begin();
	auto i = isNulls.begin();
	auto t = types.begin();
	VirtColum *column1;
	for(; e!=entries.end();e++ ,a++,i++,t++){
		switch(gtk_combo_box_get_active(GTK_COMBO_BOX(*t))){
		case 1:
			column1 = new VirtColum(gtk_entry_get_text(*e),TYPE::TEXT,NULL,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*i)), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*a)));
			columns.push_back(*column1);
			break;
		case 2:
			column1 = new VirtColum(gtk_entry_get_text(*e), TYPE::BOOLEAN,NULL,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*i)), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*a)));
			columns.push_back(*column1);
			break;
		case 3:
			column1 = new  VirtColum(gtk_entry_get_text(*e), TYPE::INTEGER,NULL,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*i)), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*a)));
			columns.push_back(*column1);
			break;
		case 4:
			column1 = new VirtColum(gtk_entry_get_text(*e), TYPE::BLOB,NULL,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*i)), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*a)));
			columns.push_back(*column1);
			break;
		case 5:
			column1 = new VirtColum(gtk_entry_get_text(*e), TYPE::REAL,NULL,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*i)), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(*a)));
			columns.push_back(*column1);
			break;
		}
	}
	std::vector<std::string> tags;
	NewVirtTable::ints->comAndcontrol->createTable(columns,gtk_entry_get_text(tableName),tags);
	gtk_window_close(GTK_WINDOW(NewVirtTable::ints->new_window));
	NewVirtTable::ints->tableDone();

}

void callBack(GtkWidget *widget, gpointer data) {

	numberOfColumns++;
	printf("11 \n");
	autoIncrs.push_back(gtk_check_button_new());
	isNulls.push_back(gtk_check_button_new());
	types.push_back(GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new()));
	entries.push_back(GTK_ENTRY(gtk_entry_new()));
	gtk_combo_box_text_append_text(types.back(),"TEXT");
	gtk_combo_box_text_append_text(types.back(),"BOOLEAN");
	gtk_combo_box_text_append_text(types.back(),"INTEGER");
	gtk_combo_box_text_append_text(types.back(),"BLOB");
	gtk_combo_box_text_append_text(types.back(),"REAL");
	gtk_grid_attach(table, GTK_WIDGET(entries.back()), 0, numberOfColumns, 1, 1);
	gtk_grid_attach(table,GTK_WIDGET( types.back()), 1, numberOfColumns, 1, 1);
	gtk_grid_attach(table, autoIncrs.back(), 2, numberOfColumns, 1, 1);
	gtk_grid_attach(table, isNulls.back(), 3, numberOfColumns, 1, 1);
	gtk_widget_show(GTK_WIDGET(entries.back()));
	gtk_widget_show(GTK_WIDGET(types.back()));
	gtk_widget_show(autoIncrs.back());
	gtk_widget_show(isNulls.back());
}
void NewVirtTable::createNewTable(CommandAndControll* comAndcontrol,void(*tableDone)()) {

	GtkButton *newColumn;
	GtkButton *createTable;
	this->comAndcontrol = comAndcontrol;
	this->tableDone = tableDone;

	GtkWidget *name;
	GtkWidget *typeName;
	GtkWidget *autoIncrement;
	GtkWidget *notNull;
	GtkEntry *entry;
	GtkWidget *isAutoIncr;
	GtkWidget *isNull;
	GtkWidget *frame;
	GtkComboBoxText *type;
	numberOfColumns = 1;
	name  = gtk_label_new("Име");
	typeName = gtk_label_new("Тип");
	autoIncrement = gtk_label_new("Самоувеличаване  ");
	notNull = gtk_label_new("Задължително  ");
	isAutoIncr = gtk_check_button_new();
	isNull = gtk_check_button_new();
	tableName = GTK_ENTRY(gtk_entry_new());
	type  = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
	entry = GTK_ENTRY(gtk_entry_new());
	table = GTK_GRID(gtk_grid_new());
	newColumn = GTK_BUTTON(gtk_button_new());
	createTable = GTK_BUTTON(gtk_button_new_with_label("Създай таблица"));
	gtk_combo_box_text_append_text(type,"TEXT");
	gtk_combo_box_text_append_text(type,"BOOLEAN");
	gtk_combo_box_text_append_text(type,"INTEGER");
	gtk_combo_box_text_append_text(type,"BLOB");
	gtk_combo_box_text_append_text(type,"REAL");
	gtk_button_set_image(newColumn, gtk_image_new_from_file("newColumn.png"));
	gtk_widget_set_size_request(GTK_WIDGET(newColumn), 50, 50);
	gtk_widget_set_size_request(GTK_WIDGET(entry), 10, 10);
	gtk_widget_set_size_request(GTK_WIDGET(createTable), 150, 30);
	gtk_widget_set_size_request(GTK_WIDGET(tableName),150,30);
	new_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	frame = gtk_fixed_new();
	gtk_container_add((GtkContainer*) new_window, (GtkWidget*) frame);

	gtk_widget_set_size_request(new_window, 400, 500);
	gtk_window_set_position(GTK_WINDOW(new_window), GTK_WIN_POS_CENTER);

	gtk_grid_attach(table, name, 0, 0, 1, 1);
	gtk_grid_attach(table, typeName, 1, 0, 1, 1);
	gtk_grid_attach(table,autoIncrement , 2, 0, 1, 1);
	gtk_grid_attach(table, notNull, 3, 0, 1, 1);

	gtk_grid_attach(table, GTK_WIDGET(entry), 0, 1, 1, 1);
	gtk_grid_attach(table, GTK_WIDGET(type), 1, 1, 1, 1);
	gtk_grid_attach(table, isAutoIncr, 2, 1, 1, 1);
	gtk_grid_attach(table, isNull, 3, 1, 1, 1);
	gtk_fixed_put(GTK_FIXED(frame),GTK_WIDGET(tableName),80,10);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(table), 100, 50);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(newColumn), 10, 10);
	gtk_fixed_put(GTK_FIXED(frame), GTK_WIDGET(createTable), 230, 450);

	gtk_widget_set_events(new_window,
			GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_BUTTON_PRESS_MASK
					| GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK
					| GDK_POINTER_MOTION_HINT_MASK);
	g_signal_connect(newColumn, "clicked", G_CALLBACK(callBack), NULL);
	g_signal_connect(createTable, "clicked", G_CALLBACK(NewVirtTable::createTableButton), NULL);
	gtk_widget_show_all(new_window);

	gtk_main();
}
NewVirtTable::NewVirtTable() {
	NewVirtTable::ints = this;

}

NewVirtTable::~NewVirtTable() {

}}
