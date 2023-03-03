/* PixbufUtils.c generated by valac 0.56.3, the Vala compiler
 * generated from PixbufUtils.vala, do not modify */

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

#include <glib.h>
#include "pantheon-files-core.h"
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>
#include <math.h>
#include <float.h>

VALA_EXTERN guint8 pf_pixbuf_utils_lighten_component (guint8 cur_value);

guint8
pf_pixbuf_utils_lighten_component (guint8 cur_value)
{
	guint new_value = 0U;
	guint8 result;
	new_value = (guint) cur_value;
	new_value += 24 + (new_value >> 3);
	if (new_value > ((guint) G_MAXUINT8)) {
		new_value = (guint) G_MAXUINT8;
	}
	result = (guint8) new_value;
	return result;
}

GdkPixbuf*
pf_pixbuf_utils_lighten (GdkPixbuf* src)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gint _tmp11_;
	gint _tmp12_;
	gint width = 0;
	gint _tmp13_;
	gint _tmp14_;
	gint height = 0;
	gint _tmp15_;
	gint _tmp16_;
	gint channels = 0;
	gint _tmp17_;
	gint _tmp18_;
	gboolean has_alpha = FALSE;
	gboolean _tmp19_;
	gboolean _tmp20_;
	GdkPixbuf* dest = NULL;
	GdkColorspace _tmp21_;
	GdkColorspace _tmp22_;
	gboolean _tmp23_;
	gboolean _tmp24_;
	gint _tmp25_;
	gint _tmp26_;
	GdkPixbuf* _tmp27_;
	gint dst_row_stride = 0;
	GdkPixbuf* _tmp28_;
	gint _tmp29_;
	gint _tmp30_;
	gint src_row_stride = 0;
	gint _tmp31_;
	gint _tmp32_;
	guint8* target_pix = NULL;
	GdkPixbuf* _tmp33_;
	void* _tmp34_;
	void* _tmp35_;
	gint target_pix_length1;
	gint _target_pix_size_;
	guint8* original_pix = NULL;
	void* _tmp36_;
	void* _tmp37_;
	gint original_pix_length1;
	gint _original_pix_size_;
	GdkPixbuf* result;
	g_return_val_if_fail (src != NULL, NULL);
	_tmp2_ = gdk_pixbuf_get_has_alpha (src);
	_tmp3_ = _tmp2_;
	if (!_tmp3_) {
		gint _tmp4_;
		gint _tmp5_;
		_tmp4_ = gdk_pixbuf_get_n_channels (src);
		_tmp5_ = _tmp4_;
		_tmp1_ = _tmp5_ == 3;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp6_ = FALSE;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp7_ = gdk_pixbuf_get_has_alpha (src);
		_tmp8_ = _tmp7_;
		if (_tmp8_) {
			gint _tmp9_;
			gint _tmp10_;
			_tmp9_ = gdk_pixbuf_get_n_channels (src);
			_tmp10_ = _tmp9_;
			_tmp6_ = _tmp10_ == 4;
		} else {
			_tmp6_ = FALSE;
		}
		_tmp0_ = _tmp6_;
	}
	g_return_val_if_fail (_tmp0_, src);
	_tmp11_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp12_ = _tmp11_;
	g_return_val_if_fail (_tmp12_ == 8, src);
	_tmp13_ = gdk_pixbuf_get_width (src);
	_tmp14_ = _tmp13_;
	width = _tmp14_;
	_tmp15_ = gdk_pixbuf_get_height (src);
	_tmp16_ = _tmp15_;
	height = _tmp16_;
	_tmp17_ = gdk_pixbuf_get_n_channels (src);
	_tmp18_ = _tmp17_;
	channels = _tmp18_;
	_tmp19_ = gdk_pixbuf_get_has_alpha (src);
	_tmp20_ = _tmp19_;
	has_alpha = _tmp20_;
	_tmp21_ = gdk_pixbuf_get_colorspace (src);
	_tmp22_ = _tmp21_;
	_tmp23_ = gdk_pixbuf_get_has_alpha (src);
	_tmp24_ = _tmp23_;
	_tmp25_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp26_ = _tmp25_;
	_tmp27_ = gdk_pixbuf_new (_tmp22_, _tmp24_, _tmp26_, width, height);
	dest = _tmp27_;
	_tmp28_ = dest;
	_tmp29_ = gdk_pixbuf_get_rowstride (_tmp28_);
	_tmp30_ = _tmp29_;
	dst_row_stride = _tmp30_;
	_tmp31_ = gdk_pixbuf_get_rowstride (src);
	_tmp32_ = _tmp31_;
	src_row_stride = _tmp32_;
	_tmp33_ = dest;
	_tmp34_ = gdk_pixbuf_get_pixels (_tmp33_);
	_tmp35_ = _tmp34_;
	target_pix = (guint8*) _tmp35_;
	target_pix_length1 = -1;
	_target_pix_size_ = target_pix_length1;
	_tmp36_ = gdk_pixbuf_get_pixels (src);
	_tmp37_ = _tmp36_;
	original_pix = (guint8*) _tmp37_;
	original_pix_length1 = -1;
	_original_pix_size_ = original_pix_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp38_ = FALSE;
			_tmp38_ = TRUE;
			while (TRUE) {
				gint src_row = 0;
				gint dst_row = 0;
				if (!_tmp38_) {
					gint _tmp39_;
					_tmp39_ = i;
					i = _tmp39_ + 1;
				}
				_tmp38_ = FALSE;
				if (!(i < height)) {
					break;
				}
				src_row = i * src_row_stride;
				dst_row = i * dst_row_stride;
				{
					gint j = 0;
					j = 0;
					{
						gboolean _tmp40_ = FALSE;
						_tmp40_ = TRUE;
						while (TRUE) {
							gint width_offset = 0;
							guint8* _tmp42_;
							gint _tmp42__length1;
							guint8* _tmp43_;
							gint _tmp43__length1;
							guint8 _tmp44_;
							guint8* _tmp45_;
							gint _tmp45__length1;
							guint8* _tmp46_;
							gint _tmp46__length1;
							guint8 _tmp47_;
							guint8* _tmp48_;
							gint _tmp48__length1;
							guint8* _tmp49_;
							gint _tmp49__length1;
							guint8 _tmp50_;
							if (!_tmp40_) {
								gint _tmp41_;
								_tmp41_ = j;
								j = _tmp41_ + 1;
							}
							_tmp40_ = FALSE;
							if (!(j < width)) {
								break;
							}
							width_offset = j * channels;
							_tmp42_ = target_pix;
							_tmp42__length1 = target_pix_length1;
							_tmp43_ = original_pix;
							_tmp43__length1 = original_pix_length1;
							_tmp44_ = _tmp43_[src_row + width_offset];
							_tmp42_[dst_row + width_offset] = pf_pixbuf_utils_lighten_component (_tmp44_);
							_tmp45_ = target_pix;
							_tmp45__length1 = target_pix_length1;
							_tmp46_ = original_pix;
							_tmp46__length1 = original_pix_length1;
							_tmp47_ = _tmp46_[(src_row + width_offset) + 1];
							_tmp45_[(dst_row + width_offset) + 1] = pf_pixbuf_utils_lighten_component (_tmp47_);
							_tmp48_ = target_pix;
							_tmp48__length1 = target_pix_length1;
							_tmp49_ = original_pix;
							_tmp49__length1 = original_pix_length1;
							_tmp50_ = _tmp49_[(src_row + width_offset) + 2];
							_tmp48_[(dst_row + width_offset) + 2] = pf_pixbuf_utils_lighten_component (_tmp50_);
							if (has_alpha) {
								guint8* _tmp51_;
								gint _tmp51__length1;
								guint8* _tmp52_;
								gint _tmp52__length1;
								guint8 _tmp53_;
								_tmp51_ = target_pix;
								_tmp51__length1 = target_pix_length1;
								_tmp52_ = original_pix;
								_tmp52__length1 = original_pix_length1;
								_tmp53_ = _tmp52_[(src_row + width_offset) + 3];
								_tmp51_[(dst_row + width_offset) + 3] = _tmp53_;
							}
						}
					}
				}
			}
		}
	}
	result = dest;
	return result;
}

