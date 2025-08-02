# Fingerprint Based Exam Hall Authentication System  

## 📌 Project Overview  
This project implements a **biometric authentication system** for exam halls using **fingerprint recognition**.  
The goal is to ensure that only authorized students can access the examination hall, thereby preventing impersonation and maintaining examination integrity.  

The system uses:  
- **Fingerprint sensor module** for biometric scanning  
- **Arduino microcontroller** to process authentication  
- **LCD display** to show status messages (Access Granted / Access Denied)  

---

## 🛠️ Technologies & Components  
- **Arduino UNO**  
- **Adafruit Fingerprint Sensor Module**  
- **16x2 LCD Display**  
- **Breadboard & Jumper Wires**  
- **SoftwareSerial Library**  
- **Adafruit Fingerprint Library**  

---

## ⚙️ Features  
- Enroll and store fingerprints in the sensor’s database  
- Authenticate students by scanning their fingerprint  
- Show real-time messages on LCD (e.g., *Place Finger*, *Access Granted*, *Access Denied*)  
- Simple, cost-effective, and secure exam hall entry system  

---

## 🔧 Circuit Connections  
- **Fingerprint Sensor** connected via `TX/RX` pins (using SoftwareSerial)  
- **LCD Display** connected to Arduino digital pins  
- **Power Supply** via Arduino 5V  

<img width="940" height="538" alt="image" src="https://github.com/user-attachments/assets/2e04f21a-690c-4e7a-a8b5-d7ccd49bc458" />

---

## 🚀 How to Run the Project  
1. Connect the components as per the circuit diagram.  
2. Install the required Arduino libraries:  
   - `Adafruit Fingerprint`  
   - `LiquidCrystal`  
3. Upload the provided `.ino` file to Arduino.  
4. Enroll student fingerprints into the sensor.  
5. Scan fingerprints to authenticate access.  

---

## 📂 Repository Structure  
