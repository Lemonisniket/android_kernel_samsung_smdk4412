/*
 * arm/include/asm/relaxed.h
 *
 * Copyright (c) 2014 NVIDIA Corporation. All rights reserved.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _ASM_RELAXED_H_
#define _ASM_RELAXED_H_

#include <asm-generic/relaxed.h>
#include <linux/compiler.h>

#ifndef cpu_read_relax
#if defined(__LINUX_ARM_ARCH__) && __LINUX_ARM_ARCH__ >= 7
static inline void cpu_read_relax(void)
{
	asm volatile("wfe" : : : "memory");
}
#else
static inline void cpu_read_relax(void)
{
	barrier();
}
#endif
#endif

#ifndef cpu_relax
#define cpu_relax() cpu_read_relax()
#endif

#endif /* _ASM_RELAXED_H_ */
