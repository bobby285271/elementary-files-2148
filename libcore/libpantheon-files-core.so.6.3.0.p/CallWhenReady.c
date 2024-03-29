/* CallWhenReady.c generated by valac 0.56.3, the Vala compiler
 * generated from CallWhenReady.vala, do not modify */

#include <glib.h>
#include "pantheon-files-core.h"
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>
#include <gio/gio.h>

enum  {
	FILES_CALL_WHEN_READY_0_PROPERTY,
	FILES_CALL_WHEN_READY_NUM_PROPERTIES
};
static GParamSpec* files_call_when_ready_properties[FILES_CALL_WHEN_READY_NUM_PROPERTIES];
typedef void (*FilesCallWhenReadyfunc_query_info) (FilesFile* gof, gpointer user_data);
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _FilesCallWhenReadyQueryInfoAsyncData FilesCallWhenReadyQueryInfoAsyncData;

struct _FilesCallWhenReadyPrivate {
	FilesCallWhenReadycall_when_ready_func f;
	gpointer f_target;
	GList* call_when_ready_list;
	const gchar* gio_default_attributes;
};

struct _FilesCallWhenReadyQueryInfoAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	FilesCallWhenReady* self;
	FilesFile* gof;
	FilesCallWhenReadyfunc_query_info fqi;
	gpointer fqi_target;
	GFileInfo* _tmp0_;
	GFile* _tmp1_;
	GFile* _tmp2_;
	const gchar* _tmp3_;
	GFileInfo* _tmp4_;
	GFileInfo* _tmp5_;
	GError* err;
	GError* _tmp6_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	GError* _tmp10_;
	GError* _tmp11_;
	GList* _tmp12_;
	FilesCallWhenReadycall_when_ready_func _tmp13_;
	gpointer _tmp13__target;
	FilesCallWhenReadycall_when_ready_func _tmp14_;
	gpointer _tmp14__target;
	GList* _tmp15_;
	GError* _inner_error0_;
};

VALA_EXTERN GList* callwhenready_cache;
GList* callwhenready_cache = NULL;
static gint FilesCallWhenReady_private_offset;
static gpointer files_call_when_ready_parent_class = NULL;

static void _g_object_unref0_ (gpointer var);
static inline void _g_list_free__g_object_unref0_ (GList* self);
static void files_call_when_ready_query_info_async (FilesCallWhenReady* self,
                                             FilesFile* gof,
                                             FilesCallWhenReadyfunc_query_info fqi,
                                             gpointer fqi_target,
                                             GAsyncReadyCallback _callback_,
                                             gpointer _user_data_);
static void files_call_when_ready_query_info_finish (FilesCallWhenReady* self,
                                              GAsyncResult* _res_);
static void files_call_when_ready_file_ready (FilesCallWhenReady* self,
                                       FilesFile* gof);
static void _files_call_when_ready_file_ready_filescallwhenreadyfunc_query_info (FilesFile* gof,
                                                                          gpointer self);
static void files_call_when_ready_query_info_async_data_free (gpointer _data);
static gboolean files_call_when_ready_query_info_async_co (FilesCallWhenReadyQueryInfoAsyncData* _data_);
static void files_call_when_ready_query_info_async_ready (GObject* source_object,
                                                   GAsyncResult* _res_,
                                                   gpointer _user_data_);
static void files_call_when_ready_finalize (GObject * obj);
static GType files_call_when_ready_get_type_once (void);

static inline gpointer
files_call_when_ready_get_instance_private (FilesCallWhenReady* self)
{
	return G_STRUCT_MEMBER_P (self, FilesCallWhenReady_private_offset);
}

static void
_g_object_unref0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}

