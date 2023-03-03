/* ProgressInfo.c generated by valac 0.56.3, the Vala compiler
 * generated from ProgressInfo.vala, do not modify */

/* Copyright (c) 2018 elementary LLC (https://elementary.io)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, Inc.,; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
/* Intermediary between a FileOperation and the ProgressUIHandler allowing the UI to show the progress
 * of the operation and also to cancel that operation. */

#include "pantheon-files-core.h"
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <float.h>
#include <math.h>
#include <glib/gi18n-lib.h>
#include <glib-object.h>

#define PF_PROGRESS_INFO_SIGNAL_DELAY_MSEC ((guint) 100)

enum  {
	PF_PROGRESS_INFO_0_PROPERTY,
	PF_PROGRESS_INFO_CANCELLABLE_PROPERTY,
	PF_PROGRESS_INFO_TITLE_PROPERTY,
	PF_PROGRESS_INFO_STATUS_PROPERTY,
	PF_PROGRESS_INFO_DETAILS_PROPERTY,
	PF_PROGRESS_INFO_PROGRESS_PROPERTY,
	PF_PROGRESS_INFO_CURRENT_PROPERTY,
	PF_PROGRESS_INFO_TOTAL_PROPERTY,
	PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY,
	PF_PROGRESS_INFO_IS_STARTED_PROPERTY,
	PF_PROGRESS_INFO_IS_FINISHED_PROPERTY,
	PF_PROGRESS_INFO_IS_PAUSED_PROPERTY,
	PF_PROGRESS_INFO_IS_CANCELLED_PROPERTY,
	PF_PROGRESS_INFO_NUM_PROPERTIES
};
static GParamSpec* pf_progress_info_properties[PF_PROGRESS_INFO_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_source_unref0(var) ((var == NULL) ? NULL : (var = (g_source_unref (var), NULL)))
enum  {
	PF_PROGRESS_INFO_CHANGED_SIGNAL,
	PF_PROGRESS_INFO_PROGRESS_CHANGED_SIGNAL,
	PF_PROGRESS_INFO_STARTED_SIGNAL,
	PF_PROGRESS_INFO_FINISHED_SIGNAL,
	PF_PROGRESS_INFO_NUM_SIGNALS
};
static guint pf_progress_info_signals[PF_PROGRESS_INFO_NUM_SIGNALS] = {0};
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _PFProgressInfoPrivate {
	GCancellable* _cancellable;
	gchar* _title;
	gchar* _status;
	gchar* _details;
	gdouble _progress;
	gdouble _current;
	gdouble _total;
	gboolean _activity_mode;
	gboolean _is_started;
	gboolean _is_finished;
	gboolean _is_paused;
	GSource* idle_source;
	gboolean source_is_now;
	gboolean start_at_idle;
	gboolean finish_at_idle;
	gboolean changed_at_idle;
	gboolean progress_at_idle;
};

static gint PFProgressInfo_private_offset;
static gpointer pf_progress_info_parent_class = NULL;

static void pf_progress_info_set_is_started (PFProgressInfo* self,
                                      gboolean value);
static void pf_progress_info_queue_idle (PFProgressInfo* self,
                                  gboolean now);
static void pf_progress_info_set_is_finished (PFProgressInfo* self,
                                       gboolean value);
static void _pf_progress_info_finish_g_cancellable_cancelled (GCancellable* _sender,
                                                       gpointer self);
static void pf_progress_info_set_is_paused (PFProgressInfo* self,
                                     gboolean value);
static void pf_progress_info_set_status (PFProgressInfo* self,
                                  const gchar* value);
static void pf_progress_info_set_activity_mode (PFProgressInfo* self,
                                         gboolean value);
static void pf_progress_info_set_progress (PFProgressInfo* self,
                                    gdouble value);
static void pf_progress_info_set_current (PFProgressInfo* self,
                                   gdouble value);
static void pf_progress_info_set_total (PFProgressInfo* self,
                                 gdouble value);
static gboolean pf_progress_info_idle_callback (PFProgressInfo* self);
static gboolean _pf_progress_info_idle_callback_gsource_func (gpointer self);
static GObject * pf_progress_info_constructor (GType type,
                                        guint n_construct_properties,
                                        GObjectConstructParam * construct_properties);
static void pf_progress_info_finalize (GObject * obj);
static GType pf_progress_info_get_type_once (void);
static void _vala_pf_progress_info_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec);
static void _vala_pf_progress_info_set_property (GObject * object,
                                          guint property_id,
                                          const GValue * value,
                                          GParamSpec * pspec);

