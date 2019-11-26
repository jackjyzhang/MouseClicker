#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <stdlib.h>

#define XMAX 1439
#define YMAX 899

// trick: shift + cmd + 4 to show mouse position

// move to (x, y) and stay there for 1 second
void mouseMove(float x, float y) {
    CGEventRef move1 = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved,
        CGPointMake(x, y),
        kCGMouseButtonLeft // ignored
    );
    CGEventPost(kCGHIDEventTap, move1);
    sleep(1);
    CFRelease(move1);
}

// left click the point (x, y)
void mouseClick(float x, float y) {
    CGEventRef click1_down = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown,
        CGPointMake(x, y),
        kCGMouseButtonLeft
    );
    // Left button up at 500x250
    CGEventRef click1_up = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp,
        CGPointMake(x, y),
        kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, click1_down);
    CGEventPost(kCGHIDEventTap, click1_up);
    CFRelease(click1_up);
    CFRelease(click1_down);
}

int main() {
    /*
    // linear mouse movement
    for(int i = 0 ; i <= 10; i++) {
        mouseMove(50 * i, 50 * i);
    }
    */

    /*
    // random mouse movement
    for(int i = 0; i < 10; i++) {
        float xpos = (float)rand() * XMAX / RAND_MAX;
        float ypos = (float)rand() * YMAX / RAND_MAX;
        mouseMove(xpos, ypos);
    }
    */

    // launchpad pos: (115, 867)
    // click launchpad 10 times
    for(int i = 0 ; i < 10; i++) {
        mouseClick(115, 867);
        sleep(1);
    }
    
    return 0;
}