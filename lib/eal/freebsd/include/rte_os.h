/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2019 Intel Corporation
 */

#ifndef _RTE_OS_H_
#define _RTE_OS_H_

/**
 * This header should contain any definition
 * which is not supported natively or named differently in FreeBSD.
 */

#include <pthread_np.h>
#include <sys/queue.h>

/* These macros are compatible with system's sys/queue.h. */
#define RTE_TAILQ_INIT(head) TAILQ_INIT(head)
#define RTE_TAILQ_HEAD(name, type) TAILQ_HEAD(name, type)
#define RTE_TAILQ_LAST(head, headname) TAILQ_LAST(head, headname)
#define RTE_TAILQ_ENTRY(type) TAILQ_ENTRY(type)
#define RTE_TAILQ_FIRST(head) TAILQ_FIRST(head)
#define RTE_TAILQ_EMPTY(head) TAILQ_EMPTY(head)
#define RTE_TAILQ_NEXT(elem, field) TAILQ_NEXT(elem, field)
#define RTE_TAILQ_HEAD_INITIALIZER(head) TAILQ_HEAD_INITIALIZER(head)
#define RTE_TAILQ_FOREACH(var, head, field) TAILQ_FOREACH(var, head, field)
#define RTE_TAILQ_INSERT_TAIL(head, elm, field) \
	TAILQ_INSERT_TAIL(head, elm, field)
#define RTE_TAILQ_REMOVE(head, elm, field) TAILQ_REMOVE(head, elm, field)
#define RTE_TAILQ_INSERT_BEFORE(listelm, elm, field) \
	TAILQ_INSERT_BEFORE(listelm, elm, field)
#define RTE_TAILQ_INSERT_AFTER(head, listelm, elm, field) \
	TAILQ_INSERT_AFTER(head, listelm, elm, field)
#define RTE_TAILQ_INSERT_HEAD(head, elm, field) \
	TAILQ_INSERT_HEAD(head, elm, field)

#define RTE_STAILQ_HEAD(name, type) STAILQ_HEAD(name, type)
#define RTE_STAILQ_HEAD_INITIALIZER(head) STAILQ_HEAD_INITIALIZER(head)
#define RTE_STAILQ_ENTRY(type) STAILQ_ENTRY(type)

/* This is not defined in sys/queue.h */
#ifndef TAILQ_FOREACH_SAFE
#define TAILQ_FOREACH_SAFE(var, head, field, tvar)		\
	for ((var) = RTE_TAILQ_FIRST((head));			\
	    (var) && ((tvar) = RTE_TAILQ_NEXT((var), field), 1);	\
	    (var) = (tvar))
#endif

typedef cpuset_t rte_cpuset_t;
#define RTE_HAS_CPUSET
#define RTE_CPU_AND(dst, src1, src2) do \
{ \
	cpuset_t tmp; \
	CPU_COPY(src1, &tmp); \
	CPU_AND(&tmp, src2); \
	CPU_COPY(&tmp, dst); \
} while (0)
#define RTE_CPU_OR(dst, src1, src2) do \
{ \
	cpuset_t tmp; \
	CPU_COPY(src1, &tmp); \
	CPU_OR(&tmp, src2); \
	CPU_COPY(&tmp, dst); \
} while (0)
#define RTE_CPU_FILL(set) CPU_FILL(set)

/* In FreeBSD 13 CPU_NAND macro is CPU_ANDNOT */
#ifdef CPU_NAND
#define RTE_CPU_NOT(dst, src) do \
{ \
	cpuset_t tmp; \
	CPU_FILL(&tmp); \
	CPU_NAND(&tmp, src); \
	CPU_COPY(&tmp, dst); \
} while (0)
#else
#define RTE_CPU_NOT(dst, src) do \
{ \
	cpuset_t tmp; \
	CPU_FILL(&tmp); \
	CPU_ANDNOT(&tmp, src); \
	CPU_COPY(&tmp, dst); \
} while (0)
#endif

#endif /* _RTE_OS_H_ */
