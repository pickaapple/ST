//
//  STdsKeyboard.hpp
//  STDeskSwitch
//
//  Created by yhys on 2017/8/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#ifndef STKeyboard_hpp
#define STKeyboard_hpp

#include "STccMacro.hpp"
#include "STdsMacro.hpp"

#define ST_KEY_UNKNOW            0
#define ST_KEY_SPACE             32      /*   */
#define ST_KEY_EXCLAMATION_MARK  33      /* ! */
#define ST_KEY_QUOTATION_MARK    34      /* " */
#define ST_KEY_NUMBER_SIGN       35      /* # */
#define ST_KEY_DOLLAR_SIGN       36      /* $ */
#define ST_KEY_PERCENT_SIGN      37      /* % */
#define ST_KEY_AMPERSAND         38      /* & */
#define ST_KEY_APOSTROPHE        39      /* ' */
#define ST_KEY_LEFT_PARENTHESIS  40      /* ( */
#define ST_KEY_RIGHT_PARENTHESIS 41      /* ) */
#define ST_KEY_ASTERISK          42      /* * */
#define ST_KEY_PLUSSIGN          43      /* + */
#define ST_KEY_COMMA             44      /* , */
#define ST_KEY_HYPHEN            45      /* - */
#define ST_KEY_PERIOD            46      /* . */
#define ST_KEY_SLASH             47      /* / */
//Number
#define ST_KEY_0    48
#define ST_KEY_1    49
#define ST_KEY_2    50
#define ST_KEY_3    51
#define ST_KEY_4    52
#define ST_KEY_5    53
#define ST_KEY_6    54
#define ST_KEY_7    55
#define ST_KEY_8    56
#define ST_KEY_9    57
//
#define ST_KEY_COLON        58    /* : */
#define ST_KEY_SEMICOLON    59    /* ; */
#define ST_KEY_LESSTHAN     60    /* < */
#define ST_KEY_EQUAL        61    /* = */
#define ST_KEY_GREATERTHAN  62    /* > */
#define ST_KEY_QUESTIONMARK 63    /* ? */
#define ST_KEY_ATSIGN       64    /* @ */
//character
#define ST_KEY_A    65
#define ST_KEY_B    66
#define ST_KEY_C    67
#define ST_KEY_D    68
#define ST_KEY_E    69
#define ST_KEY_F    70
#define ST_KEY_G    71
#define ST_KEY_H    72
#define ST_KEY_I    73
#define ST_KEY_J    74
#define ST_KEY_K    75
#define ST_KEY_L    76
#define ST_KEY_M    77
#define ST_KEY_N    78
#define ST_KEY_O    79
#define ST_KEY_P    80
#define ST_KEY_Q    81
#define ST_KEY_R    82
#define ST_KEY_S    83
#define ST_KEY_T    84
#define ST_KEY_U    85
#define ST_KEY_V    86
#define ST_KEY_W    87
#define ST_KEY_X    88
#define ST_KEY_Y    89
#define ST_KEY_Z    90
//
#define ST_KEY_LEFT_SQUARE_BRACKET   91  /* [ */
#define ST_KEY_BACKSLASH             92  /* \ */
#define ST_KEY_RIGHT_SQUARE_BRACKET  93  /* ] */
#define ST_KEY_CARET                 94  /* ^ */
#define ST_KEY_UNDERSCORE            95  /* _ */
#define ST_KEY_GRAVE_ACCENT          96  /* ` */

