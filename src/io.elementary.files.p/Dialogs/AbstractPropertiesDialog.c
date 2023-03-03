/* AbstractPropertiesDialog.c generated by valac 0.56.3, the Vala compiler
 * generated from AbstractPropertiesDialog.vala, do not modify */

/*
* Copyright (c) 2011 Marlin Developers (http://launchpad.net/marlin)
* Copyright (c) 2015-2018 elementary LLC <https://elementary.io>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, Inc.,; either
* version 3 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1335 USA.
*
* Authored by: ammonkey <am.monkeyd@gmail.com>
*/

#include <granite.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG (files_view_abstract_properties_dialog_get_type ())
#define FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG, FilesViewAbstractPropertiesDialog))
#define FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG, FilesViewAbstractPropertiesDialogClass))
#define FILES_VIEW_IS_ABSTRACT_PROPERTIES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG))
#define FILES_VIEW_IS_ABSTRACT_PROPERTIES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG))
#define FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG, FilesViewAbstractPropertiesDialogClass))

typedef struct _FilesViewAbstractPropertiesDialog FilesViewAbstractPropertiesDialog;
typedef struct _FilesViewAbstractPropertiesDialogClass FilesViewAbstractPropertiesDialogClass;
typedef struct _FilesViewAbstractPropertiesDialogPrivate FilesViewAbstractPropertiesDialogPrivate;

#define FILES_TYPE_STORAGE_BAR (files_storage_bar_get_type ())
#define FILES_STORAGE_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_TYPE_STORAGE_BAR, FilesStorageBar))
#define FILES_STORAGE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_TYPE_STORAGE_BAR, FilesStorageBarClass))
#define FILES_IS_STORAGE_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_TYPE_STORAGE_BAR))
#define FILES_IS_STORAGE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_TYPE_STORAGE_BAR))
#define FILES_STORAGE_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_TYPE_STORAGE_BAR, FilesStorageBarClass))

typedef struct _FilesStorageBar FilesStorageBar;
typedef struct _FilesStorageBarClass FilesStorageBarClass;
enum  {
	FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_0_PROPERTY,
	FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_NUM_PROPERTIES
};
static GParamSpec* files_view_abstract_properties_dialog_properties[FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_NUM_PROPERTIES];
typedef enum  {
	FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_INFO,
	FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_PERMISSIONS
} FilesViewAbstractPropertiesDialogPanelType;

#define FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_TYPE_PANEL_TYPE (files_view_abstract_properties_dialog_panel_type_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef enum  {
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_OTHER,
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_AUDIO,
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_VIDEO,
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_PHOTO,
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_APP,
	FILES_STORAGE_BAR_ITEM_DESCRIPTION_FILES = FILES_STORAGE_BAR_ITEM_DESCRIPTION_OTHER
} FilesStorageBarItemDescription;

#define FILES_STORAGE_BAR_TYPE_ITEM_DESCRIPTION (files_storage_bar_item_description_get_type ())

#define TYPE_KEY_LABEL (key_label_get_type ())
#define KEY_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_KEY_LABEL, KeyLabel))
#define KEY_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_KEY_LABEL, KeyLabelClass))
#define IS_KEY_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_KEY_LABEL))
#define IS_KEY_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_KEY_LABEL))
#define KEY_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_KEY_LABEL, KeyLabelClass))

typedef struct _KeyLabel KeyLabel;
typedef struct _KeyLabelClass KeyLabelClass;

#define TYPE_VALUE_LABEL (value_label_get_type ())
#define VALUE_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VALUE_LABEL, ValueLabel))
#define VALUE_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VALUE_LABEL, ValueLabelClass))
#define IS_VALUE_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VALUE_LABEL))
#define IS_VALUE_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VALUE_LABEL))
#define VALUE_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VALUE_LABEL, ValueLabelClass))

typedef struct _ValueLabel ValueLabel;
typedef struct _ValueLabelClass ValueLabelClass;

struct _FilesViewAbstractPropertiesDialog {
	GraniteDialog parent_instance;
	FilesViewAbstractPropertiesDialogPrivate * priv;
	GtkGrid* info_grid;
	GtkGrid* layout;
	GtkStack* stack;
	GtkStackSwitcher* stack_switcher;
	GtkWidget* header_title;
	FilesStorageBar* storagebar;
};

