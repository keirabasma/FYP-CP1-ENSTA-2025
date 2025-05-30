#include<gtk/gtk.h>
#include "gtk.h"

// Function to load the CSS file
void load_css() {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(
        screen,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    // Load the CSS file
    const gchar *css_file = "style.css";
    GError *error = NULL;
    gtk_css_provider_load_from_path(provider, css_file, &error);

    if (error) {
        g_warning("Error loading CSS file: %s", error->message);
        g_error_free(error);
    }

    g_object_unref(provider);
}

// Function to initialize and display the GTK interface
void display_gtk_interface() {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.GtkCss", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Load the CSS file
    load_css();

    status = g_application_run(G_APPLICATION(app), 0, NULL);
    g_object_unref(app);
}

// Callback function for the GTK application
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK CSS Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_widget_set_name(button, "custom-button"); // Set a name for CSS styling

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);
}