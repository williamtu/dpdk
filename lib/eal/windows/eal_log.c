/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2017-2018 Intel Corporation
 */

#include <rte_common.h>
#include <rte_log.h>
#include "eal_log.h"

/* set the log to default function, called during eal init process. */
int
eal_log_init(__rte_unused const char *id, __rte_unused int facility)
{
	FILE *f;
	if( (f = fopen( "c:\\mydpdk.log", "w+" )) == NULL ) // C4996
		printf( "The file 'mydpdk.log' was not opened\n" );
	else
		printf( "The file 'mydpdk.log' was opened\n" );

	rte_openlog_stream(f);
	eal_log_set_default(f);

	//rte_openlog_stream(stderr);
	//eal_log_set_default(stderr);
	rte_log_set_global_level(8);
	return 0;
}