struct _FilesViewAbstractPropertiesDialogClass {
	GraniteDialogClass parent_class;
};

static gpointer files_view_abstract_properties_dialog_parent_class = NULL;

VALA_EXTERN GType files_view_abstract_properties_dialog_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesViewAbstractPropertiesDialog, g_object_unref)
VALA_EXTERN GType files_storage_bar_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesStorageBar, g_object_unref)
VALA_EXTERN GType files_view_abstract_properties_dialog_panel_type_get_type (void) G_GNUC_CONST ;
VALA_EXTERN FilesViewAbstractPropertiesDialog* files_view_abstract_properties_dialog_construct (GType object_type,
                                                                                    const gchar* _title,
                                                                                    GtkWindow* parent);
VALA_EXTERN void files_view_abstract_properties_dialog_create_header_title (FilesViewAbstractPropertiesDialog* self);
VALA_EXTERN void files_view_abstract_properties_dialog_overlay_emblems (FilesViewAbstractPropertiesDialog* self,
                                                            GtkImage* file_icon,
                                                            GList* emblems_list);
VALA_EXTERN void files_view_abstract_properties_dialog_add_section (FilesViewAbstractPropertiesDialog* self,
                                                        GtkStack* stack,
                                                        const gchar* title,
                                                        const gchar* name,
                                                        GtkContainer* content);
VALA_EXTERN void files_view_abstract_properties_dialog_create_storage_bar (FilesViewAbstractPropertiesDialog* self,
                                                               GFileInfo* file_info,
                                                               gint line);
VALA_EXTERN FilesStorageBar* files_storage_bar_new_with_total_usage (guint64 storage,
                                                         guint64 total_usage);
VALA_EXTERN FilesStorageBar* files_storage_bar_construct_with_total_usage (GType object_type,
                                                               guint64 storage,
                                                               guint64 total_usage);
VALA_EXTERN GType files_storage_bar_item_description_get_type (void) G_GNUC_CONST ;
VALA_EXTERN void files_view_abstract_properties_dialog_update_storage_block_size (FilesViewAbstractPropertiesDialog* self,
                                                                      guint64 size,
                                                                      FilesStorageBarItemDescription item_description);
VALA_EXTERN GType key_label_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (KeyLabel, g_object_unref)
VALA_EXTERN KeyLabel* key_label_new (const gchar* label);
VALA_EXTERN KeyLabel* key_label_construct (GType object_type,
                               const gchar* label);
VALA_EXTERN GType value_label_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (ValueLabel, g_object_unref)
VALA_EXTERN ValueLabel* value_label_new (const gchar* label);
VALA_EXTERN ValueLabel* value_label_construct (GType object_type,
                                   const gchar* label);
VALA_EXTERN void files_storage_bar_update_block_size (FilesStorageBar* self,
                                          FilesStorageBarItemDescription description,
                                          guint64 size);
static GObject * files_view_abstract_properties_dialog_constructor (GType type,
                                                             guint n_construct_properties,
                                                             GObjectConstructParam * construct_properties);
static void _files_view_abstract_properties_dialog___lambda50_ (FilesViewAbstractPropertiesDialog* self,
                                                         GtkDialog* source,
                                                         gint type);
static void __files_view_abstract_properties_dialog___lambda50__gtk_dialog_response (GtkDialog* _sender,
                                                                              gint response_id,
                                                                              gpointer self);
static void files_view_abstract_properties_dialog_finalize (GObject * obj);
static GType files_view_abstract_properties_dialog_get_type_once (void);

static GType
files_view_abstract_properties_dialog_panel_type_get_type_once (void)
{
	static const GEnumValue values[] = {{FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_INFO, "FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_INFO", "info"}, {FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_PERMISSIONS, "FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_PERMISSIONS", "permissions"}, {0, NULL, NULL}};
	GType files_view_abstract_properties_dialog_panel_type_type_id;
	files_view_abstract_properties_dialog_panel_type_type_id = g_enum_register_static ("FilesViewAbstractPropertiesDialogPanelType", values);
	return files_view_abstract_properties_dialog_panel_type_type_id;
}

