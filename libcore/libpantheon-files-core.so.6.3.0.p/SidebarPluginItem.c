/* SidebarPluginItem.c generated by valac 0.56.3, the Vala compiler
 * generated from SidebarPluginItem.vala, do not modify */

#include "pantheon-files-core.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <glib-object.h>

enum  {
	FILES_SIDEBAR_PLUGIN_ITEM_0_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY,
	FILES_SIDEBAR_PLUGIN_ITEM_NUM_PROPERTIES
};
static GParamSpec* files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _FilesSidebarPluginItemPrivate {
	gchar* _name;
	gchar* _uri;
	GDrive* _drive;
	GVolume* _volume;
	GMount* _mount;
	GIcon* _icon;
	guint _index;
	gboolean _can_eject;
	gchar* _tooltip;
	GIcon* _action_icon;
	gboolean _show_spinner;
	guint64 _free_space;
	guint64 _disk_size;
	GActionGroup* _action_group;
	gchar* _action_group_namespace;
	GMenuModel* _menu_model;
	FilesSidebarCallbackFunc _cb;
};

static gint FilesSidebarPluginItem_private_offset;
static gpointer files_sidebar_plugin_item_parent_class = NULL;

static void files_sidebar_plugin_item_finalize (GObject * obj);
static GType files_sidebar_plugin_item_get_type_once (void);
static void _vala_files_sidebar_plugin_item_get_property (GObject * object,
                                                   guint property_id,
                                                   GValue * value,
                                                   GParamSpec * pspec);
static void _vala_files_sidebar_plugin_item_set_property (GObject * object,
                                                   guint property_id,
                                                   const GValue * value,
                                                   GParamSpec * pspec);

static inline gpointer
files_sidebar_plugin_item_get_instance_private (FilesSidebarPluginItem* self)
{
	return G_STRUCT_MEMBER_P (self, FilesSidebarPluginItem_private_offset);
}

FilesSidebarPluginItem*
files_sidebar_plugin_item_construct (GType object_type)
{
	FilesSidebarPluginItem * self = NULL;
	self = (FilesSidebarPluginItem*) g_object_new (object_type, NULL);
	return self;
}

FilesSidebarPluginItem*
files_sidebar_plugin_item_new (void)
{
	return files_sidebar_plugin_item_construct (FILES_TYPE_SIDEBAR_PLUGIN_ITEM);
}

const gchar*
files_sidebar_plugin_item_get_name (FilesSidebarPluginItem* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_name (FilesSidebarPluginItem* self,
                                    const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_name (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_name);
		self->priv->_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY]);
	}
}

const gchar*
files_sidebar_plugin_item_get_uri (FilesSidebarPluginItem* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_uri;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_uri (FilesSidebarPluginItem* self,
                                   const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_uri (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_uri);
		self->priv->_uri = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY]);
	}
}

GDrive*
files_sidebar_plugin_item_get_drive (FilesSidebarPluginItem* self)
{
	GDrive* result;
	GDrive* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_drive;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
files_sidebar_plugin_item_set_drive (FilesSidebarPluginItem* self,
                                     GDrive* value)
{
	GDrive* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_drive (self);
	if (old_value != value) {
		GDrive* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_drive);
		self->priv->_drive = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY]);
	}
}

GVolume*
files_sidebar_plugin_item_get_volume (FilesSidebarPluginItem* self)
{
	GVolume* result;
	GVolume* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_volume;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_volume (FilesSidebarPluginItem* self,
                                      GVolume* value)
{
	GVolume* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_volume (self);
	if (old_value != value) {
		GVolume* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_volume);
		self->priv->_volume = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY]);
	}
}

GMount*
files_sidebar_plugin_item_get_mount (FilesSidebarPluginItem* self)
{
	GMount* result;
	GMount* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_mount;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_mount (FilesSidebarPluginItem* self,
                                     GMount* value)
{
	GMount* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_mount (self);
	if (old_value != value) {
		GMount* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_mount);
		self->priv->_mount = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY]);
	}
}

GIcon*
files_sidebar_plugin_item_get_icon (FilesSidebarPluginItem* self)
{
	GIcon* result;
	GIcon* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_icon;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_icon (FilesSidebarPluginItem* self,
                                    GIcon* value)
{
	GIcon* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_icon (self);
	if (old_value != value) {
		GIcon* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_icon);
		self->priv->_icon = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY]);
	}
}

