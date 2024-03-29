/* plugin.c generated by valac 0.56.3, the Vala compiler
 * generated from plugin.vala, do not modify */

#include "pantheon-files-trash.h"
#include "pantheon-files-core.h"
#include <glib.h>
#include <gee.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <gio/gio.h>
#include "marlin-file-operations.h"

#define FILES_PLUGINS_TRASH_RESTORE_ALL N_ ("Restore All")
#define FILES_PLUGINS_TRASH_DELETE_ALL N_ ("Empty the Trash")
#define FILES_PLUGINS_TRASH_RESTORE_SELECTED N_ ("Restore Selected")
#define FILES_PLUGINS_TRASH_DELETE_SELECTED N_ ("Delete Selected")

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _files_plugins_base_unref0(var) ((var == NULL) ? NULL : (var = (files_plugins_base_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _marlin_file_operations_common_job_unref0(var) ((var == NULL) ? NULL : (var = (marlin_file_operations_common_job_unref (var), NULL)))

struct _FilesPluginsTrashPrivate {
	FilesTrashMonitor* trash_monitor;
	gboolean trash_is_empty;
	GeeHashMap* actionbars;
	GtkButton* delete_button;
	GtkButton* restore_button;
};

struct _Block1Data {
	int _ref_count_;
	FilesPluginsTrash* self;
	GtkApplicationWindow* window;
	FilesAbstractSlot* view;
};

static gint FilesPluginsTrash_private_offset;
static gpointer files_plugins_trash_parent_class = NULL;

static void __lambda4_ (FilesPluginsTrash* self);
static void files_plugins_trash_set_actionbar (FilesPluginsTrash* self,
                                        GtkWidget* bar);
static void ___lambda4__g_object_notify (GObject* _sender,
                                  GParamSpec* pspec,
                                  gpointer self);
static void files_plugins_trash_real_directory_loaded (FilesPluginsBase* base,
                                                GtkApplicationWindow* window,
                                                FilesAbstractSlot* view,
                                                FilesFile* directory);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void ____lambda5_ (Block1Data* _data1_);
static void _____lambda5__gtk_button_clicked (GtkButton* _sender,
                                       gpointer self);
static void ____lambda6_ (Block1Data* _data1_);
static void _g_object_unref0_ (gpointer var);
static inline void _g_list_free__g_object_unref0_ (GList* self);
static void _____lambda6__gtk_button_clicked (GtkButton* _sender,
                                       gpointer self);
static void ____lambda7_ (FilesPluginsTrash* self,
                   GList* files);
static void _____lambda7__files_abstract_slot_selection_changed (FilesAbstractSlot* _sender,
                                                          GList* files,
                                                          gpointer self);
static void files_plugins_trash_finalize (FilesPluginsBase * obj);
static GType files_plugins_trash_get_type_once (void);

static inline gpointer
files_plugins_trash_get_instance_private (FilesPluginsTrash* self)
{
	return G_STRUCT_MEMBER_P (self, FilesPluginsTrash_private_offset);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
__lambda4_ (FilesPluginsTrash* self)
{
	FilesTrashMonitor* _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	GeeArrayList* to_remove = NULL;
	GeeArrayList* _tmp3_;
	_tmp0_ = self->priv->trash_monitor;
	_tmp1_ = files_trash_monitor_get_is_empty (_tmp0_);
	_tmp2_ = _tmp1_;
	self->priv->trash_is_empty = _tmp2_;
	_tmp3_ = gee_array_list_new (GEE_MAP_TYPE_ENTRY, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, NULL, NULL, NULL);
	to_remove = _tmp3_;
	{
		GeeIterator* _entry_it = NULL;
		GeeHashMap* _tmp4_;
		GeeSet* _tmp5_;
		GeeSet* _tmp6_;
		GeeSet* _tmp7_;
		GeeIterator* _tmp8_;
		GeeIterator* _tmp9_;
		_tmp4_ = self->priv->actionbars;
		_tmp5_ = gee_abstract_map_get_entries ((GeeAbstractMap*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = _tmp6_;
		_tmp8_ = gee_iterable_iterator ((GeeIterable*) _tmp7_);
		_tmp9_ = _tmp8_;
		_g_object_unref0 (_tmp7_);
		_entry_it = _tmp9_;
		while (TRUE) {
			GeeIterator* _tmp10_;
			GeeMapEntry* entry = NULL;
			GeeIterator* _tmp11_;
			gpointer _tmp12_;
			GtkActionBar* actionbar = NULL;
			GeeMapEntry* _tmp13_;
			gconstpointer _tmp14_;
			gconstpointer _tmp15_;
			GtkActionBar* _tmp16_;
			GtkActionBar* _tmp17_;
			GtkContainer* _tmp18_;
			_tmp10_ = _entry_it;
			if (!gee_iterator_next (_tmp10_)) {
				break;
			}
			_tmp11_ = _entry_it;
			_tmp12_ = gee_iterator_get (_tmp11_);
			entry = (GeeMapEntry*) _tmp12_;
			_tmp13_ = entry;
			_tmp14_ = gee_map_entry_get_value (_tmp13_);
			_tmp15_ = _tmp14_;
			_tmp16_ = _g_object_ref0 ((GtkActionBar*) _tmp15_);
			actionbar = _tmp16_;
			_tmp17_ = actionbar;
			_tmp18_ = gtk_widget_get_parent ((GtkWidget*) _tmp17_);
			if (_tmp18_ != NULL) {
				GtkActionBar* _tmp19_;
				_tmp19_ = actionbar;
				files_plugins_trash_set_actionbar (self, (GtkWidget*) _tmp19_);
			} else {
				GeeArrayList* _tmp20_;
				GeeMapEntry* _tmp21_;
				_tmp20_ = to_remove;
				_tmp21_ = entry;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp20_, _tmp21_);
			}
			_g_object_unref0 (actionbar);
			_g_object_unref0 (entry);
		}
		_g_object_unref0 (_entry_it);
	}
	{
		GeeArrayList* _closed_list = NULL;
		GeeArrayList* _tmp22_;
		gint _closed_size = 0;
		GeeArrayList* _tmp23_;
		gint _tmp24_;
		gint _tmp25_;
		gint _closed_index = 0;
		_tmp22_ = to_remove;
		_closed_list = _tmp22_;
		_tmp23_ = _closed_list;
		_tmp24_ = gee_abstract_collection_get_size ((GeeAbstractCollection*) _tmp23_);
		_tmp25_ = _tmp24_;
		_closed_size = _tmp25_;
		_closed_index = -1;
		while (TRUE) {
			gint _tmp26_;
			gint _tmp27_;
			GeeMapEntry* closed = NULL;
			GeeArrayList* _tmp28_;
			gpointer _tmp29_;
			GeeMapEntry* _tmp30_;
			gconstpointer _tmp31_;
			gconstpointer _tmp32_;
			GeeHashMap* _tmp33_;
			GeeMapEntry* _tmp34_;
			gconstpointer _tmp35_;
			gconstpointer _tmp36_;
			_closed_index = _closed_index + 1;
			_tmp26_ = _closed_index;
			_tmp27_ = _closed_size;
			if (!(_tmp26_ < _tmp27_)) {
				break;
			}
			_tmp28_ = _closed_list;
			_tmp29_ = gee_abstract_list_get ((GeeAbstractList*) _tmp28_, _closed_index);
			closed = (GeeMapEntry*) _tmp29_;
			_tmp30_ = closed;
			_tmp31_ = gee_map_entry_get_value (_tmp30_);
			_tmp32_ = _tmp31_;
			gtk_widget_destroy ((GtkWidget*) ((GtkActionBar*) _tmp32_));
			_tmp33_ = self->priv->actionbars;
			_tmp34_ = closed;
			_tmp35_ = gee_map_entry_get_key (_tmp34_);
			_tmp36_ = _tmp35_;
			gee_abstract_map_unset ((GeeAbstractMap*) _tmp33_, (FilesAbstractSlot*) _tmp36_, NULL);
			_g_object_unref0 (closed);
		}
	}
	_g_object_unref0 (to_remove);
}

static void
___lambda4__g_object_notify (GObject* _sender,
                             GParamSpec* pspec,
                             gpointer self)
{
	__lambda4_ ((FilesPluginsTrash*) self);
}

FilesPluginsTrash*
files_plugins_trash_construct (GType object_type)
{
	FilesPluginsTrash* self = NULL;
	GeeHashMap* _tmp0_;
	FilesTrashMonitor* _tmp1_;
	FilesTrashMonitor* _tmp2_;
	self = (FilesPluginsTrash*) files_plugins_base_construct (object_type);
	_tmp0_ = gee_hash_map_new (FILES_TYPE_ABSTRACT_SLOT, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, gtk_action_bar_get_type (), (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->actionbars);
	self->priv->actionbars = _tmp0_;
	_tmp1_ = files_trash_monitor_get_default ();
	self->priv->trash_monitor = _tmp1_;
	_tmp2_ = self->priv->trash_monitor;
	g_signal_connect ((GObject*) _tmp2_, "notify::is-empty", (GCallback) ___lambda4__g_object_notify, self);
	return self;
}

FilesPluginsTrash*
files_plugins_trash_new (void)
{
	return files_plugins_trash_construct (FILES_PLUGINS_TYPE_TRASH);
}

static Block1Data*
block1_data_ref (Block1Data* _data1_)
{
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}

static void
block1_data_unref (void * _userdata_)
{
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		FilesPluginsTrash* self;
		self = _data1_->self;
		_g_object_unref0 (_data1_->window);
		_g_object_unref0 (_data1_->view);
		_files_plugins_base_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}

static void
____lambda5_ (Block1Data* _data1_)
{
	FilesPluginsTrash* self;
	GtkButton* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GList* selection = NULL;
	GList* _tmp3_;
	self = _data1_->self;
	_tmp0_ = self->priv->restore_button;
	_tmp1_ = gtk_button_get_label (_tmp0_);
	_tmp2_ = _tmp1_;
	if (g_strcmp0 (_tmp2_, _ (FILES_PLUGINS_TRASH_RESTORE_ALL)) == 0) {
		files_abstract_slot_set_all_selected (_data1_->view, TRUE);
	}
	_tmp3_ = files_abstract_slot_get_selected_files (_data1_->view);
	selection = _tmp3_;
	files_file_utils_restore_files_from_trash (selection, (GtkWidget*) _data1_->window);
}

static void
_____lambda5__gtk_button_clicked (GtkButton* _sender,
                                  gpointer self)
{
	____lambda5_ (self);
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

static void
____lambda6_ (Block1Data* _data1_)
{
	FilesPluginsTrash* self;
	GtkButton* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	self = _data1_->self;
	_tmp0_ = self->priv->delete_button;
	_tmp1_ = gtk_button_get_label (_tmp0_);
	_tmp2_ = _tmp1_;
	if (g_strcmp0 (_tmp2_, _ (FILES_PLUGINS_TRASH_DELETE_ALL)) == 0) {
		FilesFileOperationsEmptyTrashJob* job = NULL;
		FilesFileOperationsEmptyTrashJob* _tmp3_;
		FilesFileOperationsEmptyTrashJob* _tmp4_;
		_tmp3_ = marlin_file_operations_empty_trash_job_new ((GtkWindow*) _data1_->window, NULL);
		job = _tmp3_;
		_tmp4_ = job;
		marlin_file_operations_empty_trash_job_empty_trash (_tmp4_, NULL, NULL);
		_marlin_file_operations_common_job_unref0 (job);
	} else {
		GList* to_delete = NULL;
		GList* _tmp5_;
		GList* _tmp11_;
		to_delete = NULL;
		_tmp5_ = files_abstract_slot_get_selected_files (_data1_->view);
		{
			GList* gof_collection = NULL;
			GList* gof_it = NULL;
			gof_collection = _tmp5_;
			for (gof_it = gof_collection; gof_it != NULL; gof_it = gof_it->next) {
				FilesFile* _tmp6_;
				FilesFile* gof = NULL;
				_tmp6_ = _g_object_ref0 ((FilesFile*) gof_it->data);
				gof = _tmp6_;
				{
					FilesFile* _tmp7_;
					GFile* _tmp8_;
					GFile* _tmp9_;
					GFile* _tmp10_;
					_tmp7_ = gof;
					_tmp8_ = files_file_get_location (_tmp7_);
					_tmp9_ = _tmp8_;
					_tmp10_ = _g_object_ref0 (_tmp9_);
					to_delete = g_list_prepend (to_delete, _tmp10_);
					_g_object_unref0 (gof);
				}
			}
		}
		_tmp11_ = to_delete;
		if (_tmp11_ != NULL) {
			GList* _tmp12_;
			_tmp12_ = to_delete;
			marlin_file_operations_delete (_tmp12_, (GtkWindow*) _data1_->window, FALSE, NULL, NULL, NULL);
		}
		(to_delete == NULL) ? NULL : (to_delete = (_g_list_free__g_object_unref0_ (to_delete), NULL));
	}
}

static void
_____lambda6__gtk_button_clicked (GtkButton* _sender,
                                  gpointer self)
{
	____lambda6_ (self);
}

static void
____lambda7_ (FilesPluginsTrash* self,
              GList* files)
{
	if (files == NULL) {
		GtkButton* _tmp0_;
		GtkButton* _tmp1_;
		_tmp0_ = self->priv->restore_button;
		gtk_button_set_label (_tmp0_, _ (FILES_PLUGINS_TRASH_RESTORE_ALL));
		_tmp1_ = self->priv->delete_button;
		gtk_button_set_label (_tmp1_, _ (FILES_PLUGINS_TRASH_DELETE_ALL));
	} else {
		GtkButton* _tmp2_;
		GtkButton* _tmp3_;
		_tmp2_ = self->priv->restore_button;
		gtk_button_set_label (_tmp2_, _ (FILES_PLUGINS_TRASH_RESTORE_SELECTED));
		_tmp3_ = self->priv->delete_button;
		gtk_button_set_label (_tmp3_, _ (FILES_PLUGINS_TRASH_DELETE_SELECTED));
	}
}

static void
_____lambda7__files_abstract_slot_selection_changed (FilesAbstractSlot* _sender,
                                                     GList* files,
                                                     gpointer self)
{
	____lambda7_ ((FilesPluginsTrash*) self, files);
}

static void
files_plugins_trash_real_directory_loaded (FilesPluginsBase* base,
                                           GtkApplicationWindow* window,
                                           FilesAbstractSlot* view,
                                           FilesFile* directory)
{
	FilesPluginsTrash * self;
	Block1Data* _data1_;
	GtkApplicationWindow* _tmp0_;
	FilesAbstractSlot* _tmp1_;
	GtkActionBar* actionbar = NULL;
	GeeHashMap* _tmp2_;
	gpointer _tmp3_;
	GFile* _tmp4_;
	GFile* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gboolean _tmp8_;
	self = (FilesPluginsTrash*) base;
	g_return_if_fail (window != NULL);
	g_return_if_fail (view != NULL);
	g_return_if_fail (directory != NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = files_plugins_base_ref (self);
	_tmp0_ = _g_object_ref0 (window);
	_g_object_unref0 (_data1_->window);
	_data1_->window = _tmp0_;
	_tmp1_ = _g_object_ref0 (view);
	_g_object_unref0 (_data1_->view);
	_data1_->view = _tmp1_;
	_tmp2_ = self->priv->actionbars;
	_tmp3_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp2_, _data1_->view);
	actionbar = (GtkActionBar*) _tmp3_;
	_tmp4_ = files_file_get_location (directory);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_file_get_uri_scheme (_tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strcmp0 (_tmp7_, "trash") == 0;
	_g_free0 (_tmp7_);
	if (_tmp8_) {
		GtkActionBar* _tmp9_;
		GtkActionBar* _tmp31_;
		_tmp9_ = actionbar;
		if (_tmp9_ == NULL) {
			GtkActionBar* _tmp10_;
			GtkActionBar* _tmp11_;
			GtkStyleContext* _tmp12_;
			GtkButton* _tmp13_ = NULL;
			GtkButton* _tmp14_ = NULL;
			GtkButton* _tmp15_;
			GtkStyleContext* _tmp16_;
			GtkSizeGroup* size_group = NULL;
			GtkSizeGroup* _tmp17_;
			GtkSizeGroup* _tmp18_;
			GtkButton* _tmp19_;
			GtkSizeGroup* _tmp20_;
			GtkButton* _tmp21_;
			GtkActionBar* _tmp22_;
			GtkButton* _tmp23_;
			GtkActionBar* _tmp24_;
			GtkButton* _tmp25_;
			GtkButton* _tmp26_;
			GtkButton* _tmp27_;
			GtkActionBar* _tmp28_;
			GeeHashMap* _tmp29_;
			GtkActionBar* _tmp30_;
			_tmp10_ = (GtkActionBar*) gtk_action_bar_new ();
			g_object_ref_sink (_tmp10_);
			_g_object_unref0 (actionbar);
			actionbar = _tmp10_;
			_tmp11_ = actionbar;
			_tmp12_ = gtk_widget_get_style_context ((GtkWidget*) _tmp11_);
			gtk_style_context_add_class (_tmp12_, GTK_STYLE_CLASS_INLINE_TOOLBAR);
			_tmp13_ = (GtkButton*) gtk_button_new_with_label (_ (FILES_PLUGINS_TRASH_RESTORE_ALL));
			gtk_widget_set_valign ((GtkWidget*) _tmp13_, GTK_ALIGN_CENTER);
			g_object_ref_sink (_tmp13_);
			_g_object_unref0 (self->priv->restore_button);
			self->priv->restore_button = _tmp13_;
			_tmp14_ = (GtkButton*) gtk_button_new_with_label (_ (FILES_PLUGINS_TRASH_DELETE_ALL));
			g_object_set ((GtkWidget*) _tmp14_, "margin", 6, NULL);
			gtk_widget_set_margin_start ((GtkWidget*) _tmp14_, 0);
			g_object_ref_sink (_tmp14_);
			_g_object_unref0 (self->priv->delete_button);
			self->priv->delete_button = _tmp14_;
			_tmp15_ = self->priv->delete_button;
			_tmp16_ = gtk_widget_get_style_context ((GtkWidget*) _tmp15_);
			gtk_style_context_add_class (_tmp16_, GTK_STYLE_CLASS_DESTRUCTIVE_ACTION);
			_tmp17_ = gtk_size_group_new (GTK_SIZE_GROUP_HORIZONTAL);
			size_group = _tmp17_;
			_tmp18_ = size_group;
			_tmp19_ = self->priv->restore_button;
			gtk_size_group_add_widget (_tmp18_, (GtkWidget*) _tmp19_);
			_tmp20_ = size_group;
			_tmp21_ = self->priv->delete_button;
			gtk_size_group_add_widget (_tmp20_, (GtkWidget*) _tmp21_);
			_tmp22_ = actionbar;
			_tmp23_ = self->priv->delete_button;
			gtk_action_bar_pack_end (_tmp22_, (GtkWidget*) _tmp23_);
			_tmp24_ = actionbar;
			_tmp25_ = self->priv->restore_button;
			gtk_action_bar_pack_end (_tmp24_, (GtkWidget*) _tmp25_);
			_tmp26_ = self->priv->restore_button;
			g_signal_connect_data (_tmp26_, "clicked", (GCallback) _____lambda5__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
			_tmp27_ = self->priv->delete_button;
			g_signal_connect_data (_tmp27_, "clicked", (GCallback) _____lambda6__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
			g_signal_connect_after (_data1_->view, "selection-changed", (GCallback) _____lambda7__files_abstract_slot_selection_changed, self);
			_tmp28_ = actionbar;
			files_abstract_slot_add_extra_action_widget (_data1_->view, (GtkWidget*) _tmp28_);
			_tmp29_ = self->priv->actionbars;
			_tmp30_ = actionbar;
			gee_abstract_map_set ((GeeAbstractMap*) _tmp29_, _data1_->view, _tmp30_);
			_g_object_unref0 (size_group);
		}
		_tmp31_ = actionbar;
		files_plugins_trash_set_actionbar (self, (GtkWidget*) _tmp31_);
	} else {
		GtkActionBar* _tmp32_;
		_tmp32_ = actionbar;
		if (_tmp32_ != NULL) {
			GtkActionBar* _tmp33_;
			GeeHashMap* _tmp34_;
			_tmp33_ = actionbar;
			gtk_widget_destroy ((GtkWidget*) _tmp33_);
			_tmp34_ = self->priv->actionbars;
			gee_abstract_map_unset ((GeeAbstractMap*) _tmp34_, _data1_->view, NULL);
		}
	}
	_g_object_unref0 (actionbar);
	block1_data_unref (_data1_);
	_data1_ = NULL;
}

static void
files_plugins_trash_set_actionbar (FilesPluginsTrash* self,
                                   GtkWidget* bar)
{
	GtkButton* _tmp0_;
	GtkButton* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (bar != NULL);
	_tmp0_ = self->priv->restore_button;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp0_, !self->priv->trash_is_empty);
	_tmp1_ = self->priv->delete_button;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp1_, !self->priv->trash_is_empty);
	gtk_widget_set_visible (bar, !self->priv->trash_is_empty);
	gtk_widget_set_no_show_all (bar, self->priv->trash_is_empty);
	gtk_widget_show_all (bar);
}

static void
files_plugins_trash_class_init (FilesPluginsTrashClass * klass,
                                gpointer klass_data)
{
	files_plugins_trash_parent_class = g_type_class_peek_parent (klass);
	((FilesPluginsBaseClass *) klass)->finalize = files_plugins_trash_finalize;
	g_type_class_adjust_private_offset (klass, &FilesPluginsTrash_private_offset);
	((FilesPluginsBaseClass *) klass)->directory_loaded = (void (*) (FilesPluginsBase*, GtkApplicationWindow*, FilesAbstractSlot*, FilesFile*)) files_plugins_trash_real_directory_loaded;
}

static void
files_plugins_trash_instance_init (FilesPluginsTrash * self,
                                   gpointer klass)
{
	self->priv = files_plugins_trash_get_instance_private (self);
	self->priv->trash_is_empty = FALSE;
}

static void
files_plugins_trash_finalize (FilesPluginsBase * obj)
{
	FilesPluginsTrash * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_PLUGINS_TYPE_TRASH, FilesPluginsTrash);
	_g_object_unref0 (self->priv->actionbars);
	_g_object_unref0 (self->priv->delete_button);
	_g_object_unref0 (self->priv->restore_button);
	FILES_PLUGINS_BASE_CLASS (files_plugins_trash_parent_class)->finalize (obj);
}

/***
    Copyright (c) Lucas Baudin 2011 <xapantu@gmail.com>

    Marlin is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Marlin is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program.  If not, see <http://www.gnu.org/licenses/>.
***/
static GType
files_plugins_trash_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesPluginsTrashClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_plugins_trash_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesPluginsTrash), 0, (GInstanceInitFunc) files_plugins_trash_instance_init, NULL };
	GType files_plugins_trash_type_id;
	files_plugins_trash_type_id = g_type_register_static (FILES_PLUGINS_TYPE_BASE, "FilesPluginsTrash", &g_define_type_info, 0);
	FilesPluginsTrash_private_offset = g_type_add_instance_private (files_plugins_trash_type_id, sizeof (FilesPluginsTrashPrivate));
	return files_plugins_trash_type_id;
}

GType
files_plugins_trash_get_type (void)
{
	static volatile gsize files_plugins_trash_type_id__once = 0;
	if (g_once_init_enter (&files_plugins_trash_type_id__once)) {
		GType files_plugins_trash_type_id;
		files_plugins_trash_type_id = files_plugins_trash_get_type_once ();
		g_once_init_leave (&files_plugins_trash_type_id__once, files_plugins_trash_type_id);
	}
	return files_plugins_trash_type_id__once;
}

FilesPluginsBase*
module_init (void)
{
	FilesPluginsTrash* _tmp0_;
	FilesPluginsBase* result;
	_tmp0_ = files_plugins_trash_new ();
	result = (FilesPluginsBase*) _tmp0_;
	return result;
}