GType
files_view_abstract_properties_dialog_panel_type_get_type (void)
{
	static volatile gsize files_view_abstract_properties_dialog_panel_type_type_id__once = 0;
	if (g_once_init_enter (&files_view_abstract_properties_dialog_panel_type_type_id__once)) {
		GType files_view_abstract_properties_dialog_panel_type_type_id;
		files_view_abstract_properties_dialog_panel_type_type_id = files_view_abstract_properties_dialog_panel_type_get_type_once ();
		g_once_init_leave (&files_view_abstract_properties_dialog_panel_type_type_id__once, files_view_abstract_properties_dialog_panel_type_type_id);
	}
	return files_view_abstract_properties_dialog_panel_type_type_id__once;
}

FilesViewAbstractPropertiesDialog*
files_view_abstract_properties_dialog_construct (GType object_type,
                                                 const gchar* _title,
                                                 GtkWindow* parent)
{
	FilesViewAbstractPropertiesDialog * self = NULL;
	g_return_val_if_fail (_title != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	self = (FilesViewAbstractPropertiesDialog*) g_object_new (object_type, "title", _title, "transient-for", parent, "resizable", FALSE, "deletable", FALSE, "window-position", GTK_WIN_POS_CENTER_ON_PARENT, "destroy-with-parent", TRUE, NULL);
	return self;
}

void
files_view_abstract_properties_dialog_create_header_title (FilesViewAbstractPropertiesDialog* self)
{
	GtkWidget* _tmp0_;
	GtkStyleContext* _tmp1_;
	GtkWidget* _tmp2_;
	GtkWidget* _tmp3_;
	GtkWidget* _tmp4_;
	GtkGrid* _tmp5_;
	GtkWidget* _tmp6_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->header_title;
	_tmp1_ = gtk_widget_get_style_context (_tmp0_);
	gtk_style_context_add_class (_tmp1_, GRANITE_STYLE_CLASS_H2_LABEL);
	_tmp2_ = self->header_title;
	gtk_widget_set_hexpand (_tmp2_, TRUE);
	_tmp3_ = self->header_title;
	gtk_widget_set_margin_top (_tmp3_, 6);
	_tmp4_ = self->header_title;
	gtk_widget_set_valign (_tmp4_, GTK_ALIGN_CENTER);
	_tmp5_ = self->layout;
	_tmp6_ = self->header_title;
	gtk_grid_attach (_tmp5_, _tmp6_, 1, 0, 1, 1);
}

void
files_view_abstract_properties_dialog_overlay_emblems (FilesViewAbstractPropertiesDialog* self,
                                                       GtkImage* file_icon,
                                                       GList* emblems_list)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (file_icon != NULL);
	if (emblems_list != NULL) {
		gint pos = 0;
		GtkGrid* emblem_grid = NULL;
		GtkGrid* _tmp0_ = NULL;
		GtkOverlay* file_img = NULL;
		GtkOverlay* _tmp7_ = NULL;
		GtkOverlay* _tmp8_;
		GtkOverlay* _tmp9_;
		GtkGrid* _tmp10_;
		GtkGrid* _tmp11_;
		GtkOverlay* _tmp12_;
		pos = 0;
		_tmp0_ = (GtkGrid*) gtk_grid_new ();
		gtk_orientable_set_orientation ((GtkOrientable*) _tmp0_, GTK_ORIENTATION_VERTICAL);
		gtk_widget_set_halign ((GtkWidget*) _tmp0_, GTK_ALIGN_END);
		gtk_widget_set_valign ((GtkWidget*) _tmp0_, GTK_ALIGN_END);
		g_object_ref_sink (_tmp0_);
		emblem_grid = _tmp0_;
		{
			GList* emblem_name_collection = NULL;
			GList* emblem_name_it = NULL;
			emblem_name_collection = emblems_list;
			for (emblem_name_it = emblem_name_collection; emblem_name_it != NULL; emblem_name_it = emblem_name_it->next) {
				gchar* _tmp1_;
				gchar* emblem_name = NULL;
				_tmp1_ = g_strdup ((const gchar*) emblem_name_it->data);
				emblem_name = _tmp1_;
				{
					GtkImage* emblem = NULL;
					const gchar* _tmp2_;
					GtkImage* _tmp3_;
					GtkGrid* _tmp4_;
					GtkImage* _tmp5_;
					gint _tmp6_;
					_tmp2_ = emblem_name;
					_tmp3_ = (GtkImage*) gtk_image_new_from_icon_name (_tmp2_, (GtkIconSize) GTK_ICON_SIZE_BUTTON);
					g_object_ref_sink (_tmp3_);
					emblem = _tmp3_;
					_tmp4_ = emblem_grid;
					_tmp5_ = emblem;
					gtk_container_add ((GtkContainer*) _tmp4_, (GtkWidget*) _tmp5_);
					_tmp6_ = pos;
					pos = _tmp6_ + 1;
					if (pos > 3) {
						_g_object_unref0 (emblem);
						_g_free0 (emblem_name);
						break;
					}
					_g_object_unref0 (emblem);
					_g_free0 (emblem_name);
				}
			}
		}
		_tmp7_ = (GtkOverlay*) gtk_overlay_new ();
		gtk_widget_set_valign ((GtkWidget*) _tmp7_, GTK_ALIGN_CENTER);
		g_object_set ((GtkWidget*) _tmp7_, "width-request", 48, NULL);
		g_object_set ((GtkWidget*) _tmp7_, "height-request", 48, NULL);
		g_object_ref_sink (_tmp7_);
		file_img = _tmp7_;
		_tmp8_ = file_img;
		gtk_overlay_add_overlay (_tmp8_, (GtkWidget*) file_icon);
		_tmp9_ = file_img;
		_tmp10_ = emblem_grid;
		gtk_overlay_add_overlay (_tmp9_, (GtkWidget*) _tmp10_);
		_tmp11_ = self->layout;
		_tmp12_ = file_img;
		gtk_grid_attach (_tmp11_, (GtkWidget*) _tmp12_, 0, 0, 1, 1);
		_g_object_unref0 (file_img);
		_g_object_unref0 (emblem_grid);
	} else {
		GtkGrid* _tmp13_;
		_tmp13_ = self->layout;
		gtk_grid_attach (_tmp13_, (GtkWidget*) file_icon, 0, 0, 1, 1);
	}
}

