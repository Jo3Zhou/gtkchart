/*
 * Copyright (c) 2022  Martin Lund
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <gtk/gtk.h>

#if defined _WIN32 || defined __CYGWIN__
#define EXPORT __declspec(dllexport)
#else
#if defined __GNUC__
#define EXPORT __attribute__((visibility("default")))
#else
#pragma message("Compiler does not support symbol visibility.")
#define EXPORT
#endif
#endif

typedef struct chart_point_t ChartPoint;

G_BEGIN_DECLS

#define GTK_TYPE_CHART_CANVAS (gtk_chart_canvas_get_type())
G_DECLARE_FINAL_TYPE(GtkChartCanvas, gtk_chart_canvas, GTK, CHART_CANVAS,
                     GtkWidget)

typedef enum {
  GTK_CHART_CANVAS_TYPE_UNKNOWN,
  GTK_CHART_CANVAS_TYPE_LINE,
  GTK_CHART_CANVAS_TYPE_SCATTER,
  GTK_CHART_CANVAS_TYPE_GAUGE_ANGULAR,
  GTK_CHART_CANVAS_TYPE_GAUGE_LINEAR,
  GTK_CHART_CANVAS_TYPE_NUMBER
} GtkChartCanvasType;

EXPORT GtkWidget *gtk_chart_canvas_new(void);
EXPORT void gtk_chart_canvas_set_type(GtkChartCanvas *chart,
                                      GtkChartCanvasType type);
EXPORT void gtk_chart_canvas_set_title(GtkChartCanvas *chart,
                                       const char *title);
EXPORT void gtk_chart_canvas_set_label(GtkChartCanvas *chart,
                                       const char *label);
EXPORT void gtk_chart_canvas_set_x_label(GtkChartCanvas *chart,
                                         const char *x_label);
EXPORT void gtk_chart_canvas_set_y_label(GtkChartCanvas *chart,
                                         const char *y_label);
EXPORT void gtk_chart_canvas_set_x_max(GtkChartCanvas *chart, double x_max);
EXPORT void gtk_chart_canvas_set_y_max(GtkChartCanvas *chart, double y_max);
EXPORT void gtk_chart_canvas_set_x_min(GtkChartCanvas *chart, double x_min);
EXPORT void gtk_chart_canvas_set_y_min(GtkChartCanvas *chart, double y_min);
EXPORT double gtk_chart_canvas_get_x_max(GtkChartCanvas *chart);
EXPORT double gtk_chart_canvas_get_y_min(GtkChartCanvas *chart);
EXPORT void gtk_chart_canvas_set_width(GtkChartCanvas *chart, int width);
EXPORT void gtk_chart_canvas_plot_point(GtkChartCanvas *chart, double x,
                                        double y);

EXPORT void gtk_chart_canvas_set_value(GtkChartCanvas *chart, double value);
EXPORT void gtk_chart_canvas_set_value_min(GtkChartCanvas *chart, double value);
EXPORT void gtk_chart_canvas_set_value_max(GtkChartCanvas *chart, double value);
EXPORT double gtk_chart_canvas_get_value_min(GtkChartCanvas *chart);
EXPORT double gtk_chart_canvas_get_value_max(GtkChartCanvas *chart);

EXPORT bool gtk_chart_canvas_save_csv(GtkChartCanvas *chart,
                                      const char *filename, GError **error);
EXPORT bool gtk_chart_canvas_save_png(GtkChartCanvas *chart,
                                      const char *filename, GError **error);
EXPORT GSList *gtk_chart_canvas_get_points(GtkChartCanvas *chart);

EXPORT void gtk_chart_canvas_set_user_data(GtkChartCanvas *chart,
                                           void *user_data);
EXPORT void *gtk_chart_canvas_get_user_data(GtkChartCanvas *chart);

EXPORT bool gtk_chart_canvas_set_color(GtkChartCanvas *chart, char *name,
                                       char *color);
EXPORT void gtk_chart_canvas_set_font(GtkChartCanvas *chart, const char *name);

G_END_DECLS
