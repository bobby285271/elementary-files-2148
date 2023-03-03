/* plugin.c generated by valac 0.56.3, the Vala compiler
 * generated from plugin.vala, do not modify */

#include "pantheon-files-cloudproviders.h"
#include "pantheon-files-core.h"
#include <cloudproviders/cloudproviders.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_ptr_array_unref0(var) ((var == NULL) ? NULL : (var = (g_ptr_array_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _files_plugins_base_unref0(var) ((var == NULL) ? NULL : (var = (files_plugins_base_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FilesPluginsCloudPluginPrivate {
	FilesSidebarInterface* sidebar;
	CloudProvidersCollector* collector;
	GPtrArray* providers_connected;
	GRecMutex __lock_providers_connected;
};

struct _Block1Data {
	int _ref_count_;
	FilesPluginsCloudPlugin* self;
	guint32 reference;
	CloudProvidersAccount* account;
	CloudProvidersProvider* provider;
};

static gint FilesPluginsCloudPlugin_private_offset;
static gpointer files_plugins_cloud_plugin_parent_class = NULL;

static void _g_object_unref0_ (gpointer var);
static void files_plugins_cloud_plugin_on_providers_changes (FilesPluginsCloudPlugin* self);
static void _files_plugins_cloud_plugin_on_providers_changes_cloud_providers_collector_providers_changed (CloudProvidersCollector* _sender,
                                                                                                   gpointer self);
static void files_plugins_cloud_plugin_real_sidebar_loaded (FilesPluginsBase* base,
                                                     GtkWidget* widget);
static void files_plugins_cloud_plugin_real_update_sidebar (FilesPluginsBase* base,
                                                     GtkWidget* widget);
static void files_plugins_cloud_plugin_add_account_to_sidebar (FilesPluginsCloudPlugin* self,
                                                        CloudProvidersAccount* account,
                                                        CloudProvidersProvider* provider);
static void files_plugins_cloud_plugin_on_accounts_changed (FilesPluginsCloudPlugin* self);
static void _files_plugins_cloud_plugin_on_accounts_changed_cloud_providers_provider_accounts_changed (CloudProvidersProvider* _sender,
                                                                                                gpointer self);
static void files_plugins_cloud_plugin_request_sidebar_update (FilesPluginsCloudPlugin* self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static FilesSidebarPluginItem* files_plugins_cloud_plugin_adapt_plugin_item (CloudProvidersProvider* provider,
                                                                      CloudProvidersAccount* account);
static void __lambda4_ (Block1Data* _data1_);
static void ___lambda4__g_object_notify (GObject* _sender,
                                  GParamSpec* pspec,
                                  gpointer self);
static GIcon* files_plugins_cloud_plugin_get_icon (CloudProvidersAccountStatus status);
static void files_plugins_cloud_plugin_finalize (FilesPluginsBase * obj);
static GType files_plugins_cloud_plugin_get_type_once (void);

static inline gpointer
files_plugins_cloud_plugin_get_instance_private (FilesPluginsCloudPlugin* self)
{
	return G_STRUCT_MEMBER_P (self, FilesPluginsCloudPlugin_private_offset);
}

static void
_g_object_unref0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}

static void
_files_plugins_cloud_plugin_on_providers_changes_cloud_providers_collector_providers_changed (CloudProvidersCollector* _sender,
                                                                                              gpointer self)
{
	files_plugins_cloud_plugin_on_providers_changes ((FilesPluginsCloudPlugin*) self);
}

