//
//  GCControllerButtonInput.h
//  GameController
//
//  Copyright (c) 2012 Apple Inc. All rights reserved.
//

#import <GameController/GameController.h>

GAMECONTROLLER_EXPORT
@interface GCControllerButtonInput : GCControllerElement

/**
 Set this block if you want to be notified when the value on this button changes.
 
 @param button the element that has been modified.
 @param value the value the button was set to at the time the valueChangedHandler fired.
 @param pressed the pressed state of the button at the time the valueChangedHandler fired.
 */
typedef void (^GCControllerButtonValueChangedHandler)(GCControllerButtonInput *button, float value, BOOL pressed);
@property (copy) GCControllerButtonValueChangedHandler valueChangedHandler;

/**
 Set this block if you want to be notified when only the pressed state on this button changes. This
 will get called less often than the valueChangedHandler with the additional feature of the pressed state
 being different to the last time it was called.
 
 @param button the element that has been modified.
 @param value the value the button was set to at the time the pressedChangedHandler fired.
 @param pressed the pressed state of the button at the time the pressedChangedHandler fired.
 */
@property (copy) GCControllerButtonValueChangedHandler pressedChangedHandler NS_AVAILABLE(10_10, 8_0);

/**
 A normalized value for the input. Between 0 and 1 for button inputs. Values are saturated and thus never exceed the range of [0, 1].
 */
@property (readonly) float value;

/**
 Buttons are mostly used in a digital sense, thus we have a recommended method for checking for pressed state instead of
 interpreting the value.
 
 As a general guideline a button is pressed if the value exceeds 25%. However there may be hysterisis applied
 to counter noisy input values, thus incidental values around the threshold value may not trigger a change
 in pressed state.
 */
@property (readonly, getter = isPressed) BOOL pressed;

@end
