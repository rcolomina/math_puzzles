// common/log.h — tiny header-only leveled logging for the puzzle solutions.
//
// Every solution keeps its final answer on stdout, but routes its diagnostic
// chatter through these macros so the noise can be turned on/off uniformly.
//
// Levels (lowest = most severe):
//     0 ERROR   1 WARN   2 INFO (default)   3 DEBUG
//
// The active level is read once from the VERBOSE environment variable:
//     ./solution            # INFO  (level 2) — results + high-level steps
//     VERBOSE=3 ./solution   # DEBUG (level 3) — full trace
//     VERBOSE=0 ./solution   # ERROR only — quiet
//
// Usage:  LOG_INFO("answer = " << result);
//         LOG_DEBUG("stack top = " << s.top());
#ifndef PUZZLES_COMMON_LOG_H
#define PUZZLES_COMMON_LOG_H

#include <iostream>
#include <cstdlib>

namespace puzzlelog {

enum Level { ERROR = 0, WARN = 1, INFO = 2, DEBUG = 3 };

// Active verbosity, parsed once from $VERBOSE (defaults to INFO).
inline int level() {
    static int cached = -1;
    if (cached < 0) {
        const char* env = std::getenv("VERBOSE");
        cached = (env && *env) ? std::atoi(env) : INFO;
    }
    return cached;
}

inline const char* tag(int lvl) {
    switch (lvl) {
        case ERROR: return "ERROR";
        case WARN:  return "WARN";
        case INFO:  return "INFO";
        default:    return "DEBUG";
    }
}

}  // namespace puzzlelog

// `stream_expr` is any ostream-insertable chain, e.g.  "x = " << x << ", y=" << y
#define LOG_AT(lvl, stream_expr)                                            \
    do {                                                                    \
        if (puzzlelog::level() >= (lvl)) {                                  \
            std::ostream& _os = ((lvl) <= puzzlelog::WARN) ? std::cerr      \
                                                           : std::cout;     \
            _os << "[" << puzzlelog::tag(lvl) << "] " << stream_expr        \
                << std::endl;                                               \
        }                                                                   \
    } while (0)

#define LOG_ERROR(stream_expr) LOG_AT(puzzlelog::ERROR, stream_expr)
#define LOG_WARN(stream_expr)  LOG_AT(puzzlelog::WARN,  stream_expr)
#define LOG_INFO(stream_expr)  LOG_AT(puzzlelog::INFO,  stream_expr)
#define LOG_DEBUG(stream_expr) LOG_AT(puzzlelog::DEBUG, stream_expr)

#endif  // PUZZLES_COMMON_LOG_H