static inline gpointer
pf_progress_info_get_instance_private (PFProgressInfo* self)
{
	return G_STRUCT_MEMBER_P (self, PFProgressInfo_private_offset);
}

PFProgressInfo*
pf_progress_info_construct (GType object_type)
{
	PFProgressInfo * self = NULL;
	self = (PFProgressInfo*) g_object_new (object_type, NULL);
	return self;
}

PFProgressInfo*
pf_progress_info_new (void)
{
	return pf_progress_info_construct (PF_PROGRESS_TYPE_INFO);
}

void
pf_progress_info_cancel (PFProgressInfo* self)
{
	GCancellable* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_cancellable;
	g_cancellable_cancel (_tmp0_);
}

void
pf_progress_info_start (PFProgressInfo* self)
{
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_is_started;
	if (!_tmp0_) {
		pf_progress_info_set_is_started (self, TRUE);
		self->priv->start_at_idle = TRUE;
		pf_progress_info_queue_idle (self, TRUE);
	}
}

static void
_pf_progress_info_finish_g_cancellable_cancelled (GCancellable* _sender,
                                                  gpointer self)
{
	pf_progress_info_finish ((PFProgressInfo*) self);
}

void
pf_progress_info_finish (PFProgressInfo* self)
{
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_is_finished;
	if (!_tmp0_) {
		GCancellable* _tmp1_;
		guint _tmp2_;
		pf_progress_info_set_is_finished (self, TRUE);
		_tmp1_ = self->priv->_cancellable;
		g_signal_parse_name ("cancelled", g_cancellable_get_type (), &_tmp2_, NULL, FALSE);
		g_signal_handlers_disconnect_matched (_tmp1_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp2_, 0, NULL, (GCallback) _pf_progress_info_finish_g_cancellable_cancelled, self);
		self->priv->finish_at_idle = TRUE;
		pf_progress_info_queue_idle (self, TRUE);
	}
}

void
pf_progress_info_pause (PFProgressInfo* self)
{
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_is_paused;
	if (!_tmp0_) {
		pf_progress_info_set_is_paused (self, TRUE);
	}
}

void
pf_progress_info_resume (PFProgressInfo* self)
{
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_is_paused;
	if (_tmp0_) {
		pf_progress_info_set_is_paused (self, FALSE);
	}
}

void
pf_progress_info_take_status (PFProgressInfo* self,
                              gchar* _status)
{
	const gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_status != NULL);
	_tmp0_ = self->priv->_status;
	if (g_strcmp0 (_tmp0_, _status) != 0) {
		pf_progress_info_set_status (self, _status);
		self->priv->changed_at_idle = TRUE;
		pf_progress_info_queue_idle (self, FALSE);
	}
	_g_free0 (_status);
}

void
pf_progress_info_take_details (PFProgressInfo* self,
                               gchar* _details)
{
	const gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (_details != NULL);
	_tmp0_ = self->priv->_details;
	if (g_strcmp0 (_tmp0_, _details) != 0) {
		pf_progress_info_set_details (self, _details);
		self->priv->changed_at_idle = TRUE;
		pf_progress_info_queue_idle (self, FALSE);
	}
	_g_free0 (_details);
}

