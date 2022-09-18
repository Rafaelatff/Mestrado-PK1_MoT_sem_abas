# Mestrado-PK1_MoT_sem_abas
PK1_MoT_sem_abas code from Branquinho

# Hardwire provided by Branquinho

- Seeeduino v3.0 with Atmel mega328P
- Base Shield v2.1
- LM35 

# IDE config

**Arduino IDE 2.0.0**

Tools -> Board -> Arduino AVR Boards -> Arduino Pro or Pro Mini.

Use: Sketch uses 4268 bytes (13%) of program storage space. Maximum is 30720 bytes.
Global variables use 317 bytes (15%) of dynamic memory, leaving 1731 bytes for local variables. Maximum is 2048 bytes.



**Python 3.10.7**

To open the py files, I go -> Right click on the .py file -> Edit with IDLE -> Edit with IDLE 3.10 (64-bit)

To RUN the file, just go -> Run -> Run Module F5.

--after running the 1_Python_MoT_Requisição file, the output was: **ModuleNotFoundError: No module named 'serial'**.


Note1: During orientation, I saw that Branquinho was using Python 3.9.2.

Note2: Serial is not included with Python. It is a package that you'll need to install separately.



To create e virtual environment, open the CMG and:

python -m venv my-venv1 // creates a virtual environment with the name my-venv1

my-venv1\Scripts\Activate // to activate the virtual environment

pip install serial // to install the serial package into the virtual enviroment

pip list // to list packages installed into the virtual environment

![image](https://user-images.githubusercontent.com/58916022/190928519-afb5a2ff-6f4e-4992-b569-beaed277a8ca.png)

deactivate // to leave virtual environment

Or install the packages globaly.

pip install serial // to install serial package

![image](https://user-images.githubusercontent.com/58916022/190928823-fef71dde-df34-4a25-be30-9c259ea43510.png)

--after running the 1_Python_MoT_Requisição file again, the output was: **ModuleNotFoundError: No module named 'serial'**.




# Theorical Info

-Packages with 52 bytes.

-'Pacote de descida'(computer to arduino).

-'Pacote de subida'(arduino to computer).
