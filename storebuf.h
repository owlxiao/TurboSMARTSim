/*
 * storebuf.h
 *
 */

/*
 *
 * Redistributions of any form whatsoever must retain and/or include the
 * following acknowledgment, notices and disclaimer:
 *
 * This product includes software developed by Carnegie Mellon University.
 *
 * Copyright (c) 2005 by Thomas F. Wenisch, Roland E. Wunderlich, Babak Falsafi
 * and James C. Hoe for the SimFlex Project, Computer Architecture Lab at
 * Carnegie Mellon, Carnegie Mellon University
 *
 * This source file includes SMARTSim extensions originally written by
 * Thomas Wenisch and Roland Wunderlich of the SimFlex Project.
 *
 * For more information, see the SimFlex project website at:
 *   http://www.ece.cmu.edu/~simflex
 *
 * You may not use the name "Carnegie Mellon University" or derivations
 * thereof to endorse or promote products derived from this software.
 *
 * If you modify the software you must place a notice on or within any
 * modified version provided or made available to any third party stating
 * that you have modified the software.  The notice shall include at least
 * your name, address, phone number, email address and the date and purpose
 * of the modification.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" WITHOUT ANY WARRANTY OF ANY KIND, EITHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO ANY WARRANTY
 * THAT THE SOFTWARE WILL CONFORM TO SPECIFICATIONS OR BE ERROR-FREE AND ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
 * TITLE, OR NON-INFRINGEMENT.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 * BE LIABLE FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO DIRECT, INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES, ARISING OUT OF, RESULTING FROM, OR IN
 * ANY WAY CONNECTED WITH THIS SOFTWARE (WHETHER OR NOT BASED UPON WARRANTY,
 * CONTRACT, TORT OR OTHERWISE).
 *
 */

#ifndef STOREBUF_H
#define STOREBUF_H

#include "host.h"

struct store_buffer_entry {
    struct store_buffer_entry * next;
    tick_t release_cycle;
};

extern struct store_buffer_entry * theSBHead;

extern struct store_buffer_entry * theSBEntryPool;
extern struct store_buffer_entry ** theSBEntryFreeList;
extern int theSBSize;
extern int theSBCapacity;

static inline int SB_full() {
    return theSBSize == theSBCapacity;
}
static inline int SB_empty() {
    return theSBSize == 0;
}
static inline int SB_size() {
    return theSBSize;
}

tick_t SB_next_release_cycle();
void SB_pop_head();
void SB_enqueue(tick_t release_cycle);
void SB_alloc(int anSBCapacity);



#endif //STOREBUF_H