void
pf_progress_info_update_progress (PFProgressInfo* self,
                                  gdouble current,
                                  gdouble total)
{
	gdouble current_percent = 0.0;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	g_return_if_fail (self != NULL);
	current_percent = 1.0;
	if (total > ((gdouble) 0)) {
		current_percent = MIN (current / total, (gdouble) 1);
		current_percent = MAX (current_percent, (gdouble) 0);
	}
	_tmp1_ = self->priv->_activity_mode;
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gdouble _tmp2_;
		_tmp2_ = self->priv->_progress;
		_tmp0_ = fabs (current_percent - _tmp2_) > 0.005;
	}
	if (_tmp0_) {
		pf_progress_info_set_activity_mode (self, FALSE);
		pf_progress_info_set_progress (self, current_percent);
		pf_progress_info_set_current (self, current);
		pf_progress_info_set_total (self, total);
		self->priv->progress_at_idle = TRUE;
		pf_progress_info_queue_idle (self, FALSE);
	}
}

void
pf_progress_info_pulse_progress (PFProgressInfo* self)
{
	g_return_if_fail (self != NULL);
	pf_progress_info_set_activity_mode (self, TRUE);
	pf_progress_info_set_progress (self, -1.0);
	self->priv->progress_at_idle = TRUE;
	pf_progress_info_queue_idle (self, FALSE);
}

static gboolean
_pf_progress_info_idle_callback_gsource_func (gpointer self)
{
	gboolean result;
	result = pf_progress_info_idle_callback ((PFProgressInfo*) self);
	return result;
}

static void
pf_progress_info_queue_idle (PFProgressInfo* self,
                             gboolean now)
{
	gboolean _tmp0_ = FALSE;
	GSource* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp1_ = self->priv->idle_source;
	if (_tmp1_ == NULL) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp2_ = FALSE;
		if (now) {
			_tmp2_ = !self->priv->source_is_now;
		} else {
			_tmp2_ = FALSE;
		}
		_tmp0_ = _tmp2_;
	}
	if (_tmp0_) {
		GSource* _tmp3_;
		GSource* _tmp7_;
		GSource* _tmp8_;
		_tmp3_ = self->priv->idle_source;
		if (_tmp3_ != NULL) {
			GSource* _tmp4_;
			_tmp4_ = self->priv->idle_source;
			g_source_destroy (_tmp4_);
			_g_source_unref0 (self->priv->idle_source);
			self->priv->idle_source = NULL;
		}
		self->priv->source_is_now = now;
		if (now) {
			GSource* _tmp5_;
			_tmp5_ = g_idle_source_new ();
			_g_source_unref0 (self->priv->idle_source);
			self->priv->idle_source = _tmp5_;
		} else {
			GSource* _tmp6_;
			_tmp6_ = g_timeout_source_new (PF_PROGRESS_INFO_SIGNAL_DELAY_MSEC);
			_g_source_unref0 (self->priv->idle_source);
			self->priv->idle_source = _tmp6_;
		}
		_tmp7_ = self->priv->idle_source;
		g_source_set_callback (_tmp7_, _pf_progress_info_idle_callback_gsource_func, g_object_ref (self), g_object_unref);
		_tmp8_ = self->priv->idle_source;
		g_source_attach (_tmp8_, NULL);
	}
}

