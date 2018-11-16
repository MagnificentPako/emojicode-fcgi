#include <fcgi_stdio.h>
#include <stdlib.h>
#include <emojicode/runtime/Runtime.h>

class FCGI {};

extern "C" void fcgiLoop(FCGI *fcgi, runtime::Callable<void> callable) {
    callable.retain();
    while(FCGI_Accept() >= 0)
        callable();
}

SET_INFO_FOR(FCGI, fcgi, 1f3c3)
