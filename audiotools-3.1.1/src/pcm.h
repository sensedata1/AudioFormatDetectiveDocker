#ifndef PCM_H
#define PCM_H

#include "pcm_conv.h"

/********************************************************
 Audio Tools, a module and set of tools for manipulating audio data
 Copyright (C) 2007-2015  Brian Langenberger

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
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*******************************************************/


/******************
  FrameList Object
*******************/

#ifndef STANDALONE

typedef struct {
    PyObject_HEAD;

    unsigned int frames; /*the total number of PCM frames in this FrameList
                           aka the total number of rows in the "samples" array*/
    unsigned int channels; /*the total number of channels in this FrameList
                             aka the total number of columns in "samples*/
    unsigned int bits_per_sample; /*the maximum size of each sample, in bits*/

    int* samples;            /*the actual sample data itself,
                               stored raw as 32-bit signed integers*/
    unsigned samples_length; /*the total number of samples
                               which must be evenly distributable
                               between channels and bits-per-sample*/
} pcm_FrameList;

#ifdef PCM_MODULE
void
FrameList_dealloc(pcm_FrameList* self);

PyObject*
FrameList_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int FrameList_init(pcm_FrameList *self, PyObject *args, PyObject *kwds);

/*generates a new pcm_FrameList object via _PyObject_New
  whose fields *must* be populated by additional C code*/
pcm_FrameList*
FrameList_create(void);

PyObject*
FrameList_empty(PyObject *dummy, PyObject *args);

int
FrameList_CheckExact(PyObject *o);

PyObject*
FrameList_frames(pcm_FrameList *self, void* closure);

PyObject*
FrameList_channels(pcm_FrameList *self, void* closure);

PyObject*
FrameList_bits_per_sample(pcm_FrameList *self, void* closure);

Py_ssize_t
FrameList_len(pcm_FrameList *o);

PyObject*
FrameList_richcompare(PyObject *a, PyObject *b, int op);

int
FrameList_equals(pcm_FrameList *a, pcm_FrameList *b);

PyObject*
FrameList_GetItem(pcm_FrameList *o, Py_ssize_t i);

PyObject*
FrameList_frame(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_channel(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_to_bytes(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_to_float(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_frame_count(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_split(pcm_FrameList *self, PyObject *args);

PyObject*
FrameList_concat(pcm_FrameList *a, PyObject *bb);

PyObject*
FrameList_repeat(pcm_FrameList *a, Py_ssize_t i);

PyObject*
FrameList_inplace_concat(pcm_FrameList *a, PyObject *bb);

PyObject*
FrameList_inplace_repeat(pcm_FrameList *a, Py_ssize_t i);

PyObject*
FrameList_from_list(PyObject *dummy, PyObject *args);

PyObject*
FrameList_from_frames(PyObject *dummy, PyObject *args);

PyObject*
FrameList_from_channels(PyObject *dummy, PyObject *args);

/*for use with the PyArg_ParseTuple function*/
int
FrameList_converter(PyObject* obj, void** framelist);
#endif

/***********************
  FloatFrameList Object
************************/

typedef struct {
    PyObject_HEAD;

    unsigned int frames; /*the total number of PCM frames in this FrameList
                           aka the total number of rows in the "samples" array*/
    unsigned int channels; /*the total number of channels in this FrameList
                             aka the total number of columns in "samples*/

    double *samples;          /*the actual sample data itself,
                                stored raw as doubles*/
    unsigned samples_length;  /*the total number of samples
                                which must be evenly distributable
                                between channels*/
} pcm_FloatFrameList;

#ifdef PCM_MODULE
void
FloatFrameList_dealloc(pcm_FloatFrameList* self);

PyObject*
FloatFrameList_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
FloatFrameList_init(pcm_FloatFrameList *self, PyObject *args, PyObject *kwds);

int
FloatFrameList_CheckExact(PyObject *o);

PyObject*
FloatFrameList_blank(PyObject *dummy, PyObject *args);

pcm_FloatFrameList*
FloatFrameList_create(void);

PyObject*
FloatFrameList_empty(PyObject *dummy, PyObject *args);

PyObject*
FloatFrameList_frames(pcm_FloatFrameList *self, void* closure);

PyObject*
FloatFrameList_channels(pcm_FloatFrameList *self, void* closure);

Py_ssize_t
FloatFrameList_len(pcm_FloatFrameList *o);

PyObject*
FloatFrameList_richcompare(PyObject *a, PyObject *b, int op);

int
FloatFrameList_equals(pcm_FloatFrameList *a, pcm_FloatFrameList *b);

PyObject*
FloatFrameList_GetItem(pcm_FloatFrameList *o, Py_ssize_t i);

PyObject*
FloatFrameList_frame(pcm_FloatFrameList *self, PyObject *args);

PyObject*
FloatFrameList_channel(pcm_FloatFrameList *self, PyObject *args);

PyObject*
FloatFrameList_to_int(pcm_FloatFrameList *self, PyObject *args);

PyObject*
FloatFrameList_split(pcm_FloatFrameList *self, PyObject *args);

PyObject*
FloatFrameList_concat(pcm_FloatFrameList *a, PyObject *bb);

PyObject*
FloatFrameList_repeat(pcm_FloatFrameList *a, Py_ssize_t i);

PyObject*
FloatFrameList_inplace_concat(pcm_FloatFrameList *a, PyObject *bb);

PyObject*
FloatFrameList_inplace_repeat(pcm_FloatFrameList *a, Py_ssize_t i);

PyObject*
FloatFrameList_from_frames(PyObject *dummy, PyObject *args);

PyObject*
FloatFrameList_from_channels(PyObject *dummy, PyObject *args);

/*for use with the PyArg_ParseTuple function*/
int
FloatFrameList_converter(PyObject* obj, void** floatframelist);
#endif

#endif

#endif
