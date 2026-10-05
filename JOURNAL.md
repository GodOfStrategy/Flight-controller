# 10/05/2026 - Working on Reviewer Feedback

_Time spent: 0.8166h_
As my reviewer said that, my pcb wasn't following PCB designing rules, so I completely redesigned my whole PCB, placing the SD card, USB-C close from the start itself, and placing components as close as possible, I came up with a much more compact, and better routed PCB. I also impedance matched my differential pairs.
This is how my PCB looks now:
<img width="806" height="702" alt="image" src="https://github.com/user-attachments/assets/adef2591-96c5-49de-986d-781e5ee215e1" />
Here is a 3D render:
<img width="745" height="692" alt="image" src="https://github.com/user-attachments/assets/05a5931c-fdb7-42f5-96c3-61b6c874e1e0" />
Here is the lapse link: https://lapse.hackclub.com/timelapse/E01Qz0_zPHlQ


# 5/21/2026 7 AM - PCB, VIAS, JLCPCB

_Time spent: 5.2h_

SO, I completed the PCB routing last time, and today I instaleld the jlc plugin for KiCAD to directly export production ready files. Selected components in JLCPCB (very hard to find what I actually needed specifically the values that I need for my caps and resistors). I fannly got a quote, but since I had used .4/.2mm via the cost was significantly, higher, so, I changed my PCB constraints to hole size -0.3 and diameter 06 to make sure that the DRC would not leave a single 0.4/0.2 mm via on the board. so, I had to redo all vias again, look for clearance issues, resolve over 150     DRC errors, and finally select all components again on JLCPCB and get a qoute. 