static inline void
_g_list_free__g_object_unref0_ (GList* self)
{
	g_list_free_full (self, (GDestroyNotify) _g_object_unref0_);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
_files_call_when_ready_file_ready_filescallwhenreadyfunc_query_info (FilesFile* gof,
                                                                     gpointer self)
{
	files_call_when_ready_file_ready ((FilesCallWhenReady*) self, gof);
}

FilesCallWhenReady*
files_call_when_ready_construct (GType object_type,
                                 GList* _files,
                                 FilesCallWhenReadycall_when_ready_func _f,
                                 gpointer _f_target)
{
	FilesCallWhenReady * self = NULL;
	GList* _tmp0_;
	gint count = 0;
	gint total = 0;
	GList* _tmp1_;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	FilesCallWhenReady* _tmp14_;
	self = (FilesCallWhenReady*) g_object_new (object_type, NULL);
	_tmp0_ = g_list_copy_deep (_files, (GCopyFunc) g_object_ref, NULL);
	(self->files == NULL) ? NULL : (self->files = (_g_list_free__g_object_unref0_ (self->files), NULL));
	self->files = _tmp0_;
	self->priv->f = _f;
	self->priv->f_target = _f_target;
	count = 0;
	total = 0;
	_tmp1_ = self->files;
	{
		GList* gof_collection = NULL;
		GList* gof_it = NULL;
		gof_collection = _tmp1_;
		for (gof_it = gof_collection; gof_it != NULL; gof_it = gof_it->next) {
			FilesFile* gof = NULL;
			gof = (FilesFile*) gof_it->data;
			{
				gint _tmp2_;
				FilesFile* _tmp3_;
				GFileInfo* _tmp4_;
				_tmp2_ = total;
				total = _tmp2_ + 1;
				_tmp3_ = gof;
				_tmp4_ = _tmp3_->info;
				if (_tmp4_ == NULL) {
					FilesFile* _tmp5_;
					FilesFile* _tmp6_;
					FilesFile* _tmp7_;
					_tmp5_ = gof;
					_tmp6_ = _g_object_ref0 (_tmp5_);
					self->priv->call_when_ready_list = g_list_prepend (self->priv->call_when_ready_list, _tmp6_);
					_tmp7_ = gof;
					files_call_when_ready_query_info_async (self, _tmp7_, _files_call_when_ready_file_ready_filescallwhenreadyfunc_query_info, self, NULL, NULL);
				} else {
					gint _tmp8_;
					_tmp8_ = count;
					count = _tmp8_ + 1;
				}
			}
		}
	}
	if (count > 0) {
		_tmp10_ = count == total;
	} else {
		_tmp10_ = FALSE;
	}
	if (_tmp10_) {
		FilesCallWhenReadycall_when_ready_func _tmp11_;
		gpointer _tmp11__target;
		_tmp11_ = self->priv->f;
		_tmp11__target = self->priv->f_target;
		_tmp9_ = _tmp11_ != NULL;
	} else {
		_tmp9_ = FALSE;
	}
	if (_tmp9_) {
		FilesCallWhenReadycall_when_ready_func _tmp12_;
		gpointer _tmp12__target;
		GList* _tmp13_;
		_tmp12_ = self->priv->f;
		_tmp12__target = self->priv->f_target;
		_tmp13_ = self->files;
		_tmp12_ (_tmp13_, _tmp12__target);
	}
	_tmp14_ = _g_object_ref0 (self);
	callwhenready_cache = g_list_prepend (callwhenready_cache, _tmp14_);
	return self;
}

FilesCallWhenReady*
files_call_when_ready_new (GList* _files,
                           FilesCallWhenReadycall_when_ready_func _f,
                           gpointer _f_target)
{
	return files_call_when_ready_construct (FILES_TYPE_CALL_WHEN_READY, _files, _f, _f_target);
}

static void
files_call_when_ready_file_ready (FilesCallWhenReady* self,
                                  FilesFile* gof)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (gof != NULL);
	files_file_update (gof);
}

static void
files_call_when_ready_query_info_async_data_free (gpointer _data)
{
	FilesCallWhenReadyQueryInfoAsyncData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->gof);
	_g_object_unref0 (_data_->self);
	g_slice_free (FilesCallWhenReadyQueryInfoAsyncData, _data_);
}

