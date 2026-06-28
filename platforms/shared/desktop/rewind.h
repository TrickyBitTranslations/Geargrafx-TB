/*
 * Geargrafx - PC Engine / TurboGrafx Emulator
 * Copyright (C) 2024  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

#ifndef REWIND_H
#define REWIND_H

#include "geargrafx.h"

#ifdef REWIND_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

// Absolute hard cap for the ring buffer (sizes the static slot-size table). Effective capacity is
// derived from config_rewind (buffer_seconds / frames_per_snapshot) and clamped to this. Each slot
// holds a full save state + a screenshot (~2 MB), so memory ~= capacity * slot_size - allocations
// that don't fit fail gracefully (rewind stays at its previous size). 3600 = up to 60 s at 1 fps/snap.
#define REWIND_MAX_SNAPSHOTS        3600

EXTERN bool rewind_init(void);
EXTERN void rewind_destroy(void);
EXTERN void rewind_reset(void);
EXTERN void rewind_push(void);
EXTERN bool rewind_pop(void);
EXTERN bool rewind_seek(int age);
EXTERN void rewind_commit_seek(void);
EXTERN void rewind_set_active(bool a);
EXTERN bool rewind_is_active(void);
EXTERN int rewind_get_snapshot_count(void);
EXTERN int rewind_get_capacity(void);
EXTERN int rewind_get_frames_per_snapshot(void);
EXTERN size_t rewind_get_memory_usage(void);

#undef REWIND_IMPORT
#undef EXTERN
#endif /* REWIND_H */
