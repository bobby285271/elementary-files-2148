/* ProgressInfoWidget.c generated by valac 0.56.3, the Vala compiler
 * generated from ProgressInfoWidget.vala, do not modify */

/*
* Copyright 2013-2020 elementary, Inc. <https://elementary.io>
*           2007, 2011 Red Hat, Inc.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation.
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
* Authors: Alexander Larsson <alexl@redhat.com>
*          Cosimo Cecchi <cosimoc@redhat.com>
*          Julián Unrrein <junrrein@gmail.com>
*/

#include <gtk/gtk.h>
#include <glib-object.h>
#include "pantheon-files-core.h"
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
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

#define FILES_PROGRESS_TYPE_INFO_WIDGET (files_progress_info_widget_get_type ())
#define FILES_PROGRESS_INFO_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidget))
#define FILES_PROGRESS_INFO_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidgetClass))
#define FILES_PROGRESS_IS_INFO_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_PROGRESS_TYPE_INFO_WIDGET))
#define FILES_PROGRESS_IS_INFO_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_PROGRESS_TYPE_INFO_WIDGET))
#define FILES_PROGRESS_INFO_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidgetClass))

typedef struct _FilesProgressInfoWidget FilesProgressInfoWidget;
typedef struct _FilesProgressInfoWidgetClass FilesProgressInfoWidgetClass;
typedef struct _FilesProgressInfoWidgetPrivate FilesProgressInfoWidgetPrivate;
enum  {
	FILES_PROGRESS_INFO_WIDGET_0_PROPERTY,
	FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY,
	FILES_PROGRESS_INFO_WIDGET_NUM_PROPERTIES
};
static GParamSpec* files_progress_info_widget_properties[FILES_PROGRESS_INFO_WIDGET_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block52Data Block52Data;
enum  {
	FILES_PROGRESS_INFO_WIDGET_CANCELLED_SIGNAL,
	FILES_PROGRESS_INFO_WIDGET_NUM_SIGNALS
};
static guint files_progress_info_widget_signals[FILES_PROGRESS_INFO_WIDGET_NUM_SIGNALS] = {0};

struct _FilesProgressInfoWidget {
	GtkGrid parent_instance;
	FilesProgressInfoWidgetPrivate * priv;
};

struct _FilesProgressInfoWidgetClass {
	GtkGridClass parent_class;
};

struct _FilesProgressInfoWidgetPrivate {
	PFProgressInfo* _info;
	GtkLabel* status;
	GtkLabel* details;
	GtkProgressBar* progress_bar;
};

struct _Block52Data {
	int _ref_count_;
	FilesProgressInfoWidget* self;
	GtkButton* button;
};

static gint FilesProgressInfoWidget_private_offset;
static gpointer files_progress_info_widget_parent_class = NULL;

VALA_EXTERN GType files_progress_info_widget_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesProgressInfoWidget, g_object_unref)
VALA_EXTERN FilesProgressInfoWidget* files_progress_info_widget_new (PFProgressInfo* info);
VALA_EXTERN FilesProgressInfoWidget* files_progress_info_widget_construct (GType object_type,
                                                               PFProgressInfo* info);
static void files_progress_info_widget_update_data (FilesProgressInfoWidget* self);
VALA_EXTERN PFProgressInfo* files_progress_info_widget_get_info (FilesProgressInfoWidget* self);
static void files_progress_info_widget_update_progress (FilesProgressInfoWidget* self);
static void files_progress_info_widget_set_info (FilesProgressInfoWidget* self,
                                          PFProgressInfo* value);
static GObject * files_progress_info_widget_constructor (GType type,
                                                  guint n_construct_properties,
                                                  GObjectConstructParam * construct_properties);
static Block52Data* block52_data_ref (Block52Data* _data52_);
static void block52_data_unref (void * _userdata_);
static void _files_progress_info_widget_update_data_pf_progress_info_changed (PFProgressInfo* _sender,
                                                                       gpointer self);
static void _files_progress_info_widget_update_progress_pf_progress_info_progress_changed (PFProgressInfo* _sender,
                                                                                    gpointer self);
static void _files_progress_info_widget___lambda8_ (FilesProgressInfoWidget* self);
static void __files_progress_info_widget___lambda8__pf_progress_info_finished (PFProgressInfo* _sender,
                                                                        gpointer self);
static void _files_progress_info_widget___lambda9_ (Block52Data* _data52_);
static void __files_progress_info_widget___lambda9__gtk_button_clicked (GtkButton* _sender,
                                                                 gpointer self);
static void files_progress_info_widget_finalize (GObject * obj);
static GType files_progress_info_widget_get_type_once (void);
static void _vala_files_progress_info_widget_get_property (GObject * object,
                                                    guint property_id,
                                                    GValue * value,
                                                    GParamSpec * pspec);
