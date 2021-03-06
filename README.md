# Plant Tech 🌱

We're excited to have you join this course, where you'll be working with plants, Arduino boards, moisture sensors and watering systems.

The aim of Make Days is to explore and learn new things. You don't need to achieve specific goals. The structure caters for varying levels of experience; different Makers will learn different things by playing with the same tools!

Make sure to do your prep! Go to the [Make Preparation Manual](https://github.com/OfferZen-Make/plant_tech_ams/blob/master/PREP.md), follow the steps, and don't stop before you got your LED blinking!!!

# How to get started

## What will be available for you on the evening

<img src="https://media.giphy.com/media/ge91zAgmwUqLMqiH2c/giphy.gif" alt="seven" width="300"/>

* ESP8266 module
* Dupont f-f wires (x10)
* Moisture sensor
* Micro usb to usb A cable
* Watering pump
* PVC tube + cable tie
* TIP31C Transistor

## Bring your own

* Tall glass or container with water to test the sensor and water pump
* Laptop/PC with USB-A port

## Pinouts
ESP8266:

<img src="https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png?ssl=1" alt="ESP8266" width="400"/>

Mini Submersible 5V Water Pump:

<img src="Screenshot 2020-10-08 at 09.59.51.png" alt="pump" width="300"/>

TIP31C (NPN) Transistor:

<img src="https://www.componentsinfo.com/wp-content/uploads/2020/08/tip31c-pinout-equivalent.gif" alt="tip31c" width="300"/>

Moisture Sensor:

<img src="https://www.circuitstoday.com/arduino-soil-moisture-sensor/pin-out" alt="moisture" width="500"/>

The big picture:

<img src="Screenshot 2020-10-08 at 21.19.22.png" alt="complete" width="900"/>

## Part 1 - Set up your plant!

Add 300 ml water to the bag with pressed soil, forming ~1 liter of compost. Make a few small (1cm deep) holes in the soil and place the basil seeds in them, covering with a bit of loose soil.

## Part 2 - Moisture Sensor

Connect the moisture sensor with the LM393 chip that comes in the same pack. The sensor has both an analog (0 for wet and 1023 for dry) and a digital (LOW for wet and HIGH for dry) output. Check the pinout for the sensor above and see where it would connect to the ESP8266 board (tip: it has a A0, D0, GND, and needs a voltage).

Connect the ESP8266 with your PC and start up the Android IDE. Try writing a little programme to print the sensor's moisture values (analog is more interesting here as it gives you a value from a wetness-range). If coding isn't your strong suit, you can use the code provided in this repo for the [Moisture Sensor](https://github.com/OfferZen-Make/plant_tech_ams/blob/master/MoistureSensor.ino).

Upload your code to your system, wait untill the upload is done - the terminal should read: "Leaving... Hard resetting via RTS pin..." - and open the monitor (Tools > Serial Monitor) to see your printed values. Make sure that the Baud rate in the program and your serial monitor window are the same.

Put your sensor (only the two large exposed pads) in the compost of your plant, or simply put it in a glass of water, to do some readings!

### Troubleshooting

- Sometimes the ESP8266 does not show in your IDE. If so, look for the right USB-port (Tools > Port).
- When using the code from the repo, select the 115200 BAUD option for upload speed, otherwise your readings are not printed.

## Part 3 - Mini Water Pump

The pump is water submersible, sucks in water from the hole on the opposite end of the wires, and pumps it through the little outlet. In order to switch the pump on and off, it needs to be connected to the ESP8266 with the TIP31C Transistor.

The pump has a GND output to be connected to the ESP8266 and receives power from the emitter pin of the transistor. The transistor gets it power through its collector pin from the ESP8266's 3V3 pin. Finally, connect the base to the D1 pin to be able to control the pump.

Write some code (or check the code from the [complete watering system](https://github.com/OfferZen-Make/plant_tech_ams/blob/master/plant_watering_system.ino) in this repo) to get the pump up and running. Before uploading the code, make sure to submerse the pump in your tall glass/container filled with water, as you do not want to overheat its motor - and please watch out for water spills ;)

## Part 4 - Time to play!

Now that the basics of your system are up and running, it's time to play around a bit! You can put your moisture sensor in your plant and attach the PVC tubing to the water pump (potentially use the cable tie to prevent leaking) with one end, and lay the other end in the plant.

See what analog value would be a good threshhold of dryness. Implement this in your code to start activating your pump as soon as this threshold is reached. Also try to implement some delays in your code to stop the pump after a few seconds, as it takes some time for the soil to get moist and the sensor to pick this up.

If you are confident that your very own automated watering system is fully working, you can check out the repos below for some inspiration on how to communicate with your system via your phone :)

### Further ideas
- Connect your ESP8266 with [your Wi-Fi](https://www.instructables.com/IoT-ESP8266-Series-1-Connect-to-WIFI-Router/)
- Let your system update you, and feed it commands, via text/slack/whatsapp with the [MessageBird API](https://github.com/mariuspot/plant_tech_ams/blob/master/webcontrol.ino)
- Let us know your crazy ideas so we can add them here!

# Useful resources
- [ ] Check out the [OfferZen Make Subreddit](https://www.reddit.com/r/offerzenmake) and upvote any answers you find useful. Feel free to add your own questions and comments! 
- [ ] Browse through the existing Slack channels, the place where all Makers get together to share ideas, projects, and help!
- [ ] Learn about the how, where and why of Make Days with the [Make Manifesto](https://docs.google.com/document/d/12OtTltO-ozhGd7OzDswgLoRMLtfd3_i8_Pxw1Dx551U/edit)

<img src="https://media.giphy.com/media/uuxcAmIzAbKlvz4kZS/giphy.gif" alt="unbox" width="300"/>

### Congratualtions on setting up your Automated Watering System. It was a pleasure hosting you!

### Would you please let us know what you thought about this Make session? It will only take 3 minutes and we will be grateful forever: https://forms.gle/NZ6FT3DuhXuW6MuG9

### 🎁 We want to give you the gift of giving! please refer people that you think would love to attend one of our next sessions and get the Make @ Home Box delivered to their door. You can do so via the same form! 🎁 
