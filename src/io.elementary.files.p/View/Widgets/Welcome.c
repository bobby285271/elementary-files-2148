/* Welcome.c generated by valac 0.56.3, the Vala compiler
 * generated from Welcome.vala, do not modify */

#include <granite.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define FILES_VIEW_TYPE_WELCOME (files_view_welcome_get_type ())
#define FILES_VIEW_WELCOME(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_VIEW_TYPE_WELCOME, FilesViewWelcome))
#define FILES_VIEW_WELCOME_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_VIEW_TYPE_WELCOME, FilesViewWelcomeClass))
#define FILES_VIEW_IS_WELCOME(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_VIEW_TYPE_WELCOME))
#define FILES_VIEW_IS_WELCOME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_VIEW_TYPE_WELCOME))
#define FILES_VIEW_WELCOME_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_VIEW_TYPE_WELCOME, FilesViewWelcomeClass))

typedef struct _FilesViewWelcome FilesViewWelcome;
typedef struct _FilesViewWelcomeClass FilesViewWelcomeClass;
typedef struct _FilesViewWelcomePrivate FilesViewWelcomePrivate;
enum  {
	FILES_VIEW_WELCOME_0_PROPERTY,
	FILES_VIEW_WELCOME_NUM_PROPERTIES
};
static GParamSpec* files_view_welcome_properties[FILES_VIEW_WELCOME_NUM_PROPERTIES];

struct _FilesViewWelcome {
	GraniteWidgetsWelcome parent_instance;
	FilesViewWelcomePrivate * priv;
};

struct _FilesViewWelcomeClass {
	GraniteWidgetsWelcomeClass parent_class;
};

static gpointer files_view_welcome_parent_class = NULL;

VALA_EXTERN GType files_view_welcome_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesViewWelcome, g_object_unref)
VALA_EXTERN FilesViewWelcome* files_view_welcome_new (const gchar* primary,
                                          const gchar* secondary);
VALA_EXTERN FilesViewWelcome* files_view_welcome_construct (GType object_type,
                                                const gchar* primary,
                                                const gchar* secondary);
VALA_EXTERN gboolean files_view_welcome_on_button_press_event (FilesViewWelcome* self,
                                                   GdkEventButton* event);
static gboolean _files_view_welcome_on_button_press_event_gtk_widget_button_press_event (GtkWidget* _sender,
                                                                                  GdkEventButton* event,
                                                                                  gpointer self);
static GType files_view_welcome_get_type_once (void);

static gboolean
_files_view_welcome_on_button_press_event_gtk_widget_button_press_event (GtkWidget* _sender,
                                                                         GdkEventButton* event,
                                                                         gpointer self)
{
	gboolean result;
	result = files_view_welcome_on_button_press_event ((FilesViewWelcome*) self, event);
	return result;
}

FilesViewWelcome*
files_view_welcome_construct (GType object_type,
                              const gchar* primary,
                              const gchar* secondary)
{
	FilesViewWelcome * self = NULL;
	g_return_val_if_fail (primary != NULL, NULL);
	g_return_val_if_fail (secondary != NULL, NULL);
	self = (FilesViewWelcome*) granite_widgets_welcome_construct (object_type, primary, secondary);
	g_signal_connect_object ((GtkWidget*) self, "button-press-event", (GCallback) _files_view_welcome_on_button_press_event_gtk_widget_button_press_event, self, 0);
	gtk_widget_show_all ((GtkWidget*) self);
	return self;
}

FilesViewWelcome*
files_view_welcome_new (const gchar* primary,
                        const gchar* secondary)
{
	return files_view_welcome_construct (FILES_VIEW_TYPE_WELCOME, primary, secondary);
}

gboolean
files_view_welcome_on_button_press_event (FilesViewWelcome* self,
                                          GdkEventButton* event)
{
	guint button = 0U;
	guint _tmp0_ = 0U;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (event != NULL, FALSE);
	gdk_event_get_button ((GdkEvent*) event, &_tmp0_);
	button = _tmp0_;
	switch (button) {
		case 6:
		case 7:
		case 8:
		case 9:
		{
			GtkWidget* _tmp1_;
			gboolean _tmp2_ = FALSE;
			_tmp1_ = gtk_widget_get_toplevel ((GtkWidget*) self);
			g_signal_emit_by_name (_tmp1_, "button-press-event", event, &_tmp2_);
			result = _tmp2_;
			return result;
		}
		default:
		{
			result = GTK_WIDGET_CLASS (files_view_welcome_parent_class)->button_press_event ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, GRANITE_WIDGETS_TYPE_WELCOME, GraniteWidgetsWelcome), event);
			return result;
		}
	}
}

static void
files_view_welcome_class_init (FilesViewWelcomeClass * klass,
                               gpointer klass_data)
{
	files_view_welcome_parent_class = g_type_class_peek_parent (klass);
}

static void
files_view_welcome_instance_init (FilesViewWelcome * self,
                                  gpointer klass)
{
}

static GType
files_view_welcome_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesViewWelcomeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_view_welcome_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesViewWelcome), 0, (GInstanceInitFunc) files_view_welcome_instance_init, NULL };
	GType files_view_welcome_type_id;
	files_view_welcome_type_id = g_type_register_static (GRANITE_WIDGETS_TYPE_WELCOME, "FilesViewWelcome", &g_define_type_info, 0);
	return files_view_welcome_type_id;
}

GType
files_view_welcome_get_type (void)
{
	static volatile gsize files_view_welcome_type_id__once = 0;
	if (g_once_init_enter (&files_view_welcome_type_id__once)) {
		GType files_view_welcome_type_id;
		files_view_welcome_type_id = files_view_welcome_get_type_once ();
		g_once_init_leave (&files_view_welcome_type_id__once, files_view_welcome_type_id);
	}
	return files_view_welcome_type_id__once;
}