guint
files_sidebar_plugin_item_get_index (FilesSidebarPluginItem* self)
{
	guint result;
	g_return_val_if_fail (self != NULL, 0U);
	result = self->priv->_index;
	return result;
}

void
files_sidebar_plugin_item_set_index (FilesSidebarPluginItem* self,
                                     guint value)
{
	guint old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_index (self);
	if (old_value != value) {
		self->priv->_index = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY]);
	}
}

gboolean
files_sidebar_plugin_item_get_can_eject (FilesSidebarPluginItem* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_can_eject;
	return result;
}

void
files_sidebar_plugin_item_set_can_eject (FilesSidebarPluginItem* self,
                                         gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_can_eject (self);
	if (old_value != value) {
		self->priv->_can_eject = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY]);
	}
}

const gchar*
files_sidebar_plugin_item_get_tooltip (FilesSidebarPluginItem* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_tooltip;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_tooltip (FilesSidebarPluginItem* self,
                                       const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_tooltip (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_tooltip);
		self->priv->_tooltip = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY]);
	}
}

GIcon*
files_sidebar_plugin_item_get_action_icon (FilesSidebarPluginItem* self)
{
	GIcon* result;
	GIcon* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_action_icon;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_action_icon (FilesSidebarPluginItem* self,
                                           GIcon* value)
{
	GIcon* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_action_icon (self);
	if (old_value != value) {
		GIcon* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_action_icon);
		self->priv->_action_icon = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY]);
	}
}

gboolean
files_sidebar_plugin_item_get_show_spinner (FilesSidebarPluginItem* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_show_spinner;
	return result;
}

void
files_sidebar_plugin_item_set_show_spinner (FilesSidebarPluginItem* self,
                                            gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_show_spinner (self);
	if (old_value != value) {
		self->priv->_show_spinner = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY]);
	}
}

guint64
files_sidebar_plugin_item_get_free_space (FilesSidebarPluginItem* self)
{
	guint64 result;
	g_return_val_if_fail (self != NULL, 0ULL);
	result = self->priv->_free_space;
	return result;
}

void
files_sidebar_plugin_item_set_free_space (FilesSidebarPluginItem* self,
                                          guint64 value)
{
	guint64 old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_free_space (self);
	if (old_value != value) {
		self->priv->_free_space = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY]);
	}
}

guint64
files_sidebar_plugin_item_get_disk_size (FilesSidebarPluginItem* self)
{
	guint64 result;
	g_return_val_if_fail (self != NULL, 0ULL);
	result = self->priv->_disk_size;
	return result;
}

void
files_sidebar_plugin_item_set_disk_size (FilesSidebarPluginItem* self,
                                         guint64 value)
{
	guint64 old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_disk_size (self);
	if (old_value != value) {
		self->priv->_disk_size = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY]);
	}
}

GActionGroup*
files_sidebar_plugin_item_get_action_group (FilesSidebarPluginItem* self)
{
	GActionGroup* result;
	GActionGroup* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_action_group;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_action_group (FilesSidebarPluginItem* self,
                                            GActionGroup* value)
{
	GActionGroup* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_action_group (self);
	if (old_value != value) {
		GActionGroup* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_action_group);
		self->priv->_action_group = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY]);
	}
}

const gchar*
files_sidebar_plugin_item_get_action_group_namespace (FilesSidebarPluginItem* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_action_group_namespace;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_action_group_namespace (FilesSidebarPluginItem* self,
                                                      const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_action_group_namespace (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_action_group_namespace);
		self->priv->_action_group_namespace = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY]);
	}
}

GMenuModel*
files_sidebar_plugin_item_get_menu_model (FilesSidebarPluginItem* self)
{
	GMenuModel* result;
	GMenuModel* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_menu_model;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_menu_model (FilesSidebarPluginItem* self,
                                          GMenuModel* value)
{
	GMenuModel* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_menu_model (self);
	if (old_value != value) {
		GMenuModel* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_menu_model);
		self->priv->_menu_model = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY]);
	}
}

FilesSidebarCallbackFunc
files_sidebar_plugin_item_get_cb (FilesSidebarPluginItem* self)
{
	FilesSidebarCallbackFunc result;
	FilesSidebarCallbackFunc _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_cb;
	result = _tmp0_;
	return result;
}

