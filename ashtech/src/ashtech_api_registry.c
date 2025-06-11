#include "ashtech_api_registry.h"

#include "ashtech.h"

#include <string.h>

typedef struct api_registry_entry_t
{
    char name[256];
    void *api;
} api_registry_entry_t;

static bool g_initialised = false;
static api_registry_entry_t g_api_registry_entries[2];

static void add_api(const char *name, void *api)
{
    // todo: better string handling
    strcpy_s(g_api_registry_entries[1].name, 256, name);

    g_api_registry_entries[1].api = api;
}

static void *get_api(const char *name)
{
    // todo: fixme
    (void)name;

    return g_api_registry_entries[1].api;
}

static at_api_registry_api g_api_registry;
at_api_registry_api *at_global_api_registry;

void at_init_global_api_registry(void)
{
    if (!g_initialised) {
        g_initialised = true;
        g_api_registry.add_api = add_api;
        g_api_registry.get_api = get_api;

        at_global_api_registry = &g_api_registry;
    }
}

void at_shutdown_global_api_registry(void)
{
    if (at_global_api_registry != NULL) {
        g_initialised = false;
        g_api_registry.add_api = NULL;
        g_api_registry.get_api = NULL;

        at_global_api_registry = NULL;
    }
}