void
files_view_abstract_properties_dialog_add_section (FilesViewAbstractPropertiesDialog* self,
                                                   GtkStack* stack,
                                                   const gchar* title,
                                                   const gchar* name,
                                                   GtkContainer* content)
{
	GList* _tmp0_;
	GList* _tmp1_;
	gboolean _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stack != NULL);
	g_return_if_fail (title != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (content != NULL);
	if (content != NULL) {
		gtk_stack_add_titled (stack, (GtkWidget*) content, name, title);
	}
	_tmp0_ = gtk_container_get_children ((GtkContainer*) stack);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_ != NULL;
	(_tmp1_ == NULL) ? NULL : (_tmp1_ = (g_list_free (_tmp1_), NULL));
	if (_tmp2_) {
		GtkStackSwitcher* _tmp3_;
		_tmp3_ = self->stack_switcher;
		gtk_widget_show ((GtkWidget*) _tmp3_);
	}
}

void
files_view_abstract_properties_dialog_create_storage_bar (FilesViewAbstractPropertiesDialog* self,
                                                          GFileInfo* file_info,
                                                          gint line)
{
	GraniteHeaderLabel* storage_header = NULL;
	GraniteHeaderLabel* _tmp0_;
	GtkGrid* _tmp1_;
	GraniteHeaderLabel* _tmp2_;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file_info != NULL);
	_tmp0_ = granite_header_label_new (_ ("Device Usage"));
	g_object_ref_sink (_tmp0_);
	storage_header = _tmp0_;
	_tmp1_ = self->info_grid;
	_tmp2_ = storage_header;
	gtk_grid_attach (_tmp1_, (GtkWidget*) _tmp2_, 0, line, 1, 1);
	if (file_info != NULL) {
		_tmp5_ = g_file_info_has_attribute (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_SIZE);
	} else {
		_tmp5_ = FALSE;
	}
	if (_tmp5_) {
		_tmp4_ = g_file_info_has_attribute (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_FREE);
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		_tmp3_ = g_file_info_has_attribute (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_USED);
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		guint64 fs_capacity = 0ULL;
		guint64 fs_used = 0ULL;
		guint64 fs_available = 0ULL;
		guint64 fs_reserved = 0ULL;
		FilesStorageBar* _tmp6_;
		GtkGrid* _tmp7_;
		FilesStorageBar* _tmp8_;
		fs_capacity = g_file_info_get_attribute_uint64 (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_SIZE);
		fs_used = g_file_info_get_attribute_uint64 (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_USED);
		fs_available = g_file_info_get_attribute_uint64 (file_info, G_FILE_ATTRIBUTE_FILESYSTEM_FREE);
		fs_reserved = (fs_capacity - fs_used) - fs_available;
		_tmp6_ = files_storage_bar_new_with_total_usage (fs_capacity, fs_used + fs_reserved);
		g_object_ref_sink (_tmp6_);
		_g_object_unref0 (self->storagebar);
		self->storagebar = _tmp6_;
		files_view_abstract_properties_dialog_update_storage_block_size (self, fs_reserved, FILES_STORAGE_BAR_ITEM_DESCRIPTION_OTHER);
		_tmp7_ = self->info_grid;
		_tmp8_ = self->storagebar;
		gtk_grid_attach (_tmp7_, (GtkWidget*) _tmp8_, 0, line + 1, 4, 1);
	} else {
		KeyLabel* capacity_label = NULL;
		KeyLabel* _tmp9_;
		ValueLabel* capacity_value = NULL;
		ValueLabel* _tmp10_;
		KeyLabel* available_label = NULL;
		KeyLabel* _tmp11_;
		ValueLabel* available_value = NULL;
		ValueLabel* _tmp12_;
		KeyLabel* used_label = NULL;
		KeyLabel* _tmp13_;
		ValueLabel* used_value = NULL;
		ValueLabel* _tmp14_;
		GtkGrid* _tmp15_;
		KeyLabel* _tmp16_;
		GtkGrid* _tmp17_;
		ValueLabel* _tmp18_;
		KeyLabel* _tmp19_;
		GtkGrid* _tmp20_;
		KeyLabel* _tmp21_;
		GtkGrid* _tmp22_;
		ValueLabel* _tmp23_;
		KeyLabel* _tmp24_;
		GtkGrid* _tmp25_;
		KeyLabel* _tmp26_;
		GtkGrid* _tmp27_;
		ValueLabel* _tmp28_;
		KeyLabel* _tmp29_;
		_tmp9_ = key_label_new (_ ("Capacity:"));
		g_object_ref_sink (_tmp9_);
		capacity_label = _tmp9_;
		_tmp10_ = value_label_new (_ ("Unknown"));
		g_object_ref_sink (_tmp10_);
		capacity_value = _tmp10_;
		_tmp11_ = key_label_new (_ ("Available:"));
		g_object_ref_sink (_tmp11_);
		available_label = _tmp11_;
		_tmp12_ = value_label_new (_ ("Unknown"));
		g_object_ref_sink (_tmp12_);
		available_value = _tmp12_;
		_tmp13_ = key_label_new (_ ("Used:"));
		g_object_ref_sink (_tmp13_);
		used_label = _tmp13_;
		_tmp14_ = value_label_new (_ ("Unknown"));
		g_object_ref_sink (_tmp14_);
		used_value = _tmp14_;
		_tmp15_ = self->info_grid;
		_tmp16_ = capacity_label;
		gtk_grid_attach (_tmp15_, (GtkWidget*) _tmp16_, 0, line + 1, 1, 1);
		_tmp17_ = self->info_grid;
		_tmp18_ = capacity_value;
		_tmp19_ = capacity_label;
		gtk_grid_attach_next_to (_tmp17_, (GtkWidget*) _tmp18_, (GtkWidget*) _tmp19_, GTK_POS_RIGHT, 1, 1);
		_tmp20_ = self->info_grid;
		_tmp21_ = available_label;
		gtk_grid_attach (_tmp20_, (GtkWidget*) _tmp21_, 0, line + 2, 1, 1);
		_tmp22_ = self->info_grid;
		_tmp23_ = available_value;
		_tmp24_ = available_label;
		gtk_grid_attach_next_to (_tmp22_, (GtkWidget*) _tmp23_, (GtkWidget*) _tmp24_, GTK_POS_RIGHT, 1, 1);
		_tmp25_ = self->info_grid;
		_tmp26_ = used_label;
		gtk_grid_attach (_tmp25_, (GtkWidget*) _tmp26_, 0, line + 3, 1, 1);
		_tmp27_ = self->info_grid;
		_tmp28_ = used_value;
		_tmp29_ = used_label;
		gtk_grid_attach_next_to (_tmp27_, (GtkWidget*) _tmp28_, (GtkWidget*) _tmp29_, GTK_POS_RIGHT, 1, 1);
		_g_object_unref0 (used_value);
		_g_object_unref0 (used_label);
		_g_object_unref0 (available_value);
		_g_object_unref0 (available_label);
		_g_object_unref0 (capacity_value);
		_g_object_unref0 (capacity_label);
	}
	_g_object_unref0 (storage_header);
}

