#ifndef BOLT_GB_CLOCK_HH_
#define BOLT_GB_CLOCK_HH_

#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

namespace bolt {
    struct gb_clock_callback_priority {
        enum {
            high = 1,
            low = -1,
            normal = 0
        };
    };

    enum struct gb_clock_state {
        rising,
        falling,
        level
    };

    using gb_clock_callback = std::function<void(uint64_t, gb_clock_state)>;

    class gb_clock {
    public:
        gb_clock()
            : cycle(0u) {

        }

        ~gb_clock() = default;

        auto start(void) -> void {
            while (true) {
                for (auto &&cb : callbacks) {
                    cb.first(cycle, gb_clock_state::rising);
                    cb.first(cycle, gb_clock_state::level);
                    cb.first(cycle, gb_clock_state::falling);
                }

                cycle += 1u;
            }
        }

        auto register_callback(gb_clock_callback cb, int priority = gb_clock_callback_priority::normal) -> void {
            if (callbacks.empty()) {
                callbacks.emplace(callbacks.begin(), cb, priority);
            } else {
                auto pos = std::find_if(callbacks.crbegin(), callbacks.crend(), [priority](const auto &v) { return v.second >= priority; });

                callbacks.emplace(pos.base(), cb, priority);
            }
        }

    private:
        uint64_t cycle;

        std::vector<std::pair<gb_clock_callback, int>> callbacks;
    };
}

#endif