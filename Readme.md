Instruction for adding graphics file 
***************************************************************************************************

1) Copy "graphics.h" and "winbgim.h" files to "include" folder your compiler directory.

2) Copy "libbgi.a" to  "lib" folder of your compiler directory.


5) Add the following linker flags
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32


Done...

NOTE:
1) The graphics.h will work only in the program saved in ".cpp" format.

To check the graphics.h is working or not
*****************************************************************************************************
Create a new consol application in ".cpp" format and copy the codes given below, paste it in the
file you created and click "Build and Run" button or click "F9" key from your keyboard..