![image](https://stasis.hackclub-assets.com/images/1779349403458-8aad2x.png)


![image](https://stasis.hackclub-assets.com/images/1779349405512-c0as2n.png)

![Uploading image.png...](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)

![image](https://stasis.hackclub-assets.com/images/1779349403458-8aad2x.png)
![image](https://stasis.hackclub-assets.com/images/1779349405512-c0as2n.png)

# 5/20/2026 12 PM - PCB Finishing

_Time spent: 3.666666666666667h_

After discussing with @NotARoomba I figured out the Missing pins, they were supposed to be SCL and SDA. Thanks to @NotARoomba for fixing the guide, and guiding me! I also resolved the unconencted errors in the DRC, and sorted the clearance violations in the DRC
![image](https://stasis.hackclub-assets.com/images/1779281819681-j9pm3d.png)

Here is how my PCB looks:

![image](https://stasis.hackclub-assets.com/images/1779281833804-1si362.png)

![image](https://stasis.hackclub-assets.com/images/1779281819681-j9pm3d.png)
![image](https://stasis.hackclub-assets.com/images/1779281833804-1si362.png)

# 5/17/2026 7 AM - PCB Routing

_Time spent: 4.716666666666667h_

I then put together the groupd that i amde last time, and routed them accordingly. Also I noticed that, we have labeled pins like the BP_SCK,BP_SDI, but we never connected them to anything?! So I did the best thing, asked on slack!https://hackclub.slack.com/archives/C083S537USC/p1779000859915969
Here is y routing progress so far:

![image](https://stasis.hackclub-assets.com/images/1779003362045-jzcxez.png)

![image](https://stasis.hackclub-assets.com/images/1779003362045-jzcxez.png)

# 5/16/2026 6 AM - Grouping components for routing

_Time spent: 1.616666666666667h_

Grouped components together for routing later. I also changed the inductor footprints for L1,L2,L3 to 1210 metric since I need the magnetically shielded ones. I will be starting the pcb routing next time!
![image](https://stasis.hackclub-assets.com/images/1778914201699-erxr6c.png)

![image](https://stasis.hackclub-assets.com/images/1778914201699-erxr6c.png)

# 5/15/2026 4 PM - Footprints + a little detour on the impart GUI thing

_Time spent: 2.55h_

Since we're designing a flight controller, this has to be as small as possible, so I am going to be choosing the smallest footprints I can (while staying within good practices). The smaller the footprint, the more it can heat up and the less it can tolerate (for resistors and capacitors). A rule of thumb that I go by is any resistors under 80K I assign a 0201 footprint, over that and it's 0402. For capacitors, any bulk capacitors (capacitors that have high values like 4.7 µF or 10 µF) I usually assign 0402. Any bigger than 10 µF and I assign 0805, but it depends on the datasheet of the component. Under the application and implementation section there is usually a table that specifies which footprints/components to use.
I went ahead and assigned footprints 
![image](https://stasis.hackclub-assets.com/images/1778861635161-2ptu17.png)
Aha! not so easily though, first I didnt understand why, but th eimpart GUI thing disappeared from my PCB editor interface, and therefore I had to uninstall and reinstall it, and reconfigure it aswell.
After which I alloted the footprints again and then hit the update pcb from schemaitc button with satisfaction :) 

![image](https://stasis.hackclub-assets.com/images/1778861720890-2xgjdg.png)
I'll continue PCB routing next time.

![image](https://stasis.hackclub-assets.com/images/1778861635161-2ptu17.png)
![image](https://stasis.hackclub-assets.com/images/1778861720890-2xgjdg.png)

# 5/14/2026 5 PM - Completed schematis

_Time spent: 4.033333333333333h_

I faced issues with the initail easyeda2kicad library. The frist time I rant it it worked fine, but the next time, I imported some more components it didnt work out, the symbols were present in the files but KiCAD said the file was not readable. So, like a wise guy, I posted it on SLACK! 
![image](https://stasis.hackclub-assets.com/images/1778777917754-ossqzp.png)

Following the advice I installed, configured and used Steffen-W's program to import and finally use the symbols in my schematic. 
So here's my compelted schematic.

![image](https://stasis.hackclub-assets.com/images/1778777998443-tv6sri.png)
Next- Footprint assignment + starting PCB routing.

![image](https://stasis.hackclub-assets.com/images/1778777917754-ossqzp.png)
![image](https://stasis.hackclub-assets.com/images/1778777998443-tv6sri.png)

# 5/8/2026 7 AM - Scheamtics (contd.)

_Time spent: 3.25h_

Added further components, like the SD card reader, ICM,STM32. I also added new parts to the easyeda2kicad lib, which include the 2 cyrstals (25 MHz & 32.768 KHz). Aloing with buttons and the SD card shield.
![image](https://stasis.hackclub-assets.com/images/1778224240658-du2itz.png)
Then, I also downloaded the STM32MXCUBE to configure the pin outs. Here are my pin-outs.
![image](https://stasis.hackclub-assets.com/images/1778224242635-9vqd85.png)

![image](https://stasis.hackclub-assets.com/images/1778224240658-du2itz.png)
![image](https://stasis.hackclub-assets.com/images/1778224242635-9vqd85.png)

# 4/29/2026 4 PM - Schematics and importing symbols,footprints

_Time spent: 4.5h_

I want to make a flight controller following @NotARoomba's guide (https://blueprint.hackclub.com/starter-projects/flightcontroller) , with the following parts:
USB-C,
MicroSD,
TPS63070,
LMR51430,
BQ25883,
STM32F722RETx
ICM-45686,
BMP580
LED
I used this python script (from @NotARoomba) 
![image](https://stasis.hackclub-assets.com/images/1777480423797-2kb9q6.png)
[Disclaimer- This is a reference image from @NotARoomba I forgot to screenshot my output]

to import symbols, footprints, 3d models  with the part numbers using the LCSC website to source my parts.
After which I started drawing my schematics. I first drew it for the USB C receptacle 
![image](https://stasis.hackclub-assets.com/images/1777480970461-j1afzp.png)
Then the Battery charging IC (BQ25883RGER)
![image](https://stasis.hackclub-assets.com/images/1777480989620-0mpbsb.png)
Lots of resistors,caps labels took a lot of time.

![image](https://stasis.hackclub-assets.com/images/1777480423797-2kb9q6.png)
![image](https://stasis.hackclub-assets.com/images/1777480970461-j1afzp.png)
![image](https://stasis.hackclub-assets.com/images/1777480989620-0mpbsb.png)
