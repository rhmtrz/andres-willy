# Andres-willy

### Overview
Andres-willy is a project to control the Wild Willy 2 robot using a PS4 gamepad and M5Stack Atom. The robot's movements are controlled via the PS4 controller's joysticks and buttons, while the M5Stack Atom handles the hardware interface.

### Features
- Control motor speed and direction using PS4 joysticks.
- Adjust servo positions for precise movements.
- Visual feedback using M5Stack Atom's LED display.

### Requirements
- M5Stack Atom
- PS4 Controller
- PlatformIO IDE

### How to Build and Run
1. **Install PlatformIO IDE**:
   - Download and install [PlatformIO IDE](https://platformio.org/install).

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/rhmtrz/andres-willy.git
   cd andres-willy
   ```

3. **Open the Project**:
   - Open the `andres-willy` folder in PlatformIO IDE.

4. **Connect the M5Stack Atom**:
   - Connect your M5Stack Atom to your computer via USB.

5. **Build and Upload**:
   - In PlatformIO IDE, click on the "Build" button to compile the code.
   - Click on the "Upload" button to flash the firmware to the M5Stack Atom.

6. **Run the Application**:
   - Power on the M5Stack Atom and connect the PS4 controller.
   - Control the robot using the PS4 gamepad.

### How to Use PlatformIO in VS Code

1. **Install PlatformIO Extension**:
   - Open Visual Studio Code.
   - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window.
   - Search for "PlatformIO IDE" and click "Install".

2. **Open the Project**:
   - Open the `andres-willy` folder in VS Code.
   - PlatformIO will automatically detect the `platformio.ini` file and configure the environment.

3. **Build the Project**:
   - In the PlatformIO toolbar (usually at the bottom of the VS Code window), click on the "Build" button to compile the code.
   - Alternatively, you can use the Command Palette (Ctrl+Shift+P or Cmd+Shift+P on macOS) and search for "PlatformIO: Build".

4. **Upload the Firmware**:
   - Connect your M5Stack Atom to your computer via USB.
   - Click on the "Upload" button in the PlatformIO toolbar to flash the firmware to the device.
   - You can also use the Command Palette and search for "PlatformIO: Upload".

5. **Monitor Serial Output**:
   - To view the serial output from the M5Stack Atom, click on the "Monitor" button in the PlatformIO toolbar.
   - Alternatively, use the Command Palette and search for "PlatformIO: Monitor".

6. **Run the Application**:
   - Once the firmware is uploaded, power on the M5Stack Atom and connect the PS4 controller.
   - Use the PS4 gamepad to control the robot.

### License
This project is licensed under the MIT License.