static void
files_call_when_ready_query_info_async (FilesCallWhenReady* self,
                                        FilesFile* gof,
                                        FilesCallWhenReadyfunc_query_info fqi,
                                        gpointer fqi_target,
                                        GAsyncReadyCallback _callback_,
                                        gpointer _user_data_)
{
	FilesCallWhenReadyQueryInfoAsyncData* _data_;
	FilesCallWhenReady* _tmp0_;
	FilesFile* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (gof != NULL);
	_data_ = g_slice_new0 (FilesCallWhenReadyQueryInfoAsyncData);
	_data_->_async_result = g_task_new (G_OBJECT (self), NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, files_call_when_ready_query_info_async_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = _g_object_ref0 (gof);
	_g_object_unref0 (_data_->gof);
	_data_->gof = _tmp1_;
	_data_->fqi = fqi;
	_data_->fqi_target = fqi_target;
	files_call_when_ready_query_info_async_co (_data_);
}

static void
files_call_when_ready_query_info_finish (FilesCallWhenReady* self,
                                         GAsyncResult* _res_)
{
	FilesCallWhenReadyQueryInfoAsyncData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
}

static void
files_call_when_ready_query_info_async_ready (GObject* source_object,
                                              GAsyncResult* _res_,
                                              gpointer _user_data_)
{
	FilesCallWhenReadyQueryInfoAsyncData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	files_call_when_ready_query_info_async_co (_data_);
}

static GList*
vala_g_list_remove_full (GList* self,
                         gconstpointer data,
                         GFreeFunc func)
{
	GList* l = NULL;
	GList* result;
	l = self;
	while (TRUE) {
		GList* _tmp0_;
		GList* _tmp1_;
		gconstpointer _tmp2_;
		_tmp0_ = l;
		if (!(_tmp0_ != NULL)) {
			break;
		}
		_tmp1_ = l;
		_tmp2_ = ((GList*) _tmp1_)->data;
		if (_tmp2_ != data) {
			GList* _tmp3_;
			GList* _tmp4_;
			_tmp3_ = l;
			_tmp4_ = ((GList*) _tmp3_)->next;
			l = _tmp4_;
		} else {
			GList* _tmp5_;
			gconstpointer _tmp6_;
			GList* _tmp7_;
			_tmp5_ = l;
			_tmp6_ = ((GList*) _tmp5_)->data;
			func (_tmp6_);
			_tmp7_ = l;
			self = g_list_delete_link (self, (GList*) _tmp7_);
			break;
		}
	}
	result = self;
	return result;
}

static gboolean
files_call_when_ready_query_info_async_co (FilesCallWhenReadyQueryInfoAsyncData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		_data_->_tmp1_ = files_file_get_location (_data_->gof);
		_data_->_tmp2_ = _data_->_tmp1_;
		_data_->_tmp3_ = _data_->self->priv->gio_default_attributes;
		_data_->_state_ = 1;
		g_file_query_info_async (_data_->_tmp2_, _data_->_tmp3_, G_FILE_QUERY_INFO_NONE, G_PRIORITY_DEFAULT, NULL, files_call_when_ready_query_info_async_ready, _data_);
		return FALSE;
		_state_1:
		_data_->_tmp4_ = g_file_query_info_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error0_);
		_data_->_tmp0_ = _data_->_tmp4_;
		if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
		_data_->_tmp5_ = _data_->_tmp0_;
		_data_->_tmp0_ = NULL;
		_g_object_unref0 (_data_->gof->info);
		_data_->gof->info = _data_->_tmp5_;
		if (_data_->fqi != NULL) {
			_data_->fqi (_data_->gof, _data_->fqi_target);
		}
		_g_object_unref0 (_data_->_tmp0_);
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->err = _data_->_inner_error0_;
		_data_->_inner_error0_ = NULL;
		_data_->_tmp6_ = _data_->err;
		_data_->_tmp7_ = _data_->_tmp6_->message;
		_data_->_tmp8_ = files_file_get_uri (_data_->gof);
		_data_->_tmp9_ = _data_->_tmp8_;
		g_debug ("CallWhenReady.vala:75: query info failed, %s %s", _data_->_tmp7_, _data_->_tmp9_);
		_data_->_tmp10_ = _data_->err;
		if (g_error_matches (_data_->_tmp10_, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
			_data_->gof->exists = FALSE;
		}
		_data_->_tmp11_ = _data_->err;
		if (g_error_matches (_data_->_tmp11_, G_IO_ERROR, G_IO_ERROR_NOT_MOUNTED)) {
			_data_->gof->is_mounted = FALSE;
		}
		_g_error_free0 (_data_->err);
	}
	__finally0:
	if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->self->priv->call_when_ready_list = vala_g_list_remove_full (_data_->self->priv->call_when_ready_list, _data_->gof, _g_object_unref0_);
	_data_->_tmp12_ = _data_->self->priv->call_when_ready_list;
	if (_data_->_tmp12_ == NULL) {
		g_debug ("CallWhenReady.vala:87: call when ready OK - empty list");
		_data_->_tmp13_ = _data_->self->priv->f;
		_data_->_tmp13__target = _data_->self->priv->f_target;
		if (_data_->_tmp13_ != NULL) {
			_data_->_tmp14_ = _data_->self->priv->f;
			_data_->_tmp14__target = _data_->self->priv->f_target;
			_data_->_tmp15_ = _data_->self->files;
			_data_->_tmp14_ (_data_->_tmp15_, _data_->_tmp14__target);
		}
	}
	callwhenready_cache = vala_g_list_remove_full (callwhenready_cache, _data_->self, _g_object_unref0_);
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static void
files_call_when_ready_class_init (FilesCallWhenReadyClass * klass,
                                  gpointer klass_data)
{
	files_call_when_ready_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &FilesCallWhenReady_private_offset);
	G_OBJECT_CLASS (klass)->finalize = files_call_when_ready_finalize;
}

