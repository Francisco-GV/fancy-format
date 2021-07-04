<h1 align="center"> ✨ fancy-format ✨ </h1>

Format your C++ console output using **ANSI escape codes**!

This library does not do anything really complex, it only serves as a "shortcut" for the ANSI escape codes (**specifically the Select Graphic Rendition (SGR)**) which are used with the ESC character and a specific code.

Each of the codes can be found as string constants within the namespace "FancyFormat" and the nested namespace "Color".
Not all codes were considered, as some are not widely supported.
The complete list of codes [can be found here](https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters).

## Screenshots using it
<p align="center">
  <img src="https://user-images.githubusercontent.com/54688495/124041754-1cd24f00-d9cd-11eb-8c5f-a5c346e0f7b0.png">
  <img src="https://user-images.githubusercontent.com/54688495/124044607-6756ca00-d9d3-11eb-9d0e-d7b8d99c9ae2.png">
</p>

_Note: The appearance may be different depending on the console, the font and different configurations, the screenshots were taken in [Windows Terminal](https://github.com/microsoft/terminal) and the **Cascadia Mono** font._

## Warning
Not all consoles support ANSI escape codes and this library does not provide any way to check if yours is compatible.

By the way, the only ones I have tested with are the following (not only C++):
### Supported:
- Windows Terminal ✔️
- IntelliJ IDEA ✔️
- VS 2019 Debug Console ❕ (_**partially**_)
- VS 2019/Code Terminal ❕ (_**partially**_)
- Netbeans Output ❕ (_**partially**_)
### Not supported:
- CMD ❌ (supported as a Windows Terminal profile)
- PowerShell ❌ (supported as a Windows Terminal profile)
- VS Code Output ❌

I repeat: it is in **my experience**, obviously there is more, if you have doubts with yours, try it!
