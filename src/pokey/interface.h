/*
    interface.h -- header for interface.c
    Copyright (C) 2002 Guus Sliepen <guus@sliepen.warande.net>,
                  2002 Ivo Timmermans <itimmermans@bigfoot.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id: interface.h,v 1.2 2002/04/28 12:46:26 zarq Exp $
*/

#ifndef __TINC_INTERFACE_H__
#define __TINC_INTERFACE_H__

#include <gtk/gtk.h>
#include <glade/glade.h>
#include <libgnomeui/gnome-canvas.h>

#include "node.h"
#include "edge.h"

#define INTERFACE_FILE "pokey.glade"

typedef struct graph_t {
  struct graph_t *attractors[20];
  struct graph_t *repellors[20];
  int nat;
  int nrp;
  node_t *node;
} graph_t;

struct if_subnet_data {
  GnomeCanvasItem *item;           /* The gnome canvas item associated with the line */
  GtkCTreeNode *ctn;
};

struct if_node_data {
  double x, y;
  int visible;
  int id;
  GnomeCanvasItem *item;
  GtkCTreeNode *ctn;
  GladeXML *hi_xml;
};

extern int build_graph;

void if_build_graph(void);
int init_interface(void);

#endif /* __TINC_INTERFACE_H__ */