//
//  STdsApplicationOfMac.mm
//  STDeskSwitch
//
//  Created by yhys on 2017/8/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#import <AppKit/AppKit.h>

#import "STdsWindow.hpp"

#import "STdsApplication.hpp"

////////////////////////////////////////////

@interface STApplicationDelete : NSObject <NSApplicationDelegate>
{
    NS_STDS ApplicationDelegate* _applicationDelegate;
}
@end

@implementation STApplicationDelete

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
    [NSApp stop:nil];
    
    NSEvent* event = [NSEvent otherEventWithType:NSEventTypeApplicationDefined
                                        location:NSMakePoint(0, 0)
                                   modifierFlags:0
                                       timestamp:0
                                    windowNumber:0
                                         context:nil
                                         subtype:0
                                           data1:0
                                           data2:0];
    [NSApp postEvent:event atStart:YES];
    if(_applicationDelegate)
        _applicationDelegate->ApplicationDidFinishLaunching();
}

- (void)applicationDidHide:(NSNotification *)notification
{
    if(_applicationDelegate)
        _applicationDelegate->ApplicationDidEnterForeground();
}

- (void)applicationDidUnhide:(NSNotification *)notification
{
    if(_applicationDelegate)
        _applicationDelegate->ApplicationDidEnterBackground();
}

- (void)applicationWillTerminate:(NSNotification *)notification
{
    if(_applicationDelegate)
        _applicationDelegate->ApplicationWillFinish();
}

@end

////////////////////////////////////////////

@interface STApplication : NSApplication

@end

@implementation STApplication

@end

////////////////////////////////////////////

static bool InitAppKit(NS_STDS Application* stApp)
{
    if(NSApp)
        return true;
    stApp->aom._application = [STApplication sharedApplication];
    
    //set menu
    NSMenu* bar = [[NSMenu alloc] init];
    [stApp->aom._application setMainMenu:bar];
    
    //set policies
    [stApp->aom._application setActivationPolicy:NSApplicationActivationPolicyRegular];
    
    id delegate = [[STApplicationDelete alloc] init];
    if(delegate == nil)
        return false;
    [stApp->aom._application setDelegate:delegate];
    [stApp->aom._application run];
    return true;
}


////////////////////////////////////////
//STApplication

bool NS_STDS Application::Init()
{
    if(STApp)
        return true;
    InitMouseCode();
    InitKeyCode();
    InitAppKit(this);
    STApp = this;
    
    return true;
}

void NS_STDS Application::InitMouseCode()
{
}

