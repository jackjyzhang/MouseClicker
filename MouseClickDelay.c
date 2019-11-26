#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

// click (x, y) on time t
void delayedMouseClick(float x, float y, time_t t) {
    while(true) {
        printf("%ld\n", time(NULL));
        if(time(NULL) >= t) {
            mouseClick(x, y);
            break;
        }
    }
}

int main() {
    printf("An automatic mouseclicker - Jack Zhang © 2019\n");
    float x, y;
    printf("Enter mouse coordinates(x, y):\n");
    scanf("%f%f", &x, &y);
    time_t t;
    printf("Enter unix epoch timestamp:\n");
    scanf("%ld", &t);
    delayedMouseClick(x, y, t);
    // example: 115, 867, 1574XXXXXX
    return 0;
}