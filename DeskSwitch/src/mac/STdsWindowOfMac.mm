//
//  STdsWindowOfMac.mm
//  STDeskSwitch
//
//  Created by yhys on 2017/8/30.
//  Copyright © 2017年 ST Studio. All rights reserved.
//


#import <AppKit/AppKit.h>

#import "STdsWindow.hpp"
#import "STdsApplication.hpp"
#import "STdsConst.hpp"

////////////////////////////////////////////
//Function for utils
uint16_st translateToSTMouse(NSInteger buttonNumber)
{
    switch (buttonNumber)
    {
        case 1:
            return ST_MOUSE_BUTTON_3;
        case 2:
            return ST_MOUSE_BUTTON_4;
        case 3:
            return ST_MOUSE_BUTTON_5;
        case 4:
            return ST_MOUSE_BUTTON_6;
        case 5:
            return ST_MOUSE_BUTTON_7;
        case 6:
            return ST_MOUSE_BUTTON_8;
    }
    return ST_MOUSE_BUTTON_UNKNOW;
}

uint16_st translateToSTKey(NS_STDS Keyboard& keyboard, uint16_st keycode)
{
    return keyboard.GetPlatformKey(keycode);
}

uint16_st translateToSTFlag(NSUInteger flag)
{
    uint16_st ret = ST_FLAG_MODIFIER_UNKNOW;
    
    if(flag & NSEventModifierFlagCommand)
        ret |= ST_FLAG_MODIFIER_SPECIAL;
    
    if(flag & NSEventModifierFlagShift)
        ret |= ST_FLAG_MODIFIER_SHIFT;
    
    if(flag & NSEventModifierFlagControl)
        ret |= ST_FLAG_MODIFIER_CTRL;
    
    if(flag & NSEventModifierFlagOption)
        ret |= ST_FLAG_MODIFIER_ALT;
    
    return ret;
}

NSUInteger translateToPlatformFlag(uint16_st stFlag)
{
    NSUInteger ret = 0;
    
    if(stFlag & ST_FLAG_MODIFIER_SPECIAL)
        ret |= NSEventModifierFlagCommand;
    
    if(stFlag & ST_FLAG_MODIFIER_SHIFT)
        ret |= NSEventModifierFlagShift;
    
    if(stFlag & ST_FLAG_MODIFIER_CTRL)
        ret |= NSEventModifierFlagControl;
    
    if(stFlag & ST_FLAG_MODIFIER_ALT)
        ret |= NSEventModifierFlagOption;
    
    return ret;
}
////////////////////////////////////////////
//Window
@interface STNSWindow : NSWindow
{
}

@end

@implementation STNSWindow

@end

////////////////////////////////////////////
//Window delegate
@interface STNSWindowDelegate : NSObject<NSWindowDelegate>
{
    NS_STDS Window* _window;
}

- (instancetype) initWithSTWindow:(NS_STDS Window*)window;

@end

@implementation STNSWindowDelegate

- (instancetype) initWithSTWindow:(STds::Window *)window
{
    _window = window;
    return [super init];
}

- (BOOL)windowShouldClose:(id)sender
{
    return _window->ShouldClose();
}

- (void)windowWillClose:(NSNotification *)notification
{
    if(_window->GetDelegate())
        _window->GetDelegate()->WindowWillFinish();
    _window->SetDidClose();
}

- (void)windowWillMiniaturize:(NSNotification *)notification
{
    if(_window->GetDelegate())
        _window->GetDelegate()->WindowWillEnterBackground();
}

- (void)windowDidMiniaturize:(NSNotification *)notification
{
    if(_window->GetDelegate())
        _window->GetDelegate()->WindowDidEnterBackground();
}

- (void)windowDidDeminiaturize:(NSNotification *)notification
{
    if(_window->GetDelegate())
        _window->GetDelegate()->WindowDidEnterForeground();
}

@end

////////////////////////////////////////////
//Main View
@interface STContentView : NSView
{
    NS_STDS Window* _stWindow;
}

- (id) initWithSTWindow:(NS_STDS Window*)stWindow;

@end

@implementation STContentView
//initialize
- (id) initWithSTWindow:(NS_STDS Window*)stWindow
{
    _stWindow = stWindow;
    return [self init];
}
//draw

//mouse event commen function

void fireStMouseEvent(NS_STDS Window* window, NSEvent *event, int8_st buttonType, int8_st state)
{
    if(!window->_hMouseBordEvent)
        return;
    
    NSPoint eventLocation = [event locationInWindow];
    NS_STCC Point2D stPoint = { eventLocation.x, eventLocation.y };
    
    uint16_st stFlag = translateToSTFlag([event modifierFlags] & NSEventModifierFlagDeviceIndependentFlagsMask);
    
    window->_hMouseBordEvent(stPoint, buttonType, state, stFlag);
}

