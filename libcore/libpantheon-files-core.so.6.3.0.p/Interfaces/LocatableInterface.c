/* LocatableInterface.c generated by valac 0.56.3, the Vala compiler
 * generated from LocatableInterface.vala, do not modify */

#include "pantheon-files-core.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>

enum  {
	FILES_VIEW_CHROME_LOCATABLE_PATH_CHANGE_REQUEST_SIGNAL,
	FILES_VIEW_CHROME_LOCATABLE_NUM_SIGNALS
};
static guint files_view_chrome_locatable_signals[FILES_VIEW_CHROME_LOCATABLE_NUM_SIGNALS] = {0};

static void g_cclosure_user_marshal_VOID__STRING_ENUM (GClosure * closure,
                                                GValue * return_value,
                                                guint n_param_values,
                                                const GValue * param_values,
                                                gpointer invocation_hint,
                                                gpointer marshal_data);
static GType files_view_chrome_locatable_get_type_once (void);
static inline gpointer _vala_memdup2 (gconstpointer mem,
                        gsize byte_size);

void
files_view_chrome_locatable_set_display_path (FilesViewChromeLocatable* self,
                                              const gchar* path)
{
	FilesViewChromeLocatableIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = FILES_VIEW_CHROME_LOCATABLE_GET_INTERFACE (self);
	if (_iface_->set_display_path) {
		_iface_->set_display_path (self, path);
	}
}

gchar*
files_view_chrome_locatable_get_display_path (FilesViewChromeLocatable* self)
{
	FilesViewChromeLocatableIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = FILES_VIEW_CHROME_LOCATABLE_GET_INTERFACE (self);
	if (_iface_->get_display_path) {
		return _iface_->get_display_path (self);
	}
	return NULL;
}

gboolean
files_view_chrome_locatable_set_focussed (FilesViewChromeLocatable* self)
{
	FilesViewChromeLocatableIface* _iface_;
	g_return_val_if_fail (self != NULL, FALSE);
	_iface_ = FILES_VIEW_CHROME_LOCATABLE_GET_INTERFACE (self);
	if (_iface_->set_focussed) {
		return _iface_->set_focussed (self);
	}
	return FALSE;
}

static void
g_cclosure_user_marshal_VOID__STRING_ENUM (GClosure * closure,
                                           GValue * return_value,
                                           guint n_param_values,
                                           const GValue * param_values,
                                           gpointer invocation_hint,
                                           gpointer marshal_data)
{
	typedef void (*GMarshalFunc_VOID__STRING_ENUM) (gpointer data1, const char* arg_1, gint arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_ENUM callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_ENUM) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_enum (param_values + 2), data2);
}

static void
files_view_chrome_locatable_default_init (FilesViewChromeLocatableIface * iface,
                                          gpointer iface_data)
{
	files_view_chrome_locatable_signals[FILES_VIEW_CHROME_LOCATABLE_PATH_CHANGE_REQUEST_SIGNAL] = g_signal_new ("path-change-request", FILES_VIEW_CHROME_TYPE_LOCATABLE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_ENUM, G_TYPE_NONE, 2, G_TYPE_STRING, FILES_TYPE_OPEN_FLAG);
}

static GType
files_view_chrome_locatable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesViewChromeLocatableIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_view_chrome_locatable_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType files_view_chrome_locatable_type_id;
	files_view_chrome_locatable_type_id = g_type_register_static (G_TYPE_INTERFACE, "FilesViewChromeLocatable", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (files_view_chrome_locatable_type_id, gtk_box_get_type ());
	return files_view_chrome_locatable_type_id;
}

GType
files_view_chrome_locatable_get_type (void)
{
	static volatile gsize files_view_chrome_locatable_type_id__once = 0;
	if (g_once_init_enter (&files_view_chrome_locatable_type_id__once)) {
		GType files_view_chrome_locatable_type_id;
		files_view_chrome_locatable_type_id = files_view_chrome_locatable_get_type_once ();
		g_once_init_leave (&files_view_chrome_locatable_type_id__once, files_view_chrome_locatable_type_id);
	}
	return files_view_chrome_locatable_type_id__once;
}

static inline gpointer
_vala_memdup2 (gconstpointer mem,
               gsize byte_size)
{
	gpointer new_mem;
	if (mem && byte_size != 0) {
		new_mem = g_malloc (byte_size);
		memcpy (new_mem, mem, byte_size);
	} else {
		new_mem = NULL;
	}
	return new_mem;
}