static void _vala_files_progress_info_widget_set_property (GObject * object,
                                                    guint property_id,
                                                    const GValue * value,
                                                    GParamSpec * pspec);

static inline gpointer
files_progress_info_widget_get_instance_private (FilesProgressInfoWidget* self)
{
	return G_STRUCT_MEMBER_P (self, FilesProgressInfoWidget_private_offset);
}

FilesProgressInfoWidget*
files_progress_info_widget_construct (GType object_type,
                                      PFProgressInfo* info)
{
	FilesProgressInfoWidget * self = NULL;
	g_return_val_if_fail (info != NULL, NULL);
	self = (FilesProgressInfoWidget*) g_object_new (object_type, "info", info, NULL);
	return self;
}

FilesProgressInfoWidget*
files_progress_info_widget_new (PFProgressInfo* info)
{
	return files_progress_info_widget_construct (FILES_PROGRESS_TYPE_INFO_WIDGET, info);
}

static void
files_progress_info_widget_update_data (FilesProgressInfoWidget* self)
{
	GtkLabel* _tmp0_;
	PFProgressInfo* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	GtkLabel* _tmp6_;
	PFProgressInfo* _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->status;
	_tmp1_ = self->priv->_info;
	_tmp2_ = pf_progress_info_get_status (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_markup_printf_escaped ("<span font-features='tnum'>%s</span>", _tmp3_);
	_tmp5_ = _tmp4_;
	gtk_label_set_markup (_tmp0_, _tmp5_);
	_g_free0 (_tmp5_);
	_tmp6_ = self->priv->details;
	_tmp7_ = self->priv->_info;
	_tmp8_ = pf_progress_info_get_details (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_markup_printf_escaped ("<span size='small' font-features='tnum'>%s</span>", _tmp9_);
	_tmp11_ = _tmp10_;
	gtk_label_set_markup (_tmp6_, _tmp11_);
	_g_free0 (_tmp11_);
}

static void
files_progress_info_widget_update_progress (FilesProgressInfoWidget* self)
{
	gdouble progress = 0.0;
	PFProgressInfo* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_info;
	_tmp1_ = pf_progress_info_get_progress (_tmp0_);
	_tmp2_ = _tmp1_;
	progress = _tmp2_;
	if (progress < ((gdouble) 0)) {
		GtkProgressBar* _tmp3_;
		_tmp3_ = self->priv->progress_bar;
		gtk_progress_bar_pulse (_tmp3_);
	} else {
		GtkProgressBar* _tmp4_;
		_tmp4_ = self->priv->progress_bar;
		gtk_progress_bar_set_fraction (_tmp4_, progress);
	}
}

PFProgressInfo*
files_progress_info_widget_get_info (FilesProgressInfoWidget* self)
{
	PFProgressInfo* result;
	PFProgressInfo* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_info;
	result = _tmp0_;
	return result;
}

static void
files_progress_info_widget_set_info (FilesProgressInfoWidget* self,
                                     PFProgressInfo* value)
{
	PFProgressInfo* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_progress_info_widget_get_info (self);
	if (old_value != value) {
		self->priv->_info = value;
		g_object_notify_by_pspec ((GObject *) self, files_progress_info_widget_properties[FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY]);
	}
}

static Block52Data*
block52_data_ref (Block52Data* _data52_)
{
	g_atomic_int_inc (&_data52_->_ref_count_);
	return _data52_;
}

static void
block52_data_unref (void * _userdata_)
{
	Block52Data* _data52_;
	_data52_ = (Block52Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data52_->_ref_count_)) {
		FilesProgressInfoWidget* self;
		self = _data52_->self;
		_g_object_unref0 (_data52_->button);
		_g_object_unref0 (self);
		g_slice_free (Block52Data, _data52_);
	}
}

static void
_files_progress_info_widget_update_data_pf_progress_info_changed (PFProgressInfo* _sender,
                                                                  gpointer self)
{
	files_progress_info_widget_update_data ((FilesProgressInfoWidget*) self);
}

static void
_files_progress_info_widget_update_progress_pf_progress_info_progress_changed (PFProgressInfo* _sender,
                                                                               gpointer self)
{
	files_progress_info_widget_update_progress ((FilesProgressInfoWidget*) self);
}

static void
_files_progress_info_widget___lambda8_ (FilesProgressInfoWidget* self)
{
	gtk_widget_destroy ((GtkWidget*) self);
}

static void
__files_progress_info_widget___lambda8__pf_progress_info_finished (PFProgressInfo* _sender,
                                                                   gpointer self)
{
	_files_progress_info_widget___lambda8_ ((FilesProgressInfoWidget*) self);
}

static void
_files_progress_info_widget___lambda9_ (Block52Data* _data52_)
{
	FilesProgressInfoWidget* self;
	PFProgressInfo* _tmp0_;
	PFProgressInfo* _tmp1_;
	GtkButton* _tmp2_;
	self = _data52_->self;
	_tmp0_ = self->priv->_info;
	pf_progress_info_cancel (_tmp0_);
	_tmp1_ = self->priv->_info;
	g_signal_emit (self, files_progress_info_widget_signals[FILES_PROGRESS_INFO_WIDGET_CANCELLED_SIGNAL], 0, _tmp1_);
	_tmp2_ = _data52_->button;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp2_, FALSE);
}