GdkPixbuf*
pf_pixbuf_utils_darken (GdkPixbuf* src,
                        guint8 saturation,
                        guint8 darken)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gint _tmp11_;
	gint _tmp12_;
	gint width = 0;
	gint _tmp13_;
	gint _tmp14_;
	gint height = 0;
	gint _tmp15_;
	gint _tmp16_;
	gboolean has_alpha = FALSE;
	gboolean _tmp17_;
	gboolean _tmp18_;
	gint channels = 0;
	gint _tmp19_;
	gint _tmp20_;
	GdkPixbuf* dest = NULL;
	GdkColorspace _tmp21_;
	GdkColorspace _tmp22_;
	gint _tmp23_;
	gint _tmp24_;
	GdkPixbuf* _tmp25_;
	gint dst_row_stride = 0;
	GdkPixbuf* _tmp26_;
	gint _tmp27_;
	gint _tmp28_;
	gint src_row_stride = 0;
	gint _tmp29_;
	gint _tmp30_;
	guint8* target_pix = NULL;
	GdkPixbuf* _tmp31_;
	void* _tmp32_;
	void* _tmp33_;
	gint target_pix_length1;
	gint _target_pix_size_;
	guint8* original_pix = NULL;
	void* _tmp34_;
	void* _tmp35_;
	gint original_pix_length1;
	gint _original_pix_size_;
	GdkPixbuf* result;
	g_return_val_if_fail (src != NULL, NULL);
	_tmp2_ = gdk_pixbuf_get_has_alpha (src);
	_tmp3_ = _tmp2_;
	if (!_tmp3_) {
		gint _tmp4_;
		gint _tmp5_;
		_tmp4_ = gdk_pixbuf_get_n_channels (src);
		_tmp5_ = _tmp4_;
		_tmp1_ = _tmp5_ == 3;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp6_ = FALSE;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp7_ = gdk_pixbuf_get_has_alpha (src);
		_tmp8_ = _tmp7_;
		if (_tmp8_) {
			gint _tmp9_;
			gint _tmp10_;
			_tmp9_ = gdk_pixbuf_get_n_channels (src);
			_tmp10_ = _tmp9_;
			_tmp6_ = _tmp10_ == 4;
		} else {
			_tmp6_ = FALSE;
		}
		_tmp0_ = _tmp6_;
	}
	g_return_val_if_fail (_tmp0_, src);
	_tmp11_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp12_ = _tmp11_;
	g_return_val_if_fail (_tmp12_ == 8, src);
	_tmp13_ = gdk_pixbuf_get_width (src);
	_tmp14_ = _tmp13_;
	width = _tmp14_;
	_tmp15_ = gdk_pixbuf_get_height (src);
	_tmp16_ = _tmp15_;
	height = _tmp16_;
	_tmp17_ = gdk_pixbuf_get_has_alpha (src);
	_tmp18_ = _tmp17_;
	has_alpha = _tmp18_;
	_tmp19_ = gdk_pixbuf_get_n_channels (src);
	_tmp20_ = _tmp19_;
	channels = _tmp20_;
	_tmp21_ = gdk_pixbuf_get_colorspace (src);
	_tmp22_ = _tmp21_;
	_tmp23_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp24_ = _tmp23_;
	_tmp25_ = gdk_pixbuf_new (_tmp22_, has_alpha, _tmp24_, width, height);
	dest = _tmp25_;
	_tmp26_ = dest;
	_tmp27_ = gdk_pixbuf_get_rowstride (_tmp26_);
	_tmp28_ = _tmp27_;
	dst_row_stride = _tmp28_;
	_tmp29_ = gdk_pixbuf_get_rowstride (src);
	_tmp30_ = _tmp29_;
	src_row_stride = _tmp30_;
	_tmp31_ = dest;
	_tmp32_ = gdk_pixbuf_get_pixels (_tmp31_);
	_tmp33_ = _tmp32_;
	target_pix = (guint8*) _tmp33_;
	target_pix_length1 = -1;
	_target_pix_size_ = target_pix_length1;
	_tmp34_ = gdk_pixbuf_get_pixels (src);
	_tmp35_ = _tmp34_;
	original_pix = (guint8*) _tmp35_;
	original_pix_length1 = -1;
	_original_pix_size_ = original_pix_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp36_ = FALSE;
			_tmp36_ = TRUE;
			while (TRUE) {
				gint src_row = 0;
				gint dst_row = 0;
				if (!_tmp36_) {
					gint _tmp37_;
					_tmp37_ = i;
					i = _tmp37_ + 1;
				}
				_tmp36_ = FALSE;
				if (!(i < height)) {
					break;
				}
				src_row = i * src_row_stride;
				dst_row = i * dst_row_stride;
				{
					gint j = 0;
					j = 0;
					{
						gboolean _tmp38_ = FALSE;
						_tmp38_ = TRUE;
						while (TRUE) {
							gint width_offset = 0;
							guint8 r = 0U;
							guint8* _tmp40_;
							gint _tmp40__length1;
							guint8 _tmp41_;
							guint8 g = 0U;
							guint8* _tmp42_;
							gint _tmp42__length1;
							guint8 _tmp43_;
							guint8 b = 0U;
							guint8* _tmp44_;
							gint _tmp44__length1;
							guint8 _tmp45_;
							guint8 intensity = 0U;
							guint8 negalpha = 0U;
							guint8 alpha = 0U;
							guint8* _tmp46_;
							gint _tmp46__length1;
							guint8* _tmp47_;
							gint _tmp47__length1;
							guint8* _tmp48_;
							gint _tmp48__length1;
							if (!_tmp38_) {
								gint _tmp39_;
								_tmp39_ = j;
								j = _tmp39_ + 1;
							}
							_tmp38_ = FALSE;
							if (!(j < width)) {
								break;
							}
							width_offset = j * channels;
							_tmp40_ = original_pix;
							_tmp40__length1 = original_pix_length1;
							_tmp41_ = _tmp40_[src_row + width_offset];
							r = _tmp41_;
							_tmp42_ = original_pix;
							_tmp42__length1 = original_pix_length1;
							_tmp43_ = _tmp42_[(src_row + width_offset) + 1];
							g = _tmp43_;
							_tmp44_ = original_pix;
							_tmp44__length1 = original_pix_length1;
							_tmp45_ = _tmp44_[(src_row + width_offset) + 2];
							b = _tmp45_;
							intensity = (guint8) ((((r * 77) + (g * 150)) + (b * 28)) >> 8);
							negalpha = (guint8) (((G_MAXUINT8 - saturation) * darken) >> 8);
							alpha = (guint8) ((saturation * darken) >> 8);
							_tmp46_ = target_pix;
							_tmp46__length1 = target_pix_length1;
							_tmp46_[dst_row + width_offset] = (guint8) (((negalpha * intensity) + (alpha * r)) >> 8);
							_tmp47_ = target_pix;
							_tmp47__length1 = target_pix_length1;
							_tmp47_[(dst_row + width_offset) + 1] = (guint8) (((negalpha * intensity) + (alpha * g)) >> 8);
							_tmp48_ = target_pix;
							_tmp48__length1 = target_pix_length1;
							_tmp48_[(dst_row + width_offset) + 2] = (guint8) (((negalpha * intensity) + (alpha * b)) >> 8);
							if (has_alpha) {
								guint8* _tmp49_;
								gint _tmp49__length1;
								guint8* _tmp50_;
								gint _tmp50__length1;
								guint8 _tmp51_;
								_tmp49_ = target_pix;
								_tmp49__length1 = target_pix_length1;
								_tmp50_ = original_pix;
								_tmp50__length1 = original_pix_length1;
								_tmp51_ = _tmp50_[(src_row + width_offset) + 3];
								_tmp49_[(dst_row + width_offset) + 3] = _tmp51_;
							}
						}
					}
				}
			}
		}
	}
	result = dest;
	return result;
}

