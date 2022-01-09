#pragma once

#include "core.hpp"

namespace opnGL {

    struct window_data {
        int width;
        int height;
        std::string title;

        window_data(const std::string& title = "opnGL window", int width = 1280, int height = 720)
            : title(title), width(width), height(height) {}
    };

    class OPNGL_API window {
    public:
        // using event_callback_fn = std::function<void(/* ??? */&)>;

        virtual ~window() = default;

        virtual void on_update() = 0;

        static window* create(const window_data& data = window_data());
    };

}