void
files_sidebar_plugin_item_set_cb (FilesSidebarPluginItem* self,
                                  FilesSidebarCallbackFunc value)
{
	FilesSidebarCallbackFunc old_value;
	g_return_if_fail (self != NULL);
	old_value = files_sidebar_plugin_item_get_cb (self);
	if (old_value != value) {
		self->priv->_cb = value;
		g_object_notify_by_pspec ((GObject *) self, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY]);
	}
}

static void
files_sidebar_plugin_item_class_init (FilesSidebarPluginItemClass * klass,
                                      gpointer klass_data)
{
	files_sidebar_plugin_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &FilesSidebarPluginItem_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_files_sidebar_plugin_item_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_files_sidebar_plugin_item_set_property;
	G_OBJECT_CLASS (klass)->finalize = files_sidebar_plugin_item_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY] = g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY] = g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY] = g_param_spec_object ("drive", "drive", "drive", g_drive_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY] = g_param_spec_object ("volume", "volume", "volume", g_volume_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY] = g_param_spec_object ("mount", "mount", "mount", g_mount_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY] = g_param_spec_object ("icon", "icon", "icon", g_icon_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY] = g_param_spec_uint ("index", "index", "index", 0, G_MAXUINT, 0U, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY] = g_param_spec_boolean ("can-eject", "can-eject", "can-eject", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY] = g_param_spec_string ("tooltip", "tooltip", "tooltip", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY] = g_param_spec_object ("action-icon", "action-icon", "action-icon", g_icon_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY] = g_param_spec_boolean ("show-spinner", "show-spinner", "show-spinner", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY] = g_param_spec_uint64 ("free-space", "free-space", "free-space", 0, G_MAXUINT64, (guint64) 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY] = g_param_spec_uint64 ("disk-size", "disk-size", "disk-size", 0, G_MAXUINT64, (guint64) 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY] = g_param_spec_object ("action-group", "action-group", "action-group", g_action_group_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY] = g_param_spec_string ("action-group-namespace", "action-group-namespace", "action-group-namespace", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY] = g_param_spec_object ("menu-model", "menu-model", "menu-model", g_menu_model_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY, files_sidebar_plugin_item_properties[FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY] = g_param_spec_pointer ("cb", "cb", "cb", G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
}

static void
files_sidebar_plugin_item_instance_init (FilesSidebarPluginItem * self,
                                         gpointer klass)
{
	self->priv = files_sidebar_plugin_item_get_instance_private (self);
	self->priv->_show_spinner = FALSE;
	self->priv->_free_space = (guint64) 0;
	self->priv->_disk_size = (guint64) 0;
}

static void
files_sidebar_plugin_item_finalize (GObject * obj)
{
	FilesSidebarPluginItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_TYPE_SIDEBAR_PLUGIN_ITEM, FilesSidebarPluginItem);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_uri);
	_g_object_unref0 (self->priv->_drive);
	_g_object_unref0 (self->priv->_volume);
	_g_object_unref0 (self->priv->_mount);
	_g_object_unref0 (self->priv->_icon);
	_g_free0 (self->priv->_tooltip);
	_g_object_unref0 (self->priv->_action_icon);
	_g_object_unref0 (self->priv->_action_group);
	_g_free0 (self->priv->_action_group_namespace);
	_g_object_unref0 (self->priv->_menu_model);
	G_OBJECT_CLASS (files_sidebar_plugin_item_parent_class)->finalize (obj);
}

/***
    Copyright (c) 2018 elementary LLC <https://elementary.io>

    Pantheon Files is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.

    Pantheon Files is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program.  If not, see <http://www.gnu.org/licenses/>.

    Author(s):  Fernando da Silva Sousa <wild.nando@gmail.com>
***/
static GType
files_sidebar_plugin_item_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesSidebarPluginItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_sidebar_plugin_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesSidebarPluginItem), 0, (GInstanceInitFunc) files_sidebar_plugin_item_instance_init, NULL };
	GType files_sidebar_plugin_item_type_id;
	files_sidebar_plugin_item_type_id = g_type_register_static (G_TYPE_OBJECT, "FilesSidebarPluginItem", &g_define_type_info, 0);
	FilesSidebarPluginItem_private_offset = g_type_add_instance_private (files_sidebar_plugin_item_type_id, sizeof (FilesSidebarPluginItemPrivate));
	return files_sidebar_plugin_item_type_id;
}

