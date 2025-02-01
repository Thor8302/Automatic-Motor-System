# Automatic Motor System  

This **Automatic Motor System** is designed to streamline water tank management by providing **real-time water level monitoring** and **remote motor control**. It leverages the **NodeMCU** microcontroller and integrates with the **Arduino IoT Remote App** to offer a seamless user experience for home and small-scale industrial applications.

---

## Images  
![IMG-20240304-WA0006 (1)](https://github.com/user-attachments/assets/1a605d7f-1c89-4588-9ed2-ca976a729ed0)
![IMG20240107225108 (1)](https://github.com/user-attachments/assets/9a9ed092-c6f2-4d6e-9a11-3628b0babd3e)

---

## **Working Video** 
https://github.com/user-attachments/assets/130de713-e57e-4ebb-9066-5ad84c2542c7

---




## **Features**  
- **Real-Time Water Level Monitoring:** Displays the current water levels for easy tracking.  
- **Remote Motor Control:** Operate the motor from anywhere using the **Arduino IoT platform** and mobile app.  
- **Energy Efficient:** Ensures the motor runs only when needed, preventing overuse and reducing energy consumption.  
- **Compact and Standalone:** Built entirely with NodeMCU, eliminating the need for additional controllers.  
- **User-Friendly Interface:** Control and monitor the system via the **Arduino IoT Remote App**.  

---

## **Hardware Used**  
1. **NodeMCU:** Acts as the primary controller for data processing and Wi-Fi connectivity.  
2. **Ultrasonic Sensors:** Measure water levels in real-time.  
3. **DOL Starter:** Enables reliable motor operation.  
4. **Contactor:** Switches the motor on/off safely.  

---

## **How It Works**  
1. **Real-Time Monitoring:**  
   - Ultrasonic sensors measure the water level in the tank and send data to the NodeMCU.  
   - This data is displayed on the **Arduino IoT Remote App** in real time.  

2. **Remote Motor Operation:**  
   - Users can start or stop the motor via the **Arduino IoT platform**, ensuring control from any location with internet access.  
   - The system automatically manages motor operation based on predefined water level thresholds, even without user intervention.  

3. **Mobile App Integration:**  
   - The **Arduino IoT Remote App** provides a clean and intuitive interface for monitoring water levels and controlling the motor.  

---

## **Installation Instructions**  
1. Assemble the components following a suitable setup for your use case.  
2. Upload the provided code to the NodeMCU using the Arduino IDE.  
3. Configure your Wi-Fi credentials and link the system to the **Arduino IoT Cloud**.  
4. Add the system to the **Arduino IoT Remote App** for seamless control and monitoring.  
5. Power up the system and test its functionality.  

---

## **Applications**  
- Home water tank automation.  
- Small-scale irrigation systems.  
- Any scenario requiring automated motor control and real-time water level data.  

---

## **Future Improvements**  
- Integration with additional IoT platforms like Blynk or Adafruit IO for expanded functionality.  
- Enhanced analytics for water usage trends and predictions.  

---

Feel free to use, modify, or improve this project as needed. If you have any questions or feedback, don’t hesitate to reach out! 😊