FilesPluginsCloudPlugin*
files_plugins_cloud_plugin_construct (GType object_type)
{
	FilesPluginsCloudPlugin* self = NULL;
	GPtrArray* _tmp0_;
	CloudProvidersCollector* _tmp1_;
	CloudProvidersCollector* _tmp2_;
	self = (FilesPluginsCloudPlugin*) files_plugins_base_construct (object_type);
	_tmp0_ = g_ptr_array_new_full ((guint) 0, _g_object_unref0_);
	_g_ptr_array_unref0 (self->priv->providers_connected);
	self->priv->providers_connected = _tmp0_;
	_tmp1_ = cloud_providers_collector_dup_singleton ();
	_g_object_unref0 (self->priv->collector);
	self->priv->collector = _tmp1_;
	_tmp2_ = self->priv->collector;
	g_signal_connect (_tmp2_, "providers-changed", (GCallback) _files_plugins_cloud_plugin_on_providers_changes_cloud_providers_collector_providers_changed, self);
	return self;
}

FilesPluginsCloudPlugin*
files_plugins_cloud_plugin_new (void)
{
	return files_plugins_cloud_plugin_construct (FILES_PLUGINS_CLOUD_TYPE_PLUGIN);
}

/**
     * Assign loaded sidebar to plugin's sidebar reference
     *
     * @param a instance of Files.AbstractSidebar
     */
static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
files_plugins_cloud_plugin_real_sidebar_loaded (FilesPluginsBase* base,
                                                GtkWidget* widget)
{
	FilesPluginsCloudPlugin * self;
	FilesSidebarInterface* _tmp0_;
	self = (FilesPluginsCloudPlugin*) base;
	g_return_if_fail (widget != NULL);
	_tmp0_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_CAST (widget, FILES_TYPE_SIDEBAR_INTERFACE, FilesSidebarInterface));
	_g_object_unref0 (self->priv->sidebar);
	self->priv->sidebar = _tmp0_;
	files_plugins_cloud_plugin_on_providers_changes (self);
}

/**
     * Plugin hook that triggers when sidebar receives a update request on
     * Files's code
     *
     * @param a instance of Files.AbstractSidebar
     */
static void
files_plugins_cloud_plugin_real_update_sidebar (FilesPluginsBase* base,
                                                GtkWidget* widget)
{
	FilesPluginsCloudPlugin * self;
	CloudProvidersCollector* _tmp0_;
	GList* _tmp1_;
	self = (FilesPluginsCloudPlugin*) base;
	g_return_if_fail (widget != NULL);
	_tmp0_ = self->priv->collector;
	_tmp1_ = cloud_providers_collector_get_providers (_tmp0_);
	{
		GList* provider_collection = NULL;
		GList* provider_it = NULL;
		provider_collection = _tmp1_;
		for (provider_it = provider_collection; provider_it != NULL; provider_it = provider_it->next) {
			CloudProvidersProvider* _tmp2_;
			CloudProvidersProvider* provider = NULL;
			_tmp2_ = _g_object_ref0 ((CloudProvidersProvider*) provider_it->data);
			provider = _tmp2_;
			{
				CloudProvidersProvider* _tmp3_;
				GList* _tmp4_;
				_tmp3_ = provider;
				_tmp4_ = cloud_providers_provider_get_accounts (_tmp3_);
				{
					GList* account_collection = NULL;
					GList* account_it = NULL;
					account_collection = _tmp4_;
					for (account_it = account_collection; account_it != NULL; account_it = account_it->next) {
						CloudProvidersAccount* _tmp5_;
						CloudProvidersAccount* account = NULL;
						_tmp5_ = _g_object_ref0 ((CloudProvidersAccount*) account_it->data);
						account = _tmp5_;
						{
							CloudProvidersAccount* _tmp6_;
							CloudProvidersProvider* _tmp7_;
							_tmp6_ = account;
							_tmp7_ = provider;
							files_plugins_cloud_plugin_add_account_to_sidebar (self, _tmp6_, _tmp7_);
							_g_object_unref0 (account);
						}
					}
				}
				_g_object_unref0 (provider);
			}
		}
	}
}

static void
_files_plugins_cloud_plugin_on_accounts_changed_cloud_providers_provider_accounts_changed (CloudProvidersProvider* _sender,
                                                                                           gpointer self)
{
	files_plugins_cloud_plugin_on_accounts_changed ((FilesPluginsCloudPlugin*) self);
}