GType
files_sidebar_plugin_item_get_type (void)
{
	static volatile gsize files_sidebar_plugin_item_type_id__once = 0;
	if (g_once_init_enter (&files_sidebar_plugin_item_type_id__once)) {
		GType files_sidebar_plugin_item_type_id;
		files_sidebar_plugin_item_type_id = files_sidebar_plugin_item_get_type_once ();
		g_once_init_leave (&files_sidebar_plugin_item_type_id__once, files_sidebar_plugin_item_type_id);
	}
	return files_sidebar_plugin_item_type_id__once;
}

static void
_vala_files_sidebar_plugin_item_get_property (GObject * object,
                                              guint property_id,
                                              GValue * value,
                                              GParamSpec * pspec)
{
	FilesSidebarPluginItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_TYPE_SIDEBAR_PLUGIN_ITEM, FilesSidebarPluginItem);
	switch (property_id) {
		case FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY:
		g_value_set_string (value, files_sidebar_plugin_item_get_name (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY:
		g_value_set_string (value, files_sidebar_plugin_item_get_uri (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_drive (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_volume (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_mount (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_icon (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY:
		g_value_set_uint (value, files_sidebar_plugin_item_get_index (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY:
		g_value_set_boolean (value, files_sidebar_plugin_item_get_can_eject (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY:
		g_value_set_string (value, files_sidebar_plugin_item_get_tooltip (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_action_icon (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY:
		g_value_set_boolean (value, files_sidebar_plugin_item_get_show_spinner (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY:
		g_value_set_uint64 (value, files_sidebar_plugin_item_get_free_space (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY:
		g_value_set_uint64 (value, files_sidebar_plugin_item_get_disk_size (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_action_group (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY:
		g_value_set_string (value, files_sidebar_plugin_item_get_action_group_namespace (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY:
		g_value_set_object (value, files_sidebar_plugin_item_get_menu_model (self));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY:
		g_value_set_pointer (value, files_sidebar_plugin_item_get_cb (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_files_sidebar_plugin_item_set_property (GObject * object,
                                              guint property_id,
                                              const GValue * value,
                                              GParamSpec * pspec)
{
	FilesSidebarPluginItem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_TYPE_SIDEBAR_PLUGIN_ITEM, FilesSidebarPluginItem);
	switch (property_id) {
		case FILES_SIDEBAR_PLUGIN_ITEM_NAME_PROPERTY:
		files_sidebar_plugin_item_set_name (self, g_value_get_string (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_URI_PROPERTY:
		files_sidebar_plugin_item_set_uri (self, g_value_get_string (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_DRIVE_PROPERTY:
		files_sidebar_plugin_item_set_drive (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_VOLUME_PROPERTY:
		files_sidebar_plugin_item_set_volume (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_MOUNT_PROPERTY:
		files_sidebar_plugin_item_set_mount (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ICON_PROPERTY:
		files_sidebar_plugin_item_set_icon (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_INDEX_PROPERTY:
		files_sidebar_plugin_item_set_index (self, g_value_get_uint (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_CAN_EJECT_PROPERTY:
		files_sidebar_plugin_item_set_can_eject (self, g_value_get_boolean (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_TOOLTIP_PROPERTY:
		files_sidebar_plugin_item_set_tooltip (self, g_value_get_string (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_ICON_PROPERTY:
		files_sidebar_plugin_item_set_action_icon (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_SHOW_SPINNER_PROPERTY:
		files_sidebar_plugin_item_set_show_spinner (self, g_value_get_boolean (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_FREE_SPACE_PROPERTY:
		files_sidebar_plugin_item_set_free_space (self, g_value_get_uint64 (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_DISK_SIZE_PROPERTY:
		files_sidebar_plugin_item_set_disk_size (self, g_value_get_uint64 (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_PROPERTY:
		files_sidebar_plugin_item_set_action_group (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_ACTION_GROUP_NAMESPACE_PROPERTY:
		files_sidebar_plugin_item_set_action_group_namespace (self, g_value_get_string (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_MENU_MODEL_PROPERTY:
		files_sidebar_plugin_item_set_menu_model (self, g_value_get_object (value));
		break;
		case FILES_SIDEBAR_PLUGIN_ITEM_CB_PROPERTY:
		files_sidebar_plugin_item_set_cb (self, g_value_get_pointer (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
