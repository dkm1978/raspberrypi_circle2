My custom platform for PlatformIO based on https://registry.platformio.org/platforms/platformio/windows_x86 <br>
I added "Resource Hacker" to the toolchain to allow changing the icon of the compiled program.<br>

Additionally the toolchain contains UPX : the Ultimate Packer for eXecutables - https://upx.github.io/<br>
Additional option in the platformio.ini configuration file:<br>

custom_upx_file = false ; true | false<br>

with this option the compiled program will be compressed using UPX.<br>

The examples directory contains the example program.<br>
To change the icon of the compiled program you need to add the dafault.ico file to the main project directory.