//mouse event
- (void)mouseMoved:(NSEvent *)event
{
    if(!_stWindow->_hMouseBordEvent)
        return;
    
    NSPoint eventLocation = [event locationInWindow];
    NS_STCC Point2D stPoint = { eventLocation.x, eventLocation.y };
    
    if(_stWindow->_windowConfig._receiveEventOnlyInWindow)
    {
        NSRect windowRect = [_stWindow->wom._window frame];
        NS_STCC Rect stRect = {windowRect.origin.x,
            windowRect.origin.y, windowRect.size.width, windowRect.size.height};
        
        if(! NS_STCC IfPointInRect(stPoint, stRect))
            return;
    }
    
    uint16_st stFlag = translateToSTFlag([event modifierFlags] & NSEventModifierFlagDeviceIndependentFlagsMask);
    
    //mouse moved is commen for all button, so the type if unknow.
    _stWindow->_hMouseBordEvent(stPoint, ST_MOUSE_BUTTON_UNKNOW,
                                NS_STDS STMousePressMove, stFlag);
}
- (void)mouseDown:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_LEFT,
                     NS_STDS STMousePressDown);
}

- (void)mouseUp:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_LEFT,
                     NS_STDS STMousePressUp);
}

- (void)mouseDragged:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_LEFT,
                     NS_STDS STMousePressDrag);
}

- (void)rightMouseDown:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_RIGHT,
                     NS_STDS STMousePressDown);
}

- (void)rightMouseUp:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_RIGHT,
                     NS_STDS STMousePressUp);
}

- (void)rightMouseDragged:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, ST_MOUSE_BUTTON_RIGHT,
                     NS_STDS STMousePressDrag);
}

- (void)otherMouseDown:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, translateToSTMouse([event buttonNumber]),
                     NS_STDS STMousePressDown);
}

- (void)otherMouseUp:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, translateToSTMouse([event buttonNumber]),
                     NS_STDS STMousePressUp);
}

- (void)otherMouseDragged:(NSEvent *)event
{
    fireStMouseEvent(_stWindow, event, translateToSTMouse([event buttonNumber]),
                     NS_STDS STMousePressDrag);
}

- (nullable NSView *)hitTest:(NSPoint)point
{
    return self;
}

//key event
- (void)keyDown:(NSEvent *)event
{
    if(!_stWindow->_hKeyBordEvent)
        return;
    
    NS_STDS Keyboard& stKeyboard = _stWindow->_applicatin->_keyboard;
    
    uint16_st stFlag = translateToSTFlag([event modifierFlags] & NSEventModifierFlagDeviceIndependentFlagsMask);
    
    uint16_st stKey  = translateToSTKey(stKeyboard, [event keyCode]);
    
    _stWindow->_hKeyBordEvent(stKey,stFlag,NS_STDS STKeyPressStateDown);
}

- (void)keyUp:(NSEvent *)event
{
    if(!_stWindow->_hKeyBordEvent)
        return;
    
    NS_STDS Keyboard& stKeyboard = _stWindow->_applicatin->_keyboard;
    NSUInteger flag = [event modifierFlags] & NSEventModifierFlagDeviceIndependentFlagsMask;
    uint16_st stFlag = translateToSTFlag(flag);
    uint16_st stKey  = translateToSTKey(stKeyboard, [event keyCode]);
    
    _stWindow->_hKeyBordEvent(stKey,stFlag,NS_STDS STKeyPressStateUp);
}

- (BOOL)performKeyEquivalent:(NSEvent *)event
{
    return NO;
}

- (void)flagsChanged:(NSEvent *)event
{
    //NSLog(@"flagsChanged view %lud",(unsigned long)[event modifierFlags]);
}

@end


static bool CreateNativeWindow(NS_STDS Window* window)
{
    NSWindowStyleMask style = NSWindowStyleMaskClosable | NSWindowStyleMaskTitled | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
    
    window->wom._window = [[STNSWindow alloc]
                           initWithContentRect:NSMakeRect(window->_orignX,
                                                          window->_orignY,
                                                          window->_width,
                                                          window->_height)
                           styleMask:style
                           backing:NSBackingStoreBuffered
                           defer:NO];
    
    //Window Delegate
    STNSWindowDelegate* delegate = [[STNSWindowDelegate alloc] initWithSTWindow:window];
    [window->wom._window setDelegate:delegate];
    
    //Content View
    STContentView* cView = [[STContentView alloc] initWithSTWindow:window];
    
    //Window Attribute Set
    [window->wom._window setContentView:cView];
    [window->wom._window makeFirstResponder:cView];
    [window->wom._window setTitle:[NSString stringWithUTF8String:window->_title]];
    
    //Window config from WindowConfig
    [window->wom._window setRestorable:NO];
    [window->wom._window setAcceptsMouseMovedEvents:window->_windowConfig._acceptMouseMoveEvent];
    
    return true;
}

////////////////////////////////////////
//Function Of Window

int8_st NS_STDS Window::Create()
{
    if(!STApp)
        Application app;
    
    if(!CreateNativeWindow(this))
        return WINDOW_CREATE_FAIL;
    
    Focus();
    
    return SUCCESS;
}

void NS_STDS Window::Show()
{
    [wom._window orderFront:nil];
}

void NS_STDS Window::Focus()
{
    [NSApp activateIgnoringOtherApps:YES];
    
    [wom._window makeKeyAndOrderFront:nil];
}

void NS_STDS Window::Hiden()
{
    [wom._window orderOut:nil];
}

void NS_STDS Window::PollEvents()
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    for (;;)
    {
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                               inMode:NSDefaultRunLoopMode
                                              dequeue:YES];
        if (event == nil)
            break;
        
        [NSApp sendEvent:event];
    }
    [pool release];
}

