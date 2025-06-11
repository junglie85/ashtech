#include "ashtech_window.h"

#include <ashtech.h>
#include <ashtech_api_registry.h>
#include <stdbool.h>
#include <stdio.h>

at_window_api g_window_api;
bool g_initialised = false;

static void create_window(void)
{
    printf("window created\n");
}

AT_LOAD_PLUGIN
{
    (void)load;
    if (!g_initialised) {
        g_initialised = true;
        g_window_api.create_window = create_window;

        api_registry->add_api(AT_WINDOW_API_NAME, &g_window_api);
    }
}