static gint
vala_g_ptr_array_get_length (GPtrArray* self)
{
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = (gint) self->len;
	return result;
}

static void
files_plugins_cloud_plugin_on_providers_changes (FilesPluginsCloudPlugin* self)
{
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	{
		GPtrArray* _tmp0_;
		_tmp0_ = self->priv->providers_connected;
		g_rec_mutex_lock (&self->priv->__lock_providers_connected);
		{
			GList* providers = NULL;
			CloudProvidersCollector* _tmp1_;
			GList* _tmp2_;
			GList* _tmp3_;
			_tmp1_ = self->priv->collector;
			_tmp2_ = cloud_providers_collector_get_providers (_tmp1_);
			providers = _tmp2_;
			_tmp3_ = providers;
			{
				GList* provider_collection = NULL;
				GList* provider_it = NULL;
				provider_collection = _tmp3_;
				for (provider_it = provider_collection; provider_it != NULL; provider_it = provider_it->next) {
					CloudProvidersProvider* provider = NULL;
					provider = (CloudProvidersProvider*) provider_it->data;
					{
						GPtrArray* _tmp4_;
						CloudProvidersProvider* _tmp5_;
						_tmp4_ = self->priv->providers_connected;
						_tmp5_ = provider;
						if (!g_ptr_array_find (_tmp4_, _tmp5_, NULL)) {
							GPtrArray* _tmp6_;
							CloudProvidersProvider* _tmp7_;
							CloudProvidersProvider* _tmp8_;
							CloudProvidersProvider* _tmp9_;
							_tmp6_ = self->priv->providers_connected;
							_tmp7_ = provider;
							_tmp8_ = _g_object_ref0 (_tmp7_);
							g_ptr_array_add (_tmp6_, _tmp8_);
							_tmp9_ = provider;
							g_signal_connect (_tmp9_, "accounts-changed", (GCallback) _files_plugins_cloud_plugin_on_accounts_changed_cloud_providers_provider_accounts_changed, self);
						}
					}
				}
			}
			{
				guint i = 0U;
				GPtrArray* _tmp10_;
				gint _tmp11_;
				gint _tmp12_;
				_tmp10_ = self->priv->providers_connected;
				_tmp11_ = vala_g_ptr_array_get_length (_tmp10_);
				_tmp12_ = _tmp11_;
				i = (guint) _tmp12_;
				{
					gboolean _tmp13_ = FALSE;
					_tmp13_ = TRUE;
					while (TRUE) {
						CloudProvidersProvider* provider = NULL;
						GPtrArray* _tmp15_;
						gconstpointer _tmp16_;
						GList* _tmp17_;
						CloudProvidersProvider* _tmp18_;
						GList* _tmp19_;
						if (!_tmp13_) {
							guint _tmp14_;
							_tmp14_ = i;
							i = _tmp14_ - 1;
						}
						_tmp13_ = FALSE;
						if (!(i > ((guint) 0))) {
							break;
						}
						_tmp15_ = self->priv->providers_connected;
						_tmp16_ = g_ptr_array_index (_tmp15_, i - 1);
						provider = (CloudProvidersProvider*) _tmp16_;
						_tmp17_ = providers;
						_tmp18_ = provider;
						_tmp19_ = g_list_find (_tmp17_, _tmp18_);
						if (_tmp19_ == NULL) {
							CloudProvidersProvider* _tmp20_;
							guint _tmp21_;
							GPtrArray* _tmp22_;
							_tmp20_ = provider;
							g_signal_parse_name ("accounts-changed", cloud_providers_provider_get_type (), &_tmp21_, NULL, FALSE);
							g_signal_handlers_disconnect_matched (_tmp20_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp21_, 0, NULL, (GCallback) _files_plugins_cloud_plugin_on_accounts_changed_cloud_providers_provider_accounts_changed, self);
							_tmp22_ = self->priv->providers_connected;
							g_ptr_array_remove_index_fast (_tmp22_, i - 1);
						}
					}
				}
			}
		}
		__finally0:
		{
			GPtrArray* _tmp23_;
			_tmp23_ = self->priv->providers_connected;
			g_rec_mutex_unlock (&self->priv->__lock_providers_connected);
		}
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
	}
	files_plugins_cloud_plugin_request_sidebar_update (self);
}