GdkPixbuf*
pf_pixbuf_utils_colorize (GdkPixbuf* src,
                          GdkRGBA* color)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gint _tmp11_;
	gint _tmp12_;
	guint8 red_value = 0U;
	GdkRGBA _tmp13_;
	guint8 green_value = 0U;
	GdkRGBA _tmp14_;
	guint8 blue_value = 0U;
	GdkRGBA _tmp15_;
	gint width = 0;
	gint _tmp16_;
	gint _tmp17_;
	gint height = 0;
	gint _tmp18_;
	gint _tmp19_;
	gboolean has_alpha = FALSE;
	gboolean _tmp20_;
	gboolean _tmp21_;
	gint channels = 0;
	gint _tmp22_;
	gint _tmp23_;
	GdkPixbuf* dest = NULL;
	GdkColorspace _tmp24_;
	GdkColorspace _tmp25_;
	gint _tmp26_;
	gint _tmp27_;
	GdkPixbuf* _tmp28_;
	gint dst_row_stride = 0;
	GdkPixbuf* _tmp29_;
	gint _tmp30_;
	gint _tmp31_;
	gint src_row_stride = 0;
	gint _tmp32_;
	gint _tmp33_;
	guint8* target_pix = NULL;
	GdkPixbuf* _tmp34_;
	void* _tmp35_;
	void* _tmp36_;
	gint target_pix_length1;
	gint _target_pix_size_;
	guint8* original_pix = NULL;
	void* _tmp37_;
	void* _tmp38_;
	gint original_pix_length1;
	gint _original_pix_size_;
	GdkPixbuf* result;
	g_return_val_if_fail (src != NULL, NULL);
	g_return_val_if_fail (color != NULL, NULL);
	_tmp2_ = gdk_pixbuf_get_has_alpha (src);
	_tmp3_ = _tmp2_;
	if (!_tmp3_) {
		gint _tmp4_;
		gint _tmp5_;
		_tmp4_ = gdk_pixbuf_get_n_channels (src);
		_tmp5_ = _tmp4_;
		_tmp1_ = _tmp5_ == 3;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		gboolean _tmp6_ = FALSE;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp7_ = gdk_pixbuf_get_has_alpha (src);
		_tmp8_ = _tmp7_;
		if (_tmp8_) {
			gint _tmp9_;
			gint _tmp10_;
			_tmp9_ = gdk_pixbuf_get_n_channels (src);
			_tmp10_ = _tmp9_;
			_tmp6_ = _tmp10_ == 4;
		} else {
			_tmp6_ = FALSE;
		}
		_tmp0_ = _tmp6_;
	}
	g_return_val_if_fail (_tmp0_, src);
	_tmp11_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp12_ = _tmp11_;
	g_return_val_if_fail (_tmp12_ == 8, src);
	_tmp13_ = *color;
	red_value = (guint8) floor (_tmp13_.red * G_MAXUINT8);
	_tmp14_ = *color;
	green_value = (guint8) floor (_tmp14_.green * G_MAXUINT8);
	_tmp15_ = *color;
	blue_value = (guint8) floor (_tmp15_.blue * G_MAXUINT8);
	_tmp16_ = gdk_pixbuf_get_width (src);
	_tmp17_ = _tmp16_;
	width = _tmp17_;
	_tmp18_ = gdk_pixbuf_get_height (src);
	_tmp19_ = _tmp18_;
	height = _tmp19_;
	_tmp20_ = gdk_pixbuf_get_has_alpha (src);
	_tmp21_ = _tmp20_;
	has_alpha = _tmp21_;
	_tmp22_ = gdk_pixbuf_get_n_channels (src);
	_tmp23_ = _tmp22_;
	channels = _tmp23_;
	_tmp24_ = gdk_pixbuf_get_colorspace (src);
	_tmp25_ = _tmp24_;
	_tmp26_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp27_ = _tmp26_;
	_tmp28_ = gdk_pixbuf_new (_tmp25_, has_alpha, _tmp27_, width, height);
	dest = _tmp28_;
	_tmp29_ = dest;
	_tmp30_ = gdk_pixbuf_get_rowstride (_tmp29_);
	_tmp31_ = _tmp30_;
	dst_row_stride = _tmp31_;
	_tmp32_ = gdk_pixbuf_get_rowstride (src);
	_tmp33_ = _tmp32_;
	src_row_stride = _tmp33_;
	_tmp34_ = dest;
	_tmp35_ = gdk_pixbuf_get_pixels (_tmp34_);
	_tmp36_ = _tmp35_;
	target_pix = (guint8*) _tmp36_;
	target_pix_length1 = -1;
	_target_pix_size_ = target_pix_length1;
	_tmp37_ = gdk_pixbuf_get_pixels (src);
	_tmp38_ = _tmp37_;
	original_pix = (guint8*) _tmp38_;
	original_pix_length1 = -1;
	_original_pix_size_ = original_pix_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp39_ = FALSE;
			_tmp39_ = TRUE;
			while (TRUE) {
				gint src_row = 0;
				gint dst_row = 0;
				if (!_tmp39_) {
					gint _tmp40_;
					_tmp40_ = i;
					i = _tmp40_ + 1;
				}
				_tmp39_ = FALSE;
				if (!(i < height)) {
					break;
				}
				src_row = i * src_row_stride;
				dst_row = i * dst_row_stride;
				{
					gint j = 0;
					j = 0;
					{
						gboolean _tmp41_ = FALSE;
						_tmp41_ = TRUE;
						while (TRUE) {
							gint width_offset = 0;
							guint8* _tmp43_;
							gint _tmp43__length1;
							guint8* _tmp44_;
							gint _tmp44__length1;
							guint8 _tmp45_;
							guint8* _tmp46_;
							gint _tmp46__length1;
							guint8* _tmp47_;
							gint _tmp47__length1;
							guint8 _tmp48_;
							guint8* _tmp49_;
							gint _tmp49__length1;
							guint8* _tmp50_;
							gint _tmp50__length1;
							guint8 _tmp51_;
							if (!_tmp41_) {
								gint _tmp42_;
								_tmp42_ = j;
								j = _tmp42_ + 1;
							}
							_tmp41_ = FALSE;
							if (!(j < width)) {
								break;
							}
							width_offset = j * channels;
							_tmp43_ = target_pix;
							_tmp43__length1 = target_pix_length1;
							_tmp44_ = original_pix;
							_tmp44__length1 = original_pix_length1;
							_tmp45_ = _tmp44_[src_row + width_offset];
							_tmp43_[dst_row + width_offset] = (guint8) ((_tmp45_ * red_value) >> 8);
							_tmp46_ = target_pix;
							_tmp46__length1 = target_pix_length1;
							_tmp47_ = original_pix;
							_tmp47__length1 = original_pix_length1;
							_tmp48_ = _tmp47_[(src_row + width_offset) + 1];
							_tmp46_[(dst_row + width_offset) + 1] = (guint8) ((_tmp48_ * green_value) >> 8);
							_tmp49_ = target_pix;
							_tmp49__length1 = target_pix_length1;
							_tmp50_ = original_pix;
							_tmp50__length1 = original_pix_length1;
							_tmp51_ = _tmp50_[(src_row + width_offset) + 2];
							_tmp49_[(dst_row + width_offset) + 2] = (guint8) ((_tmp51_ * blue_value) >> 8);
							if (has_alpha) {
								guint8* _tmp52_;
								gint _tmp52__length1;
								guint8* _tmp53_;
								gint _tmp53__length1;
								guint8 _tmp54_;
								_tmp52_ = target_pix;
								_tmp52__length1 = target_pix_length1;
								_tmp53_ = original_pix;
								_tmp53__length1 = original_pix_length1;
								_tmp54_ = _tmp53_[(src_row + width_offset) + 3];
								_tmp52_[(dst_row + width_offset) + 3] = _tmp54_;
							}
						}
					}
				}
			}
		}
	}
	result = dest;
	return result;
}

