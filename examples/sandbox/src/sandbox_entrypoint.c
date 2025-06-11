#include "ashtech_registry.h"

#include <ashtech.h>
#include <string.h>

typedef struct api_registry_entry_t
{
    char name[256];
    void *api;
} api_registry_entry_t;

static at_core_registry_api g_api_registry;
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

at_core_registry_api *at_create_core_registry(void)
{
    if (!g_initialised) {
        g_initialised = true;
        g_api_registry.add_api = add_api;
        g_api_registry.get_api = get_api;
    }

    return &g_api_registry;
}

void at_destroy_core_registry(at_core_registry_api *registry)
{
    if (registry != NULL) {
        g_initialised = false;
        g_api_registry.add_api = NULL;
        g_api_registry.get_api = NULL;
    }
}
