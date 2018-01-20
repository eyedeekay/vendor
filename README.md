# vendor
Vendor configuration files

This repository is for my experiments with getting coreboot to run on my ancient
laptop(GM45) and learning about how coreboot works on slightly newer hardware
(Baytrail mostly).

The reason I'm doing this is because my netbook is basically a simplified
version of the Lenovo X200, which is already Librebooted so "How hard could it
be?" I guess that might make me a reckless amateur, but I've got an external
flasher and my other laptop now so we're about to find out. I know it won't work
right away, but I'm like 60% sure what I've got here won't result in a brick,
and adding a little Freedom to the world, even if it's ten-years-out-of-date
Freedom with a short manufacturing run, seems to me to be worthwhile. Also, it's
a chance to learn about Coreboot, which brings me to my other folders. First,
the other Alienware folders. I looked into the other releases of the Alienware
M11X line and realized something else interesting: They're all pretty similar
to the Lenovo and Roda laptops that are already in Coreboot, they just usually
don't have docks or fingerprint scanners and stuff, which makes a big part of
porting these motherboards a subtractive process! In the beginning, at least,
it seems it's largely a matter of "Find device that isn't present. Remove device
from build. Remove files that configure the device to build. Remove source code
for device. Remove code that initializes the device." So if I can do it for the
M11XR1, then I can probably do it for the M11XR2 and M11Xr3, and probably also
the contemporary M15XR1 and M15Xr2 too. These laptops will likely require more
firmware than the M11XR1, which may be possible to liberate at the lowest level,
but it still seems like a worthwhile endeavor which may enhance these enthusiast
laptops. Which then brings me to acer/zhk. If my premise with the M11XR1 is that
it's really close to an X200, and that the M11X and M15X series in general are
very similar to laptops already supported in Coreboot, then it may be that there
are more recent laptops that might be similarly ready to port, because they in
turn are very similar to Chromebooks of the same era. Unlike Chromebooks,
they'll obviously require external flashing and these laptops will likely never
be fully freed from proprietary firmware, but there are kind of a shitload of
cheap Acer/Baytrail Win10 netbooks bought by college students that just kind
of... sit there. Doing nothing. Because they barely function anymore, thanks
Windows 10. My point is that *maybe*, with older hardware where much of the work
has already been done, it's not that unapproachable to start hacking the boot
firmware of your own laptop as an amateur.


## Information Resources:

  * [Obviously, the Coreboot web site:](https://coreboot.org)
    * [Web mirror of Git documentation:](https://coreboot.org/git-docs/)
    * [Specifically, this project targets "Supporting a new board with the same cpu family, chipset, but different SuperIO":](https://www.coreboot.org/Developer_Manual#How_to_support_a_new_board)
  * [Chromium 2014 Firmware Summit](http://www.chromium.org/chromium-os/2014-firmware-summit)
  * [Flashrom web site:](https://flashrom.org)
    * [I'm using a ch341 based USB flasher:](https://www.flashrom.org/Supported_hardware#USB_Devices)
    * [In-System Programming](https://flashrom.org/ISP)
  * [German tutorial which uses a ch341a to set the HAP bit on a Thinkpad. Pretty good pics of the ch341a in action.](https://github.com/patbec/ThinkPad-T560-HAP-Bit)
  * [Libreboot web site:](https://libreboot.org/)
    * [Libreboot's X200 hardware dumps:](https://libreboot.org/docs/hardware/hwdumps)
  * [me_cleaner, for disabling and shrinking the Managment Engine:](https://github.com/corna/me_cleaner/)
    * [Especially this flashing guide, with it's cautious backup steps:](https://github.com/corna/me_cleaner/wiki/External-flashing)
  * [Embedded Firmware Solutions on Springerlink has some good walkthroughs especially for the FSP](https://link.springer.com/book/10.1007/978-1-4842-0070-4)
  * [This Notebookreview thread has some useful information](http://forum.notebookreview.com/threads/how-to-recover-the-m11x-from-a-bad-bios-flash.529859/)
  * [This is a pretty nice intro to the ch341a flasher](https://onetransistor.blogspot.com/2017/08/ch341a-mini-programmer-schematic.html)
  * [An ME_Cleaner centric flashing procedure.](https://hardenedlinux.github.io/firmware/2016/11/17/neutralize_ME_firmware_on_sandybridge_and_ivybridge.html)


## Custom Resources: These came from me, use at your own risk, I am a reckless amateur

  * [My copy of the coreboot toolchain, available on Docker Hub:](https://github.com/eyedeekay/coreboot-dockerfile)

