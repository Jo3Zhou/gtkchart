# GtkChart - a chart widget for GTK4

[Screencast from 2022-09-30 16-06-43 - gtkchart-fixed.webm](https://user-images.githubusercontent.com/353407/193289610-34b59005-1bc7-4f60-ba94-ecf34d601a4b.webm)

## Introduction

The beginnings of a small chart widget library for GTK4.

This is a spinoff from the [lxi-tools](https://lxi-tools.github.io) project.

Much can be improved but it is better than nothing.

```diff
! Looking for maintainers or contributors to help improve this library.
! Please reach out if interested.
```

## Motivation

Couldn't find a chart widget library for GTK4 so created one.

## Features

 * Various chart types
   * Line
   * Scatter
   * Linear gauge
   * Angular gauge
   * Number
 * Dimensionally scalable
 * Plot and render data live
 * Save rendered chart to PNG
 * Save plotted data to CSV
 * Demo application

## Todo

 * Optimize Cairo/snapshot code
 * Make line and gauge charts handle negative axis ranges
 * Make charts zoomable
 * Make chart axes autoscale depending on plot value
 * Etc.

## Usage

```
#include <gtk/gtk.h>
#include <gtkchart.h>
...
// Required for GtkChart to be recognized by builder
gtk_chart_get_type();
...
GtkChart *chart = GTK_CHART(gtk_chart_new());
gtk_chart_set_type(chart, GTK_CHART_TYPE_LINE);
gtk_chart_set_title(chart, "Title");
gtk_chart_set_label(chart, "Label");
gtk_chart_set_x_label(chart, "X label [ ]");
gtk_chart_set_y_label(chart, "Y label [ ]");
gtk_chart_set_x_max(chart, 100);
gtk_chart_set_y_max(chart, 10);
gtk_chart_set_width(chart, 800);
...
gtk_chart_plot_point(chart, 0.0, 0.0);
gtk_chart_plot_point(chart, 1.0, 1.0);
gtk_chart_plot_point(chart, 2.0, 2.0);
gtk_chart_plot_point(chart, 3.0, 3.0);
...
gtk_chart_save_csv(chart, "chart0.csv");
gtk_chart_save_png(chart, "chart0.png");
```

See the [demo application](demo/demo_box.c) for more details.

## Chart Types

<p align="center">
<img src="images/line.png">
<img src="images/scatter.png">
<img src="images/gauge-angular.png">
<img src="images/gauge-line.png">
<img src="images/number.png">
</p>

