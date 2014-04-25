MacSleepIndicator
==========================

Sketch for Digispark(Tiny Core) to make it Sleep Indicator Light for Macs.

see video on YouTube :

       http://youtu.be/iPPq3i3_Bag

The [Digispark](http://digistump.com/category/1) with this sketch receives commands via USB.

'0' : LED OFF

'1' : LED ON

'2' : BLINK ( PowerBook Style )

'3' : BLINK ( MacBook Style )

Send command when your Mac sleeps/wakes with 'send' command comes with SDK.

I use [ControlPlane](http://www.controlplaneapp.com/) to execute command at these events.


---

Copyright 2014 Masatoshi "yoz" Yoshizawa ( @yozjp )

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

---

This code was written in thank for codes below:

* Echo.ino by unknown in DigiUSB sample sketches
* TinySoftPwmDemo.ino by RC NAVY in DigisparkTinySoftPwm sample sketch