static void
files_call_when_ready_instance_init (FilesCallWhenReady * self,
                                     gpointer klass)
{
	self->priv = files_call_when_ready_get_instance_private (self);
	self->priv->call_when_ready_list = NULL;
	self->priv->gio_default_attributes = "standard::is-hidden,standard::is-backup,standard::is-symlink," "standard::type,standard::name,standard::display-name,standard::fast-co" \
"ntent-type,standard::size," "standard::symlink-target,access::*,time::*,owner::*,trash::*,unix::*,i" \
"d::filesystem,thumbnail::*";
}

static void
files_call_when_ready_finalize (GObject * obj)
{
	FilesCallWhenReady * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_TYPE_CALL_WHEN_READY, FilesCallWhenReady);
	(self->files == NULL) ? NULL : (self->files = (_g_list_free__g_object_unref0_ (self->files), NULL));
	(self->priv->call_when_ready_list == NULL) ? NULL : (self->priv->call_when_ready_list = (_g_list_free__g_object_unref0_ (self->priv->call_when_ready_list), NULL));
	G_OBJECT_CLASS (files_call_when_ready_parent_class)->finalize (obj);
}

static GType
files_call_when_ready_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesCallWhenReadyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_call_when_ready_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesCallWhenReady), 0, (GInstanceInitFunc) files_call_when_ready_instance_init, NULL };
	GType files_call_when_ready_type_id;
	files_call_when_ready_type_id = g_type_register_static (G_TYPE_OBJECT, "FilesCallWhenReady", &g_define_type_info, 0);
	FilesCallWhenReady_private_offset = g_type_add_instance_private (files_call_when_ready_type_id, sizeof (FilesCallWhenReadyPrivate));
	return files_call_when_ready_type_id;
}

GType
files_call_when_ready_get_type (void)
{
	static volatile gsize files_call_when_ready_type_id__once = 0;
	if (g_once_init_enter (&files_call_when_ready_type_id__once)) {
		GType files_call_when_ready_type_id;
		files_call_when_ready_type_id = files_call_when_ready_get_type_once ();
		g_once_init_leave (&files_call_when_ready_type_id__once, files_call_when_ready_type_id);
	}
	return files_call_when_ready_type_id__once;
}

