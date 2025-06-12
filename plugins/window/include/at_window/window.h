#pragma once

#define AT_WINDOW_API_NAME "at_window_api"

typedef struct at_window_api
{
    void (*create_window)(void);
} at_window_api;