#define ST_KEY_LEFT_CURLY_BRACE      123  /* { */
#define ST_KEY_VERTICALBAR           124  /* | */
#define ST_KEY_RIGHT_CURLY_BRACE     125  /* } */
#define ST_KEY_TILDE                 126  /* ~ */
//function keys
#define ST_KEY_F1   256 //0x100
#define ST_KEY_F2   257
#define ST_KEY_F3   258
#define ST_KEY_F4   259
#define ST_KEY_F5   260
#define ST_KEY_F6   261
#define ST_KEY_F7   262
#define ST_KEY_F8   263
#define ST_KEY_F9   264
#define ST_KEY_F10  265
#define ST_KEY_F11  266
#define ST_KEY_F12  267
#define ST_KEY_F13  267
#define ST_KEY_F14  267
#define ST_KEY_F15  267
#define ST_KEY_F16  267
#define ST_KEY_F17  267
#define ST_KEY_F18  267
#define ST_KEY_F19  267
#define ST_KEY_F20  267
//control keys
#define ST_KEY_BACKSPACE    512 //0x200
#define ST_KEY_TAB          513
#define ST_KEY_CLEAR        514
#define ST_KEY_ENTER        515
#define ST_KEY_ESCAPE       516
#define ST_KEY_PAGE_UP      517
#define ST_KEY_PAGE_DOWN    518
#define ST_KEY_HOME         519
#define ST_KEY_END          520
#define ST_KEY_LEFT_ARROW   521
#define ST_KEY_UP_ARROW     522
#define ST_KEY_RIGHT_ARROW  523
#define ST_KEY_DOWN_ARROW   524
#define ST_KEY_INSERT       525
#define ST_KEY_DELETE       526

//modifier keys
#define ST_KEY_LEFT_SPECIAL     768 //0x300
#define ST_KEY_RIGHT_SPECIAL    769 
#define ST_KEY_LEFT_SHIFT       770 
#define ST_KEY_RIGHT_SHIFT      771 
#define ST_KEY_LEFT_CTRL        772 
#define ST_KEY_RIGHT_CTRL       773 
#define ST_KEY_LEFT_ALT         774 
#define ST_KEY_RIGHT_ALT        775

//Flag changeable
#define ST_KEY_CAPS_LOCK     1024   //0x400
#define ST_KEY_NUM_LOCK      1025

//Media keys
#define ST_KEY_VOICEUP      1280    //0x500
#define ST_KEY_VOICEDOWN    1281
#define ST_KEY_SILENCE      1282
#define ST_KEY_PREVIOUS     1283
#define ST_KEY_STARTORSTOP  1284
#define ST_KEY_NEXT         1285

//Key pad
#define ST_KEY_KP_0         1536    //0x600
#define ST_KEY_KP_1         1537
#define ST_KEY_KP_2         1538
#define ST_KEY_KP_3         1539
#define ST_KEY_KP_4         1540
#define ST_KEY_KP_5         1541
#define ST_KEY_KP_6         1542
#define ST_KEY_KP_7         1543
#define ST_KEY_KP_8         1544
#define ST_KEY_KP_9         1545
#define ST_KEY_KP_ADD       1546
#define ST_KEY_KP_DECIMAL   1547
#define ST_KEY_KP_DIVIDE    1548
#define ST_KEY_KP_ENTER     1549
#define ST_KEY_KP_EQUAL     1550
#define ST_KEY_KP_MULTIPLY  1551
#define ST_KEY_KP_SUBTRACT  1552

//Modifier flag
#define ST_FLAG_MODIFIER_UNKNOW     0x00
#define ST_FLAG_MODIFIER_SPECIAL    0x01
#define ST_FLAG_MODIFIER_SHIFT      0x02
#define ST_FLAG_MODIFIER_CTRL       0x04
#define ST_FLAG_MODIFIER_ALT        0x08

#pragma GCC visibility push(default)

NS_STDS_BEGIN


////////////////////////////////////////

enum STKeyPressState
{
    STKeyPressStateDown,
    STKeyPressStateUp
};

typedef void (*OnKeyboardEvent)(uint16_st key, uint16_st modifierFlag, int8_st state);

////////////////////////////////////////

class Keyboard
{
public:
    void      SetPlatformKey(uint16_st uIndex,uint16_st platformKey);
    
    uint16_st GetPlatformKey(uint16_st uIndex);
    
    Keyboard();
    
    virtual ~Keyboard();
    
protected:
    uint16_st _platformKeys[256];
};

NS_STDS_END

#pragma GCC visibility pop

#endif /* STKeyboard_hpp */