static void
files_plugins_cloud_plugin_on_accounts_changed (FilesPluginsCloudPlugin* self)
{
	g_return_if_fail (self != NULL);
	files_plugins_cloud_plugin_request_sidebar_update (self);
}

static void
files_plugins_cloud_plugin_request_sidebar_update (FilesPluginsCloudPlugin* self)
{
	FilesSidebarInterface* _tmp0_;
	FilesSidebarInterface* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->sidebar;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp1_ = self->priv->sidebar;
	files_sidebar_interface_reload (_tmp1_);
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
		FilesPluginsCloudPlugin* self;
		self = _data1_->self;
		_g_object_unref0 (_data1_->account);
		_g_object_unref0 (_data1_->provider);
		_files_plugins_base_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}

static void
__lambda4_ (Block1Data* _data1_)
{
	FilesPluginsCloudPlugin* self;
	FilesSidebarInterface* _tmp0_;
	FilesSidebarInterface* _tmp1_;
	FilesSidebarPluginItem* _tmp2_;
	FilesSidebarPluginItem* _tmp3_;
	self = _data1_->self;
	_tmp0_ = self->priv->sidebar;
	g_return_if_fail (_tmp0_ != NULL);
	_tmp1_ = self->priv->sidebar;
	_tmp2_ = files_plugins_cloud_plugin_adapt_plugin_item (_data1_->provider, _data1_->account);
	_tmp3_ = _tmp2_;
	files_sidebar_interface_update_plugin_item (_tmp1_, _tmp3_, _data1_->reference);
	_g_object_unref0 (_tmp3_);
}

static void
___lambda4__g_object_notify (GObject* _sender,
                             GParamSpec* pspec,
                             gpointer self)
{
	__lambda4_ (self);
}

