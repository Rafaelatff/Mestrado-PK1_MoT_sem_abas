# Mestrado-PK1_MoT_sem_abas
PK1_MoT_sem_abas code from Branquinho

# Hardwire provided by Branquinho

- PK1 v2
- Seeeduino v3.0 with Atmel mega328P
- Base Shield v2.1
- LM35 

# IDE config

**Arduino IDE 2.0.0**

- First, [download Arduino IDE](https://www.arduino.cc/en/software).
- Tools -> Board -> Arduino AVR Boards -> Arduino Pro or Pro Mini, or:

![image](https://user-images.githubusercontent.com/58916022/197593796-684a6179-8fcf-471d-bc77-a47984094802.png)

![image](https://user-images.githubusercontent.com/58916022/197593907-ab1f0394-18a3-4756-b290-e9ff4ec15b4f.png)
- Now, code is ready to be uploaded in the Atmel mega328P.

Use: Sketch uses 4268 bytes (13%) of program storage space. Maximum is 30720 bytes.
Global variables use 317 bytes (15%) of dynamic memory, leaving 1731 bytes for local variables. Maximum is 2048 bytes.

**Python 3.10.8**

- First, [download Python](https://www.python.org/downloads/).
- After the download is complete, run the executable file.
- Tick the 'Add python.exe to PATH' option.

![image](https://user-images.githubusercontent.com/58916022/197539837-e9d6f3f0-b8a6-429f-a70c-5bddd66df9bc.png)
- After the installation proccess is complete, open the Command Prompt and run a 'pip install serial'. The serial is used by '1_Python_MoT_Requisição.py'.

![image](https://user-images.githubusercontent.com/58916022/197544181-f09da409-831f-461a-aa24-f870c8800876.png)
- Do the same for 'pip install matplotlib', since it is used in '2_Python_D_G_MoT_Comandos.py'.
- Do the same for 'pip install schedule', since it is used in '3D_Python_MoT_Exibição_Lum.py'.
- Do the same for 'pip install pyserial', since it is used in '3D_Python_MoT_Exibição_Lum.py'.
- Do the same for 'pip install pandas', since it is used in '3D_Python_MoT_Exibição_Lum.py'.
- Now python files are ready to use. 

# Theorical Info

-Packages with 52 bytes.
-'Pacote de descida'(computer to arduino).
-'Pacote de subida'(arduino to computer).
