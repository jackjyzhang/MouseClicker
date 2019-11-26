#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>

// https://developer.apple.com/documentation/coregraphics/quartz_event_services
// https://stackoverflow.com/questions/2734117/simulating-mouse-input-programmatically-in-os-x

int main() {
    // Move to 200x200
    CGEventRef move1 = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved,
        CGPointMake(2, 2),
        kCGMouseButtonLeft // ignored
    );
    // Move to 1000x250
    CGEventRef move2 = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved,
        CGPointMake(2000, 2000),
        kCGMouseButtonLeft // ignored
    );
    // Left button down at 500x250
    CGEventRef click1_down = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown,
        CGPointMake(2000, 2000),
        kCGMouseButtonLeft
    );
    // Left button up at 500x250
    CGEventRef click1_up = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp,
        CGPointMake(2000, 2000),
        kCGMouseButtonLeft
    );

    // Now, execute these events with an interval to make them noticeable
    CGEventPost(kCGHIDEventTap, move1);
    sleep(1);
    CGEventPost(kCGHIDEventTap, move2);
    sleep(1);
    CGEventPost(kCGHIDEventTap, click1_down);
    CGEventPost(kCGHIDEventTap, click1_up);

    // Release the events
    CFRelease(click1_up);
    CFRelease(click1_down);
    CFRelease(move2);
    CFRelease(move1);

    return 0;
}