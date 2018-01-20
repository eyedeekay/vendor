Getting Coreboot to work on the Alienware M11XR1
================================================

This guide is a WORK IN PROGESS. My SPI flasher will arrive in the mail
tomorrow. At best, it's an account of how I removed the lenovo/x200 specific
stuff from the lenovo/x200 config folder and replaced it with alienware/m11xr1
specific stuff.

First, I'd like to point one thing out:
---------------------------------------

I'm fairly certain there are like a gazillion laptops from the 2007-2010 period
which have just one or two little differences with laptops which can use
Coreboot or even Libreboot in lieu of a fully proprietary vendor firmware. Some
of these [are so close to a supported device](https://www.coreboot.org/Developer_Manual#How_to_support_a_new_board)
that it seems a shame not to attempt to port them myself. I mean, I've kind of
always wanted to.

So in this case, the M11XR1 is pretty much a simplified X200
------------------------------------------------------------

As I explained before, I decided to do this becaue my laptops components are all
supported by Coreboot, there's just no board configuration for it. The laptop
that is closest to mine is the X200(But it's also very similar to the Roda RK9)
and so I started by copying src/mainboard/lenovo/x200 to
src/mainboard/alienware/m11xr1. Then I changed to the newly created directory
and replaced references to "Lenovo" with "Alienware" and references to "x200"
to references to "m11xr1" which, if you wanted to take a shortcut, you could do
like this:

        sed -i 's|lenovo|alienware|g' Kconfig*
        sed -i 's|Lenovo|Alienware|g' Kconfig*
        sed -i 's|LENOVO|ALIENWARE|g' Kconfig*
        sed -i 's|thinkpad|alienware|g' Kconfig*
        sed -i 's|ThinkPad|Alienware|g' Kconfig*
        sed -i 's|THINKPAD|ALIENWARE|g' Kconfig*
        sed -i 's|x200|m11xr1|g' Kconfig*
        sed -i 's|X200|M11XR1|g' Kconfig*
        sed -i 's|lenovo|alienware|g' */Kconfig*
        sed -i 's|Lenovo|Alienware|g' */Kconfig*
        sed -i 's|LENOVO|ALIENWARE|g' */Kconfig*
        sed -i 's|thinkpad|alienware|g' */Kconfig*
        sed -i 's|ThinkPad|Alienware|g' */Kconfig*
        sed -i 's|THINKPAD|ALIENWARE|g' */Kconfig*
        sed -i 's|x200|m11xr1|g' */Kconfig*
        sed -i 's|X200|M11XR1|g' */Kconfig*

But then you'd find in the Kconfig file that you had accidentally changed the
CBFS_SIZE default from 0x200000 to 0m11xr1000. Simply change it back. What you
have at this point is a version of the x200 configuration which can be built
by selecting Alienware-related options instead of Lenovo ones.

Edit the Kconfig to remove the X200 specific components
-------------------------------------------------------

I forget exactly how I did it, but I figured out that the M11X used an ENE based
Embedded Controller. This is pretty cool because it's already available in
Coreboot and we just have to add it to the M11XR1 tree. But first we need to
remove the Lenovo SuperIO and EC from the existing Kconfig. They are pretty
much self-evident:

        select EC_LENOVO_PMH7
        select EC_LENOVO_H8
        select SUPERIO_NSC_PC87382
        select DRIVERS_LENOVO_WACOM

Simply commenting out or deleting them will remove them from the system
configuration. Building the firmware will probably be unsuccessful at this
point.

Removing the files related to the X200 specific peripherals
-----------------------------------------------------------

The next pretty easy bit is to remove the code which deals with components
specific to the x200, like the dock and the superIO. These files are clearly
named, simply remove dock.c and dock.h. Also make sure that acpi/superio.asl is
empty, but do not delete it.

New, remove references to these from Makefile.inc and from any #include
statements where they appear. You can find the include statements in files by
doing

        grep -h 'dock.h' * */*

or similar.

Also you'll need to remove the code for the X200 Embedded Controllers. This is
pretty much all in the files ec.h and ec.c. Simply delete them, and set then
remove the include statement from mainboard.c and any other files where it is
included.

Note that *at this point it is likely that your code will once again build.*
*However, it will pretty much definitely not represent something which will*
*work*. It will have no code to talk to the embedded controller or anything.

Adding the new Embedded Controller to the Kconfig
-------------------------------------------------

The Alienware M11XR1 uses an ENE932 based Embedded Controller. Enabling it in
the new Kconfig is simply a matter of adding that configuration line to the
Kconfig. The option in question is **select EC_COMPAL_ENE932**.

Adding the source code for the Embedded Controller
--------------------------------------------------

Examine the most similar board that uses the ENEKB932, the S230U. Adapt it's
EC configuration code.

Initializing the Embedded Controller in mainboard.c
---------------------------------------------------

Configure the new EC code to work with the existing mainboard.c code.

Editing the Device Tree
-----------------------

Now that I've got a version of the X200 tree configured to build with Alienware
related identifiers instead, the next step is to de-configure the components
that are present on the X200 that are not present on thhe M11X. Have a look at
the diff I created [here](https://github.com/eyedeekay/vendor/blob/master/docs/board-differences-overview.diff)
to get an idea of how to determine that, that diff was generated by doing

        my_device="m11xr1"
        sudo lspci -nnvvv | tee "$my_device.lspci.log"
        grep -A 1 "[0-9][0-9]:[0-9][0-9]" "$my_device.lspci.log" > "$my_device.lspci.log.trim"
        curl -s https://libreboot.org/docs/hardware/hwdumps/x200/lspci.log | grep -A 1 "[0-9][0-9]:[0-9][0-9]" > x200.lspci.log.trim
        diff -y $(find . -name *.lspci.log.trim)

So as we can see, the devices we need to remove from the Kconfig are the Intel
networking controller and the first two USB controllers.

Correct the addresses and subsystem ID's of the PCI devices. Remove PCI devices
that aren't present.

And back to my original point
-----------------------------