GdkPixbuf*
pf_pixbuf_utils_lucent (GdkPixbuf* src,
                        guint percent)
{
	gint width = 0;
	gint _tmp0_;
	gint _tmp1_;
	gint height = 0;
	gint _tmp2_;
	gint _tmp3_;
	gboolean has_alpha = FALSE;
	gboolean _tmp4_;
	gboolean _tmp5_;
	GdkPixbuf* dest = NULL;
	GdkColorspace _tmp6_;
	GdkColorspace _tmp7_;
	gint _tmp8_;
	gint _tmp9_;
	GdkPixbuf* _tmp10_;
	gint dst_row_stride = 0;
	GdkPixbuf* _tmp11_;
	gint _tmp12_;
	gint _tmp13_;
	gint src_row_stride = 0;
	gint _tmp14_;
	gint _tmp15_;
	guint8* target_pix = NULL;
	GdkPixbuf* _tmp16_;
	void* _tmp17_;
	void* _tmp18_;
	gint target_pix_length1;
	gint _target_pix_size_;
	guint8* original_pix = NULL;
	void* _tmp19_;
	void* _tmp20_;
	gint original_pix_length1;
	gint _original_pix_size_;
	GdkPixbuf* result;
	g_return_val_if_fail (src != NULL, NULL);
	g_return_val_if_fail (percent <= ((guint) 100), src);
	_tmp0_ = gdk_pixbuf_get_width (src);
	_tmp1_ = _tmp0_;
	width = _tmp1_;
	_tmp2_ = gdk_pixbuf_get_height (src);
	_tmp3_ = _tmp2_;
	height = _tmp3_;
	_tmp4_ = gdk_pixbuf_get_has_alpha (src);
	_tmp5_ = _tmp4_;
	has_alpha = _tmp5_;
	_tmp6_ = gdk_pixbuf_get_colorspace (src);
	_tmp7_ = _tmp6_;
	_tmp8_ = gdk_pixbuf_get_bits_per_sample (src);
	_tmp9_ = _tmp8_;
	_tmp10_ = gdk_pixbuf_new (_tmp7_, TRUE, _tmp9_, width, height);
	dest = _tmp10_;
	_tmp11_ = dest;
	_tmp12_ = gdk_pixbuf_get_rowstride (_tmp11_);
	_tmp13_ = _tmp12_;
	dst_row_stride = _tmp13_;
	_tmp14_ = gdk_pixbuf_get_rowstride (src);
	_tmp15_ = _tmp14_;
	src_row_stride = _tmp15_;
	_tmp16_ = dest;
	_tmp17_ = gdk_pixbuf_get_pixels (_tmp16_);
	_tmp18_ = _tmp17_;
	target_pix = (guint8*) _tmp18_;
	target_pix_length1 = -1;
	_target_pix_size_ = target_pix_length1;
	_tmp19_ = gdk_pixbuf_get_pixels (src);
	_tmp20_ = _tmp19_;
	original_pix = (guint8*) _tmp20_;
	original_pix_length1 = -1;
	_original_pix_size_ = original_pix_length1;
	if (has_alpha) {
		gdouble ratio = 0.0;
		ratio = ((gdouble) percent) / 100;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp21_ = FALSE;
				_tmp21_ = TRUE;
				while (TRUE) {
					gint src_row = 0;
					gint dst_row = 0;
					if (!_tmp21_) {
						gint _tmp22_;
						_tmp22_ = i;
						i = _tmp22_ + 1;
					}
					_tmp21_ = FALSE;
					if (!(i < height)) {
						break;
					}
					src_row = i * src_row_stride;
					dst_row = i * dst_row_stride;
					{
						gint j = 0;
						j = 0;
						{
							gboolean _tmp23_ = FALSE;
							_tmp23_ = TRUE;
							while (TRUE) {
								gint dr = 0;
								gint sr = 0;
								guint8* _tmp25_;
								gint _tmp25__length1;
								gint _tmp26_;
								guint8* _tmp27_;
								gint _tmp27__length1;
								gint _tmp28_;
								guint8 _tmp29_;
								guint8* _tmp30_;
								gint _tmp30__length1;
								gint _tmp31_;
								guint8* _tmp32_;
								gint _tmp32__length1;
								gint _tmp33_;
								guint8 _tmp34_;
								guint8* _tmp35_;
								gint _tmp35__length1;
								gint _tmp36_;
								guint8* _tmp37_;
								gint _tmp37__length1;
								gint _tmp38_;
								guint8 _tmp39_;
								guint8* _tmp40_;
								gint _tmp40__length1;
								guint8* _tmp41_;
								gint _tmp41__length1;
								guint8 _tmp42_;
								if (!_tmp23_) {
									gint _tmp24_;
									_tmp24_ = j;
									j = _tmp24_ + 1;
								}
								_tmp23_ = FALSE;
								if (!(j < width)) {
									break;
								}
								dr = dst_row + (j * 4);
								sr = src_row + (j * 4);
								_tmp25_ = target_pix;
								_tmp25__length1 = target_pix_length1;
								_tmp26_ = dr;
								dr = _tmp26_ + 1;
								_tmp27_ = original_pix;
								_tmp27__length1 = original_pix_length1;
								_tmp28_ = sr;
								sr = _tmp28_ + 1;
								_tmp29_ = _tmp27_[_tmp28_];
								_tmp25_[_tmp26_] = _tmp29_;
								_tmp30_ = target_pix;
								_tmp30__length1 = target_pix_length1;
								_tmp31_ = dr;
								dr = _tmp31_ + 1;
								_tmp32_ = original_pix;
								_tmp32__length1 = original_pix_length1;
								_tmp33_ = sr;
								sr = _tmp33_ + 1;
								_tmp34_ = _tmp32_[_tmp33_];
								_tmp30_[_tmp31_] = _tmp34_;
								_tmp35_ = target_pix;
								_tmp35__length1 = target_pix_length1;
								_tmp36_ = dr;
								dr = _tmp36_ + 1;
								_tmp37_ = original_pix;
								_tmp37__length1 = original_pix_length1;
								_tmp38_ = sr;
								sr = _tmp38_ + 1;
								_tmp39_ = _tmp37_[_tmp38_];
								_tmp35_[_tmp36_] = _tmp39_;
								_tmp40_ = target_pix;
								_tmp40__length1 = target_pix_length1;
								_tmp41_ = original_pix;
								_tmp41__length1 = original_pix_length1;
								_tmp42_ = _tmp41_[sr];
								_tmp40_[dr] = (guint8) (_tmp42_ * ratio);
							}
						}
					}
				}
			}
		}
	} else {
		percent = (255U * percent) / 100U;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp43_ = FALSE;
				_tmp43_ = TRUE;
				while (TRUE) {
					gint src_row = 0;
					gint dst_row = 0;
					if (!_tmp43_) {
						gint _tmp44_;
						_tmp44_ = i;
						i = _tmp44_ + 1;
					}
					_tmp43_ = FALSE;
					if (!(i < height)) {
						break;
					}
					src_row = i * src_row_stride;
					dst_row = i * dst_row_stride;
					{
						gint j = 0;
						j = 0;
						{
							gboolean _tmp45_ = FALSE;
							_tmp45_ = TRUE;
							while (TRUE) {
								gint dr = 0;
								gint sr = 0;
								guint8* _tmp47_;
								gint _tmp47__length1;
								gint _tmp48_;
								guint8* _tmp49_;
								gint _tmp49__length1;
								gint _tmp50_;
								guint8 _tmp51_;
								guint8* _tmp52_;
								gint _tmp52__length1;
								gint _tmp53_;
								guint8* _tmp54_;
								gint _tmp54__length1;
								gint _tmp55_;
								guint8 _tmp56_;
								guint8* _tmp57_;
								gint _tmp57__length1;
								gint _tmp58_;
								guint8* _tmp59_;
								gint _tmp59__length1;
								gint _tmp60_;
								guint8 _tmp61_;
								guint8* _tmp62_;
								gint _tmp62__length1;
								if (!_tmp45_) {
									gint _tmp46_;
									_tmp46_ = j;
									j = _tmp46_ + 1;
								}
								_tmp45_ = FALSE;
								if (!(j < width)) {
									break;
								}
								dr = dst_row + (j * 4);
								sr = src_row + (j * 3);
								_tmp47_ = target_pix;
								_tmp47__length1 = target_pix_length1;
								_tmp48_ = dr;
								dr = _tmp48_ + 1;
								_tmp49_ = original_pix;
								_tmp49__length1 = original_pix_length1;
								_tmp50_ = sr;
								sr = _tmp50_ + 1;
								_tmp51_ = _tmp49_[_tmp50_];
								_tmp47_[_tmp48_] = _tmp51_;
								_tmp52_ = target_pix;
								_tmp52__length1 = target_pix_length1;
								_tmp53_ = dr;
								dr = _tmp53_ + 1;
								_tmp54_ = original_pix;
								_tmp54__length1 = original_pix_length1;
								_tmp55_ = sr;
								sr = _tmp55_ + 1;
								_tmp56_ = _tmp54_[_tmp55_];
								_tmp52_[_tmp53_] = _tmp56_;
								_tmp57_ = target_pix;
								_tmp57__length1 = target_pix_length1;
								_tmp58_ = dr;
								dr = _tmp58_ + 1;
								_tmp59_ = original_pix;
								_tmp59__length1 = original_pix_length1;
								_tmp60_ = sr;
								sr = _tmp60_ + 1;
								_tmp61_ = _tmp59_[_tmp60_];
								_tmp57_[_tmp58_] = _tmp61_;
								_tmp62_ = target_pix;
								_tmp62__length1 = target_pix_length1;
								_tmp62_[dr] = (guint8) percent;
							}
						}
					}
				}
			}
		}
	}
	result = dest;
	return result;
}