static gboolean
pf_progress_info_idle_callback (PFProgressInfo* self)
{
	GSource* source = NULL;
	GSource* _tmp0_;
	GSource* _tmp1_;
	GSource* _tmp2_;
	GSource* _tmp3_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = g_main_current_source ();
	source = _tmp0_;
	_tmp1_ = source;
	if (g_source_is_destroyed (_tmp1_)) {
		result = G_SOURCE_REMOVE;
		return result;
	}
	_tmp2_ = source;
	_tmp3_ = self->priv->idle_source;
	_vala_assert (_tmp2_ == _tmp3_, "source == idle_source");
	_g_source_unref0 (self->priv->idle_source);
	self->priv->idle_source = NULL;
	if (self->priv->start_at_idle) {
		self->priv->start_at_idle = FALSE;
		g_signal_emit (self, pf_progress_info_signals[PF_PROGRESS_INFO_STARTED_SIGNAL], 0);
	}
	if (self->priv->finish_at_idle) {
		PFProgressInfoManager* _tmp4_;
		PFProgressInfoManager* _tmp5_;
		self->priv->finish_at_idle = FALSE;
		g_signal_emit (self, pf_progress_info_signals[PF_PROGRESS_INFO_FINISHED_SIGNAL], 0);
		_tmp4_ = pf_progress_info_manager_get_instance ();
		_tmp5_ = _tmp4_;
		pf_progress_info_manager_remove_finished_info (_tmp5_, self);
		_g_object_unref0 (_tmp5_);
	}
	if (self->priv->changed_at_idle) {
		g_signal_emit (self, pf_progress_info_signals[PF_PROGRESS_INFO_CHANGED_SIGNAL], 0);
		self->priv->changed_at_idle = FALSE;
	}
	if (self->priv->progress_at_idle) {
		g_signal_emit (self, pf_progress_info_signals[PF_PROGRESS_INFO_PROGRESS_CHANGED_SIGNAL], 0);
		self->priv->progress_at_idle = FALSE;
	}
	result = G_SOURCE_REMOVE;
	return result;
}

GCancellable*
pf_progress_info_get_cancellable (PFProgressInfo* self)
{
	GCancellable* result;
	GCancellable* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_cancellable;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
pf_progress_info_set_cancellable (PFProgressInfo* self,
                                  GCancellable* value)
{
	GCancellable* old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_cancellable (self);
	if (old_value != value) {
		GCancellable* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_cancellable);
		self->priv->_cancellable = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_CANCELLABLE_PROPERTY]);
	}
}

const gchar*
pf_progress_info_get_title (PFProgressInfo* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_title;
	result = _tmp0_;
	return result;
}

void
pf_progress_info_set_title (PFProgressInfo* self,
                            const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_title (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_title);
		self->priv->_title = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_TITLE_PROPERTY]);
	}
}

const gchar*
pf_progress_info_get_status (PFProgressInfo* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_status;
	result = _tmp0_;
	return result;
}

static void
pf_progress_info_set_status (PFProgressInfo* self,
                             const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_status (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_status);
		self->priv->_status = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_STATUS_PROPERTY]);
	}
}

const gchar*
pf_progress_info_get_details (PFProgressInfo* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_details;
	result = _tmp0_;
	return result;
}

void
pf_progress_info_set_details (PFProgressInfo* self,
                              const gchar* value)
{
	gchar* old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_details (self);
	if (g_strcmp0 (value, old_value) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_details);
		self->priv->_details = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_DETAILS_PROPERTY]);
	}
}

gdouble
pf_progress_info_get_progress (PFProgressInfo* self)
{
	gdouble result;
	g_return_val_if_fail (self != NULL, 0.0);
	result = self->priv->_progress;
	return result;
}

static void
pf_progress_info_set_progress (PFProgressInfo* self,
                               gdouble value)
{
	gdouble old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_progress (self);
	if (old_value != value) {
		self->priv->_progress = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_PROGRESS_PROPERTY]);
	}
}

gdouble
pf_progress_info_get_current (PFProgressInfo* self)
{
	gdouble result;
	g_return_val_if_fail (self != NULL, 0.0);
	result = self->priv->_current;
	return result;
}

static void
pf_progress_info_set_current (PFProgressInfo* self,
                              gdouble value)
{
	gdouble old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_current (self);
	if (old_value != value) {
		self->priv->_current = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_CURRENT_PROPERTY]);
	}
}

gdouble
pf_progress_info_get_total (PFProgressInfo* self)
{
	gdouble result;
	g_return_val_if_fail (self != NULL, 0.0);
	result = self->priv->_total;
	return result;
}

static void
pf_progress_info_set_total (PFProgressInfo* self,
                            gdouble value)
{
	gdouble old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_total (self);
	if (old_value != value) {
		self->priv->_total = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_TOTAL_PROPERTY]);
	}
}

gboolean
pf_progress_info_get_activity_mode (PFProgressInfo* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_activity_mode;
	return result;
}