static void
__files_progress_info_widget___lambda9__gtk_button_clicked (GtkButton* _sender,
                                                            gpointer self)
{
	_files_progress_info_widget___lambda9_ (self);
}

static GObject *
files_progress_info_widget_constructor (GType type,
                                        guint n_construct_properties,
                                        GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	FilesProgressInfoWidget * self;
	Block52Data* _data52_;
	PFProgressInfo* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GtkLabel* _tmp3_ = NULL;
	GtkProgressBar* _tmp4_ = NULL;
	GtkLabel* _tmp5_ = NULL;
	gchar* _tmp6_;
	GtkButton* _tmp7_ = NULL;
	GtkButton* _tmp8_;
	GtkStyleContext* _tmp9_;
	GtkLabel* _tmp10_;
	GtkProgressBar* _tmp11_;
	GtkButton* _tmp12_;
	GtkLabel* _tmp13_;
	PFProgressInfo* _tmp14_;
	PFProgressInfo* _tmp15_;
	PFProgressInfo* _tmp16_;
	GtkButton* _tmp17_;
	parent_class = G_OBJECT_CLASS (files_progress_info_widget_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidget);
	_data52_ = g_slice_new0 (Block52Data);
	_data52_->_ref_count_ = 1;
	_data52_->self = g_object_ref (self);
	_tmp0_ = self->priv->_info;
	_tmp1_ = pf_progress_info_get_status (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = (GtkLabel*) gtk_label_new (_tmp2_);
	gtk_label_set_use_markup (_tmp3_, TRUE);
	gtk_label_set_max_width_chars (_tmp3_, 50);
	gtk_label_set_selectable (_tmp3_, TRUE);
	gtk_label_set_width_chars (_tmp3_, 50);
	g_object_set (_tmp3_, "wrap", TRUE, NULL);
	gtk_label_set_xalign (_tmp3_, (gfloat) 0);
	g_object_ref_sink (_tmp3_);
	_g_object_unref0 (self->priv->status);
	self->priv->status = _tmp3_;
	_tmp4_ = (GtkProgressBar*) gtk_progress_bar_new ();
	gtk_widget_set_hexpand ((GtkWidget*) _tmp4_, TRUE);
	gtk_progress_bar_set_pulse_step (_tmp4_, 0.05);
	gtk_progress_bar_set_show_text (_tmp4_, FALSE);
	gtk_widget_set_valign ((GtkWidget*) _tmp4_, GTK_ALIGN_CENTER);
	g_object_ref_sink (_tmp4_);
	_g_object_unref0 (self->priv->progress_bar);
	self->priv->progress_bar = _tmp4_;
	_tmp5_ = (GtkLabel*) gtk_label_new ("details");
	gtk_label_set_use_markup (_tmp5_, TRUE);
	gtk_label_set_selectable (_tmp5_, TRUE);
	gtk_label_set_max_width_chars (_tmp5_, 50);
	g_object_set (_tmp5_, "wrap", TRUE, NULL);
	gtk_label_set_xalign (_tmp5_, (gfloat) 0);
	g_object_ref_sink (_tmp5_);
	_g_object_unref0 (self->priv->details);
	self->priv->details = _tmp5_;
	_tmp6_ = g_strdup (_ ("Cancel"));
	_tmp7_ = (GtkButton*) gtk_button_new_from_icon_name ("process-stop-symbolic", (GtkIconSize) GTK_ICON_SIZE_BUTTON);
	gtk_widget_set_tooltip_text ((GtkWidget*) _tmp7_, _tmp6_);
	_g_free0 (_tmp6_);
	g_object_ref_sink (_tmp7_);
	_data52_->button = _tmp7_;
	_tmp8_ = _data52_->button;
	_tmp9_ = gtk_widget_get_style_context ((GtkWidget*) _tmp8_);
	gtk_style_context_add_class (_tmp9_, GTK_STYLE_CLASS_FLAT);
	gtk_grid_set_column_spacing ((GtkGrid*) self, 6);
	_tmp10_ = self->priv->status;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp10_, 0, 0, 2, 1);
	_tmp11_ = self->priv->progress_bar;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp11_, 0, 1, 1, 1);
	_tmp12_ = _data52_->button;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp12_, 1, 1, 1, 1);
	_tmp13_ = self->priv->details;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp13_, 0, 2, 2, 1);
	gtk_widget_show_all ((GtkWidget*) self);
	files_progress_info_widget_update_data (self);
	files_progress_info_widget_update_progress (self);
	_tmp14_ = self->priv->_info;
	g_signal_connect_object (_tmp14_, "changed", (GCallback) _files_progress_info_widget_update_data_pf_progress_info_changed, self, 0);
	_tmp15_ = self->priv->_info;
	g_signal_connect_object (_tmp15_, "progress-changed", (GCallback) _files_progress_info_widget_update_progress_pf_progress_info_progress_changed, self, 0);
	_tmp16_ = self->priv->_info;
	g_signal_connect_object (_tmp16_, "finished", (GCallback) __files_progress_info_widget___lambda8__pf_progress_info_finished, self, 0);
	_tmp17_ = _data52_->button;
	g_signal_connect_data (_tmp17_, "clicked", (GCallback) __files_progress_info_widget___lambda9__gtk_button_clicked, block52_data_ref (_data52_), (GClosureNotify) block52_data_unref, 0);
	block52_data_unref (_data52_);
	_data52_ = NULL;
	return obj;
}

