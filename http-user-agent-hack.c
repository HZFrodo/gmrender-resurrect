//
// gcc -I lib -I include -shared -fPIC -Wall -o http-user-agent-hack.so http-user-agent-hack.c
// LD_PRELOAD=$PWD/http-user-agent-hack.so cvlc
//
#define _GNU_SOURCE
#include <stdio.h>
#include "libvlc_internal.h"

void libvlc_set_user_agent (libvlc_instance_t *p_i, const char *name, const char *http)
{
    libvlc_int_t *p_libvlc = p_i->p_libvlc_int;
    char *str;

    var_SetString (p_libvlc, "user-agent", name);
    if ((http != NULL)
     && (asprintf (&str, "GStreamer curlhttpsrc libcurl/7.87.8 curl/7.87.8 aria2/1.36.6") != -1))
    {
        var_SetString (p_libvlc, "http-user-agent", str);
	fprintf(stderr, "!!! force http-user-agent to [%s] !!!\n", str);
        free (str);
    }
    (void)http;
}
