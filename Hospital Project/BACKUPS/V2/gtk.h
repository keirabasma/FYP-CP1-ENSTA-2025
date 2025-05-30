#ifndef GTK_INTERFACE_H
#define GTK_INTERFACE_H

#include <gtk/gtk.h>

// Function declarations
void load_css();
void display_gtk_interface();
void activate(GtkApplication *app, gpointer user_data);

#endif