static void
files_progress_info_widget_class_init (FilesProgressInfoWidgetClass * klass,
                                       gpointer klass_data)
{
	files_progress_info_widget_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &FilesProgressInfoWidget_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_files_progress_info_widget_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_files_progress_info_widget_set_property;
	G_OBJECT_CLASS (klass)->constructor = files_progress_info_widget_constructor;
	G_OBJECT_CLASS (klass)->finalize = files_progress_info_widget_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY, files_progress_info_widget_properties[FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY] = g_param_spec_object ("info", "info", "info", PF_PROGRESS_TYPE_INFO, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	files_progress_info_widget_signals[FILES_PROGRESS_INFO_WIDGET_CANCELLED_SIGNAL] = g_signal_new ("cancelled", FILES_PROGRESS_TYPE_INFO_WIDGET, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PF_PROGRESS_TYPE_INFO);
}

static void
files_progress_info_widget_instance_init (FilesProgressInfoWidget * self,
                                          gpointer klass)
{
	self->priv = files_progress_info_widget_get_instance_private (self);
}

static void
files_progress_info_widget_finalize (GObject * obj)
{
	FilesProgressInfoWidget * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidget);
	_g_object_unref0 (self->priv->status);
	_g_object_unref0 (self->priv->details);
	_g_object_unref0 (self->priv->progress_bar);
	G_OBJECT_CLASS (files_progress_info_widget_parent_class)->finalize (obj);
}

static GType
files_progress_info_widget_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesProgressInfoWidgetClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_progress_info_widget_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesProgressInfoWidget), 0, (GInstanceInitFunc) files_progress_info_widget_instance_init, NULL };
	GType files_progress_info_widget_type_id;
	files_progress_info_widget_type_id = g_type_register_static (gtk_grid_get_type (), "FilesProgressInfoWidget", &g_define_type_info, 0);
	FilesProgressInfoWidget_private_offset = g_type_add_instance_private (files_progress_info_widget_type_id, sizeof (FilesProgressInfoWidgetPrivate));
	return files_progress_info_widget_type_id;
}

GType
files_progress_info_widget_get_type (void)
{
	static volatile gsize files_progress_info_widget_type_id__once = 0;
	if (g_once_init_enter (&files_progress_info_widget_type_id__once)) {
		GType files_progress_info_widget_type_id;
		files_progress_info_widget_type_id = files_progress_info_widget_get_type_once ();
		g_once_init_leave (&files_progress_info_widget_type_id__once, files_progress_info_widget_type_id);
	}
	return files_progress_info_widget_type_id__once;
}

static void
_vala_files_progress_info_widget_get_property (GObject * object,
                                               guint property_id,
                                               GValue * value,
                                               GParamSpec * pspec)
{
	FilesProgressInfoWidget * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidget);
	switch (property_id) {
		case FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY:
		g_value_set_object (value, files_progress_info_widget_get_info (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_files_progress_info_widget_set_property (GObject * object,
                                               guint property_id,
                                               const GValue * value,
                                               GParamSpec * pspec)
{
	FilesProgressInfoWidget * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_PROGRESS_TYPE_INFO_WIDGET, FilesProgressInfoWidget);
	switch (property_id) {
		case FILES_PROGRESS_INFO_WIDGET_INFO_PROPERTY:
		files_progress_info_widget_set_info (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