static void
pf_progress_info_set_activity_mode (PFProgressInfo* self,
                                    gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_activity_mode (self);
	if (old_value != value) {
		self->priv->_activity_mode = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY]);
	}
}

gboolean
pf_progress_info_get_is_started (PFProgressInfo* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_started;
	return result;
}

static void
pf_progress_info_set_is_started (PFProgressInfo* self,
                                 gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_is_started (self);
	if (old_value != value) {
		self->priv->_is_started = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_IS_STARTED_PROPERTY]);
	}
}

gboolean
pf_progress_info_get_is_finished (PFProgressInfo* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_finished;
	return result;
}

static void
pf_progress_info_set_is_finished (PFProgressInfo* self,
                                  gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_is_finished (self);
	if (old_value != value) {
		self->priv->_is_finished = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_IS_FINISHED_PROPERTY]);
	}
}

gboolean
pf_progress_info_get_is_paused (PFProgressInfo* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_paused;
	return result;
}

static void
pf_progress_info_set_is_paused (PFProgressInfo* self,
                                gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = pf_progress_info_get_is_paused (self);
	if (old_value != value) {
		self->priv->_is_paused = value;
		g_object_notify_by_pspec ((GObject *) self, pf_progress_info_properties[PF_PROGRESS_INFO_IS_PAUSED_PROPERTY]);
	}
}

gboolean
pf_progress_info_get_is_cancelled (PFProgressInfo* self)
{
	gboolean result;
	GCancellable* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_cancellable;
	result = g_cancellable_is_cancelled (_tmp0_);
	return result;
}

static GObject *
pf_progress_info_constructor (GType type,
                              guint n_construct_properties,
                              GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	PFProgressInfo * self;
	GCancellable* _tmp0_;
	GCancellable* _tmp1_;
	GCancellable* _tmp2_;
	PFProgressInfoManager* _tmp3_;
	PFProgressInfoManager* _tmp4_;
	GApplication* _tmp5_;
	parent_class = G_OBJECT_CLASS (pf_progress_info_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PF_PROGRESS_TYPE_INFO, PFProgressInfo);
	_tmp0_ = g_cancellable_new ();
	_tmp1_ = _tmp0_;
	pf_progress_info_set_cancellable (self, _tmp1_);
	_g_object_unref0 (_tmp1_);
	_tmp2_ = self->priv->_cancellable;
	g_signal_connect_object (_tmp2_, "cancelled", (GCallback) _pf_progress_info_finish_g_cancellable_cancelled, self, 0);
	_tmp3_ = pf_progress_info_manager_get_instance ();
	_tmp4_ = _tmp3_;
	pf_progress_info_manager_add_new_info (_tmp4_, self);
	_g_object_unref0 (_tmp4_);
	_tmp5_ = g_application_get_default ();
	g_application_hold (_tmp5_);
	return obj;
}