void
files_view_abstract_properties_dialog_update_storage_block_size (FilesViewAbstractPropertiesDialog* self,
                                                                 guint64 size,
                                                                 FilesStorageBarItemDescription item_description)
{
	FilesStorageBar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->storagebar;
	if (_tmp0_ != NULL) {
		FilesStorageBar* _tmp1_;
		_tmp1_ = self->storagebar;
		files_storage_bar_update_block_size (_tmp1_, item_description, size);
	}
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
_files_view_abstract_properties_dialog___lambda50_ (FilesViewAbstractPropertiesDialog* self,
                                                    GtkDialog* source,
                                                    gint type)
{
	g_return_if_fail (source != NULL);
	switch (type) {
		case GTK_RESPONSE_CLOSE:
		{
			gtk_widget_destroy ((GtkWidget*) self);
			break;
		}
		default:
		break;
	}
}

static void
__files_view_abstract_properties_dialog___lambda50__gtk_dialog_response (GtkDialog* _sender,
                                                                         gint response_id,
                                                                         gpointer self)
{
	_files_view_abstract_properties_dialog___lambda50_ ((FilesViewAbstractPropertiesDialog*) self, _sender, response_id);
}

static GObject *
files_view_abstract_properties_dialog_constructor (GType type,
                                                   guint n_construct_properties,
                                                   GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	FilesViewAbstractPropertiesDialog * self;
	GraniteHeaderLabel* info_header = NULL;
	GraniteHeaderLabel* _tmp0_;
	GtkGrid* _tmp1_ = NULL;
	GtkGrid* _tmp2_;
	GraniteHeaderLabel* _tmp3_;
	GtkStack* _tmp4_;
	GtkStack* _tmp5_;
	GtkGrid* _tmp6_;
	GEnumValue* _tmp7_;
	GtkStack* _tmp8_;
	GtkStack* _tmp9_;
	GtkStackSwitcher* _tmp10_ = NULL;
	GtkGrid* _tmp11_ = NULL;
	GtkGrid* _tmp12_;
	GtkStackSwitcher* _tmp13_;
	GtkGrid* _tmp14_;
	GtkStack* _tmp15_;
	GtkBox* _tmp16_;
	GtkGrid* _tmp17_;
	parent_class = G_OBJECT_CLASS (files_view_abstract_properties_dialog_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG, FilesViewAbstractPropertiesDialog);
	gtk_window_set_default_size ((GtkWindow*) self, 220, -1);
	_tmp0_ = granite_header_label_new (_ ("Info"));
	g_object_ref_sink (_tmp0_);
	info_header = _tmp0_;
	_tmp1_ = (GtkGrid*) gtk_grid_new ();
	gtk_grid_set_column_spacing (_tmp1_, 6);
	gtk_grid_set_row_spacing (_tmp1_, 6);
	g_object_ref_sink (_tmp1_);
	_g_object_unref0 (self->info_grid);
	self->info_grid = _tmp1_;
	_tmp2_ = self->info_grid;
	_tmp3_ = info_header;
	gtk_grid_attach (_tmp2_, (GtkWidget*) _tmp3_, 0, 0, 2, 1);
	_tmp4_ = (GtkStack*) gtk_stack_new ();
	g_object_ref_sink (_tmp4_);
	_g_object_unref0 (self->stack);
	self->stack = _tmp4_;
	_tmp5_ = self->stack;
	_tmp6_ = self->info_grid;
	_tmp7_ = g_enum_get_value (g_type_class_ref (FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_TYPE_PANEL_TYPE), FILES_VIEW_ABSTRACT_PROPERTIES_DIALOG_PANEL_TYPE_INFO);
	gtk_stack_add_titled (_tmp5_, (GtkWidget*) _tmp6_, (_tmp7_ != NULL) ? _tmp7_->value_name : NULL, _ ("General"));
	_tmp8_ = self->stack;
	_tmp9_ = _g_object_ref0 (_tmp8_);
	_tmp10_ = (GtkStackSwitcher*) gtk_stack_switcher_new ();
	gtk_box_set_homogeneous ((GtkBox*) _tmp10_, TRUE);
	gtk_widget_set_margin_top ((GtkWidget*) _tmp10_, 12);
	gtk_widget_set_no_show_all ((GtkWidget*) _tmp10_, TRUE);
	gtk_stack_switcher_set_stack (_tmp10_, _tmp9_);
	_g_object_unref0 (_tmp9_);
	g_object_ref_sink (_tmp10_);
	_g_object_unref0 (self->stack_switcher);
	self->stack_switcher = _tmp10_;
	_tmp11_ = (GtkGrid*) gtk_grid_new ();
	g_object_set ((GtkWidget*) _tmp11_, "margin", 12, NULL);
	gtk_widget_set_margin_top ((GtkWidget*) _tmp11_, 0);
	gtk_grid_set_column_spacing (_tmp11_, 12);
	gtk_grid_set_row_spacing (_tmp11_, 6);
	g_object_ref_sink (_tmp11_);
	_g_object_unref0 (self->layout);
	self->layout = _tmp11_;
	_tmp12_ = self->layout;
	_tmp13_ = self->stack_switcher;
	gtk_grid_attach (_tmp12_, (GtkWidget*) _tmp13_, 0, 1, 2, 1);
	_tmp14_ = self->layout;
	_tmp15_ = self->stack;
	gtk_grid_attach (_tmp14_, (GtkWidget*) _tmp15_, 0, 2, 2, 1);
	_tmp16_ = gtk_dialog_get_content_area ((GtkDialog*) self);
	_tmp17_ = self->layout;
	gtk_container_add ((GtkContainer*) G_TYPE_CHECK_INSTANCE_CAST (_tmp16_, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp17_);
	gtk_dialog_add_button ((GtkDialog*) self, _ ("Close"), (gint) GTK_RESPONSE_CLOSE);
	g_signal_connect_object ((GtkDialog*) self, "response", (GCallback) __files_view_abstract_properties_dialog___lambda50__gtk_dialog_response, self, 0);
	_g_object_unref0 (info_header);
	return obj;
}

static void
files_view_abstract_properties_dialog_class_init (FilesViewAbstractPropertiesDialogClass * klass,
                                                  gpointer klass_data)
{
	files_view_abstract_properties_dialog_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = files_view_abstract_properties_dialog_constructor;
	G_OBJECT_CLASS (klass)->finalize = files_view_abstract_properties_dialog_finalize;
}

static void
files_view_abstract_properties_dialog_instance_init (FilesViewAbstractPropertiesDialog * self,
                                                     gpointer klass)
{
	self->storagebar = NULL;
}

static void
files_view_abstract_properties_dialog_finalize (GObject * obj)
{
	FilesViewAbstractPropertiesDialog * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_VIEW_TYPE_ABSTRACT_PROPERTIES_DIALOG, FilesViewAbstractPropertiesDialog);
	_g_object_unref0 (self->info_grid);
	_g_object_unref0 (self->layout);
	_g_object_unref0 (self->stack);
	_g_object_unref0 (self->stack_switcher);
	_g_object_unref0 (self->header_title);
	_g_object_unref0 (self->storagebar);
	G_OBJECT_CLASS (files_view_abstract_properties_dialog_parent_class)->finalize (obj);
}

static GType
files_view_abstract_properties_dialog_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesViewAbstractPropertiesDialogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_view_abstract_properties_dialog_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesViewAbstractPropertiesDialog), 0, (GInstanceInitFunc) files_view_abstract_properties_dialog_instance_init, NULL };
	GType files_view_abstract_properties_dialog_type_id;
	files_view_abstract_properties_dialog_type_id = g_type_register_static (GRANITE_TYPE_DIALOG, "FilesViewAbstractPropertiesDialog", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return files_view_abstract_properties_dialog_type_id;
}

GType
files_view_abstract_properties_dialog_get_type (void)
{
	static volatile gsize files_view_abstract_properties_dialog_type_id__once = 0;
	if (g_once_init_enter (&files_view_abstract_properties_dialog_type_id__once)) {
		GType files_view_abstract_properties_dialog_type_id;
		files_view_abstract_properties_dialog_type_id = files_view_abstract_properties_dialog_get_type_once ();
		g_once_init_leave (&files_view_abstract_properties_dialog_type_id__once, files_view_abstract_properties_dialog_type_id);
	}
	return files_view_abstract_properties_dialog_type_id__once;
}

