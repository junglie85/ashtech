#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <at/ashtech.h>
#include <at/api_registry.h>
#include <at/thing.h>
#include <at_window/window.h>

int main(void)
{
    at_init_global_api_registry();

    HMODULE ashtech_window = LoadLibraryA("at_window.dll");
    if (ashtech_window == NULL) {
        printf("failed to load library");
        return -1;
    }
    at_load_plugin_fn *load_plugin = (at_load_plugin_fn *)GetProcAddress(ashtech_window, AT_STRINGIFY(AT_LOAD_PLUGIN_FN_NAME));
    if (load_plugin == NULL) {
        printf("failed to load plugin entrypoint");
        return -2;
    }
    load_plugin(at_global_api_registry, true);

    at_window_api *window_api = at_global_api_registry->get_api(AT_WINDOW_API_NAME);

    printf("Hello, ashtech!\n");
    at_thing_do();
    window_api->create_window();

    load_plugin(at_global_api_registry, false);
    FreeLibrary(ashtech_window);

    at_shutdown_global_api_registry();

    return 0;
}