static void
pf_progress_info_class_init (PFProgressInfoClass * klass,
                             gpointer klass_data)
{
	pf_progress_info_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &PFProgressInfo_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_pf_progress_info_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_pf_progress_info_set_property;
	G_OBJECT_CLASS (klass)->constructor = pf_progress_info_constructor;
	G_OBJECT_CLASS (klass)->finalize = pf_progress_info_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_CANCELLABLE_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_CANCELLABLE_PROPERTY] = g_param_spec_object ("cancellable", "cancellable", "cancellable", g_cancellable_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_TITLE_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_TITLE_PROPERTY] = g_param_spec_string ("title", "title", "title", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_STATUS_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_STATUS_PROPERTY] = g_param_spec_string ("status", "status", "status", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_DETAILS_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_DETAILS_PROPERTY] = g_param_spec_string ("details", "details", "details", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_PROGRESS_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_PROGRESS_PROPERTY] = g_param_spec_double ("progress", "progress", "progress", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_CURRENT_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_CURRENT_PROPERTY] = g_param_spec_double ("current", "current", "current", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_TOTAL_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_TOTAL_PROPERTY] = g_param_spec_double ("total", "total", "total", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY] = g_param_spec_boolean ("activity-mode", "activity-mode", "activity-mode", TRUE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_IS_STARTED_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_IS_STARTED_PROPERTY] = g_param_spec_boolean ("is-started", "is-started", "is-started", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_IS_FINISHED_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_IS_FINISHED_PROPERTY] = g_param_spec_boolean ("is-finished", "is-finished", "is-finished", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_IS_PAUSED_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_IS_PAUSED_PROPERTY] = g_param_spec_boolean ("is-paused", "is-paused", "is-paused", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PF_PROGRESS_INFO_IS_CANCELLED_PROPERTY, pf_progress_info_properties[PF_PROGRESS_INFO_IS_CANCELLED_PROPERTY] = g_param_spec_boolean ("is-cancelled", "is-cancelled", "is-cancelled", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	pf_progress_info_signals[PF_PROGRESS_INFO_CHANGED_SIGNAL] = g_signal_new ("changed", PF_PROGRESS_TYPE_INFO, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	pf_progress_info_signals[PF_PROGRESS_INFO_PROGRESS_CHANGED_SIGNAL] = g_signal_new ("progress-changed", PF_PROGRESS_TYPE_INFO, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	pf_progress_info_signals[PF_PROGRESS_INFO_STARTED_SIGNAL] = g_signal_new ("started", PF_PROGRESS_TYPE_INFO, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	pf_progress_info_signals[PF_PROGRESS_INFO_FINISHED_SIGNAL] = g_signal_new ("finished", PF_PROGRESS_TYPE_INFO, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void
pf_progress_info_instance_init (PFProgressInfo * self,
                                gpointer klass)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	self->priv = pf_progress_info_get_instance_private (self);
	_tmp0_ = g_strdup (_ ("Preparing"));
	self->priv->_title = _tmp0_;
	_tmp1_ = g_strdup (_ ("Preparing"));
	self->priv->_status = _tmp1_;
	_tmp2_ = g_strdup (_ ("Preparing"));
	self->priv->_details = _tmp2_;
	self->priv->_progress = 0.0;
	self->priv->_current = 0.0;
	self->priv->_total = 0.0;
	self->priv->_activity_mode = TRUE;
}

static void
pf_progress_info_finalize (GObject * obj)
{
	PFProgressInfo * self;
	GApplication* _tmp0_;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PF_PROGRESS_TYPE_INFO, PFProgressInfo);
	_tmp0_ = g_application_get_default ();
	g_application_release (_tmp0_);
	_g_object_unref0 (self->priv->_cancellable);
	_g_free0 (self->priv->_title);
	_g_free0 (self->priv->_status);
	_g_free0 (self->priv->_details);
	_g_source_unref0 (self->priv->idle_source);
	G_OBJECT_CLASS (pf_progress_info_parent_class)->finalize (obj);
}

static GType
pf_progress_info_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (PFProgressInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pf_progress_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PFProgressInfo), 0, (GInstanceInitFunc) pf_progress_info_instance_init, NULL };
	GType pf_progress_info_type_id;
	pf_progress_info_type_id = g_type_register_static (G_TYPE_OBJECT, "PFProgressInfo", &g_define_type_info, 0);
	PFProgressInfo_private_offset = g_type_add_instance_private (pf_progress_info_type_id, sizeof (PFProgressInfoPrivate));
	return pf_progress_info_type_id;
}

GType
pf_progress_info_get_type (void)
{
	static volatile gsize pf_progress_info_type_id__once = 0;
	if (g_once_init_enter (&pf_progress_info_type_id__once)) {
		GType pf_progress_info_type_id;
		pf_progress_info_type_id = pf_progress_info_get_type_once ();
		g_once_init_leave (&pf_progress_info_type_id__once, pf_progress_info_type_id);
	}
	return pf_progress_info_type_id__once;
}

static void
_vala_pf_progress_info_get_property (GObject * object,
                                     guint property_id,
                                     GValue * value,
                                     GParamSpec * pspec)
{
	PFProgressInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PF_PROGRESS_TYPE_INFO, PFProgressInfo);
	switch (property_id) {
		case PF_PROGRESS_INFO_CANCELLABLE_PROPERTY:
		g_value_set_object (value, pf_progress_info_get_cancellable (self));
		break;
		case PF_PROGRESS_INFO_TITLE_PROPERTY:
		g_value_set_string (value, pf_progress_info_get_title (self));
		break;
		case PF_PROGRESS_INFO_STATUS_PROPERTY:
		g_value_set_string (value, pf_progress_info_get_status (self));
		break;
		case PF_PROGRESS_INFO_DETAILS_PROPERTY:
		g_value_set_string (value, pf_progress_info_get_details (self));
		break;
		case PF_PROGRESS_INFO_PROGRESS_PROPERTY:
		g_value_set_double (value, pf_progress_info_get_progress (self));
		break;
		case PF_PROGRESS_INFO_CURRENT_PROPERTY:
		g_value_set_double (value, pf_progress_info_get_current (self));
		break;
		case PF_PROGRESS_INFO_TOTAL_PROPERTY:
		g_value_set_double (value, pf_progress_info_get_total (self));
		break;
		case PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY:
		g_value_set_boolean (value, pf_progress_info_get_activity_mode (self));
		break;
		case PF_PROGRESS_INFO_IS_STARTED_PROPERTY:
		g_value_set_boolean (value, pf_progress_info_get_is_started (self));
		break;
		case PF_PROGRESS_INFO_IS_FINISHED_PROPERTY:
		g_value_set_boolean (value, pf_progress_info_get_is_finished (self));
		break;
		case PF_PROGRESS_INFO_IS_PAUSED_PROPERTY:
		g_value_set_boolean (value, pf_progress_info_get_is_paused (self));
		break;
		case PF_PROGRESS_INFO_IS_CANCELLED_PROPERTY:
		g_value_set_boolean (value, pf_progress_info_get_is_cancelled (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_pf_progress_info_set_property (GObject * object,
                                     guint property_id,
                                     const GValue * value,
                                     GParamSpec * pspec)
{
	PFProgressInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PF_PROGRESS_TYPE_INFO, PFProgressInfo);
	switch (property_id) {
		case PF_PROGRESS_INFO_CANCELLABLE_PROPERTY:
		pf_progress_info_set_cancellable (self, g_value_get_object (value));
		break;
		case PF_PROGRESS_INFO_TITLE_PROPERTY:
		pf_progress_info_set_title (self, g_value_get_string (value));
		break;
		case PF_PROGRESS_INFO_STATUS_PROPERTY:
		pf_progress_info_set_status (self, g_value_get_string (value));
		break;
		case PF_PROGRESS_INFO_DETAILS_PROPERTY:
		pf_progress_info_set_details (self, g_value_get_string (value));
		break;
		case PF_PROGRESS_INFO_PROGRESS_PROPERTY:
		pf_progress_info_set_progress (self, g_value_get_double (value));
		break;
		case PF_PROGRESS_INFO_CURRENT_PROPERTY:
		pf_progress_info_set_current (self, g_value_get_double (value));
		break;
		case PF_PROGRESS_INFO_TOTAL_PROPERTY:
		pf_progress_info_set_total (self, g_value_get_double (value));
		break;
		case PF_PROGRESS_INFO_ACTIVITY_MODE_PROPERTY:
		pf_progress_info_set_activity_mode (self, g_value_get_boolean (value));
		break;
		case PF_PROGRESS_INFO_IS_STARTED_PROPERTY:
		pf_progress_info_set_is_started (self, g_value_get_boolean (value));
		break;
		case PF_PROGRESS_INFO_IS_FINISHED_PROPERTY:
		pf_progress_info_set_is_finished (self, g_value_get_boolean (value));
		break;
		case PF_PROGRESS_INFO_IS_PAUSED_PROPERTY:
		pf_progress_info_set_is_paused (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

