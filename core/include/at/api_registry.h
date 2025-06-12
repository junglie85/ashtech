#pragma once

#include "at/ashtech.h"

typedef struct at_api_registry_api
{
    void (*add_api)(const char *name, void *api);
    void *(*get_api)(const char *name);
} at_api_registry_api;

#define AT_LOAD_PLUGIN_FN_NAME at_load_plugin
#define AT_LOAD_PLUGIN_FN(name) void name(at_api_registry_api *api_registry, bool load)
typedef AT_LOAD_PLUGIN_FN(at_load_plugin_fn);
#define AT_LOAD_PLUGIN AT_DLL_EXPORT AT_LOAD_PLUGIN_FN(AT_EXPAND(AT_LOAD_PLUGIN_FN_NAME))

#if defined(AT_INTERNAL_FN)

extern at_api_registry_api *at_global_api_registry;
void at_init_global_api_registry(void);
void at_shutdown_global_api_registry(void);

#endif // AT_INTERNAL_FN
