Menu
====

should work with both I2C and 'normal' LCD's, currently for 2 row lcds (1602).

use #define I2C in the main program when using the I2C lcd.

The main goal of the library is to be able to pick a corner or center on top/bottom on the lcd, and place text.
Some functionalities such as conversions from date&time to strings, and methods to print the time on a corner straightaway are added.
It's possible to give the reference of a rtc object, so that the current time is printed, instead of having to give up a datestamp.

what's currently NOT working:
when using the I2C option: the object (for instance lcdMenu1) has to be created in the same function as where it is used. When defined outside of the function (such as the public variables) it just doesn't work. I'm still figuring out why it doesn't work.

what's currently working (as far as i'm concerned):
every method (public & private) using the 'normal' liquidcrystal settings, giving D0-D4.