static void
files_plugins_cloud_plugin_add_account_to_sidebar (FilesPluginsCloudPlugin* self,
                                                   CloudProvidersAccount* account,
                                                   CloudProvidersProvider* provider)
{
	Block1Data* _data1_;
	CloudProvidersAccount* _tmp0_;
	CloudProvidersProvider* _tmp1_;
	GMenuModel* _tmp2_;
	GMenuModel* _tmp3_;
	FilesSidebarInterface* _tmp4_;
	FilesSidebarPluginItem* _tmp5_;
	FilesSidebarPluginItem* _tmp6_;
	guint32 _tmp7_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (account != NULL);
	g_return_if_fail (provider != NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = files_plugins_base_ref (self);
	_tmp0_ = _g_object_ref0 (account);
	_g_object_unref0 (_data1_->account);
	_data1_->account = _tmp0_;
	_tmp1_ = _g_object_ref0 (provider);
	_g_object_unref0 (_data1_->provider);
	_data1_->provider = _tmp1_;
	_tmp2_ = cloud_providers_account_get_menu_model (_data1_->account);
	_tmp3_ = _tmp2_;
	g_menu_model_get_n_items (_tmp3_);
	_tmp4_ = self->priv->sidebar;
	_tmp5_ = files_plugins_cloud_plugin_adapt_plugin_item (_data1_->provider, _data1_->account);
	_tmp6_ = _tmp5_;
	_tmp7_ = files_sidebar_interface_add_plugin_item (_tmp4_, _tmp6_, FILES_PLACE_TYPE_NETWORK_CATEGORY);
	_g_object_unref0 (_tmp6_);
	_data1_->reference = _tmp7_;
	g_signal_connect_data ((GObject*) _data1_->account, "notify", (GCallback) ___lambda4__g_object_notify, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	block1_data_unref (_data1_);
	_data1_ = NULL;
}

/**
     * Generate a SidebarPluginItem from provider and account information
     */
static FilesSidebarPluginItem*
files_plugins_cloud_plugin_adapt_plugin_item (CloudProvidersProvider* provider,
                                              CloudProvidersAccount* account)
{
	FilesSidebarPluginItem* item = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	GIcon* _tmp9_;
	GIcon* _tmp10_;
	GIcon* _tmp11_;
	GActionGroup* _tmp12_;
	GActionGroup* _tmp13_;
	GActionGroup* _tmp14_;
	gchar* _tmp15_;
	GMenuModel* _tmp16_;
	GMenuModel* _tmp17_;
	GMenuModel* _tmp18_;
	GIcon* _tmp19_;
	FilesSidebarPluginItem* _tmp20_ = NULL;
	FilesSidebarPluginItem* result;
	g_return_val_if_fail (provider != NULL, NULL);
	g_return_val_if_fail (account != NULL, NULL);
	_tmp0_ = cloud_providers_account_get_name (account);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strdup (_tmp1_);
	_tmp3_ = cloud_providers_account_get_path (account);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup (_tmp4_);
	_tmp6_ = cloud_providers_account_get_path (account);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strdup (_tmp7_);
	_tmp9_ = cloud_providers_account_get_icon (account);
	_tmp10_ = _tmp9_;
	_tmp11_ = _g_object_ref0 (_tmp10_);
	_tmp12_ = cloud_providers_account_get_action_group (account);
	_tmp13_ = _tmp12_;
	_tmp14_ = _g_object_ref0 (_tmp13_);
	_tmp15_ = g_strdup ("cloudprovider");
	_tmp16_ = cloud_providers_account_get_menu_model (account);
	_tmp17_ = _tmp16_;
	_tmp18_ = _g_object_ref0 (_tmp17_);
	_tmp19_ = files_plugins_cloud_plugin_get_icon (cloud_providers_account_get_status (account));
	_tmp20_ = files_sidebar_plugin_item_new ();
	files_sidebar_plugin_item_set_name (_tmp20_, _tmp2_);
	_g_free0 (_tmp2_);
	files_sidebar_plugin_item_set_tooltip (_tmp20_, _tmp5_);
	_g_free0 (_tmp5_);
	files_sidebar_plugin_item_set_uri (_tmp20_, _tmp8_);
	_g_free0 (_tmp8_);
	files_sidebar_plugin_item_set_icon (_tmp20_, _tmp11_);
	_g_object_unref0 (_tmp11_);
	files_sidebar_plugin_item_set_show_spinner (_tmp20_, cloud_providers_account_get_status (account) == CLOUD_PROVIDERS_ACCOUNT_STATUS_SYNCING);
	files_sidebar_plugin_item_set_action_group (_tmp20_, _tmp14_);
	_g_object_unref0 (_tmp14_);
	files_sidebar_plugin_item_set_action_group_namespace (_tmp20_, _tmp15_);
	_g_free0 (_tmp15_);
	files_sidebar_plugin_item_set_menu_model (_tmp20_, _tmp18_);
	_g_object_unref0 (_tmp18_);
	files_sidebar_plugin_item_set_action_icon (_tmp20_, _tmp19_);
	_g_object_unref0 (_tmp19_);
	item = _tmp20_;
	result = item;
	return result;
}

/**
     * Get icon for current account status
     *
     * @param a status {@link CloudProviders.AccountStatus} of a {@link CloudProviders.Account}
     *
     * @return a error icon if status is error else returns null
     */
static GIcon*
files_plugins_cloud_plugin_get_icon (CloudProvidersAccountStatus status)
{
	GThemedIcon* _tmp0_ = NULL;
	GIcon* result;
	if (status == CLOUD_PROVIDERS_ACCOUNT_STATUS_ERROR) {
		GThemedIcon* _tmp1_;
		_tmp1_ = (GThemedIcon*) g_themed_icon_new_with_default_fallbacks ("dialog-error-symbolic");
		_g_object_unref0 (_tmp0_);
		_tmp0_ = _tmp1_;
	} else {
		_g_object_unref0 (_tmp0_);
		_tmp0_ = NULL;
	}
	result = (GIcon*) _tmp0_;
	return result;
}

static void
files_plugins_cloud_plugin_class_init (FilesPluginsCloudPluginClass * klass,
                                       gpointer klass_data)
{
	files_plugins_cloud_plugin_parent_class = g_type_class_peek_parent (klass);
	((FilesPluginsBaseClass *) klass)->finalize = files_plugins_cloud_plugin_finalize;
	g_type_class_adjust_private_offset (klass, &FilesPluginsCloudPlugin_private_offset);
	((FilesPluginsBaseClass *) klass)->sidebar_loaded = (void (*) (FilesPluginsBase*, GtkWidget*)) files_plugins_cloud_plugin_real_sidebar_loaded;
	((FilesPluginsBaseClass *) klass)->update_sidebar = (void (*) (FilesPluginsBase*, GtkWidget*)) files_plugins_cloud_plugin_real_update_sidebar;
}

static void
files_plugins_cloud_plugin_instance_init (FilesPluginsCloudPlugin * self,
                                          gpointer klass)
{
	self->priv = files_plugins_cloud_plugin_get_instance_private (self);
	g_rec_mutex_init (&self->priv->__lock_providers_connected);
}

static void
files_plugins_cloud_plugin_finalize (FilesPluginsBase * obj)
{
	FilesPluginsCloudPlugin * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_PLUGINS_CLOUD_TYPE_PLUGIN, FilesPluginsCloudPlugin);
	_g_object_unref0 (self->priv->sidebar);
	_g_object_unref0 (self->priv->collector);
	g_rec_mutex_clear (&self->priv->__lock_providers_connected);
	_g_ptr_array_unref0 (self->priv->providers_connected);
	FILES_PLUGINS_BASE_CLASS (files_plugins_cloud_plugin_parent_class)->finalize (obj);
}

/***
    Copyright (c) 2019 elementary LLC <https://elementary.io>

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
files_plugins_cloud_plugin_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesPluginsCloudPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_plugins_cloud_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesPluginsCloudPlugin), 0, (GInstanceInitFunc) files_plugins_cloud_plugin_instance_init, NULL };
	GType files_plugins_cloud_plugin_type_id;
	files_plugins_cloud_plugin_type_id = g_type_register_static (FILES_PLUGINS_TYPE_BASE, "FilesPluginsCloudPlugin", &g_define_type_info, 0);
	FilesPluginsCloudPlugin_private_offset = g_type_add_instance_private (files_plugins_cloud_plugin_type_id, sizeof (FilesPluginsCloudPluginPrivate));
	return files_plugins_cloud_plugin_type_id;
}

GType
files_plugins_cloud_plugin_get_type (void)
{
	static volatile gsize files_plugins_cloud_plugin_type_id__once = 0;
	if (g_once_init_enter (&files_plugins_cloud_plugin_type_id__once)) {
		GType files_plugins_cloud_plugin_type_id;
		files_plugins_cloud_plugin_type_id = files_plugins_cloud_plugin_get_type_once ();
		g_once_init_leave (&files_plugins_cloud_plugin_type_id__once, files_plugins_cloud_plugin_type_id);
	}
	return files_plugins_cloud_plugin_type_id__once;
}

FilesPluginsBase*
module_init (void)
{
	FilesPluginsCloudPlugin* _tmp0_;
	FilesPluginsBase* result;
	_tmp0_ = files_plugins_cloud_plugin_new ();
	result = (FilesPluginsBase*) _tmp0_;
	return result;
}