void NS_STDS Application::InitKeyCode()
{
    _keyboard.SetPlatformKey(0x31,  ST_KEY_SPACE);
    _keyboard.SetPlatformKey(0x32,  ST_KEY_GRAVE_ACCENT);
    
    _keyboard.SetPlatformKey(0x2A,  ST_KEY_BACKSLASH);
    _keyboard.SetPlatformKey(0x2F,  ST_KEY_PERIOD);
    _keyboard.SetPlatformKey(0x2B,  ST_KEY_COMMA);
    
    _keyboard.SetPlatformKey(0x27,  ST_KEY_APOSTROPHE);
    _keyboard.SetPlatformKey(0x29,  ST_KEY_SEMICOLON);
    
    _keyboard.SetPlatformKey(0x2C,  ST_KEY_SLASH);
    _keyboard.SetPlatformKey(0x1E,  ST_KEY_RIGHT_SQUARE_BRACKET);
    _keyboard.SetPlatformKey(0x21,  ST_KEY_LEFT_SQUARE_BRACKET);
    
    _keyboard.SetPlatformKey(0x33,  ST_KEY_BACKSPACE);
    _keyboard.SetPlatformKey(0x18,  ST_KEY_EQUAL);
    _keyboard.SetPlatformKey(0x1B,  ST_KEY_HYPHEN);
    
    _keyboard.SetPlatformKey(0x1D,  ST_KEY_0);
    _keyboard.SetPlatformKey(0x12,  ST_KEY_1);
    _keyboard.SetPlatformKey(0x13,  ST_KEY_2);
    _keyboard.SetPlatformKey(0x14,  ST_KEY_3);
    _keyboard.SetPlatformKey(0x15,  ST_KEY_4);
    _keyboard.SetPlatformKey(0x17,  ST_KEY_5);
    _keyboard.SetPlatformKey(0x16,  ST_KEY_6);
    _keyboard.SetPlatformKey(0x1A,  ST_KEY_7);
    _keyboard.SetPlatformKey(0x1C,  ST_KEY_8);
    _keyboard.SetPlatformKey(0x19,  ST_KEY_9);
    
    _keyboard.SetPlatformKey(0x00,  ST_KEY_A);
    _keyboard.SetPlatformKey(0x0B,  ST_KEY_B);
    _keyboard.SetPlatformKey(0x08,  ST_KEY_C);
    _keyboard.SetPlatformKey(0x02,  ST_KEY_D);
    _keyboard.SetPlatformKey(0x0E,  ST_KEY_E);
    _keyboard.SetPlatformKey(0x03,  ST_KEY_F);
    _keyboard.SetPlatformKey(0x05,  ST_KEY_G);
    _keyboard.SetPlatformKey(0x04,  ST_KEY_H);
    _keyboard.SetPlatformKey(0x22,  ST_KEY_I);
    _keyboard.SetPlatformKey(0x26,  ST_KEY_J);
    _keyboard.SetPlatformKey(0x28,  ST_KEY_K);
    _keyboard.SetPlatformKey(0x25,  ST_KEY_L);
    _keyboard.SetPlatformKey(0x2E,  ST_KEY_M);
    _keyboard.SetPlatformKey(0x2D,  ST_KEY_N);
    _keyboard.SetPlatformKey(0x1F,  ST_KEY_O);
    _keyboard.SetPlatformKey(0x23,  ST_KEY_P);
    _keyboard.SetPlatformKey(0x0C,  ST_KEY_Q);
    _keyboard.SetPlatformKey(0x0F,  ST_KEY_R);
    _keyboard.SetPlatformKey(0x01,  ST_KEY_S);
    _keyboard.SetPlatformKey(0x11,  ST_KEY_T);
    _keyboard.SetPlatformKey(0x20,  ST_KEY_U);
    _keyboard.SetPlatformKey(0x09,  ST_KEY_V);
    _keyboard.SetPlatformKey(0x0D,  ST_KEY_W);
    _keyboard.SetPlatformKey(0x07,  ST_KEY_X);
    _keyboard.SetPlatformKey(0x10,  ST_KEY_Y);
    _keyboard.SetPlatformKey(0x06,  ST_KEY_Z);
    
    //Function keys
    _keyboard.SetPlatformKey(0x7A,  ST_KEY_F1);
    _keyboard.SetPlatformKey(0x78,  ST_KEY_F2);
    _keyboard.SetPlatformKey(0x63,  ST_KEY_F3);
    _keyboard.SetPlatformKey(0x76,  ST_KEY_F4);
    _keyboard.SetPlatformKey(0x60,  ST_KEY_F5);
    _keyboard.SetPlatformKey(0x61,  ST_KEY_F6);
    _keyboard.SetPlatformKey(0x62,  ST_KEY_F7);
    _keyboard.SetPlatformKey(0x64,  ST_KEY_F8);
    _keyboard.SetPlatformKey(0x65,  ST_KEY_F9);
    _keyboard.SetPlatformKey(0x6D,  ST_KEY_F10);
    _keyboard.SetPlatformKey(0x67,  ST_KEY_F11);
    _keyboard.SetPlatformKey(0x6F,  ST_KEY_F12);
    _keyboard.SetPlatformKey(0x69,  ST_KEY_F13);
    _keyboard.SetPlatformKey(0x6B,  ST_KEY_F14);
    _keyboard.SetPlatformKey(0x71,  ST_KEY_F15);
    _keyboard.SetPlatformKey(0x6A,  ST_KEY_F16);
    _keyboard.SetPlatformKey(0x40,  ST_KEY_F17);
    _keyboard.SetPlatformKey(0x4F,  ST_KEY_F18);
    _keyboard.SetPlatformKey(0x50,  ST_KEY_F19);
    _keyboard.SetPlatformKey(0x5A,  ST_KEY_F20);
    
    //Control keys
    _keyboard.SetPlatformKey(0x30,  ST_KEY_TAB);
    _keyboard.SetPlatformKey(0x24,  ST_KEY_ENTER);
    _keyboard.SetPlatformKey(0x35,  ST_KEY_ESCAPE);
    _keyboard.SetPlatformKey(0x74,  ST_KEY_PAGE_UP);
    _keyboard.SetPlatformKey(0x79,  ST_KEY_PAGE_DOWN);
    _keyboard.SetPlatformKey(0x73,  ST_KEY_HOME);
    _keyboard.SetPlatformKey(0x77,  ST_KEY_END);
    _keyboard.SetPlatformKey(0x7B,  ST_KEY_LEFT_ARROW);
    _keyboard.SetPlatformKey(0x7E,  ST_KEY_UP_ARROW);
    _keyboard.SetPlatformKey(0x7C,  ST_KEY_RIGHT_ARROW);
    _keyboard.SetPlatformKey(0x7D,  ST_KEY_DOWN_ARROW);
    _keyboard.SetPlatformKey(0x72,  ST_KEY_INSERT);
    _keyboard.SetPlatformKey(0x75,  ST_KEY_DELETE);
    
    //Modifier keys
    _keyboard.SetPlatformKey(0x37,  ST_KEY_LEFT_SPECIAL);
    _keyboard.SetPlatformKey(0x36,  ST_KEY_RIGHT_SPECIAL);
    _keyboard.SetPlatformKey(0x38,  ST_KEY_LEFT_SHIFT);
    _keyboard.SetPlatformKey(0x3C,  ST_KEY_RIGHT_SHIFT);
    _keyboard.SetPlatformKey(0x3B,  ST_KEY_LEFT_CTRL);
    _keyboard.SetPlatformKey(0x3E,  ST_KEY_RIGHT_CTRL);
    _keyboard.SetPlatformKey(0x3A,  ST_KEY_LEFT_ALT);
    _keyboard.SetPlatformKey(0x3D,  ST_KEY_RIGHT_ALT);
    
    //Flag changeable
    _keyboard.SetPlatformKey(0x47,  ST_KEY_NUM_LOCK);
    _keyboard.SetPlatformKey(0x39,  ST_KEY_CAPS_LOCK);
    
    //Media keys
    
    //Key pad
    _keyboard.SetPlatformKey(0x52,  ST_KEY_KP_0);
    _keyboard.SetPlatformKey(0x53,  ST_KEY_KP_1);
    _keyboard.SetPlatformKey(0x54,  ST_KEY_KP_2);
    _keyboard.SetPlatformKey(0x55,  ST_KEY_KP_3);
    _keyboard.SetPlatformKey(0x56,  ST_KEY_KP_4);
    _keyboard.SetPlatformKey(0x57,  ST_KEY_KP_5);
    _keyboard.SetPlatformKey(0x58,  ST_KEY_KP_6);
    _keyboard.SetPlatformKey(0x59,  ST_KEY_KP_7);
    _keyboard.SetPlatformKey(0x5B,  ST_KEY_KP_8);
    _keyboard.SetPlatformKey(0x5C,  ST_KEY_KP_9);
    _keyboard.SetPlatformKey(0x45,  ST_KEY_KP_ADD);
    _keyboard.SetPlatformKey(0x41,  ST_KEY_KP_DECIMAL);
    _keyboard.SetPlatformKey(0x4B,  ST_KEY_KP_DIVIDE);
    _keyboard.SetPlatformKey(0x4C,  ST_KEY_KP_ENTER);
    _keyboard.SetPlatformKey(0x51,  ST_KEY_KP_EQUAL);
    _keyboard.SetPlatformKey(0x43,  ST_KEY_KP_MULTIPLY);
    _keyboard.SetPlatformKey(0x4E,  ST_KEY_KP_SUBTRACT);
}
