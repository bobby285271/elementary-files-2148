/* AppUtils.c generated by valac 0.56.3, the Vala compiler
 * generated from AppUtils.vala, do not modify */

#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib.h>
#include <unistd.h>
#include <sys/types.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

VALA_EXTERN GtkWindow* files_get_active_window (void);
VALA_EXTERN gboolean files_is_admin (void);

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

GtkWindow*
files_get_active_window (void)
{
	GtkApplication* gtk_app = NULL;
	GApplication* _tmp0_;
	GtkWindow* _tmp1_;
	GtkWindow* _tmp2_;
	GtkWindow* result;
	_tmp0_ = g_application_get_default ();
	gtk_app = G_TYPE_CHECK_INSTANCE_CAST (_tmp0_, gtk_application_get_type (), GtkApplication);
	_tmp1_ = gtk_application_get_active_window (gtk_app);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	result = _tmp2_;
	return result;
}

gboolean
files_is_admin (void)
{
	gboolean result;
	result = getuid () == ((uid_t) 0);
	return result;
}

